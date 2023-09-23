#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	/*Update next pointers to perform the swap.*/
	(*n1)->next = n2->next;
	/*Check if n2 has a next node and update its prev pointer.*/
	if (n2->next != NULL)
		n2->next->prev = *n1;
	/*Update prev pointer of n2 to point to the previous node.*/
	n2->prev = (*n1)->prev;
	/*Update next pointer of n2 to point to n1 (n1 comes after n2).*/
	n2->next = *n1;
	/*Check if n1 has a previous node and update its next pointer.*/
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2; /*Update the head if n1 was the head.*/
	/*Update prev pointer of n1 to point to n2.*/
	(*n1)->prev = n2;
	/*Update n1 to point to the node before n2 in the sorted list.*/
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;
	/*Check if the list is empty or has only one element.*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	/*Iterate through the list starting from the second element.*/
	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		/*Perform insertion sort within the doubly-linked list*/
		while (insert != NULL && iter->n < insert->n)
		{
			/*Call swap_nodes to swap insert and iter.*/
			swap_nodes(list, &insert, iter);
			/*Print the list after each swap.*/
			print_list((const listint_t *)*list);
		}
	}
}
