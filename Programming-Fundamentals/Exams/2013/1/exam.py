'''
Points->Euros conversion
'''
points = int(input("How many points do you have: "))
euros = (points * 2.8) / 10

'''
How much money is left to pay for the ticket
'''
points_available = int(input("Enter your points: "))
ticket_price = float(input("How much is the ticket: "))
money_left_topay = 0
money_availabe = (points_available * 2.8) / 10

if money_availabe - ticket_price >= 0:
    money_left_topay = round(ticket_price - money_availabe, 1)

'''
Discounts by age
'''
discount = 0
age = int(input("Enter your age: "))

if age <= 7:
    discount = 50
elif 7 < age <= 18:
    discount = 40
elif 18 < age <= 23:
    discount = 25
elif 23 < age <= 64:
    discount = 0
else:
    discount = 35

'''
Loyalty bonuses
'''
client_points = int(input("Enter your points: "))
numtrips = int(input("Number of trips with this company: "))
augmented_points = client_points

for _ in range(numtrips):
    augmented_points += (augmented_points * 0.10)

'''
Unique identification
'''
id_ = int(input("Your ID: "))
digits = 0
idcopy = id_
unique_id = 0

'''Digit counter'''
while idcopy // 10 >= 0:
    digits += 1
    idcopy //= 10
    if idcopy == 0:
        break

print(digits)
idcopy = id_

'''Unique Id Creator'''
for i in range(digits):
    if id_ <= 10:
        break
    unique_id += ((idcopy % 10) * (idcopy // (10**(digits-1-(2*i)))))
    idcopy //= 10
    idcopy %= (10**(digits-2-(2*i)))
    
print(unique_id)
