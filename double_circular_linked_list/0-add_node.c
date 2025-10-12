#include "list.h"
#include <string.h>

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: address of the head pointer
 * @str: string to duplicate into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *node, *tail;

	if (list == NULL || str == NULL)
		return (NULL);

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);

	node->str = strdup(str);
	if (node->str == NULL)
	{
		free(node);
		return (NULL);
	}

	if (*list == NULL)
	{
		/* First node points to itself in a circular list */
		node->next = node;
		node->prev = node;
		*list = node;
		return (node);
	}

	/* Existing non-empty circular list */
	tail = (*list)->prev;

	node->next = *list;
	node->prev = tail;

	tail->next = node;
	(*list)->prev = node;

	return (node);
}

/**
 * add_node_begin - Add a new node to the beginning of a double circular list
 * @list: address of the head pointer
 * @str: string to duplicate into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *node;

	node = add_node_end(list, str);
	if (node == NULL)
		return (NULL);

	/*
	* If list was empty, *list already points to node. Otherwise,
	* move head to the new node we added at the end (which becomes new head).
	*/
	*list = node;

	return (node);
}
