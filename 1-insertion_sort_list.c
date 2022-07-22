#include "sort.h"
/**
 * swap - swaps the elements of a d l list
 * @prev: previous element
 * @cu: current element
 */

void swap(listint_t *prev, listint_t *cu)
{
	cu->prev = prev->prev;
	prev->next = cu->next;
	prev->prev = cu;
	cu->next = prev;

	if (cu->prev)
		cu->prev->next = cu;
	if (prev->next)
		prev->next->prev = prev;
}

/**
 * insertion_sort_list - implementation of the insertion sort
 * @list: the list to sort
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *cu, *first;
	int i, c = 0;

	if (list == NULL || (*list) == NULL)
		return;

	first = *list;
	cu = *list;

	while (cu != NULL)
	{
		c++;
		while (cu->prev != NULL)
			if (cu->n < cu->prev->n)
			{
				swap(cu->prev, cu);

				if (cu->prev == NULL)
				{
					first = cu;
					*list = first;
				}

				print_list(*list);
			}
			else
				break;

		for (i = 0; i < c; i++)
			if (i == 0)
				cu = first->next;
			else
				cu = cu->next;
	}
}
