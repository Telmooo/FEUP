def interleave(l1, l2):
    r = []
    if not l1 or not l2: return []
    u1 = unpack(l1)
    u2 = unpack(l2)
    for x, y in zip(u1, u2):
        r += [x, y]
    return r

def unpack(l):
    r = []
    for i in l:
        if isinstance(i, list):
            r += unpack(i)
        else:
            r+=[i]
    return r
