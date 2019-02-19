"""Temperature converter Fº->Cº"""

temp_f = float(input("Temperature in Farenheit: "))

temp_c = (temp_f - 32) / 1.8

"""Engine: Cools down 1Cº if the engine speed slows down 50rpm, 
   heats up 1Cº if it speeds up 150rpm
"""

temp_wanted = float(input("Desired temperature: "))

temp_atual = float(input("Current temperature: "))

if temp_atual - temp_wanted >= 0:
    rpm = 50 * (temp_atual - temp_wanted)
else:
    rpm = 150 * (temp_wanted - temp_atual)

"""Improved Engine"""

temp_wanted1 = float(input("Desired temperature: "))

temp_atual1 = float(input("Current temperature: "))

option = int(input("Enter a mode: "))

if temp_atual1 - temp_wanted1 >= 0:
    rpm1 = 50 * (temp_atual1 - temp_wanted1)
else:
    rpm1 = 150 * (temp_wanted1 - temp_atual1)
    
if option == 0: rpm1 = rpm1
elif option == 1: rpm1 *= 0.75
elif option == 2: rpm1 *= 0.40
elif option == 3: rpm1 *= 2

print(rpm1)

'''
Working with recursion
'''
n = input("Enter a number (5's will be substituted by 6's: ")
result = ""

for digits in n:
    if digits != "5":
        result += digits
    else:
        result += "6"

print(int(result))

num = int(input("Enter a number: "))

'''
Secret Code
'''
msg = ""
numcopy = num
inverse = 0
extra = ""
digits = 0

while True:
    inverse = inverse * 10 + (numcopy % 10)
    if inverse == 0 and numcopy % 10 == 0:
        extra += "/"

    numcopy //= 10
    if numcopy == 0:
        break

while True:
    msg += ("." * (inverse % 10)) + "/"
    inverse //= 10
    if inverse == 0:
        msg += extra
        break

print(msg)
