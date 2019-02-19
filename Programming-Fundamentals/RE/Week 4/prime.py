'''
Prime number checker
'''

def is_prime():
    '''
    Function is_prime checks if the number n is prime or not.
    Returns True if n is prime, False if n isn't.
    '''
    num = int(input("Enter a number: "))
    #Special case of number 2
    if num == 2:
        result = True
    #If it's not 2, then any other number different to 2 aren't prime
    #i.e: 0 and 1
    #unless they are greater than 2, then this would be tested in the loop
    else:
        result = False
    #Checks if any number greater than 2 is prime
    for i in range(2, num):
        if num % i == 0:
            result = False
            break
        else:
            result = True
        
    return result

print(is_prime())
