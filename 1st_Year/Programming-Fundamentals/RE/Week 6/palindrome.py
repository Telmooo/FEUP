'''
Number of palindromes in a word
'''
def palindrome(astring):
    '''
    Any consecutive substring that it's equal to its reverse is a palindrome
    Only consideres consecutive substrings(no jumping characters)
    Any substring with 1 character is not considered a palindrome
    '''
    counter = 0
    #condition to be enter the process of finding palindromes
    if len(astring) > 1:
        #loop where the character on string and its index varies linearly
        #last character isn't considered to the process as it's impossible
        #to form a substring with atleast 2 characters with the last as pivot
        for char, index in zip(astring[:-1], range(len(astring))):
            substr = char
            #checks every substring for the pivot character by adding
            #consecutive characters that are after the pivot character
            for char_i in astring[index + 1:]:
                substr += char_i
                #adds 1 if substring is equal to its reverse else 0
                counter += substr == substr [::-1]
    return "For string '{0}': {1} palindrome substrings".format(astring, counter)
