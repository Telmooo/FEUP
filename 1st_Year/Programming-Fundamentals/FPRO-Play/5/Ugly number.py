def ugly(n):
    x = n
    if x > 0:
        x = divide(n, 2)
        x = divide(x, 3)
        x = divide(x, 5)
    return x == 1    
 

def divide(x, y):
    while x%y==0:
        x /= y
    return x
