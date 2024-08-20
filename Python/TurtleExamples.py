import turtle

# Set up the screen
screen = turtle.Screen()
screen.title("Turtle Circle Drawing")

# Create a turtle object
my_turtle = turtle.Turtle()
my_turtle.color("blue")
# Draw a circle with a radius of 100 units
my_turtle.circle(100)
my_turtle.begin_fill() 
my_turtle.circle(70)
 
my_turtle.end_fill() 

for index in range(0, 4):
    # Move the turtle forward by 100 units
    my_turtle.forward(100)

    # Turn the turtle left by 90 degrees
    my_turtle.left(90)
# Keep the window open until 

my_turtle.forward(100)

my_turtle.penup()

my_turtle.forward(100)

my_turtle.pendown()

my_turtle.forward(100)

my_turtle.penup()

my_turtle.forward(100)

my_turtle.pendown()

for i in range(0, 10):
    my_turtle.penup()

    my_turtle.forward(10)

    my_turtle.pendown()
    
    my_turtle.forward(10)

screen.exitonclick()