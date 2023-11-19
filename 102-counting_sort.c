#include "sort.h"
#include <stdio.h>
/**
 * _calloc - this is a calloc function
 * @memb: number of elemets
 * @size: element bit size
 * Return: pointer to alocated memory
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
 * counting_sort - sorts array of integers using counting sort algorithm
 * @array: array to sort
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int index, max = 0, *counter = NULL, *temp = NULL;
	size_t n;

	if (array == NULL || size < 2)
		return;

	for (n = 0; n < size; n++)
		if (array[n] > max)
			max = array[n];
	counter = _calloc(max + 1, sizeof(int));
	temp = _calloc(size + 1, sizeof(int));

	for (n = 0; n < size; n++)
		counter[array[n]]++;

	for (index = 1; index <= max; index++)
		counter[index] += counter[index - 1];
	print_array(counter, max + 1);

	for (n = 0; n < size; ++n)
	{
		temp[counter[array[n]] - 1] = array[n];
		counter[array[n]]--;
	}

	for (n = 0; n < size; n++)
		array[n] = temp[n];
	free(temp);
	free(counter);

}
