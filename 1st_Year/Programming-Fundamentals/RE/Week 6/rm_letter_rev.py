'''
String Iterator
'''
def rm_letter_rev(l, astr):
    '''
    Removes the character <l> from the string and returns the reversed string
    <Case Sensitive!>
    '''
    return astr.replace(l, "")[::-1]
