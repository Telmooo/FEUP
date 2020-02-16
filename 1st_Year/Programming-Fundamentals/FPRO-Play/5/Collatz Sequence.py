def collatz(n):
    '''
    Dangerous, can easily be near infinite
    '''
    x = n
    r = f"{n}"
    while x != 1 and x>0:
        x = x*3 + 1 if x%2 else x//2
        r = ",".join((r, str(x)))
    return r if n>0 else ""
