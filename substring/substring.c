#include "substring.h"
#include <stdlib.h>
#include <string.h>

/**
 * is_valid_substring - Check if substring at position is valid concatenation
 * @s: the string being scanned
 * @pos: starting position in s
 * @words: array of words to match
 * @nb_words: number of words
 * @word_len: length of each word
 * @used: array to track which words have been used
 *
 * Return: 1 if valid, 0 otherwise
 */
static int is_valid_substring(char const *s, int pos, char const **words,
							   int nb_words, int word_len, int *used)
{
	int i, j;
	int found;

	/* Reset used array */
	for (i = 0; i < nb_words; i++)
		used[i] = 0;

	/* Check each chunk of word_len characters */
	for (i = 0; i < nb_words; i++)
	{
		found = 0;
		/* Try to find this chunk in the words array */
		for (j = 0; j < nb_words; j++)
		{
			/* Skip already used words */
			if (used[j])
				continue;

			/* Check if this chunk matches this word */
			if (strncmp(s + pos + (i * word_len), words[j], word_len) == 0)
			{
				used[j] = 1;
				found = 1;
				break;
			}
		}

		/* If this chunk doesn't match any unused word, invalid */
		if (!found)
			return (0);
	}

	return (1);
}

/**
 * find_substring - Find all substrings that are concatenations of all words
 * @s: the string to scan
 * @words: array of words to find
 * @nb_words: number of words in array
 * @n: address to store number of indices found
 *
 * Return: allocated array of indices, or NULL if none found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *indices, *used;
	int s_len, word_len, total_len;
	int i, count;

	/* Initialize return value */
	*n = 0;

	/* Handle edge cases */
	if (!s || !words || nb_words == 0)
		return (NULL);

	/* Calculate lengths */
	s_len = strlen(s);
	word_len = strlen(words[0]);
	total_len = word_len * nb_words;

	/* If substring would be longer than s, no matches possible */
	if (total_len > s_len)
		return (NULL);

	/* Allocate array to store indices (worst case: all positions match) */
	indices = malloc(sizeof(int) * (s_len - total_len + 1));
	if (!indices)
		return (NULL);

	/* Allocate helper array to track used words */
	used = malloc(sizeof(int) * nb_words);
	if (!used)
	{
		free(indices);
		return (NULL);
	}

	/* Check each possible starting position */
	count = 0;
	for (i = 0; i <= s_len - total_len; i++)
	{
		if (is_valid_substring(s, i, words, nb_words, word_len, used))
		{
			indices[count] = i;
			count++;
		}
	}

	free(used);

	/* If no matches found, return NULL */
	if (count == 0)
	{
		free(indices);
		return (NULL);
	}

	*n = count;
	return (indices);
}
