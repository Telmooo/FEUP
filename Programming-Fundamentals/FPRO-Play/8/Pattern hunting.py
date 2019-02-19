def pattern_hunting(l1, l2, p):
    rg = range(len(l1))
    l=[]
    for i in rg:
        if p in l1[i]:
            l.append(l2[i])
        elif p in l2[i]:
            l.append(l1[i])
    return sorted(l, reverse=True)
