'''
Ages
'''
names = ["name", "anothername", "othername"]
ages = [17, 23, 35]
control = 0
result = ""

for name in names:
    index = 0
    for age in ages:
        if index == control:
            result += name + "-" + str(age) + " "
            break
        index += 1
    control += 1
    
print(result[:-1])
