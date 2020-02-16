def maximum_depth(l, depth=1):
    if l == []: return depth
    maxd = 1 #default
    for subl in l:
        x = maximum_depth(subl, depth+1)
        if x > maxd:
            maxd = x
    return maxd
