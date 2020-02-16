'''
Translation table
'''
def translate(astring, table):
    '''
    Switchs the characters on the string according to the translation table
    given
    '''
    #converts the table into a dictionary
    transl = dict(table)
    #translation process: if the character is in the dictionary, gets switched
    #else the character isn't switched
    return "".join(str(transl[char]) if char in transl else char for char in astring)
