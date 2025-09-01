/*
 * File: 0-mul.c
 * Description: Multiply two positive numbers passed as strings.
 * Constraints: Only malloc, free and exit from libc are allowed.
 * Output uses _putchar. On error, the program exits with status 98.
 */

#include "holberton.h"

/**
 * _strlen - compute string length
 * @s: string
 * Return: number of characters before NUL
 */
int _strlen(char *s)
{
	int n = 0;

	while (s && s[n])
		n++;
	return (n);
}

/**
 * is_digit_str - check if string is only digits 0-9 and not empty
 * @s: string to check
 * Return: 1 if valid, 0 otherwise
 */
int is_digit_str(char *s)
{
	int i;

	if (!s || s[0] == '\0')
		return (0);
	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * print_error_and_exit - print "Error" and exit with status 98
 */
void print_error_and_exit(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * multiply - multiply two positive number strings and print result
 * @num1: first number string (digits only)
 * @num2: second number string (digits only)
 *
 * Description: grade-school O(n*m) multiplication using an int array.
 */
void multiply(char *num1, char *num2)
{
	int len1, len2, total, i, j, d1, d2, sum, carry, started;
	int *res;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	total = len1 + len2;

	res = (int *)malloc(sizeof(int) * total);
	if (res == NULL)
		exit(98);

	for (i = 0; i < total; i++)
		res[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		d1 = num1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			d2 = num2[j] - '0';
			sum = res[i + j + 1] + (d1 * d2) + carry;
			res[i + j + 1] = sum % 10;
			carry = sum / 10;
		}
		res[i] += carry;
	}

	started = 0;
	for (i = 0; i < total; i++)
	{
		if (!started && res[i] == 0)
			continue;
		started = 1;
		_putchar(res[i] + '0');
	}
	if (!started)
		_putchar('0');
	_putchar('\n');
	free(res);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success (exits 98 on error)
 */
int main(int argc, char **argv)
{
	char *num1, *num2;

	if (argc != 3)
		print_error_and_exit();

	num1 = argv[1];
	num2 = argv[2];

	if (!is_digit_str(num1) || !is_digit_str(num2))
		print_error_and_exit();

	multiply(num1, num2);
	return (0);
}
