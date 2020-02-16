"""
Raising your own exceptions
"""
def raise_exception(alist, value):
    return [ValueError(f"{i} is not greater than {value}") for i in alist if i<=value]
