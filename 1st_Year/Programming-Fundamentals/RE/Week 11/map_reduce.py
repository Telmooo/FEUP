"""
Map-Reduce
"""
def map_reduce(n1, n2):
    from functools import reduce
    ls = map(lambda x: x**2, range(n1+(1*n1%2==0), n2+1, 2))
    return reduce(lambda x,y: x+y if x*y>50 else x*y, ls)
