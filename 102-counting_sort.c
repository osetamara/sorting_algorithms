#include "sort.h"
#include <stdlib.h>

/**
 * arr_max - Find the maximum value in an array.
 * @array: The input array.
 * @size: The size of the array.
 *
 * Return: The maximum value in the array.
 */
int arr_max(int *array, size_t size)
{
	int max;
	size_t r;

	max = array[0];
	for (r = 1; r < size; r++)
		if (array[r] > max)
			max = array[r];
	return (max);
}

/**
 * counting_sort - Sorts an array using  Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description: Counting sort is a non-comparative sorting algorithm that works
 * by counting number occurrences of each element using this information
 * to place elements in their sorted positions. Prints count
 * array after counting and the sorted array after sorting.
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *output_array, max, num;
	size_t r;

    /*Check if size is less than 2 or if array is NULL, no sorting needed.*/
	if (size < 2 || !array)
		return;
	/* Find the maximum value in the input array.*/
	max = arr_max(array, size);
	/*Allocate memory for the counting array and the output array.*/
	count_array = malloc(sizeof(int) * (max + 1));
	output_array = malloc(sizeof(int) * size);
	/*Initialize the counting array with zeros.*/
	for (r = 0; (int)r <= max; r++)
		count_array[r] = 0;
	/*Count the occurrences of each element in the input array.*/
	for (r = 0; r < size; r++)
	{
		num = array[r];
		count_array[num] += 1;
	}
	/*Print the counting array to show the count of each element.*/
	print_array(count_array, max + 1);
	/*Calculate the positions of each element in the sorted order.*/
	for (r = 1; (int)r <= max; r++)
		count_array[r] += count_array[r - 1];
	/*Rearrrrange the elements into the sorted order.*/
	for (r = 0; r < size; r++)
	{output_array[count_array[array[r]] - 1] = array[r];
		count_array[array[r]]--;
	}
	/*Copy the sorted elements back to the original array.*/
	for (r = 0; r < size; r++)
		array[r] = output_array[r];
	/*Free allocated memory.*/
	free(output_array);
	free(count_array);
}
