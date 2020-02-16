"""
Override operation
"""
def override(l1, l2):
    f =  {x[0] for x in l2}
    return sorted(l2 + list(filter(lambda x: x[0] not in f,l1)))
