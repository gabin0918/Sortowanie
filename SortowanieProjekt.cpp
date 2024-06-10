#include "Sorting.h"
#include <algorithm>


/* Funkcja realizujaca algorytm sortowania babelkowego
* parameter tab - ciag do posortowania
* parameter n - ilosc elementow do posortowania
* parameter isIncreasing - wskazuje jak ma byc posortowana tablica (true - rosnaco, false - malejaco)
*/
void bubbleSort(int* tab, int n, bool isIncreasing) {
    if (n < 2) return; // jesli liczba elementow jest mniejsza niz 2, to konczymy algorytm
    bool swapped; // zmienna pomocnicza - sygnalizuje czy w petli sortujacej zostalo wykonane przestawienie elementow
    for (int i = 0; i < n - 1; i++) { // przejscie po calej dlugosci tablicy n-1 razy
        swapped = false; 
        for (int j = 0; j < n - i - 1; j++) { // petla sortujaca - porownanie elementu sprawdzanego j z elementem nastepnym
            if (isIncreasing) {
                if (tab[j] > tab[j + 1]) {
                    int temp = tab[j];
                    tab[j] = tab[j + 1];
                    tab[j + 1] = temp;
                    swapped = true;
                }
            }
            else {
                if (tab[j] < tab[j + 1]) {
                    int temp = tab[j];
                    tab[j] = tab[j + 1];
                    tab[j + 1] = temp;
                    swapped = true;
                }
            }
        }
        // warunek dodatkowy do optymalizacji
        if (!swapped) break;// jeżeli swapped jest false to w całym przebiegu nie było zamiany więc tablica jest posortowana
    }
}

