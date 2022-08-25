#include "sort.h"


/**
 * selection_sort - sorts an array in asc order using selection sort algorithm
 * @array: array to sort
 * @size: size of array to sort
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int min = 0, temp = 0;
	bool minFound = false;

	for (; j < size && array && size > 1; j++)
	{
		min = j;
		for (i = j + 1; i < size; i++)
		{
			if (array[i] < array[min])
			{
				min = i;
				minFound = true;
			}
		}
		temp = array[j];
		array[j] = array[min];
		array[min] = temp;
		if (minFound)
			print_array(array, size);
		minFound = false;
	}
}
