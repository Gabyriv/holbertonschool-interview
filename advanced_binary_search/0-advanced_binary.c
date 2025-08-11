#include <stdio.h>
#include "search_algos.h"

/*
 * File: 0-advanced_binary.c
 * Description:
 *   Recursive binary search that prints the current subarray on each split
 *   and returns the FIRST index of a value in a sorted array.
 *   Only one loop is used to print the array; search itself is recursive.
 */

/**
 * print_subarray - Print the subarray between indexes left and right inclusive
 * @array: Pointer to the first element of the array
 * @left: Left bound index (inclusive)
 * @right: Right bound index (inclusive)
 *
 * Return: void
 */
static void print_subarray(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * advanced_binary_recursive - Recursive helper to locate first occurrence
 * @array: Pointer to the first element of the array
 * @left: Current left index (inclusive)
 * @right: Current right index (inclusive)
 * @value: Value to search for
 *
 * Return: Index where value is located (first occurrence), or -1 on failure
 */
static int advanced_binary_recursive(int *array, size_t left,
	size_t right, int value)
{
	size_t mid;

	if (array == NULL)
		return (-1);

	if (left > right)
		return (-1);

	print_subarray(array, left, right);

	/* Base case: single element range after printing */
	if (left == right)
	{
		if (array[left] == value)
			return ((int)left);
		return (-1);
	}

	mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		if (mid == left)
			return ((int)mid);
		/* Keep searching on the left to find the first occurrence */
		return (advanced_binary_recursive(array, left, mid, value));
	}

	if (array[mid] > value)
	{
		/* Search left half including mid to match expected prints */
		return (advanced_binary_recursive(array, left, mid, value));
	}

	/* array[mid] < value */
	return (advanced_binary_recursive(array, mid + 1, right, value));
}

/**
 * advanced_binary - Search for a value in a sorted array using advanced binary
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in @array
 * @value: Value to search for
 *
 * Return: Index where value is located (first occurrence), or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
