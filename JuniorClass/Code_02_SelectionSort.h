#pragma once
#include<iostream>

class SelectionSort
{

public:
	static void selectionSort(int arr[], int size)
	{
		if (arr == nullptr || size < 2)
			return;
		for (int i = 0; i < size - 1; i++)
		{
			int minIndex = i;
			for (int j = i + 1; j < size; j++)
			{
				minIndex = arr[j] < arr[minIndex] ? j : minIndex;
			}
			swap(arr, i, minIndex);
		}
	}

private:
	static void swap(int arr[], int i, int j)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
};