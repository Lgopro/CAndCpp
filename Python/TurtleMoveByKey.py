import turtle





# Set up the screen
screen = turtle.Screen()
screen.title("Turtle Circle Drawing")

# Create a turtle object
my_turtle = turtle.Turtle()
my_turtle.pensize(1)
my_turtle.speed(1)
screen.setup(width=800, height=600)


def MoveForaward():
    my_turtle.forward(20)
    

def RotateLeft():
    my_turtle.left(10)

    
def RotateRight():
    my_turtle.right(10)
    
def MoveBackward():
    my_turtle.backward(20)

screen.listen()
screen.onkey(key = "w", fun = MoveForaward)
screen.onkey(key = "s", fun = MoveBackward)
screen.onkey(key = "a", fun = RotateLeft)
screen.onkey(key = "d", fun = RotateRight)


screen.exitonclick()