#include "Sorting.h"
#include "FileManager.h"
#include <iostream>
#include <chrono>
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
    std::string inputFilename = "FileInput.txt";
    std::string outputFilename = "FileOutput.txt";

    std::cout << "Choose sorting algorithm from the list:\n1 - Bubble Sort\n2 - Quick Sort\n3 - Heap Sort\n4 - Merge Sort\n";
    int choice = -1;
    while (choice > 4 || choice < 1) std::cin >> choice; //Zabezpiecznie przed niepoprawną wartością

    int n = 0;
    int* tab;
    bool isIncreasing = true; // zalozenie, ze uzytkownik wybierze porzadek niemalejacy

    try {
        readData(inputFilename, tab, n); // odczyt danych z pliku
        
        std::cout << "\nData for sorting: " << std::endl;
        for (int i = 0; i < n; ++i) { // Dane przed sortowaniem
            std::cout << tab[i] << " ";
        }
        std::cout << "\n";
        std::chrono::duration<double> time;
        auto start = std::chrono::system_clock::now();
        auto end = std::chrono::system_clock::now();
        
        int choiceType = -1;
        
        std::cout << "Choose sorting type:\n1 - ascending\n2 - descending" << std::endl;
        while (choiceType > 2 || choiceType < 1) std::cin >> choiceType;

        if (choiceType == 2) isIncreasing = false; // zmiana wartosci, jesli zalozenie uzytkownik wybierze porzadek nierosnacy

        switch (choice)
        {
        case 1:
            start = std::chrono::system_clock::now();
            bubbleSort(tab, n, isIncreasing);
            end = std::chrono::system_clock::now();
            time = end-start;
            std::cout <<"Sorting time in miliseconds for bubble sort: " << time.count() * 1000000 << std::endl;
            break;

        case 2:
            start = std::chrono::system_clock::now();
            quickSort(tab, 0, n - 1, isIncreasing);
            end = std::chrono::system_clock::now();
            time = end-start;
            std::cout <<"Sorting time in miliseconds for quick sort: " << time.count() * 1000000<< std::endl;
            break;

        case 3:
            start = std::chrono::system_clock::now();
            heapSort(tab, n, isIncreasing);
            end = std::chrono::system_clock::now();
            time = end-start;
            std::cout <<"Sorting time in miliseconds for heap sort: " << time.count() * 1000000 << std::endl;
            break;

        case 4:
            start = std::chrono::system_clock::now();
            mergeSort(tab, 0, n - 1, isIncreasing);
            end = std::chrono::system_clock::now();
            time = end-start;
            std::cout <<"Sorting time in miliseconds for merge sort: " << time.count() * 1000000 << std::endl;
            break;
        }

        std::cout << "Sorted data:\n";
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