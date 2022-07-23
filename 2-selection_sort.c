#include "sort.h"
/**
 * selection_sort - sort array using selection sort
 * @array: array to be sorted
 * @size: length of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, pos;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		pos = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[pos] > array[j])
				pos = j;
		}
		if (pos != i)
		{
			temp = array[i];
			array[i] = array[pos];
			array[pos] = temp;
			print_array(array, size);
		}
	}
}
