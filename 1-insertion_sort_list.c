#include "sort.h"

/**
 * insertion_sort_list - sorts a dlinked list (asc) using the Insertion algo
 * @list: dlinked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL, *node1 = NULL, *node2 = NULL;
	listint_t *key = NULL, *lshift = NULL;
	int listLen = 1;

	if (!list)
		return;
	for (head = *list; head->next; listLen++)
		head = head->next;
	head = *list;
	if (listLen == 1)
		return;
	if (listLen == 2)
	{
		node1 = head;
		node2 = head->next;
		swap_nodes(node1, node2);
		*list = node2;
		print_list(*list);
		return;
	}
	while (head->next)
	{
		head = head->next;
		key = head;
		lshift = key->prev;
		while (lshift)
		{
			if (key->n < lshift->n)
			{
				node1 = lshift;
				node2 = key;
				swap_nodes(node1, node2);
				if (node2->prev == NULL)
					*list = node2;
				print_list(*list);
			}
			lshift = lshift->prev;
		}

	}
}

/**
 * swap_nodes - swaps nodes of a doubly linked list
 * @node1: one node to swap
 * @node2: the otehr node to swap
 */
void swap_nodes(listint_t *node1, listint_t *node2)
{
	listint_t *nodeLeft = NULL, *nodeRight = NULL;

	if (!node1 || !node2)
		return;

	if (node1->prev)
	{
		nodeLeft = node1->prev;
		node2->prev = nodeLeft;
		nodeLeft->next = node2;
	}
	else
		node2->prev = NULL;

	if (node2->next)
	{
		nodeRight = node2->next;
		node1->next = nodeRight;
		nodeRight->prev = node1;
	}
	else
		node1->next = NULL;

	node1->prev = node2;
	node2->next = node1;
}
