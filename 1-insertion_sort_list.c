#include "sort.h"

/**
 * swap - Swap a node with the next node
 * @node: The node to be swapped with its next node
 */
void swap(listint_t *node)
{
    if (node == NULL || node->next == NULL)
        return;

    listint_t *tmp = node->next;

    if (tmp->next != NULL)
        tmp->next->prev = node;

    if (node->prev != NULL)
        node->prev->next = tmp;

    node->next = tmp->next;
    tmp->prev = node->prev;
    tmp->next = node;
    node->prev = tmp;
}

/**
 * insertion_sort_list - Sort a linked list using the insertion sort algorithm
 * @list: Pointer to the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    if (!list || !*list || !(*list)->next)
        return;

    listint_t *current = *list;

    while (current)
    {
        if (current->n > current->next->n)
        {
            listint_t *tmp = current;
            swap(tmp);

            while (tmp->prev && tmp->n < tmp->prev->n)
            {
                swap(tmp->prev);
                tmp = tmp->prev;
            }

            if (!tmp->prev)
                *list = tmp;
        }
        else
        {
            current = current->next;
        }
    }
}