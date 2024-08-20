import turtle
import random

# Function to generate a random color
def random_color():
    r = random.random()  # Random value for red (0.0 to 1.0)
    g = random.random()  # Random value for green (0.0 to 1.0)
    b = random.random()  # Random value for blue (0.0 to 1.0)
    return (r, g, b)


# Set up the screen
screen = turtle.Screen()
screen.title("Turtle Circle Drawing")

# Create a turtle object
my_turtle = turtle.Turtle()
my_turtle.pensize(1)

# Change the background color of the screen
screen.bgcolor("lightblue")  # You can use any color name or RGB tuple
my_turtle.hideturtle() # Hide courser
my_turtle.speed(0)

my_turtle.penup()
my_turtle.goto(-screen.window_width() // 2, -screen.window_height() // 2)
my_turtle.pendown()

move_y = 0
x_location = -screen.window_width() // 2
y_location =  -screen.window_height() // 2
    
for rows in range(0, 10):
    
    for location in range (0, 600 , 60):
        my_turtle.dot(20, random_color())
        my_turtle.penup()
        my_turtle.goto(x_location + location, y_location + move_y)
        my_turtle.pendown()
        
    move_y += 60

my_turtle.dot(20, random_color())
screen.exitonclick()