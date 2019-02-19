'''
Count Subset
'''
def is_specialchar(char):
    '''
    check if a character is a special character 
    (spaces are not considered special characters in this case)
    '''
    return char.isalnum() if char != " " else True

def count(word, phrase):
    '''
    Returns the occurence of the exact word on the phrase
    '''
    #fixed special characters joint with words

    #filters every special character (except spaces) in a phrase
    filtered = "".join(filter(is_specialchar, phrase))
    #converts both word and phrase to lowercase(not case sensitive)
    #splits the phrase and counts the occurence of the exact word    
    return filtered.lower().split().count(word.lower())
