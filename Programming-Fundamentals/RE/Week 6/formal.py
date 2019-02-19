'''
First-last name conventions
'''
def formal(name):
    '''
    Formats a name to the form "{last name}, {I. N. I. T. I. A. L. S.}
    '''
    #splits the names in the full name
    names = name.split()
    #formats the name to the formal format
    #first gets the last name(located at the end of the list)
    #then iterates over the rest of the list(excluding the last name)
    #and gets the first character, joining them according to the form
    return "{0}, {1}.".format(names[-1], ". ".join(aname[0] for aname in names[:-1]))
