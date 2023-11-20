#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps two integers
 * @a: 1st integer
 * @b: 2nd integer
 **/
void swap(int *a, int *b)
{
	int j = *a;

	*a = *b;
	*b = j;
}

/**
 * maxHeapify - Tmain function to heapify a Max Heap
 * @array: array
 * @size: size of the array for print
 * @index: index
 * @i: size of the array to run
 */
void maxHeapify(int *array, size_t size, int index, size_t i)
{
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;


	if (left < (int)i && array[left] > array[largest])
		largest = left;

	if (right < (int)i && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		swap(&array[index], &array[largest]);
		print_array(array, size);
		maxHeapify(array, size, largest, i);
	}
}

/**
 * heap_sort -  sorts an array of integers in ascending order using
 * heap sort algorithm
 * @array: array to sort
 * @size: size of the array
 **/
void heap_sort(int *array, size_t size)
{
	int k;

	if (array == NULL || size < 2)
		return;

	for (k = (size - 2) / 2; k >= 0; --k)
		maxHeapify(array, size, k, size);

	for (k = (size - 1); k > 0; --k)
	{
		swap(&array[0], &array[k]);
		print_array(array, size);

		maxHeapify(array, size, 0, k);
	}
}
