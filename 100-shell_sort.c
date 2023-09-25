#include "sort.h"

/**
 * shell_sort - Sorts an array using Shell sort algorithm with Knuth Sequence.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description: Shell sort is a variation of insertion sort that improves
 * efficiency by comparing and swapping elements that are farther apart.
 * The Knuth Sequence is used to determine gap between elements to be compared.
 * Prints the array after each gap-based insertion sort.
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1, r, m, tmp;
	/*Determine the initial gap using the Knuth Sequence.*/
	while (gap < ((int)(size)))
		gap = (3 * gap) + 1;
	/*Reduce the gap in each iteration until it becomes 1.*/
	for (gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (r = gap; r < (int)size; r += 1)
		{
			tmp = array[r];
			/* Perform insertion sort within the current gap.*/
			for (m = r; m >= gap && array[m - gap] > tmp; m -= gap)
				array[m] = array[m - gap];
			array[m] = tmp;
		}
		print_array(array, size);/*Print the array after each gap-based insertion sort.*/
	}
}
