def batch_norm(alist, batch_size):
    while alist:
        l = alist[:batch_size]
        orde = sorted(l)
        m = orde[(len(orde)-1)//2:len(orde)//2+1]
        yield [x-sum(m)/len(m) for x in l]
        alist = alist[batch_size:]
