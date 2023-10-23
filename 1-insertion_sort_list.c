#include "sort.h"


void swap(listint_t *list);
listint_t *get_first(listint_t *list);

/**
 * insertion_sort_list - sort a linked list in insertion algorithme
 *
 * @list: Pointer to the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp;
	listint_t *cur, *first;

	cur = *list;
	if (*list == NULL || list == NULL || (*list)->next == NULL)
	{
		return;
	}

	while (cur != NULL)
	{
		if (cur->next == NULL)
		{
			(*list) = get_first((*list));
			return;
		}
		if (cur->n == cur->next->n)
		{
			cur = cur->next;
		}
		else if (cur->n < cur->next->n)
		{
			cur = cur->next;
		}
		else if (cur->n > cur->next->n)
		{
			tmp = cur;
			swap(tmp);
			tmp = tmp->prev;
			first = get_first(cur);
			print_list(first);
			while (tmp != NULL)
			{
				if (tmp->prev == NULL || tmp->n > tmp->prev->n)
				{
					break;
				}
				else if (tmp->n < tmp->prev->n)
				{
					swap(tmp->prev);
					first = get_first(*list);
					print_list(first);
				}
			}
		}
	}
}
/**
 * swap - swap a node with the next node
 *
 * @list: Pointer to the node that will be swap
 */
void swap(listint_t *list)
{
	listint_t *tmp;

	if (list == NULL || list->next == NULL)
	{
		return;
	}
	tmp = list->next;
	if (tmp->next != NULL)
	{
		tmp->next->prev = list;
	}
	if (list->prev != NULL)
	{
		list->prev->next = tmp;
	}

	list->next = tmp->next;
	tmp->prev = list->prev;
	tmp->next = list;
	list->prev = tmp;
}

/**
 * get_first - get to the first node of a double linked list
 *
 * @list: Pointer to a node
 *
 * Return: first node
 */
listint_t *get_first(listint_t *list)
{
	listint_t *head;

	head = list;
	while (head->prev != NULL)
	{
		head = head->prev;
	}
	return (head);
}
