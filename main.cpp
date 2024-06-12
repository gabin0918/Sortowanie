#include "Sorting.h"
#include "FileManager.h"
#include <iostream>

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
    // sprawdzenie pracy z plikami odczytu/zapisu oraz sortowan
    std::string inputFilename = "FileInput.txt";
    std::string outputFilename = "FileOutput.txt";

    int n = 0;
    int* tab;
    try {
        readData(inputFilename, tab, n);
        for (int i = 0; i < n; ++i) { // Dane przed sortowaniem
            std::cout << tab[i] << " ";
        }

        bubbleSort(tab, n, false);
        // quickSort(tab, 0, n - 1, true);
        // heapSort(tab, n, true);
        //mergeSort(tab, 0, n - 1, false);

        std::cout << "\n";
        for (int i = 0; i < n; ++i) { // Dane po sortowaniu
            std::cout << tab[i] << " ";
        }

        writeData(outputFilename, tab, n);
        std::cout << "\nData sorted and written to " << outputFilename << std::endl;
        delete[] tab;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    

    return 0;
}