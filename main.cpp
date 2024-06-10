#include <iostream>
#include "Sorting.h"

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

int main() {

    const int n = 5;
    int tab[n] = { 1, 7, 3, 4, 9 };

    // bubbleSort(tab, n, false);
    // quickSort(tab, 0, n - 1, true);
    // heapSort(tab, n, true);
    mergeSort(tab, 0, n - 1, false);
    for (int i = 0; i < n; ++i) {
        std::cout << tab[i] << " ";
    }

    return 0;
}