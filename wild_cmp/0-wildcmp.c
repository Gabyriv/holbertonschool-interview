#include "holberton.h"

/**
 * wildcmp - compares two strings; s2 may contain '*' as a wildcard
 * @s1: first string
 * @s2: second string (may include '*')
 *
 * Return: 1 if the strings can be considered identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	/* If both strings end, they match */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* 
     * If current chars match or s2 has '?'-like equality (not allowed here),
	 * we only support '*' as wildcard per requirements.
	 */
	if (*s2 != '*')
	{
		if (*s1 == *s2 && *s1 != '\0')
			return (wildcmp(s1 + 1, s2 + 1));
		/* Either mismatch or s1 ended while s2 didn't */
		return (0);
	}

	/* 
     * Now *s2 == '*' case:
	 * Collapse consecutive '*' by advancing s2 over them recursively.
	 */
	if (*s2 == '*')
	{
		/* Skip over consecutive '*' to normalize */
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));

		/* Try '*' matching empty string: advance s2 */
		if (wildcmp(s1, s2 + 1))
			return (1);

		/* Try '*' matching one or more chars of s1: advance s1 if possible */
		if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			return (1);

		/* No match */
		return (0);
	}

	/* 
     * Unreachable in practice due to earlier returns
     * but keeps structure clear 
     */
	return (0);
}
