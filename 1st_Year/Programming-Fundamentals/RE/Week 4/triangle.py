'''
Bob the Triangle Builder
'''

def triangle_form():
    '''
    Checks if it's possible to build a triangle, and which type of triangle it
    exists.
    '''
    side1 = int(input("Choose the lenght for the first side of the triangle: "))
    side2 = int(input("Choose the lenght for the first side of the triangle: "))
    side3 = int(input("Choose the lenght for the first side of the triangle: "))

    #conditions to build a triangle
    if side1+side2 > side3 and side1+side3 > side2 and side2+side3 > side1:
        #condition for an equilateral triangle
        if side1 == side2 and side1 == side3:
            result = "Equilateral"
        #condition for a scalene triangle
        elif side1 != side2 and side1 != side3 and side2 != side3:
            result = "Scalene"
        #if it isn't a scalene nor an equilateral it's an isosceles
        else:
            result = "Isosceles"

    else:
        result = "Not a triangle"
        
    return result

print(triangle_form())
