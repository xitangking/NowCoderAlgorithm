#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<algorithm>

#include "Code_00_BubbleSort.h"
#include "Code_01_InsertionSort.h"
#include "Code_02_SelectionSort.h"

 using namespace std;

 double random()
 {
	 return rand() / double(RAND_MAX);
 }

 int getIntArraySize(int arr[])
 {
	 return sizeof(arr) / sizeof(int);
 }

 int* generateRandomArray(int maxSize, int maxValue,int* size)
 {
	 srand((unsigned)time(nullptr));
	 *size = (int)((maxSize + 1) * random());
	 int* arr = new int[*size];
	 for (int i = 0; i < *size; i++)
	 {
		 arr[i] = (int)((maxValue + 1) * random()) - (int)(maxValue * random()); // 如此这般，生成的 max = maxValue ，min = 0 - (maxVlaue - 1) = 1 - maxValue
	 }
	 return arr;
 }

 int* copyArray(int arr[],int size)
 {
	 if (arr == nullptr)
		 return nullptr;
	 int* res = new int[size];
	 for (int i = 0; i < size; i++)
	 {
		 res[i] = arr[i];
	 }
	 return res;
 }

 bool isEqual(int arr1[],int size1, int arr2[],int size2)
 {
	 if ((arr1 == nullptr && arr2 != nullptr) || (arr1 != nullptr && arr2 == nullptr)) {
		 return false;
	 }
	 if (arr1 == nullptr && arr2 == nullptr) {
		 return true;
	 }
	 if (size1 != size2) {
		 return false;
	 }
	 for (int i = 0; i < size1; i++) {
		 if (arr1[i] != arr2[i]) {
			 return false;
		 }
	 }
	 return true;
 }

 void printArray(int arr[],int size)
 {
	 if (arr == nullptr)
		 return;
	 for (int i = 0; i < size; ++i)
	 {
		 cout << arr[i] << " ";
	 }
	 cout << endl;
 }

 void sort(int arr[], int size)
 {
	 //BubbleSort::bubbleSort(arr, size);

	 //InsertionSort::insertionSort(arr, size);

	 SelectionSort::selectionSort(arr, size);
 }

 void main()
 {
	 int testTime = 500000;
	 int maxSize = 100;
	 int maxValue = 100;
	 bool succeed = true;
	 int size;
	 for (int i = 0; i < testTime; i++)
	 {
		 int* arr1 = generateRandomArray(maxSize, maxValue, &size);
		 int* arr2 = copyArray(arr1, size);
		 sort(arr1, size);
		 std::sort(arr2, arr2 + size);
		 if (!isEqual(arr1, size, arr2, size))
		 {
			 succeed = false;
			 break;
		 }
	 }

	 cout << (succeed ? "Nice" : "Fucking fucked!") << endl;

	 int* arr = generateRandomArray(maxSize, maxValue, &size);
	 printArray(arr, size);

	 cout << "-------------------------------------------------------------------" << endl;

	 sort(arr, size);
	 printArray(arr, size);

	 cin.get();
 }