# Count it!

Recursive Reddit keyword counter for Holberton School.

This project implements `count_words(subreddit, word_list)` which queries the
Reddit API for all hot posts in a subreddit, parses post titles, and prints a
sorted count of given keywords.

## Environment

- Ubuntu 14.04 LTS
- Python 3.4.3
- PEP 8 style, executable files, shebang `#!/usr/bin/python3`
- Requests library for HTTP calls

## Files

- `0-count.py` — implementation of `count_words()` (recursive)
- `0-main.py` — small driver to run examples from CLI
- `requirements.txt` — Python dependencies (requests)

## Function Prototype

```python
def count_words(subreddit, word_list):
    """Print a sorted, case-insensitive count of keywords in hot post titles."""
```

Notes:

- The function is recursive and paginates using Reddit's `after` token.
- Duplicate words in `word_list` are summed in the final total.
- Matching is case-insensitive and by exact token only.
- Words are printed in lowercase, skipping those with zero count.
- Results are sorted by count (descending) then alphabetically (ascending).
- Invalid subreddits or no matches: print nothing.
- Redirects are not followed (`allow_redirects=False`).

## Setup

```bash
pip3 install -r requirements.txt
```

## Usage

```bash
./0-main.py <subreddit> '<space separated keywords>'

# examples
./0-main.py programming 'react python java javascript scala no_results_for_this_one'
./0-main.py programming 'JavA java'
./0-main.py not_a_valid_subreddit 'python java'
```

Example output (live counts will vary):

```text
python: 18
java: 15
javascript: 4
react: 2
scala: 1
```

## Implementation Details

- API endpoint: `https://www.reddit.com/r/<subreddit>/hot.json`
- Custom User-Agent header is required: `holberton:count_it:v1.0 (by /u/holberton_student)`
- Pagination via `after` is handled recursively (no loop for pages)
- Network timeout of 10 seconds is used; JSON parsing is guarded

## Constraints Recap

- Must be recursive for pagination
- Case-insensitive counting; duplicates in `word_list` are summed
- Exact-token matches only; punctuation or substrings do not count
- Print nothing for invalid subreddit or when there are no matches

## Author

Gabriel Rivera
