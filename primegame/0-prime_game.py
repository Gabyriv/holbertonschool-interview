#!/usr/bin/python3
"""Prime Game"""


def is_prime(n):
    """
    Checks if a number is prime.
    """
    if n <= 1:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


def _prime_counts_up_to(n):
    """
    Build a prefix array where prefix[i] == number of primes in [1..i].

    Why this works for the game:
    - In a round with numbers 1..n, each move must choose a prime p that
      is still present. Choosing p removes p and all multiples of p.
    - Starting from the full set 1..n, each prime <= n can be chosen at
      most once (when p is chosen, p is removed).
    - Under optimal play, the number of available moves is exactly the
      count of primes <= n (because composites get removed as side effects,
      but primes are the only selectable moves).
    - Therefore, Maria (first player) wins iff (number of primes <= n) is odd.
    """
    if n < 0:
        n = 0

    # Simplified sieve + prefix build for readability (same behavior).
    # This documents the change: fewer temporary variables, clearer loops.
    is_prime_arr = [True] * (n + 1)
    if n >= 0:
        is_prime_arr[0] = False
    if n >= 1:
        is_prime_arr[1] = False

    # Mark non-primes by crossing off multiples of each prime.
    # Use descriptive loop names for readability.
    for candidate_prime in range(2, int(n ** 0.5) + 1):
        if is_prime_arr[candidate_prime]:
            for multiple in range(candidate_prime * candidate_prime,
                                  n + 1,
                                  candidate_prime):
                is_prime_arr[multiple] = False

    # Build prefix counts so prefix[i] == number of primes in [1..i].
    prefix = [0] * (n + 1)
    count = 0
    for i in range(n + 1):
        if is_prime_arr[i]:
            count += 1
        prefix[i] = count
    return prefix


def isWinner(x, nums):
    """
    Determines the winner of the prime game.

    Args:
        x (int): The number of rounds to play.
        nums (list of int): An array of n.

    Returns:
        str: The name of the player that won the most rounds.
        None: If the winner cannot be determined.
    """
    if x <= 0 or not nums:
        return None

    # Only play the first x rounds, per the spec.
    rounds = nums[:x]
    max_n = max(rounds)
    prime_counts = _prime_counts_up_to(max_n)

    maria_wins = 0
    ben_wins = 0

    for n in rounds:
        # Maria wins if the number of moves (primes <= n) is odd.
        if prime_counts[n] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    if ben_wins > maria_wins:
        return "Ben"
    return None
