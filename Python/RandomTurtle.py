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
my_turtle.pensize(5)

while True:
    # Generate and set a random color for the turtle's pen
    random_pen_color = random_color()
    my_turtle.pencolor(random_pen_color)
    random_turn_around = random.randint(0, 360)
    my_turtle.left(random_turn_around)
    my_turtle.forward(50)



screen.exitonclick()