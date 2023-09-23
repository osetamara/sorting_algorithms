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
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min; /*Pointer to minimum element in unsorted part of the array.*/
	size_t r, k;
	/*Check if the array is NULL or has less than 2 elements.*/
	if (array == NULL || size < 2)
		return;
	/*Loop through the array to select the minimum element in each pass.*/
	for (r = 0; r < size - 1; r++)
	{
		min = array + i;/*Assume the current element is the minimum.*/
		/*Find the actual minimum element in the unsorted part of the array.*/
		for (k = r + 1; k < size; k++)
			min = (array[k] < *min) ? (array + k) : min;
		/*If the assumed minimum is not the actual minimum, swap them.*/

		if ((array + r) != min)
		{
			swap_ints(array + r, min);
			/*Print the array after each swap.*/
			print_array(array, size);
		}
	}
}
