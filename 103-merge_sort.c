#include "sort.h"
#include <stdio.h>
/**
 *_calloc - this is a calloc function
 *@memb: number of elemets
 *@size: element bit size
 *Return: pointer to allocated memory
 */
void *_calloc(unsigned int memb, unsigned int size)
{
	unsigned int n = 0;
	char *t;

	if (memb == 0 || size == 0)
		return (NULL);
	t = malloc(memb * size);
	if (t == NULL)
		return (NULL);
	for (n = 0; n < (memb * size); n++)
		t[n] = 0;
	return (t);
}
/**
 * merge - makes a merge
 * @arr: one from start to mid
 * @temp: temp array used in merge
 * @start: first element position
 * @m: array middle
 * @end: last element position
 **/
void merge(int *arr, int *temp, int start, int m, int end)
{

	int left_size = m - start + 1, right_size = end - m;
	int *array_left, *array_right;
	
	int left, right, k = 0;

	array_left = &temp[0];
	array_right = &temp[right_size];
	for (left = 0; left < left_size; left++)
		array_left[left] = arr[start + left];
	for (right = 0; right < right_size; right++)
		array_right[right] = arr[m + 1 + right];
	left = 0, right = 0, k = start;

	while (left < left_size && right < right_size)
	{
		if (array_left[left] <= array_right[right])
			arr[k] = array_left[left], left++;
		else
			arr[k] = array_right[right], right++;
		k++;
	}
	
	while (left < left_size)
		arr[k] = array_left[left], left++, k++;

	while (right < right_size)
		arr[k] = array_right[right], right++, k++;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array_left, left);
	printf("[right]: ");
	print_array(array_right, right);
	printf("[Done]: ");
	print_array(&arr[start], left + right);
}
/**
 * mergesort - sorts an array of integers using merge sort
 * @array: array of integers
 * @temp: temporary array used in merge
 * @start: fisrt element position
 * @end: last element position
 * Return: void
 */
void mergesort(int *array, int *temp, int start, int end)
{
	int m;

	m = (start + end) / 2;
	if ((start + end) % 2 == 0)
		m--;
	if (m >= start)
	{
		mergesort(array, temp, start, m);
		mergesort(array, temp, m + 1, end);
		merge(array, temp, start, m, end);
	}
}
/**
 * merge_sort - sorts an array of integers in ascending using merge
 * sort
 * @size: size of the list
 * @array: array of integers
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;
	temp = _calloc(size, sizeof(int));
	mergesort(array, temp, 0, size - 1);
	free(temp);
}
