'''
Find local minima
'''
def local_minima(alist, n):
    '''
    Finds all local minima from a list
    '''
    lm = []
    for idx, x in enumerate(alist):
        #gets all the neighbours (excludes the pivot element (x))
        #neighbours aren't transversal (first element isn't a neighbour of the last)
        neigh = [alist[i] for i in range(idx-n//2, idx+n//2+1) if i in range(len(alist)) and i!=idx]
        #test the condition to be a local minima
        if all(x<=y for y in neigh):
            #test if there's any local minima that's a neighbour
            #if there is, the current element isn't added
            if not any(x==y and (y, j) in lm for j in range(idx-n//2, idx) for y in neigh):
                lm.append((x, idx))
    return lm
