#ifndef Sorting_h
#define Sorting_h

void bubbleSort(int* tab, int n, bool isIncreasing);

void quickSort(int* tab, int left, int right, bool isIncreasing);

void heapify(int* tab, int n, int i, bool isIncreasing);
void heapSort(int* tab, int n, bool isIncreasing);

void merge(int* tab, int left, int mid, int right, bool isIncreasing);
void mergeSort(int* tab, int left, int right, bool isIncreasing);

#endif