def histogram(alist, bins):
    l = []
    for i in range(len(bins)-1):
        l.append(len(list(filter(lambda x: bins[i]<=x<bins[i+1], alist))))
    return l
