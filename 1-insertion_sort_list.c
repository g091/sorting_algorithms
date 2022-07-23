#include "sort.h"
/**
 * insertion_sort_list - sorts doubly linked list in ascending order using
 * insertion sort
 * @list: doubly linked list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *forw, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (forw = (*list)->next; forw && forw->prev; forw = forw->next)
	{
		for (; forw && forw->prev && forw->n < forw->prev->n;
		     forw = forw->prev)
		{
			temp = forw->prev;
			swap(list, temp, forw);
			print_list(*list);
			forw = forw->next;
		}
	}
}

/**
 * swap - swaps 2 nodes
 * @head: head node
 * @node1: 1st node
 * @node2: 2nd node
 * Return: nothing
 */

void swap(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *prev, *next;

	prev = node1->prev;
	next = node2->next;

	if (prev != NULL)
		prev->next = node2;
	else
		*head = node2;

	node1->prev = node2;
	node1->next = next;
	node2->prev = prev;
	node2->next = node1;
	if (next)
		next->prev = node1;
}
