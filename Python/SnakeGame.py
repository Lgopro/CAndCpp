from turtle import Screen, Turtle
import time
import random

CURRENT_LENGTH = 3
GRID_SIZE = 20  # Size of the grid cells
# Set up the screen
screen = Screen()
screen.title("Snake Game")
screen.bgcolor("black")
screen.setup(width = 800, height = 800)
coordinates = [[20, 0], [0, 0], [-20, 0]]

# Create a turtle object
write_turtle = Turtle()
write_turtle.hideturtle()  # Hide the turtle arrow for a clean look
write_turtle.penup()       # Don't draw while moving

# Print text on the screen
write_turtle.goto(0, 360)  # Position the turtle at the center of the screen
write_turtle.color("white")
score = 0
write_turtle.write("Score is: " + str(score), align="center", font=("Arial", 16, "bold"))

random_turtle = Turtle("circle")
random_turtle.color("green")
random_x = random.randint(-360 // GRID_SIZE, 360 // GRID_SIZE) * GRID_SIZE
random_y = random.randint(-360 // GRID_SIZE, 360 // GRID_SIZE) * GRID_SIZE

segment1 = Turtle("square")
segment2 = Turtle("square")
segment3 = Turtle("square")

segments = [segment1 , segment2, segment3]


direction = "Right"


for index in range (0, CURRENT_LENGTH):
    segments[index].color("white")
    segments[index].penup()
    segments[index].goto(coordinates[index])
    segments[index].pendown()
      
def RotateLeft():
    global direction
    if direction == "Left":
        segments[0].setheading(270)
        direction = "Down"
        return
    if direction == "Right":
        segments[0].setheading(90)
        direction = "Up"
        return
    if direction == "Up":
        segments[0].setheading(180)
        direction = "Left"
        return
    if direction == "Down":
        segments[0].setheading(0)
        direction = "Right"
        return
        
        
def RotateRight():
    global direction
    if direction == "Left":
        segments[0].setheading(90)
        direction = "Up"
        return
    if direction == "Right":
        segments[0].setheading(270)
        direction = "Down"
        return
    if direction == "Up":
        segments[0].setheading(0)
        direction = "Right"
        return
    if direction == "Down":
        segments[0].setheading(180)
        direction = "Left"
        return
        
screen.tracer(0)

screen.listen()
screen.onkey(key = "a", fun = RotateLeft)
screen.onkey(key = "d", fun = RotateRight)
colision_flag = False


while True:
    screen.update()
    
    # Update the head direction and position based on user input
    segments[0].penup()
    segments[0].forward(20)    
    segments[0].pendown()
    
    for index in range (CURRENT_LENGTH - 1, 0, -1):
        coordinates[index] = coordinates[index - 1]
        
    for index in range (1, CURRENT_LENGTH):
        segments[index].penup()
        segments[index].goto(coordinates[index])
        segments[index].pendown()
        
    coor_to_inc = coordinates[CURRENT_LENGTH - 1]
    
    coordinates[0] = segments[0].pos()
    
    for index in range (1, len(segments)):
        if round(coordinates[0][0]) == round(coordinates[index][0]) and round(coordinates[0][1]) == round(coordinates[index][1]):
            write_turtle.goto(0, 0)  
            write_turtle.write("You lose! Score is: " + str(score), align="center", font=("Arial", 16, "bold"))
            colision_flag = True
    
    if colision_flag == True:
        break
        
    if(coordinates[0][0] > screen.window_width() // 2 or coordinates[0][0] < -screen.window_width() // 2 or coordinates[0][1] > screen.window_height() // 2 or coordinates[0][1] < -screen.window_height() // 2):
        write_turtle.goto(0, 0)  
        write_turtle.write("You lose! Score is: " + str(score), align="center", font=("Arial", 16, "bold"))
        break
    
    if round(coordinates[0][0]) == random_x and round(coordinates[0][1]) == random_y:
        segments.append(Turtle("square"))
        coordinates.append(coor_to_inc)
        CURRENT_LENGTH += 1
        segments[CURRENT_LENGTH - 1].color("white")
        segments[CURRENT_LENGTH - 1].penup()
        segments[CURRENT_LENGTH - 1].goto(coordinates[CURRENT_LENGTH - 1])
        segments[CURRENT_LENGTH - 1].pendown()
        random_x = random.randint(-360 // GRID_SIZE, 360 // GRID_SIZE) * GRID_SIZE
        random_y = random.randint(-360 // GRID_SIZE, 360 // GRID_SIZE) * GRID_SIZE
        score += 10
        write_turtle.clear()
        write_turtle.write("Score is: " + str(score), align="center", font=("Arial", 16, "bold"))
        
    random_turtle.penup()
    random_turtle.goto((random_x, random_y))
    random_turtle.pendown()
    
    time.sleep(0.1)
    
screen.exitonclick()