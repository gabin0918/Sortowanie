#include "FileManager.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

/* Funkcja realizujaca odczyt danych z pliku
* parameter fileName - nazwa pliku
* parameter tab - wskaznik do tablicy do zapisania danych z pliku
* parameter n - ilosc liczb do odczytu do tablicy - pierwsza liczba w pliku
*/
void readData(const std::string& fileName, int*& tab, int& n) {
	std::ifstream fileIn(fileName);
	if (!fileIn.is_open()) throw std::runtime_error("Could not open input file.");

	int value; // zmienna do odczytywania danych z pliku 
	int i = 0; 
	fileIn >> n;
	tab = new int[n];
	while (fileIn >> value && i < n) { // odczyt danych do posortowania
		tab[i++] = value;
	}

	fileIn.close();
}

/* Funkcja realizujaca zapis danych do pliku
* parameter fileName - nazwa pliku
* parameter tab - wskaznik do tablicy danych z pliku
* parameter n - rozmiar tablicy
*/
void writeData(const std::string& fileName, int* tab, const int& n) {
	std::ofstream fileOut(fileName);
	if (!fileOut.is_open()) throw std::runtime_error("Could not open output file.");

	for (int i = 0; i < n; ++i) {
		fileOut << tab[i] << std::endl; // zapis danych do pliku
	}
	
	fileOut.close();
}