from turtle import Screen, Turtle
import time
import random

class Bricks:
    def __init__(self, screen):
        self.bricks = []
        self.y_location = 0
        self.size = 0
        self.screen = screen
        
    def CheckIfColide(self, x_location, y_location):
        for brick in self.bricks:
            for segment in brick:  # Iterate over each Turtle in the current brick
                if abs(round(segment.ycor()) - y_location) < 1:  # Check y-coordinate
                    # Check if x_location falls between the xcor of the first and last segment
                    if brick[-1].xcor() <= x_location <= brick[0].xcor():
                        print("Collision detected!")
                        return True
                    print("Turtle x:", x_location, "turtle y:", y_location)
                    print("Brick y:", brick[0].ycor(), "and brick x range is", brick[-1].xcor(), "to", brick[0].xcor())
        return False

                    
    def CreateBrick(self):
        amount_of_bricks_to_create = random.randint(1, 3)
        for index in range(amount_of_bricks_to_create):
            amount_of_segments = random.randint(1, 3)
            x_location = 260
            y_location = random.randint(-260, 260)
            expel_from_y_location = y_location % 20
            if(expel_from_y_location != 0):
                y_location -= expel_from_y_location
                
            segment_positions = []
            for segment in range(amount_of_segments):
                
                brick = Turtle("square")
                brick.color("black")
                brick.penup()
                brick.goto(x_location, y_location)
                x_location -= 20
                brick.pendown()
                brick.setheading(180)
                segment_positions.append(brick)
            self.bricks.append(segment_positions)
            
    def Move(self): 
        # List to keep track of bricks to remove
        bricks_to_remove = []
        
        for index in range(len(self.bricks)):
            for segment in self.bricks[index]:
                segment.penup()
                segment.forward(20)
                segment.pendown()

            # Check if the last segment of the brick is out of bounds (x-coordinate < -260)
            if self.bricks[index][-1].xcor() < -260:
                bricks_to_remove.append(index)  # Mark the brick for removal

        # Remove the bricks that are out of bounds
        for i in reversed(bricks_to_remove):  # Iterate in reverse to avoid index shifting issues
            for segment in self.bricks[i]:
                segment.hideturtle()  # Hide the turtle before removal
            del self.bricks[i]
            
        time.sleep(0.2)    
           
        
        
                
class TurtleDriveGame:
    def __init__(self, screen, bricks, move_turtle):
        self.CURRENT_LENGTH = 3
        self.GRID_SIZE = 20  # Size of the grid cells
        # Set up the screen
        self.screen = screen
        
        # Create a turtle object
        self.write_turtle = Turtle()
        self.write_turtle.hideturtle()  # Hide the turtle arrow for a clean look
        self.write_turtle.penup()       # Don't draw while moving

        # Print text on the screen
        self.write_turtle.goto(0, 0)  # Position the turtle at the center of the screen
        self.write_turtle.color("black")
        
        self.moving_turtle = move_turtle
        self.brick_arr = bricks
        
        self.screen.listen()
        self.screen.onkey(key = "w", fun = self.MoveForaward)
        self.screen.onkey(key = "s", fun = self.MoveBack)
    
    def MoveForaward(self):
        self.moving_turtle.penup()
        self.moving_turtle.forward(20)    
        self.moving_turtle.pendown() 
    
    def MoveBack(self):
        if(self.moving_turtle.ycor() > -260):
            self.moving_turtle.penup()
            self.moving_turtle.backward(20)    
            self.moving_turtle.pendown()
           
    def Run(self):
        self.screen.tracer(0)
        turtle_y = 0
        
        status = False
        while turtle_y < 280:
            bricks.CreateBrick()
            bricks.Move()
            turtle_y = round(self.moving_turtle.ycor())
            turtle_x = round(self.moving_turtle.xcor())
            status = bricks.CheckIfColide(turtle_x, turtle_y)
            if(status == True):
                break
            self.screen.update() 
            
            
        if status == False:    
            self.write_turtle.write("You win! Please press the screen to exit!", align="center", font=("Arial", 16, "bold")) 
        else:
            self.write_turtle.write("You lose! Please press the screen to exit!", align="center", font=("Arial", 16, "bold"))      
        self.screen.exitonclick()
              
class RunTurtle:
    def __init__(self):
        # Create a turtle object
        self.move_turtle = Turtle()
        self.move_turtle.shape("turtle")
        self.move_turtle.hideturtle()  # Hide the turtle arrow for a clean look
        self.move_turtle.penup()       # Don't draw while moving
        self.move_turtle.hideturtle()
        self.move_turtle.setheading(90)  # 90 degrees is "up" direction
        # Print text on the screen
        self.move_turtle.goto(0, -260)  # Position the turtle at the center of the screen
        self.move_turtle.showturtle()
        self.move_turtle.pendown()    
        self.move_turtle.color("black")
        
        
def GenereteScreen():
    screen = Screen()
    screen.title("Snake Game")
    screen.bgcolor("white")
    screen.setup(width = 600, height = 600)
    return screen

my_screen = GenereteScreen()    
bricks = Bricks(my_screen)
turtle = RunTurtle()
turtle_game = TurtleDriveGame(my_screen, bricks, turtle.move_turtle)
turtle_game.Run()
