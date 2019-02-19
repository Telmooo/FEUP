"""
Sort by lambda
"""
def sort_by_f(l):
    return sorted(l, key=lambda x: x if x<5 else 5-x)
