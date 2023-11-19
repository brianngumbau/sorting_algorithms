#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * using selection sort algorithm
 * @size: size of the array
 * @array: list with numbers
 */
void selection_sort(int *array, size_t size)
{
	size_t n, index;
	int temp, swap, flag = 0;

	if (array == NULL)
		return;
	for (n = 0; n < size; n++)
	{
		temp = n;
		flag = 0;
		for (index = n + 1; index < size; index++)
		{
			if (array[temp] > array[index])
			{
				temp = index;
				flag += 1;
			}
		}
		swap = array[n];
		array[n] = array[temp];
		array[temp] = swap;
		if (flag != 0)
			print_array(array, size);
	}
}
