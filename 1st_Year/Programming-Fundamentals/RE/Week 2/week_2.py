import datetime

#Variables and print (Ex1)

#Creating the variables for each word
word1 = "The"
word2 = "quick"
word3 = "brown"
word4 = "fox"
word5 = "jumps"
word6 = "over"
word7 = "the"
word8 = "lazy"
word9 = "dog"

print() #Giving a blank space (line break)
print(word1, word2, word3, word4, word5, word6, word7, word8, word9)

#Input and string operators (Ex2)

#HTML format: <tag>text</tag>

tag = input("Enter a tag for your HTML element: ")
text = input("Enter your text: ")

print()
print("<" + tag + ">" + text + "</" + tag + ">")

#Input and cast (Ex3)

n = int(input("Enter your value for n: "))

#For this case we'll use n=9

nn = int(str(n)+str(n))
nnn= int(str(nn)+str(n))

print()
print(n + nn + nnn)

#Formula for compound interest (Ex4)

#   P= principal amount(initial investment)
#   r= annual nominal interest rate(as a decimal)
#   n= number of times the interest is compounded per year
#   t= number of years
#   A= new principal amount(final result)

t = 2                                                                           #By default in this exercise, the interest is calculated for 2 years 

#For item 1, P = 1000; n = 2 and r = 1%

P1 = 1000
r1 = float("1%".strip("%")) / 100                                       
n1 = 2

#For item 2, P = 650; n = 1 and r = -0.05%

P2 = 650
r2 = float("-0.05%".strip("%")) / 100
n2 = 1

#For item 3, the values are introduced by the user. In this case will be using P = 5250.25; r = 10%; n = 12

P3 = float(input("Initial investment(€): "))
r3 = (float(input("Interest rate(percentage): ").strip("%"))) / 100
n3 = int(input("Times the interest is compounded per year: "))

A1 = P1 * ((1 + (r1/n1)) ** (n1*t))
A2 = P2 * ((1 + (r2/n2)) ** (n2*t))
A3 = P3 * ((1 + (r3/n3)) ** (n3*t))

A1 = round(A1, 2)
A2 = round(A2, 2)
A3 = round(A3, 2)

print()
print("1. The final amount after", t, "years is", str(A1) + "€.", "(P =", P1, "; n =", n1, ";r =", str(r1 * 100) + "%)")
print()
print("2. The final amount after", t, "years is", str(A2) + "€.", "(P =", P2, "; n =", n2, ";r =", str(r2 * 100) + "%)")
print()
print("3. The final amount after", t, "years is", str(A3) + "€.", "(P =", P3, "; n =", n3, ";r =", str(r3 * 100) + "%)")

#Clock + Alarm (set for 8h30min after the current time) (Ex5)

current_time = datetime.datetime.now()

#We want to set an alarm to 8h:30min after the current time

#Setting the alarm (Using only mathematics)

alarm_h = ((current_time.hour + 8) + ((current_time.minute + 30) // 60)) % 24                                
alarm_min = (current_time.minute + 30) % 60

#Another way to set the alarm (Combining previous method(mathematics) + conditional statements)

#alarm_minute = current_time.minute + 30
#alarm_hour = current_time.hour + 8
#
#if alarm_minute >= 60:
#    alarm_minute = alarm_minute % 60
#    alarm_hour = alarm_hour + 1
#
#if alarm_hour >= 24:
#    alarm_hour = alarm_hour % 24
#
#if alarm_minute < 10:
#    alarm_minute = "0" + str(alarm_minute)
#else:
#    alarm_minute = str(alarm_minute)
#
#if alarm_hour < 10:
#    alarm_hour = "0" + str(alarm_hour)
#else:
#    alarm_hour = str(alarm_hour)
#
#alarm1 = alarm_hour + ":" + alarm_minute

#Another way to set the alarm (using the class timedelta)

#alarm = current_time + datetime.timedelta(hours=8, minutes=30)

############################################################################################

print()
print("Time now:", current_time.strftime("%H:%M") + ".")

#Results given by using the mathematics only method

print()
print("Alarm was set to:", str(alarm_h).zfill(2) + ":" + str(alarm_min).zfill(2) + ".")
print()
print("Alarm was set to:", str("%02d" % alarm_h) + ":" + str("%02d" % alarm_min) + ".")

#Result give by using the mathematics + conditionals method

#print()
#print("The alarm was set to:", alarm1 + ".")

#Result given by the timedelta method

#print()
#print("Alarm was set to:", alarm.strftime("%H:%M") + ".")
