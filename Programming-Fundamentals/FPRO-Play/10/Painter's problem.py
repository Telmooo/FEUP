def paint(n, boards):
    if n==1: return max(boards)
    ls = []
    for i in range(len(boards)-n+1):
        ls.append(paint(1, boards[:i+1])+paint(n-1, boards[i+1:]))
    return min(ls)
