#include "sort.h"
#include <stdio.h>
/**
 *swap_node - swaps a node with its previous one
 *@node: node
 *@list: node list
 *Return: pointer to node \
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
/**
 * cocktail_sort_list - sorts a doubly linked list using cocktail shaker sort
 * @list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int done_swap = 1;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	node = *list;
	while (done_swap == 1)
	{
		done_swap = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_node(node->next, list);
				done_swap = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (done_swap == 0)
			break;
		done_swap = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_node(node, list);
				done_swap = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
