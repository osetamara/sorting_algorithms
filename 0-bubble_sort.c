#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t r, len = size;
	bool bubbly = false;
	/*Check if the array is NULL or has less than 2 elements.*/
	if (array == NULL || size < 2)
		return;
	/*Start the bubble sort algorithm.*/
	while (bubbly == false)
	{
		bubbly = true;
		/*Iterate through the array and compare adjacent elements.*/
		for (r = 0; r < len - 1; r++)
		{
			/*If the current element is greater than the next element, swap them.*/
			if (array[r] > array[r + 1])
			{
				swap_ints(array + r, array + r + 1);
				/* Print the array after each swap.*/
				print_array(array, size);
				/*Set bubbly to false to indicate that a swap occurred in this pass.*/
				bubbly = false;
			}
		}
		len--;
	}
}
