#ifndef SORT_H
#define SORT_H

/*
 * File: sort.h
 * Description: Header file for merge sort project.
 * Contains function prototypes and required includes.
 */

#include <stddef.h>

/*
 * print_array - Prints an array of integers.
 * @array: Pointer to the first element of the array to print.
 * @size: Number of elements in the array.
 */
void print_array(const int *array, size_t size);

/*
 * merge_sort - Sorts an array of integers in ascending order using
 * the top-down Merge Sort algorithm.
 * @array: Pointer to the first element of the array to sort.
 * @size: Number of elements in the array.
 */
void merge_sort(int *array, size_t size);

#endif /* SORT_H */
