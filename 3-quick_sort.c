#include "sort.h"

int swapCount = 0;

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
	int i = start, pivot = a[end], pIndex = start;

	// printf("dtsrting s new psrtition\n");
	for (; i < end; i++)
	{
		/*printf("Iteration %d (i)\nstart = %d\nend = %d\npivot = %d\npIndex: = %d\n\n", i, start, end, pivot, pIndex);*/
		if (a[i] <= pivot/* && i != pIndex*/)
		{
			swap_a(&a[i], &a[pIndex]);
			pIndex++;
			print_array(fullArray, fullSize);
			// swapCount++;
			// printf("swapCount = %d\n", swapCount);
		}
	}
	swap_a(&a[pIndex], &a[end]);
	print_array(fullArray, fullSize);
	// swapCount++;
	// printf("swapCount = %d\n", swapCount);
	return (pIndex);
}
