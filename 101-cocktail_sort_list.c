#include "sort.h"

/**
 * swapme - Swap the nodes themselves in a doubly linked list.
 * @current: Pointer to the current node.
 * @current_old: Pointer to the previous node.
 * @list: The doubly linked list.
 *
 * Description: Swaps the positions of two nodes in doubly linked list
 * and updates the list pointers accordingly. Prints the list after each swap.
 */
void swapme(listint_t *current, listint_t *current_old, listint_t **list)
{
	/*Store the next nodes of both current and current_old.*/
	listint_t *temp1 = current->next;
	listint_t *temp2 = current_old->prev;
	/*update the next and prev pointers to swap the nodes.*/
	if (temp1 != NULL)
		temp1->prev = current_old;
	if (temp2 != NULL)
		temp2->next = current;
	current->prev = temp2;
	current_old->next = temp1;
	current->next = current_old;
	current_old->prev = current;
	/*If current_old was the head of  list, update list pointer.*/
	if (*list == current_old)
		*list = current;
	print_list(*list);/*Print the doubly linked list after each swap.*/
}

/**
 * cocktail_sort_list - Sorts doubly linkedlist using cocktail sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 *
 * Description: Sorts the doubly linked list in ascending order. Prints list
 * after each swap operation.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *check = *list, *first = NULL, *last = NULL;
	/*Check if list pointer is NULL, list is empty, or has only one element.*/
	if (!list || !(*list) || !(*list)->next)
		return; /* If any of these conditions are met, no need to sort.*/
	/*/Start the cocktail sort algorithm.*/
	do {
		/*Move to right and swap if current node is greater than next node.*/
		while (check->next)
		{
			if (check->n > check->next->n)
				swapme(check->next, check, list);
			else
				check = check->next;
		}
		/* Update the last sorted node.*/
		last = check;
		while (check->prev != first)
		{
			if (check->n < check->prev->n)
				swapme(check, check->prev, list);
			else
				check = check->prev;
		}
		/* Update the first sorted node.*/
		first = check;
	} while (first != last);/*Repeat until the entire list is sorted.*/
}
