'''
The sum of the double
'''
d = int(input("Enter a number(1 digit): "))
num = int(input("Enter a number: "))
sum_num = 0
copy = num

while copy != 0:
    if copy % 10 > d:
        sum_num += ((copy % 10)*2)
    copy //= 10
    
print(sum_num)
