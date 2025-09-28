#!/usr/bin/python3
"""Module for calculating the fewest coins needed to reach a total."""


def makeChange(coins, total):
    """Determine the minimum number of coins required to achieve ``total``.

    Args:
        coins (list): List of available coin denominations (positive integers).
        total (int): Target sum to achieve using the fewest number of coins.

    Returns:
        int: Fewest number of coins needed, ``0`` if ``total`` is non-positive,
        or ``-1`` if the amount cannot be met with the given coins.
    """
    if total <= 0:
        return 0

    # Remove non-positive and duplicate denominations to simplify processing.
    unique_coins = sorted(set(filter(lambda value: value > 0, coins)))
    if not unique_coins:
        return -1

    max_value = total + 1  # Acts as infinity for DP initialization.
    dp = [max_value] * (total + 1)
    dp[0] = 0

    # Build DP table with minimal coins for each amount.
    for coin in unique_coins:
        for amount in range(coin, total + 1):
            candidate = dp[amount - coin] + 1
            if candidate < dp[amount]:
                dp[amount] = candidate

    return dp[total] if dp[total] != max_value else -1
