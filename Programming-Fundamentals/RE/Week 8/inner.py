'''
Inner dot product
'''
def inner(u, v):
    '''
    Computes the dot product of two vectors
    '''
    return sum(u[i]*v[i] for i in range(len(u)))
