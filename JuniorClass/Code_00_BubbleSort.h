#pragma once

class BubbleSort
{

public:

	static void bubbleSort(int arr[],int size)
	{
		if (arr == nullptr || size == 0)
			return;
		for (int e = size - 1; e > 0; --e)
		{
			for (int i = 0; i < e; i++)
			{
				if (arr[i] > arr[i + 1])
					swap(arr, i, i + 1);
			}
		}
	}

private:

	static void swap(int arr[], int i, int j)
	{
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
};
