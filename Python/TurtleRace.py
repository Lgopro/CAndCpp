import turtle
import random

# Set up the screen
screen = turtle.Screen()
screen.title("Turtle Circle Drawing")

# Create a turtle object
blue_turtle = turtle.Turtle()
red_turtle = turtle.Turtle()
yellow_turtle = turtle.Turtle()
green_turtle = turtle.Turtle()
purple_turtle = turtle.Turtle()
orange_turtle = turtle.Turtle()

screen.setup(width=600, height=600)

all_turtles = [blue_turtle, red_turtle, yellow_turtle, green_turtle, purple_turtle, orange_turtle]
all_colors = ["blue", "red", "yellow", "green", "purple", "orange"]
location = [180, 240, 300, 360, 420, 480]
x_location = -screen.window_width() // 2 + 10
y_location =  -screen.window_height() // 2
current_x_location = [x_location, x_location, x_location, x_location, x_location, x_location]

user_color_bet = screen.textinput(title = "Make your bet!", 
                                  prompt = "Which turtle will win the race? Enter one of the colors: blue, red, yellow, green, purple, orange." )

for index in range(0, 6):
    all_turtles[index].shape("turtle")
    all_turtles[index].color(all_colors[index])
    all_turtles[index].penup()
    all_turtles[index].goto(x_location, y_location + location[index])
    all_turtles[index].pendown()

def GetRandomMove():
    return random.randint(1, 20)

def GetRandomTurtle():
    return random.randint(0, 5)


while True:
    index = GetRandomTurtle()
    move_length = GetRandomMove()
    
    all_turtles[index].penup()
    all_turtles[index].forward(move_length)
    all_turtles[index].pendown()
    
    current_x_location[index] += move_length
    if(current_x_location[index] >= screen.window_width() // 2):
        if(all_colors[index] == user_color_bet):
            print("You Chose the right color! You Won!")
        else:
            print("The color you chose is: " + user_color_bet + ". The color that won is: " + all_colors[index] + ". You LOSE!")
        break

screen.exitonclick()