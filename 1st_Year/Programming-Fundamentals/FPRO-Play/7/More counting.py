def count_elems(tup):
    res = ()
    for obj in tup:
        try:
            res += (len(obj),)
        except TypeError:
            res += (1,)
    return res
