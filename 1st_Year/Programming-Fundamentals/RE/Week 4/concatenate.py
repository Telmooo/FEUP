'''
Creates a bound of love between two numbers
(aka joins them together if you want the boring definition)
'''
def concatenate():
    '''
    Joins two integers into a single number
    '''
    n1 = int(input("Enter the first number: "))
    n2 = int(input("Enter the second number: "))
    n2_len = 0
    #makes copies of the numbers so that the original number can be used later
    n2_copy = n2

    #digit counters
    #this guarantees that the loop is run atleast 1 time for every
    #non negative number, including 0
    while n2_copy >= 0:
        n2_len += 1
        n2_copy //= 10
        #exits loop if number is 0
        if n2_copy == 0:
            break

    n2_copy = n2
    result = 0

    #assembles two integers into a single integer
    for i in range(n2_len):
        while n2_copy % 10 != 0:
            result += (10**i)
            n2_copy -= 1

        n2_copy //= 10
    
    result = (n1 * (10 ** n2_len)) + result

    return result

print(concatenate())
