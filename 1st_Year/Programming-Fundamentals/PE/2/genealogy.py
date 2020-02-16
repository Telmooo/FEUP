def order(tup):
    ordr = ["sibling", "parent", "cousin", "grandparent"]
    return ordr.index(tup[1])
def genealogy(l):
    x = sorted(sorted(l, key = lambda y: y[0]), key = order)
    return x
