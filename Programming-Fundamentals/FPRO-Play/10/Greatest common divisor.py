def rec_gcd(n1, n2):
    if n1==0 or n2==0:
        return
    x = n1%n2
    if x:
        return rec_gcd(n2, x)
    return n2
