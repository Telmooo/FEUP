def checkValues(components):
    '''
    Checks if the components has any invalid values
    '''
    for i in components: 
        if i > 100 or i < 0:
            return False
        return True

LE = int(input("Enter the grade for LE: "))
RE = int(input("Enter the grade for RE: "))
PE = int(input("Enter the grade for PE: "))
TE = int(input("Enter the grade for TE: "))

components = [LE, RE, PE, TE]

if checkValues(components):
    #Checks if the student did not pass
    if PE < 40 or TE < 40:
        print("RFC")
    #Calculates the grade if the student did pass
    else:    
        grade = (LE + RE + 4*PE + 4*TE)/50
        print("{0}".format(int(grade)))
else:
    print("Input Error")
