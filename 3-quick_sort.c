#include "sort.h"


/**
 * swap_a - swaps two elements of an array of ints
 * @a: pointer to array value
 * @b: pointer to array value
 */
void swap_a(int *a, int *b)
{
	int temp = 0;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * quick_sort - sorts an array of ints using the Quick sort algo
 * @array: array to sort
 * @size: size of array to sort
 */
void quick_sort(int *array, size_t size)
{
	int start = 0, end = size - 1;

	if (!array || size == 1)
		return;

	quicksort(array, start, end, array, (int)size);
}

/**
 * quicksort - actual quicksort algorithm with better parameters
 * @a: array to sort
 * @start: start index of array
 * @end: end index of array
 * @fullArray: original array (complete)
 * @fullSize: size of original array (complete)
 */
void quicksort(int *a, int start, int end, int *fullArray, int fullSize)
{
	int pIndex = 0;

	if (start >= end)
		return;

	pIndex = partition(a, start, end, fullArray, fullSize);
	quicksort(a, start, pIndex - 1, fullArray, fullSize);
	quicksort(a, pIndex + 1, end, fullArray, fullSize);

}

/**
 * partition - partitions the array (elems left of pivot are lower and <->)
 * @a: array to partition
 * @start: first index of array to partition
 * @end: last index of array to partition
 * @fullArray: original array (complete)
 * @fullSize: size of original array (complete)
 * Return: index of pivot after partition/rearrangement
 */
int partition(int *a, int start, int end, int *fullArray, int fullSize)
{
	int i = start, pivot = a[end], j = 0;

/*	printf("Partition\n"); */
	for (; i < end; i++)
	{
	/**
	 * 	printf("a[i = %d] = %d\nstart = %d\nend = %d\npivot = %d\n\n",
	 * 	i, a[i], start, end, pivot);
	 */

		if (a[i] > pivot)
		{
			for (j = i + 1; j < end; j++)
			{
				if (a[j] <= pivot)
				{
				/*	printf("swap %d (i) for %d (j)\n", a[i], a[j]); */
					swap_a(&a[i], &a[j]);
					print_array(fullArray, fullSize);
					break;
				}
			}
			if (pivot < a[i])
			{
			/*	printf("swap %d (i) for %d (end)\n", a[i], a[end]); */
				swap_a(&a[i], &a[end]);
				print_array(fullArray, fullSize);
			}
			pivot = a[end];
		}
	}
	return (i);
}
