#pragma once
class InsertionSort
{
public:
	static void insertionSort(int arr[], int size)
	{
		if (arr == nullptr || size < 2)
			return;
		for (int i = 1; i < size; i++)
		{
			for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1] ; j--)
			{
				swap(arr, j, j + 1);
			}
		}
	}

private:
	static void swap(int arr[], int i, int j) // 不用额外变量完成交换，实力装X
	{
		arr[i] = arr[i] ^ arr[j];
		arr[j] = arr[i] ^ arr[j];
		arr[i] = arr[i] ^ arr[j];
	}
};

