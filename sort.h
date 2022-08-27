#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern int swapCount;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

void swap_nodes(listint_t *node1, listint_t *node2);

void quicksort(int *a, int start, int end, int *fullArray, int fullSize);
int partition(int *a, int start, int end, int *fullArray, int fullSize);

/**
 * swap_a - swaps two elements of an array of ints
 * @a: pointer to array value
 * @b: pointer to array value
 */
void swap_a(int *a, int *b); /* swap SBA */
/* void swap(int *xp, int *yp); swap LUIS */

#endif /* SORT_H */
