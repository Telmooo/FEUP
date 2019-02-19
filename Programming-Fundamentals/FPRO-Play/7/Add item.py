def add_item(tup, idx, item):
    ls = list(tup)
    if tup:
        if idx in (0, len(tup)-1):
                ls[idx] = item
        else: ls.insert(idx, item)
    else:
        ls.insert(idx, item)
    return tuple(ls)
