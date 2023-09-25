#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_left_right - Print the left and right partitions during merging.
 * @array: The original array being merged.
 * @size: The size of the second array.
 * @first: The initial position of the first array.
 * @mid: The middle position, which separates the two arrays.
 *
 * Description: Prints left and right partitions during merging process.
 */
void print_left_right(int *array, int size, int first, int mid)
{
	int l;

	printf("Merging...\n");
	printf("[left]: ");
	l = first;
	while (l < mid)
	{
		if (l != mid - 1)
			printf("%d, ", array[l]);
		else
			printf("%d\n", array[l]);
		l++;
	}

	printf("[right]: ");
	l = mid;
	while (l < size)
	{
		if (l < size - 1)
			printf("%d, ", array[l]);
		else
			printf("%d\n", array[l]);
		l++;
	}
}

/**
 * merge - Merge the values in the position of the array.
 * @array: The original array to be merged.
 * @size: The size of the second array.
 * @first: The initial position of the first array.
 * @mid: The middle position, which separates the two arrays.
 * @cpy: A copy of the original array.
 *
 * Description: Merges two partitions of the array into a single sorted array.
 * Prints the merged result after the merge operation.
 */
void merge(int *array, int size, int first, int mid, int *cpy)
{
	int r, m, l;

	print_left_right(array, size, first, mid);

	r = first;
	m = mid;

	printf("[Done]: ");
	l = first;
	while (l < size)
	{
		if (r < mid && (m >= size || array[r] <= array[m]))
		{
			cpy[l] = array[r];
			r++;
		}
		else
		{
			cpy[l] = array[m];
			m++;
		}
		if (l < size - 1)
			printf("%d, ", cpy[l]);
		else
			printf("%d\n", cpy[l]);
		l++;
	}
}

/**
 * mergeSort - Recursive function to perform the merge sort algorithm.
 * @cpy: A copy of the original array.
 * @first: The initial position of the array.
 * @size: The size of the original array.
 * @array: The original array.
 *
 * Description: Recursively divides the array into smaller partitions and
 * merges them back together in sorted order.
 */
void mergeSort(int *cpy, int first, int size, int *array)
{
	int mid;

	if (size - first < 2)
		return;/*Base case: if the partition size is 1 or 0, no need to sort.*/

	mid = (size + first) / 2;

	mergeSort(array, first, mid, cpy);/*Sort the left partition.*/
	mergeSort(array, mid, size, cpy);/* Sort the right partition.*/

	merge(cpy, size, first, mid, array);/*Merge the two sorted partitions.*/
}

/**
 * copy_array - Copy the contents of one array to another.
 * @arr: The source array.
 * @cpy: The destination array.
 * @size: The size of the array.
 *
 * Description: Copies the contents source array to destination array.
 */
void copy_array(int *arr, int *cpy, int size)
{
	int r;

	for (r = 0; r < (int)size; r++)
		cpy[r] = arr[r];
}

/**
 * merge_sort - Sort an array using the merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description: Creates partitions of the array and merges them back together
 * in sorted order using the merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *cpy;

	cpy = malloc(sizeof(int) * size);

	if (cpy == NULL)
		return;

	copy_array(array, cpy, size);

	mergeSort(cpy, 0, size, array);/*Start the merge sort.*/

	free(cpy);/*Free the allocated memory for the copy array.*/
}

