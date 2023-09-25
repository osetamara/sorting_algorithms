#include "sort.h"

/**
 * selection_sort - Sorts an array using the selection sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t r, d, less, tmp, swap;

	if (array == NULL)
		return;/*If the array is empty, nothing to sort, so return.*/

	for (r = 0; r < size; r++)
	{
		/*Initialize variables to keep track of index of smallest element*/
		/*and whether a swap has occurred.*/
		for (less = r, d = r; d < size; d++)
		{
			/*Find the index of the smallest element in the unsorted part of the array.*/
			if (array[d] < array[less])
			{
				less = d; /*Update the index of the smallest element.*/
				swap = 1;/*Set swap to 1 to indicate that a swap is needed.*/
			}
		}
		if (swap == 1)
		{
			/*Swap the smallest element with the current element.*/
			tmp = array[less];
			array[less] = array[r];
			array[r] = tmp;
			/*Print the array after each swap.*/
			print_array(array, size);
			swap = 0;/*Reset swap to 0 for the next iteration.*/
		}
	}
}
