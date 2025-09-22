#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/*
 * File: 0-merge_sort.c
 * Description: Top-down merge sort implementation that prints the
 * merging process as specified. Uses a single malloc'd buffer for
 * the entire sort (one malloc, one free).
 */

/**
 * merge_range - Merge two consecutive sorted ranges from array into aux.
 * @array: Source array containing the two ranges to merge.
 * @aux: Auxiliary buffer to write the merged result.
 * @left: Start index of the left range (inclusive).
 * @mid: Start index of the right range (left range ends at mid - 1).
 * @right: End index of the right range (exclusive).
 *
 * Description: After merging into aux, copy the merged segment back
 * into array in-place.
 */
static void merge_range(int *array, int *aux, size_t left,
		size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	/* Print ranges prior to merging as required */
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	/* Merge into aux */
	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			aux[k++] = array[i++];
		else
			aux[k++] = array[j++];
	}
	while (i < mid)
		aux[k++] = array[i++];
	while (j < right)
		aux[k++] = array[j++];

	/* Copy back to array */
	for (k = left; k < right; k++)
		array[k] = aux[k];

	/* Print merged result */
	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Recursively sorts array[left:right) using
 * merge sort.
 * @array: Array to sort.
 * @aux: Pre-allocated auxiliary buffer (same size as array).
 * @left: Start index of the segment (inclusive).
 * @right: End index of the segment (exclusive).
 */
static void merge_sort_recursive(int *array, int *aux,
		size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
		return;

	/* choose split point: left size <= right size */
	mid = left + (right - left) / 2;

	/* Sort left half first, then right half */
	merge_sort_recursive(array, aux, left, mid);
	merge_sort_recursive(array, aux, mid, right);

	/* Merge the two sorted halves */
	merge_range(array, aux, left, mid, right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 * Merge Sort.
 * @array: Pointer to the first element of the array to sort.
 * @size: Number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *aux;

	if (array == NULL || size < 2)
		return;

	aux = malloc(sizeof(int) * size);
	if (aux == NULL)
		return; /* malloc failed */

	merge_sort_recursive(array, aux, 0, size);

	free(aux);
}
