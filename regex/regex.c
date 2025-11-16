#include "regex.h"

/**
 * regex_match - checks if a pattern matches a string
 * @str: pointer to the string to scan
 * @pattern: pointer to the regular expression pattern
 *
 * Return: 1 if the pattern matches the string, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	int first_match;

	/* If pattern is empty, str must also by empty */
	if (*pattern == '\0')
		return (*str == '\0');

	/* Does this first character match (taking '.' into account) */
	first_match = (*str != '\0') &&
		(*pattern == *str || *pattern == '.');

	/**
	 * If the next pattern character is '*', we have 2 possibilities:
	 *  1. Skip "x*" entirely (zero occurrences)
	 *  2. If the first characters match, consume one char from the str
	 *      and keep pattern at the same position (for mor repeats)
	 */
	if (*(pattern + 1) == '*')
	{
		/* zero occurence of preceding char OR one more occurrnce */
		return (regex_match(str, pattern + 2) ||
			(first_match && regex_match(str + 1, pattern)));
	}
	else
	{
		/* No '*', so we must match current chars and the move both */
		return (first_match && regex_match(str + 1, pattern + 1));
	}
}
