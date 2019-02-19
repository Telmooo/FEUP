'''
Is the Yin number equal to the Yang number?
(checks if a number is a palindrome)
'''
def capicua():
    '''
    Checks if an integer is a palindrome
    '''
    num = int(input("Enter a number: "))
    reverse_num = 0
    num_copy = num

    #algorithm to reverse the order of the digits of a number
    while num_copy > 0:
        #removes the last digit
        pivot = num_copy % 10

        #processes the reversion of the number digit by digit
        reverse_num = (reverse_num * 10) + pivot

        #condition for the end of the loop
        num_copy //= 10

    #check if the number is a palindrome or not
    if num == reverse_num:
        result = "{0} is a palindrome.".format(num)
    else:
        result = "{0} is not a palindrome.".format(num)
        
    return result

print(capicua())
