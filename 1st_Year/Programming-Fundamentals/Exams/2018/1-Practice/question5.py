lower = int(input("Enter the start number (integer): "))
upper = int(input("Enter the end number (integer): "))
primes = ""

#Checks for the primes between the numbers x and y, including x and y
for i in range(lower, upper+1):
    divisors = 0
    is_prime = True
    
    if i <= 1:
        is_prime = False
    
    for j in range(2, int((i**(1/2)))+1):
        if i % j == 0:
            is_prime = False
            break
    if is_prime:
        primes += "{0} ".format(i)
                
print()
print("Prime numbers between {0} and {1} are: {2}".format(lower, upper, primes[:-1]))
