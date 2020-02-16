'''
Thriathlon
'''
tS = float(input("How many hours took the swimming: "))
tC = float(input("How many hours took the cycling: "))
tR = float(input("How many hours took the run: "))

total_time = tS + tC + tR

if total_time >= 4:
    print("Time")
elif (1.5 / tS) < 2:
    print("Swimming")
elif (40 / tC) < 20:
    print("Cycling")
elif (10 / tR) < 8:
    print("Running")
else:
    print(total_time)
