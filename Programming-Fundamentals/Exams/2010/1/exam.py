'''
Planes needed
'''
people = int(input("Enter the number of people that will travel: "))
capacity = int(input("Enter the plane capacity: "))

if people % capacity == 0:
    planes = people // capacity
else:
    planes = (people // capacity) + 1

'''
Pick a plane
'''
passengers = int(input("Enter the number of people that will travel: "))
plane_chosen = ""

if passengers < 150:
    plane_chosen = "A320"
elif passengers < 300:
    plane_chosen = "A330"
elif passengers < 500:
    plane_chosen = "A380"
else:
    plane_chosen = "None"
    
print(plane_chosen, end = "")

'''
Company fees
'''
passe = int(input("Enter the number of people that will travel: "))
capac = int(input("Enter the plane capacity: "))

if passe % capac == 0:
    plane = passe // capac
else:
    plane = (passe // capac) + 1

passe_fee = passe * 50
plane_fee = 0
if plane < 10:
    plane_fee = plane * 1000
else:
    plane_fee = 10 * 1000 + (plane - 10) * 500

total_fee = plane_fee + passe_fee

print(total_fee)

'''
Multiples of 3 in a number
'''
num = int(input("Please enter a number: "))
copy = num
mult = 0

while copy != 0:
    digit = copy % 10
    copy //= 10
    if digit in [3, 6, 9]:
        mult += 1

print(mult)

'''
Multiple of 3 creator
'''
nume = int(input("Please enter a number: "))
copy1 = nume
mults = 0
i = 0

while copy1 != 0:
    digit = copy1 % 10
    copy1 //= 10
    if digit in [3, 6, 9]:
        mults += (digit * (10**i))
        i +=1

print(mults)