/* Funkcja realizujaca algorytm sortowania szybkiego
* parameter tab - ciag do posortowania
* parameter left - indeks elementu poczatkowego sprawdzanej podtablicy
* parameter rigth - indeks elementu koncowego sprawdzanej podtablicy
* parameter isIncreasing - true jesli tablica ma byc posortowana niemalejaco, false - jesli nierosnaco
*/
void quickSort(int* tab, int left, int right, bool isIncreasing) {// lewy to 0 a prawy to n-1
    if (left >= right) return; // podtablica ma dlugosc 0 lub 1, wiec jest posortowana - koniec dzialania

    int i = left;
    int j = right;
    int pivot = tab[(left + right) / 2];

    while (i <= j) { // w pętli znajdujemy elementy, które są po złej stronie pivota, a następnie je zamieniamy
        if (isIncreasing) {
            while (tab[i] < pivot) i++;
            while (tab[j] > pivot) j--;
        }
        else {
            while (tab[i] > pivot) i++;
            while (tab[j] < pivot) j--;
        }

        if (i <= j) {
            std::swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }

    if (left < j) quickSort(tab, left, j, isIncreasing); // rekurencyjne sortowanie lewej podtablicy (od lewej granicy do j)
    if (i < right) quickSort(tab, i, right, isIncreasing); // rekurencyjne sortowanie prawej podtablicy (od i do prawej granicy)
}

/* Funkcja do przywracania wlasnosci kopca - zaklada sie, ze tablica jest posortowana zgodnie z wlanoscia kopca, 
ale element tab[i] moze naruszac wlasnosc kopca
* parameter tab - tablica zawierajaca kopiec
* parameter n - rozmiar tablicy
* parameter i - indeks elementu tablicy, ktory moze naruszac wlasnosc kopca
* parameter isIncreasing - true jesli kopiec typu max (sortowanie niemalejaco), false - kopiec min (sortowanie nierosnaco)
*/
void heapify(int* tab, int n, int i, bool isIncreasing) {
    int largestOrSmallest = i; // zmienna pomocnicza do zapisania indeksu mniejszego/wiekszego elementu 
    int left = 2 * i + 1;  // indeks lewego syna elementu o indeksie i
    int right = 2 * i + 2; // indeks prawego synu elementu o indeksie i

    if (isIncreasing) { // kopiec jest typu max, jesli sortowanie ma byc w porzadku niemalejacym
        if (left < n && tab[left] > tab[largestOrSmallest])
            largestOrSmallest = left;

        if (right < n && tab[right] > tab[largestOrSmallest])
            largestOrSmallest = right;
    } else { // kopiec jest typu min, jesli sortowanie ma byc w porzadku nierosnacym
        if (left < n && tab[left] < tab[largestOrSmallest])
            largestOrSmallest = left;

        if (right < n && tab[right] < tab[largestOrSmallest])
            largestOrSmallest = right;
    }

    // zamiana sprawdzanego tab[i] z jednym z jego synow, jesli tab[i] okazal sie najwiekszym (kopiec typu max)  
    // lub najmniejszym (kopiec typu min) to procedura zatrzymuje sie
    if (largestOrSmallest != i) {
        std::swap(tab[i], tab[largestOrSmallest]);
        heapify(tab, n, largestOrSmallest, isIncreasing); // poddrzewo zaczepione w tab[largestOrSmallest] moze nie spelniac 
        // wlasnosci kopca, dlatego wywolujemy dla niego heapify() ponownie
    }
}

/* Funkcja realizujaca algorytm sortowania przez kopcowanie
* parameter tab - tablica danych do posortowania
* parameter n - rozmiar tablicy
* parameter isIncreasing - true jesli kopiec ma byc posortowany niemalejaco, false - jesli nierosnaco
*/
void heapSort(int* tab, int n, bool isIncreasing) {
    /* dla wezlow, ktore nie sa liscmi, wywolana jest funkcja, ktora wstawi element o indeksie i na odpowiedni miejsce
    pierwsza iteracja jest wykonywana dla ostatniego wezla, ktory nie jest lisciem, czyli elementu o indeksie n / 2 - 1, 
    a ostatnia dla korzenia o indeksi 0 */
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(tab, n, i, isIncreasing);

    for (int i = n - 1; i > 0; i--) {
        std::swap(tab[0], tab[i]); // zamiana korzenia kopca z ostatnim elementem tablicy
        // przywrocenie wlasnosci kopca dla tablicy zmniejszonej o 1 element (ostatni element jest na odpowiednim miejscu),
        heapify(tab, i, 0, isIncreasing); // bo korzen moze byc nie na swoim miejscu 
    }
}

/* Funkcja wykonuje scalanie z sortowaniem dwoch polowek podtablicy
* parameter tab - tablica danych do posortowania
* parameter left - indeks skrajnie lewego elementu obszaru roboczego tablicy
* parameter mid - indeks srodkowego elementu obszaru roboczego tablicy (to ostatni element prawej podtablicy, przy liczbie parzystej
  elementow dwie podtablicy sa rownych rozmiarow, przy liczbie nieparzystej - prawa podtablica jest o 1 element mniejsza)
* parameter right - indeks skrajnie prawego elementu obszaru roboczego tablicy
* parameter isIncreasing - true jesli tablica ma byc posortowana niemalejaco, false - jesli nierosnaco
*/
void merge(int* tab, int left, int mid, int right, bool isIncreasing) {
    int n1 = mid - left + 1; // rozmiar lewego obszaru roboczego tablicy
    int n2 = right - mid; // rozmiar prawego obszaru roboczego tablicy

    // tablicy pomocnicze, do ktorej kopiujemy lewa i prawa podtablice
    int* L = new int[n1]; 
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = tab[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = tab[mid + 1 + j];

    // indeksy do poruszania sie po tablicach R[], L[] i tab[] odpowiednio 
    int i = 0, j = 0, k = left;

    // poruszanie po potablicach i porownanie wartosci ich elementow dopoki ktoras z tablic sie nie wyczerpi
    if (isIncreasing) { // sortowanie niemalejaco
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                tab[k++] = L[i++];
            } else {
                tab[k++] = R[j++];
            }
        }
    } else { // sortowanie nierosnaco
        while (i < n1 && j < n2) {
            if (L[i] >= R[j]) {
                tab[k++] = L[i++];
            } else {
                tab[k++] = R[j++];
            }
        }
    }
    // jesli po zakonczeniu porownan w lewej lub prawej podtablicy pozostaly elementy, to zostana po kolei dodane do tab[]
    while (i < n1) {
        tab[k++] = L[i++];
    }
    while (j < n2) {
        tab[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}

/* Funkcja realizuje sortowanie przez scalanie - wykonuje rekurencyjnie dzielenie tablicy wejsciowej na podtablicy rozmiarem o polowe mniejszym, 
dopoki nie bedzie to pojedynczy element (rozkrecanie sie rekurencji). Nastepnie laczy od najmniejszej podtablicy w tablicy
o rozmiarze 2 razy wiekszym jednoczesnie sortujac za pomoca funkcji pomocniczej merge() (skrecanie sie rekurencji)
* parameter tab - tablica danych do posortowania
* parameter left - indeks skrajnie lewego elementu obszaru roboczego tablicy
* parameter right - indeks skrajnie prawego elementu obszaru roboczego tablicy
* parameter isIncreasing - true jesli tablica ma byc posortowana niemalejaco, false - jesli nierosnaco
*/
void mergeSort(int* tab, int left, int right, bool isIncreasing) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(tab, left, mid, isIncreasing);
    mergeSort(tab, mid + 1, right, isIncreasing);
    merge(tab, left, mid, right, isIncreasing);
}


