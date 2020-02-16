num = float(input("Enter a positive number: "))

if num < 0:
    print("This number doesn't have a real square root")

else:    
    #root of 0 == 0, special case
    if num == 0:
        root = 0
    #get an approximation of any other square root
    else:
        approximation = num/2
        root = (approximation + (num/approximation)) / 2.0
        
        while (int(root*100)) != (int(approximation*100)):
            approximation = root
            root = (root + (num/root)) / 2.0

        print()
        print("root: {0:.3f}".format(root))
