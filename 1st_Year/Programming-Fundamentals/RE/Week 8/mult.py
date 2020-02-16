'''
Matrix multiplication
'''
def mult(M, N):
    '''
    Multiplies two matrices if valid for multiplication
    '''
    new_mx = []
    if len(M[0]) == len(N):
        new_mx = [[sum(x*y for x, y in zip(row_M, col_N)) 
         for col_N in zip(*N)] for row_M in M]
    return new_mx
