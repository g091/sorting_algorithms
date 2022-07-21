#include "sort.h"
/**
 * bubble_sort - sorts thru bubble_sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t num_sorted = 0;
	int temp;

	if (array != NULL)
	{
		while (num_sorted < size - 1)
		{
			for (i = 0, num_sorted = 0; i < size - 1; i++)
			{
				if (array[i] > array[i + 1])
				{
					temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
					print_array(array, size);
				}
				else
					num_sorted++;
			}
		}
	}
}
