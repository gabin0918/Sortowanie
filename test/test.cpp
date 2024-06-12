#include "pch.h"
#include "Sorting.h"
//#include "SortowanieProjekt.cpp"

// Testy dla funkcji bubbleSort()
TEST(SortingTest, BubbleSort) {
	int arr[] = { 5, 3, 8, 4, 2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, size, true);
	int expected[] = { 2, 3, 4, 5, 8 };
	for (int i = 0; i < size; ++i) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(SortingTest, BubbleSortEmpty) {
	int* arr = nullptr;
	int size = 0;
	bubbleSort(arr, size, true);
	EXPECT_EQ(arr, nullptr);
}

TEST(SortingTest, BubbleSortSingleElement) {
	int arr[] = { 7 };
	int size = 1;
	bubbleSort(arr, size, true);
	int expected[] = { 7 };
	for (int i = 0; i < size; ++i) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(SortingTest, BubbleSortAlreadySorted) {
	int arr[] = { 8, 9, 11, 16, 23 };
	int size = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, size, true);
	int expected[] = { 8, 9, 11, 16, 23 };
	for (int i = 0; i < size; ++i) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(SortingTest, BubbleSortReversed) {
	int arr[] = { 19, 12, 6, 2, 1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, size, true);
	int expected[] = { 1, 2, 6, 12, 19 };
	for (int i = 0; i < size; ++i) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

// Testy dla funkcji quickSort()
TEST(SortingTest, QuickSort) {
	int arr[] = { 4, 19, 32, 2, 43, 13, 4, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, size - 1, true);
	int expected[] = { 2, 4, 4, 6, 13, 19, 32, 43 };
	for (int i = 0; i < size; ++i) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(SortingTest, QuickSortEmpty) {
	int* arr = nullptr;
	int size = 0;
	quickSort(arr, 0, size - 1, true);
	EXPECT_EQ(arr, nullptr);
}

TEST(SortingTest, QuickSortSingleElement) {
	int arr[] = { 7 };
	int size = 1;
	quickSort(arr, 0, size - 1, true);
	int expected[] = { 7 };
	for (int i = 0; i < size; ++i) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(SortingTest, QuickSortAlreadySorted) {
	int arr[] = { 8, 9, 11, 16, 23 };
	int size = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, size - 1, true);
	int expected[] = { 8, 9, 11, 16, 23 };
	for (int i = 0; i < size; ++i) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(SortingTest, QuickSortReversed) {
	int arr[] = { 19, 12, 6, 2, 1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, size - 1, true);
	int expected[] = { 1, 2, 6, 12, 19 };
	for (int i = 0; i < size; ++i) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

// Testy dla funkcji mergeSort()
TEST(SortingTest, MergeSort) {
	int arr[] = { 4, 19, 32, 2, 43, 13, 4, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, 0, size - 1, true);
	int expected[] = { 2, 4, 4, 6, 13, 19, 32, 43 };
	for (int i = 0; i < size; ++i) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(SortingTest, MergeSortEmpty) {
	int* arr = nullptr;
	int size = 0;
	mergeSort(arr, 0, size - 1, true);
	EXPECT_EQ(arr, nullptr);
}

TEST(SortingTest, MergeSortSingleElement) {
	int arr[] = { 45 };
	int size = 1;
	mergeSort(arr, 0, size - 1, true);
	int expected[] = { 45 };
	for (int i = 0; i < size; ++i) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(SortingTest, MergeSortAlreadySorted) {
	int arr[] = { 4, 32, 41, 46, 53 };
	int size = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, 0, size - 1, true);
	int expected[] = { 4, 32, 41, 46, 53 };
	for (int i = 0; i < size; ++i) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(SortingTest, MergeSortReversed) {
	int arr[] = { 19, 12, 6, 2, 1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, 0, size - 1, true);
	int expected[] = { 1, 2, 6, 12, 19 };
	for (int i = 0; i < size; ++i) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

// Testy dla funkcji heapSort()
TEST(SortingTest, HeapSort) {
	int arr[] = { 5, 3, 8, 4, 2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, size, true);
	int expected[] = { 2, 3, 4, 5, 8 };
	for (int i = 0; i < size; ++i) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(SortingTest, HeapSortEmpty) {
	int* arr = nullptr;
	int size = 0;
	heapSort(arr, size, true);
	EXPECT_EQ(arr, nullptr);
}

TEST(SortingTest, HeapSortSingleElement) {
	int arr[] = { 7 };
	int size = 1;
	heapSort(arr, size, true);
	int expected[] = { 7 };
	for (int i = 0; i < size; ++i) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(SortingTest, HeapSortAlreadySorted) {
	int arr[] = { 8, 9, 11, 16, 23 };
	int size = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, size, true);
	int expected[] = { 8, 9, 11, 16, 23 };
	for (int i = 0; i < size; ++i) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(SortingTest, HeapSortReversed) {
	int arr[] = { 19, 12, 6, 2, 1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, size, true);
	int expected[] = { 1, 2, 6, 12, 19 };
	for (int i = 0; i < size; ++i) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}