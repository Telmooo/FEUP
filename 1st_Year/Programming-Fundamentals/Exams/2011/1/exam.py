'''
Calculate IMC
'''
m = float(input("Enter your mass (in kg): "))
height = float(input("Enter your height: "))

imc = m / (height ** 2)

'''
Classification based on IMC
'''
mass = float(input("Enter your weight (in kg): "))
height1 = float(input("Enter your height: "))

imc = mass / (height1 ** 2)
state = ""

if imc < 18.5:
    state = "Thiness"
if 18.5 <= imc < 25:
    state = "Healthy"
if 25 <= imc < 30:
    state = "Excessive weight"
if imc >= 30:
    state = "Obesity"
    
'''
Heat or Meat
'''
calories = int(input("Enter the number of calories you gained or you lost" 
                     + "(+ for lost, - for gained): "))
procedure = ""

if calories < 0:
    if calories % 450 == 0:
        hour = calories / 450
    else:
        hour = int((-calories / 450) + 1)
    procedure = "cycling: " + str(hour)
elif calories > 0:
    pizza = calories // 432
    juice = (calories - (432*pizza)) * 2
    procedure = "eat: " + str(pizza) + "+" + str(juice)
else:
    procedure = "continue"

'''
Sum 2 by 2 digits
'''
num = int(input("Enter a number: "))
copy = num
sum_ = 0

while copy != 0:
    sum_ += (copy % 10)
    copy //= 100
