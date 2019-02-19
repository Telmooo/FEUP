'''
Check Armstrong number
'''
num = int(input("Enter a number(3 digits): "))
sum_cube = 0
copy = num

while copy != 0:
    sum_cube += ((copy % 10)**3)
    copy //= 10

print(sum_cube == num)
