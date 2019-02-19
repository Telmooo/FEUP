'''
Students Grades
'''
def average_score(record):
    '''
    Computes the average_score
    '''
    return sum(record[2]) / len(record[2])

def priority(record):
    '''
    Defines the priority for names and id's
    '''
    return (record[0], record[1])

def sort_grades(records):
    '''
    Sorts the records according according to the following priority criteria
    1. Sort based on the average grade (descending order);
    2. Then sort based on student name (ascending order);
    3. Then sort based on student number (ascending order);
    '''
    #sorts the records 3 times
    #1st sorts them by ids (ascending order)
    #2nd sorts them by names (ascending order)
    #3rd sorts them by average grade and reverses the list (descending order)
    #finally converts the records to a tuple as sorted function gives a list
    return tuple(sorted(sorted(records, key = priority), key = average_score, reverse = True))
