#include "sort.h"
/**
  * partition - split array
  * @arr: array
  * @left: left most index
  * @right: right most index
  * @size: full array size
  * Return: pivot index
  */

int partition(int *arr, int left, int right, size_t size)
{
	int i, i2, pivot, temp;

	pivot = arr[right];
	i = left;

	for (i2 = left; i2 < right; i2++)
	{
		if (arr[i2] < pivot)
		{
			if (i != i2)
			{
				temp = arr[i2];
				arr[i2] = arr[i];
				arr[i] = temp;
				print_array(arr, size);
			}
			i++;
		}
	}
	if (arr[i] != arr[right])
	{
		temp = arr[i];
		arr[i] = arr[right];
		arr[right] = temp;
		print_array(arr, size);
	}

	return (i);
}

/**
  * qs_alg - recursive sorting algorithm
  * @arr: array
  * @left: leftmost index
  * @right: rightmost index
  * @size: full size of array
  */

void qs_alg(int *arr, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(arr, left, right, size);
		qs_alg(arr, left, pivot - 1, size);
		qs_alg(arr, pivot + 1, right, size);
	}
}

/**
  * quick_sort - quick sort algorithm
  * @array: array to be sorted
  * @size: size of array
  */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	qs_alg(array, 0, size - 1, size);
}
