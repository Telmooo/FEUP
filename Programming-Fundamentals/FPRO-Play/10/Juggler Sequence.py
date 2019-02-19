def juggler(n, p):
    if p == 0: return n
    i = juggler(n, p-1)
    return int(i**((1+2*(i%2))/2))
