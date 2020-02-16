#Assignment #3: Program flow with turtles

import turtle
#Regular Polygons (Ex1)

num_sides = int(input("How many sides does the polygon you want to draw have: "))       

lenght = float(input("What is the lenght of the side of your polygon: "))               

color = input("What color for the border of the polygon: ")                             
fill_color = input("What color for the inside of the polygon: ")                       

wd = turtle.Screen()
      
little_slave = turtle.Turtle()      

little_slave.color(color)           

little_slave.fillcolor(fill_color)  
angle = 360 / num_sides             

little_slave.begin_fill()           

#Draws a polygon with the specifications the user chooses

for _ in range(num_sides):
    little_slave.fd(lenght)         
    little_slave.left(angle)       

little_slave.end_fill()             
little_slave.up()                   
little_slave.hideturtle()           

print()                                         
print("Little Slave is done with her job!")     

wd.exitonclick()                   
    
#Polygons with turtles (Ex2)

little_slave = turtle.Turtle()      

wd = turtle.Screen()                
  
little_slave.hideturtle()      

#Draws 4 polygons: 1 square, 1 triangle, 1 hexagon and 1 octagon, all in different places    

for num_sides in [4, 3, 6, 8]:
    
    angle = 360 / num_sides
    little_slave.up()
    x = (((-1) ** (num_sides + (num_sides % 2) + (num_sides // 8))) * 
        (100 + (((1 + (num_sides % 2) + (num_sides // 8)) % 2)*300)))
    
    y = ((-1)**(num_sides // 5)) * (200 + (((num_sides // 5)*100)))
    
    little_slave.goto(x, y)
    little_slave.down()
    
    for _ in range(num_sides):
        little_slave.fd(200)
        little_slave.lt(angle)

print()
print("Little Slave is done with her job!")

wd.exitonclick()

#For and range (Ex3)

#Prints that all the turtles with even number are super cool! :)

for n in range(20, 251):
    if n % 2 == 0:              
        print("Python turtle number <{}> is cool!".format(n))

#Turtle clock (Ex4)

wd = turtle.Screen()                    

wd.bgcolor("light green")              

little_slave = turtle.Turtle()
little_slave.color("blue")              
little_slave.shape("turtle")            
little_slave.pensize("3")               
little_slave.hideturtle()               
little_slave.stamp()                    

#Draws a turtle clock

for _ in range (12):                    
    little_slave.up()                    
    little_slave.goto(0, 0)             
    little_slave.fd(200)           
    little_slave.down()        
    little_slave.fd(10)
    little_slave.up()
    little_slave.fd(25)
    little_slave.stamp()
    little_slave.left(30)               
    
little_slave.goto(0,0)

print()                                             
print("Little Slave is done with her job!")         

wd.exitonclick()                        

#Stars (Ex5)

n = int(input('How many sides does our little "star" have: '))     

wd = turtle.Screen()

wd.bgcolor("blue")                     

little_slave = turtle.Turtle()          
little_slave.color("white")           
little_slave.shape("circle")            
little_slave.pensize("3")               
little_slave.stamp()                 
little_slave.hideturtle()         

#Draws a little "star"

for _ in range (n):                   
    little_slave.up()                   
    little_slave.goto(0, 0)           
    little_slave.down()                 
    little_slave.fd(200)               
    little_slave.stamp()
    little_slave.left(360/n)          
    
little_slave.goto(0,0)

print()                                            
print("Little Slave is done with her job!")

wd.exitonclick()                        
    
