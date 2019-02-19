'''
Fizz and Buzz Lightyear
'''

def fizz_buzz():
    '''
    Plays the Fizz Buzz Game
    '''
    n = int(input("Enter a number for the Fizz Buzz Game: "))
    
    result = ""

    #game conditions
    for i in range(n+1):
        if i % 3 == 0 and i % 5 == 0:
            continue

        elif i % 3 == 0:
            result += "Fizz "

        elif i % 5 == 0:
            result += "Buzz "

        else:
            result += "{0} ".format(i)

    result = result[:-1]
    
    return result

print(fizz_buzz())
