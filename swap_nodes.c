#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a dlinked list
 *
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
