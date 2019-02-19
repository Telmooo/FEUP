def count_until(tup):
    control = False
    idx = None
    for obj in tup:
        if isinstance(obj, tuple):
            control = True
            idx = tup.index(obj)
    return idx if control else -1
