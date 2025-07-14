#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *prev, *search_start, *search_end;

	if (list == NULL)
		return (NULL);

	current = list->express;
	prev = list;
	search_start = list;
	search_end = NULL;

	if (current == NULL) /* No express lane, search entire list */
	{
		while (prev->next)
			prev = prev->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
				list->index, prev->index);
		search_start = list;
		search_end = prev;
	}
	else
	{
		while (current != NULL)
		{
			printf("Value checked at index [%lu] = [%d]\n",
					current->index, current->n);

			if (current->n >= value)
			{
				printf("Value found between indexes [%lu] and [%lu]\n",
						prev->index, current->index);
				search_start = prev;
				search_end = current;
				break;
			}

			if (current->express == NULL)
			{
				prev = current;
				while (current->next)
					current = current->next;
				printf("Value found between indexes [%lu] and [%lu]\n",
						prev->index, current->index);
				search_start = prev;
				search_end = current;
				break;
			}

			prev = current;
			current = current->express;
		}
	}

	current = search_start;
	while (current != NULL && current->index <= search_end->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				current->index, current->n);

		if (current->n == value)
			return (current);

		if (current->n > value)
			break;

		current = current->next;
	}

	return (NULL);
}
