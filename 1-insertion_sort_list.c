#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @left: The left node
 * @right: The right node
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	right->next = left;
	left->prev = right;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                      using the insertion sort algorithm
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		insert = current->prev;

		while (insert && current->n < insert->n)
		{
			swap_nodes(list, insert, current);
			print_list(*list);
			insert = current->prev;
		}

		current = current->next;
	}
}
