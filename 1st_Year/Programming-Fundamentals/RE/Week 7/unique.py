'''
Unique
'''
def unique(atuple):
    '''
    Deletes the duplicated integers, making the integers on the tuple unique
    and orders them in ascending order
    '''
    #creates a set (unordered collection of unique elements)
    #sorts them and converts the result to a tuple (sorted gives a list)
    return tuple(sorted(set(atuple)))
