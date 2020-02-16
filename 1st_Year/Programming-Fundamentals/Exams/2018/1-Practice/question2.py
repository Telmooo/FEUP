num = int(input("Enter a whole number: "))

sum_divisors = 0

#sum of all the divisors of a number, including himself
for i in range(1, num+1):
    if num % i == 0:
        sum_divisors += i

print(sum_divisors)
