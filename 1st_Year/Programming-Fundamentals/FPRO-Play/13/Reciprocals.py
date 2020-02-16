def reciprocals(alist):
    l = []
    for x in alist:
        try:
            l.append(1/x)
        except:
            continue
    return l
