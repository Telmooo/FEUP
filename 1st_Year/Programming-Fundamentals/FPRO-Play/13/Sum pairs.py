def sum_pairs(alist):
    l = []
    for i, x in enumerate(alist[:-1]):
        try:
            l.append(x+alist[i+1])
        except:
            continue
    return l
