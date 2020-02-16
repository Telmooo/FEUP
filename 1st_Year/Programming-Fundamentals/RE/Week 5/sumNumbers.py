def sum_numbers(n):
    """
    returns the sum of all positive integers up to and including n
    """
    total = 0
    for i in range(n+1):
        total += i
    return total
