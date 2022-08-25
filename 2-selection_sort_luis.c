#include "sort.h"
/**
 * swap - this funtion swap the position of array
 * @xp: pointer to int
 * @yp: pointer to int
 * return: void
 */
void swap(int *xp, int *yp)
{
	int temp = 0;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array with integers
 * @size: array size
 * return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, min_idx = 0;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_idx])
				min_idx = j;
		if (min_idx != i)
		{
			swap(&array[min_idx], &array[i]);
			print_array(array, size);
		}
	}
}
