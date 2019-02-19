def permuta(alist, step=0):
    if len(alist)==0:
        return [alist]
    perm = []
    for idx, c in enumerate(alist):
        ls = alist.copy()
        ls[idx] = ls[0]
        ls[0] = c
        ls = ls[1:]
        for p in permuta(ls):
            perm.append([c]+p)
    return perm
