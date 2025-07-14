#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *prev;

	/* Check if list is NULL */
	if (list == NULL)
		return (NULL);

	/* Start with the first express node if it exists */
	current = list->express;
	prev = list;

	/* Use express lane to find the range where value might be */
	while (current != NULL && current->express != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       current->index, current->n);

		/* If current express node value is >= search value, stop here */
		if (current->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
			       prev->index, current->index);
			break;
		}

		prev = current;
		current = current->express;
	}

	/* If we reached the end of express lane, continue to the end of list */
	if (current != NULL && current->express == NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       current->index, current->n);
		printf("Value found between indexes [%lu] and [%lu]\n",
		       prev->index, current->index);
	}

	/* If we found a value >= search value in express lane, search backwards */
	if (current != NULL && current->n >= value && prev != NULL)
	{
		current = prev;
	}

	/* Search linearly from current position */
	while (current != NULL)
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
