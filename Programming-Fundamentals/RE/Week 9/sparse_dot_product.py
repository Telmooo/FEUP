"""
Sparse dot product
"""
def sparse_dot_product(dict1, dict2):
    return sum(dict1[key]*dict2.get(key, 0) for key in dict1.keys())
