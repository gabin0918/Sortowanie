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

int main(){

}

