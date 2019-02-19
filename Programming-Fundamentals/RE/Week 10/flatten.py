"""
Flatten
"""
def flatten(alist):
    new_list = []
    for obj in alist:
        if isinstance(obj, list):
            new_list += flatten(obj)
        else:
            new_list += [obj]
    return new_list
