'''
Zero-sum Triplet
'''
from itertools import combinations

def triplet(atuple):
    '''
    Searchs the triplet with the lowest index whose sum is 0
    '''
    #generates every combination with 3 elements possible
    #tuple has by default more than 3 elements
    null_comb = [comb for comb in combinations(atuple, 3) if sum(comb) == 0]
    indexes = [tuple(atuple.index(val) for val in null_comb[i]) for i in range(len(null_comb))]
    return tuple(atuple[i] for i in min(indexes)) if indexes else ()
