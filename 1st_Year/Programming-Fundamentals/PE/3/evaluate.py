def evaluate(a, x):
    r = 0
    for i, c in enumerate(a):
        r += c*(x**i)
    return r
