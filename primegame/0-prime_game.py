#!/usr/bin/python3
"""Prime Game"""

def is_prime(n):
    """
    Checks if a number is prime.
    """
    if n <= 1:
        return False
    for i in range(2, n + 1):
        if n % i == 0:
            return False
    return True


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
    
    maria_wins = 0
    ben_wins = 0
    
    for n in nums:
        if is_prime(n):
            maria_wins += 1
        else:
            ben_wins += 1
            
    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
