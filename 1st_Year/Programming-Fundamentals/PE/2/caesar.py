from math import sqrt

def caesar(message):
    import string
    alp = string.ascii_uppercase
    msg = message.split(" ")
    encoded = []
    i = 0
    for word in msg:
        wordx = ""
        for c in word:
            if c in alp: 
                j = alp.index(c)
                wordx += alp[(j-fibonacci(i))%26]
            else:
                wordx += c
            i+=1
        encoded.append(wordx)
        i+=1
    return " ".join(encoded)
    
def fibonacci(n):
    if n == 0: return 0
    if n == 1: return 1
    x = (1+sqrt(5))**n
    w = (1-sqrt(5))**n
    y = 2**n
    
    return int(((x-w)/(y*sqrt(5))))
