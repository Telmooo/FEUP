def recursive_dot(l1, l2):
    r = 0
    if not l1 or not l2: return 0
    for x, y in zip(l1, l2):
        if isinstance(x, list):
            r += recursive_dot(x, y)
        else:
            r += x*y
    return r
