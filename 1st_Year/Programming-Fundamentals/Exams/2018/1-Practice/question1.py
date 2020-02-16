P = 1000
t = 1
r = float(input("Enter the interest rate: "))
n = int(input("Enter the frequency of payments: "))

r2 = float(input("Enter another interest rate: "))
n2 = int(input("Enter another frequency of payments: "))

#Calculates final amounts
A1 = round(P * ((1 + (r / n))**(n * t)), 3)

A2 = round(P * ((1 + (r2 / n2))**(n2 * t)), 3)

print()
print("For r={0} and n={1} you'll have {2}".format(r, n, A1))
print()
print("For r={0} and n={1} you'll have {2}".format(r2, n2, A2))
