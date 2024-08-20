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
my_turtle.speed(0)

for angle in range(0, 360, 10):
    my_turtle.pencolor(random_color())  
    my_turtle.setheading(angle)
    my_turtle.circle(250)



screen.exitonclick()