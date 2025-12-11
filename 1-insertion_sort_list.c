#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *                       in ascending order using insertion sort
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		next = current->next;
		prev = current->prev;

		while (prev && current->n < prev->n)
		{
			/* Swap current node backward */

			/* Detach current */
			prev->next = current->next;
			if (current->next)
				current->next->prev = prev;

			/* Insert current before prev */
			current->prev = prev->prev;
			current->next = prev;

			if (prev->prev)
				prev->prev->next = current;
			else
				*list = current;

			prev->prev = current;

			print_list(*list);
			prev = current->prev;
		}
		current = next;
	}
}
