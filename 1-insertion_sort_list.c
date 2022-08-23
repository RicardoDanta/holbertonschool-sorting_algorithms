#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *
 * @list: list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *aux_node = NULL;

	if (list == NULL || *list == NULL)
		return;

	current = *list;
	for (; current;	current = aux_node)
	{
		aux_node = current->next;
		for (; current->prev && current->n < current->prev->n;)
		{
			swap_nodes(current, current->prev, list);
			print_list(*list);
		}
	}
}

/**
 * swap_nodes - swaps two nodes in a dlinked list
 *
 * @head: pointer the head
 * @nodeA: node A
 * @nodeB: node B
 */

void swap_nodes(listint_t *nodeA, listint_t *nodeB, listint_t **head)
{
	listint_t *aux;
	listint_t *aux_pointer[4];


	/* rename if out of order */
	if (nodeB->next == nodeA)
	{
		aux = nodeA;
		nodeA = nodeB;
		nodeB = aux;
	}


	/* creates auxiliar values of each node */
	aux_pointer[0] = nodeA->prev;
	aux_pointer[1] = nodeB->prev;
	aux_pointer[2] = nodeA->next;
	aux_pointer[3] = nodeB->next;


	nodeA->prev = aux_pointer[2];
	nodeB->prev = aux_pointer[0];
	nodeA->next = aux_pointer[3];
	nodeB->next = aux_pointer[1];


	if (nodeA->next)
		nodeA->next->prev = nodeA;

	if (nodeB->prev)
		nodeB->prev->next = nodeB;

	if (nodeB->prev == NULL)
		*head = nodeB;
}
