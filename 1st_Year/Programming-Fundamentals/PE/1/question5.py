'''
Octal Converter
'''
dec = int(input("Enter a number (in decimal): "))

octal = 0
binary = 0
copy = dec
current_digit = 0
i = 0
j = 0

while copy != 0:
    current_digit = copy % 10
    binary += ((copy % 2) * (10**i))
    i += 1
    copy //= 2

while binary != 0:
    for k in range(3):
        current_digit = binary % 10
        octal += ((current_digit * (2**k)) * (10**j))
        binary //= 10
    j += 1

print(octal)
