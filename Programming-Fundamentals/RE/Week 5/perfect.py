def is_perfect(n):
    """
    check wether a number n is perfect
    """
    #calculates the sum of all divisors for numbers greater than 1
    if n > 1:
        sum_divisors = 0
        for i in range(1, n):
            if n % i == 0:
                sum_divisors += i
        if sum_divisors == n:
            return True
        return False
    #for numbers lower or equal to 1, only the number 1 is perfect
    #0 has no divisors, and every sum of the divisors of negative numbers is 0
    else:
        return n == 1
