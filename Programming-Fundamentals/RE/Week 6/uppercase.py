'''
Convert to uppercase
'''
def uppercase(astring):
    '''
    If any of the first 3 characters on the string is in uppercase
    then the string is converted to uppercase
    '''
    #using the "any" function to return a bool based on the occurence of any
    #character in uppercase on the first 3 characters on the string
    #where the bool will serve as a index to get a value on the list
    return [astring, astring.upper()][any(char.isupper() for char in astring[:3])]
