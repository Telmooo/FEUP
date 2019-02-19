'''
Find my Type
'''
def find_dtype(atuple, data_type):
    '''
    Filters all the elements of a tuple whose type isn't the one
    specified in data_type
    '''
    #compares the type of each object with the data_type given
    #if there's no match, that object isn't included in the final tuple
    return tuple(obj for obj in atuple if type(obj).__name__ == data_type)
