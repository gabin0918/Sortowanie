#include <iostream>
#include <algorithm>
/*
Napisz program który pozwoli na posortowanie tabeli w języku C++ następującymi algorytmami:
 Sortowanie bąbelkowe
 Sortowanie przez scalanie
 Sortowanie szybkie
 Sortowanie przez kopcowanie
Program powinien pozwalać na wybranie algorytmu sortowania.
Tablica wejściowa powinna być podana w formie pliku tekstowego z wartościami podanymi w
kolejnych liniach.
Wyjście powinno być zapisywane do pliku tekstowego w formie analogicznej do pliku
wejściowego.

*/
//bąbelkowe
void bubbleSort(int* tab, int n, bool isIncreasing) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
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
        //Warunek dodatkowy do optymalizacji
        if (!swapped) break;//Jeżeli swapped jest false to w całym przebiegu nie było zamiany więc tablica jest posortowana
    }
}
//szybkie
void quickSort(int* tab, int left, int right, bool isIncreasing) {//lewy to 0 a prawy to n-1
    if (left >= right) return;

    int i = left;
    int j = right;
    int pivot = tab[(left + right) / 2];

    while (i <= j) {
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

    if (left < j) quickSort(tab, left, j, isIncreasing);
    if (i < right) quickSort(tab, i, right, isIncreasing);
}
//do kopcowego
void heapify(int* tab, int n, int i, bool isIncreasing) {
    int largestOrSmallest = i; // Initialize largest or smallest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    if (isIncreasing) {
        if (left < n && tab[left] > tab[largestOrSmallest])
            largestOrSmallest = left;

        if (right < n && tab[right] > tab[largestOrSmallest])
            largestOrSmallest = right;
    } else {
        if (left < n && tab[left] < tab[largestOrSmallest])
            largestOrSmallest = left;

        if (right < n && tab[right] < tab[largestOrSmallest])
            largestOrSmallest = right;
    }

    if (largestOrSmallest != i) {
        std::swap(tab[i], tab[largestOrSmallest]);
        heapify(tab, n, largestOrSmallest, isIncreasing);
    }
}
//kopcowe
void heapSort(int* tab, int n, bool isIncreasing) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(tab, n, i, isIncreasing);

    for (int i = n - 1; i > 0; i--) {
        std::swap(tab[0], tab[i]);
        heapify(tab, i, 0, isIncreasing);
    }
}
// do scalania
void merge(int* tab, int left, int mid, int right, bool isIncreasing) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = tab[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = tab[mid + 1 + j];

    int i = 0, j = 0, k = left;

    if (isIncreasing) {
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                tab[k] = L[i];
                i++;
            } else {
                tab[k] = R[j];
                j++;
            }
            k++;
        }
    } else {
        while (i < n1 && j < n2) {
            if (L[i] >= R[j]) {
                tab[k] = L[i];
                i++;
            } else {
                tab[k] = R[j];
                j++;
            }
            k++;
        }
    }

    while (i < n1) {
        tab[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        tab[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}
// przez scalania
void mergeSort(int* tab, int left, int right, bool isIncreasing) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(tab, left, mid, isIncreasing);
    mergeSort(tab, mid + 1, right, isIncreasing);
    merge(tab, left, mid, right, isIncreasing);
}

int main(){

}

