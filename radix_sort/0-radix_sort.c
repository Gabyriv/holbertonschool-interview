#include "sort.h"

/**
 * get_max - Finds the maximum value in an array
 * @array: The array to search
 * @size: Number of elements in the array
 *
 * Return: The maximum integer value in the array
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_by_digit - Sorts array by a specific digit using counting sort
 * @array: The array to sort
 * @size: Number of elements in the array
 * @exp: The exponent representing the current digit (1, 10, 100, etc.)
 */
void counting_sort_by_digit(int *array, size_t size, int exp)
{
	int *output;
	int count[10] = {0};
	size_t i;

	/* Allocate memory for output array */
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	/* Count occurrences of each digit */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Change count[i] to contain actual position of this digit in output */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array by placing elements in sorted order */
	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* Copy the output array back to the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Description: Implements the LSD (Least Significant Digit) radix sort
 * algorithm. Prints the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	/* No need to sort if array is NULL or has less than 2 elements */
	if (array == NULL || size < 2)
		return;

	/* Find the maximum number to determine number of digits */
	max = get_max(array, size);

	/* Perform counting sort for each digit position */
	/* exp is 10^i where i is the current digit position */
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_by_digit(array, size, exp);
		print_array(array, size);
	}
}
