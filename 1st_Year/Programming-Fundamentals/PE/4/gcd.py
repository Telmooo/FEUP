def gcd(a, b):
    from math import gcd as hackerman
    return hackerman(a, b)
#another method
    if b == 0: return a
    x, y = abs(a), abs(b)
    r = x%y
    return gcd(y, r) if r else y
