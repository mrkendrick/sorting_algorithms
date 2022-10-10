#include "sort.h"
/**
 * sorted_insert - insert sorted data in list
 * @head: head
 * @node: node
 * Return: void
*/

void sorted_insert(listint_t **head, listint_t *node)
{
	listint_t *current;

	if (*head == NULL)
		*head = node;
	else if ((*head)->n >= node->n)
	{
		node->next = *head;
		node->next->prev = node;
		*head = node;
	}
	else
	{
		current = *head;

		while (current->next != NULL && current->next->n < node->n)
		{
			current = current->next;
			node->next = current->next;
		}
		if (current->next != NULL)
		{
			node->next->prev = node;
		}
		current->next = node;
		node->prev = current;
	}
}
/**
 * insertion_sort_list - insertion sort on a double linked list
 * @list: list to be sorted
 * Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *current, *next;

	if ((*list) != NULL || (*list)->next != NULL)
	{
		current = *list;
		sorted = NULL;
		while (current != NULL)
		{
			next = current->next;
			current->prev = current->next = NULL;
			sorted_insert(&sorted, current);
			print_list(sorted);
			current = next;
		}
		*list = sorted;

	}
}
