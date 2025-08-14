#!/usr/bin/python3
"""
Count keywords in titles of hot posts from a subreddit using Reddit API.

Requirements implemented:
- Uses requests with a proper User-Agent
- Recursive pagination via `after` parameter (no while-loop for pages)
- Case-insensitive counting; duplicates in word_list are summed
- Exact-token matching only (e.g., "java." does not count as "java")
- Prints nothing on invalid subreddit or no matches
"""

import requests


def count_words(subreddit, word_list, after=None, counts=None, targets=None):
    """Recursively query Reddit hot posts and print sorted keyword counts.

    Args:
        subreddit (str): Subreddit name.
        word_list (list): List of keywords (strings).
        after (str): Reddit pagination token (internal use).
        counts (dict): Accumulator for counts (internal use).
        targets (dict): Mapping keyword->duplicate multiplier (internal use).

    Behavior:
        - Prints results in descending count, then alphabetically for ties.
        - Only prints words with positive counts; words are printed lowercase.
        - Returns None and prints nothing for invalid subreddits.
    """
    if subreddit is None or word_list is None:
        return

    # Initialize target words and counters on the first call
    if targets is None:
        targets = {}
        for w in word_list:
            if isinstance(w, str):
                lw = w.lower()
                if lw:
                    targets[lw] = targets.get(lw, 0) + 1
        counts = dict((w, 0) for w in targets.keys())

    # If there are no valid targets, nothing to do
    if not targets:
        return

    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    headers = {
        'User-Agent': 'holberton:count_it:v1.0 (by /u/holberton_student)'
    }
    params = {'limit': 100}
    if after is not None:
        params['after'] = after

    try:
        res = requests.get(
            url, headers=headers, params=params, allow_redirects=False,
            timeout=10
        )
    except Exception:
        # Network or requests error: per spec, print nothing
        return

    if res.status_code != 200:
        # Invalid subreddit or redirected: print nothing
        return

    try:
        payload = res.json().get('data', {})
    except Exception:
        return
    children = payload.get('children', [])

    # Process titles in this page
    for child in children:
        title = child.get('data', {}).get('title', '')
        tokens = title.lower().split()
        # Exact-token match only (no punctuation stripping)
        for token in tokens:
            if token in targets:
                counts[token] += 1

    # Recurse if there is another page
    next_after = payload.get('after')
    if next_after is not None:
        return count_words(subreddit, word_list, next_after, counts, targets)

    # Finalize and print sorted results
    results = []
    for word in counts:
        total = counts[word] * targets[word]
        if total > 0:
            results.append((word, total))

    if not results:
        return

    # Sort by count desc, then word asc
    results.sort(key=lambda item: (-item[1], item[0]))

    for word, total in results:
        print('{}: {}'.format(word, total))

