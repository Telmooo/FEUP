from math import pi
from math import sin

'''
Conversion Degree-Rad
'''
degree = float(input("Enter the temperature in ºC: "))
rad = (degree * pi) / 180

'''
Distance projectil
'''
g = 9.8
v0 = float(input("Initial velocity: "))
angle = float(input("Angle of elevation: "))
angle_rad = (angle * pi) / 180

distance = ((v0 ** 2) * sin(2 * angle_rad)) / g

'''
Compass
'''
azimute = int(input("Azimute: "))
cardeal_point = ""

if azimute > 315:
    azimute -= 360
elif azimute < -45:
    azimute += 360
    
if -45 < azimute <= 45:
    cardeal_point = "N"
elif 45 < azimute <= 135:
    cardeal_point = "E"
elif 135 < azimute <= 225:
    cardeal_point = "S"
elif 225 < azimute <= 315:
    cardeal_point = "O"
    
'''
Projectil hit
'''

g = 9.8
v0 = float(input("Initial velocity: "))
angle = float(input("Angle of elevation: "))
angle_rad = (angle * pi) / 180

distance = ((v0 ** 2) * sin(2 * angle_rad)) / g
text = ""

if distance <= 100:
    text = "Hit"
elif distance <= 500:
    text = "Damaged"
elif distance <= 1000:
    text = "Close"
else:
    text = "Far" 

'''
Secret Code
'''
num = int(input("Enter a number to codify: "))
copy = num
code = 0
    
'''Code generator'''
while copy != 0:
    if copy <= 10:
        break
    code += ((copy % 10) * ((copy // 10) % 10))
    copy //= 100
    
print(int(code))
