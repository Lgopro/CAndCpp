from turtle import Screen, Turtle
import time
import random
import math


class PingPong:
    def __init__(self):
        self.CURRENT_LENGTH = 5
        self.GRID_SIZE = 20  # Size of the grid cells
        # Set up the screen
        self.screen = Screen()
        self.screen.title("Ping Pong Game")
        self.screen.bgcolor("black")
        self.screen.setup(width = 800, height = 800)
        self.screen.tracer(0)
                # Create a turtle object
        self.write_turtle = Turtle()
        self.write_turtle.hideturtle()  # Hide the turtle arrow for a clean look
        self.write_turtle.penup()       # Don't draw while moving

        # Print text on the screen
        self.write_turtle.goto(0, 360)  # Position the turtle at the center of the screen
        self.write_turtle.color("white")
        self.InitBall()
        self.InitLeftSide()
        self.InitRightSide()
    
    def InitLeftSide(self):
        self.coordinates_left = [[-380, 40], [-380, 20], [-380, 0], [-380, -20], [-380, -40]]

        # Create a turtle object
        self.write_turtle_left = Turtle()
        self.write_turtle_left.hideturtle()  # Hide the turtle arrow for a clean look
        self.write_turtle_left.penup()       # Don't draw while moving

        # Print text on the screen
        self.write_turtle_left.goto(-150, 360)  # Position the turtle at the center of the screen
        self.write_turtle_left.color("white")
        self.score_left = 0
        self.write_turtle_left.write("Score is: " + str(self.score_left), align="center", font=("Arial", 16, "bold"))

        self.segments_left = [Turtle("square") , Turtle("square"), Turtle("square"), Turtle("square"), Turtle("square")]

        for index in range (0, self.CURRENT_LENGTH):
            self.segments_left[index].color("white")
            self.segments_left[index].penup()
            self.segments_left[index].goto(self.coordinates_left[index])
            self.segments_left[index].pendown()
            
    def InitRightSide(self):
        self.coordinates_right = [[380, 40], [380, 20], [380, 0], [380, -20], [380, -40]]

        # Create a turtle object
        self.write_turtle_right = Turtle()
        self.write_turtle_right.hideturtle()  
        self.write_turtle_right.penup()      

        # Print text on the screen
        self.write_turtle_right.goto(150, 360)
        self.write_turtle_right.color("white")
        self.score_right = 0
        self.write_turtle_right.write("Score is: " + str(self.score_right), align="center", font=("Arial", 16, "bold"))

        self.segments_right = [Turtle("square") , Turtle("square"), Turtle("square"), Turtle("square"), Turtle("square")]


        for index in range (0, self.CURRENT_LENGTH):
            self.segments_right[index].color("white")
            self.segments_right[index].penup()
            self.segments_right[index].goto(self.coordinates_right[index])
            self.segments_right[index].pendown()    
        
    def InitBall(self):
        self.ball = Turtle("circle")
        self.ball.color("green")
          
    def GoUpLeft(self):
        if self.coordinates_left[-1][1] < 360:  # Ensure the paddle doesn't go out of bounds
            for index in range(self.CURRENT_LENGTH - 1, 0, -1):
                self.coordinates_left[index][1] = self.coordinates_left[index - 1][1]  # Shift each segment to the position of the previous one
            self.coordinates_left[0][1] += self.GRID_SIZE  # Move the top segment up
            self.UpdatePaddle(self.segments_left, self.coordinates_left)

    def GoDownLeft(self):
        if self.coordinates_left[0][1] > -360:  # Ensure the paddle doesn't go out of bounds
            for index in range(self.CURRENT_LENGTH - 1):
                self.coordinates_left[index][1] = self.coordinates_left[index + 1][1]  # Shift each segment to the position of the next one
            self.coordinates_left[-1][1] -= self.GRID_SIZE  # Move the bottom segment down
            self.UpdatePaddle(self.segments_left, self.coordinates_left)

    def GoUpRight(self):
        if self.coordinates_right[-1][1] < 360:  # Ensure the paddle doesn't go out of bounds
            for index in range(self.CURRENT_LENGTH - 1, 0, -1):
                self.coordinates_right[index][1] = self.coordinates_right[index - 1][1]  # Shift each segment to the position of the previous one
            self.coordinates_right[0][1] += self.GRID_SIZE  # Move the top segment up
            self.UpdatePaddle(self.segments_right, self.coordinates_right)

    def GoDownRight(self):
        if self.coordinates_right[0][1] > -360:  # Ensure the paddle doesn't go out of bounds
            for index in range(self.CURRENT_LENGTH - 1):
                self.coordinates_right[index][1] = self.coordinates_right[index + 1][1]  # Shift each segment to the position of the next one
            self.coordinates_right[-1][1] -= self.GRID_SIZE  # Move the bottom segment down
            self.UpdatePaddle(self.segments_right, self.coordinates_right)
             
    def UpdatePaddle(self, segments, coordinates):
        for index in range(self.CURRENT_LENGTH):
            segments[index].penup()
            segments[index].goto(coordinates[index])
            segments[index].pendown()
        
    def GenerateRandomDirection(self):
        while True:
            self.random_direction = random.randint(0,360)
            if((self.random_direction > 0 and self.random_direction < 130) or (self.random_direction > 230 and self.random_direction < 360)):
                break
        return self.random_direction        
        
    def CheckCollision(self):
        x_coor = self.ball.xcor()
        y_coor = self.ball.ycor()
        
        last_segment_begin_left = self.segments_left[0]

        # Get the x and y coordinates of the last segment
        segment_y_begin_left = last_segment_begin_left.ycor()
        
        last_segment_end_left = self.segments_left[-1]

        # Get the x and y coordinates of the last segment
        segment_y_end_left = last_segment_end_left.ycor()
        
        
        last_segment_begin_right = self.segments_right[0]

        # Get the x and y coordinates of the last segment
        segment_y_begin_right = last_segment_begin_right.ycor()
        
        last_segment_end_right = self.segments_right[-1]

        # Get the x and y coordinates of the last segment
        segment_y_end_right = last_segment_end_right.ycor()
        
        if((round(y_coor) >= 380 and x_coor < 380 and x_coor > -380) or (round(y_coor) <= -380 and x_coor < 380 and x_coor > -380)):
            self.GetNewDirection()
        elif(round(x_coor) <= 380 and round(x_coor) >= 360):
            if(round(segment_y_begin_right) >= round(y_coor) and round(segment_y_end_right) <= round(y_coor)):
                self.GetNewDirection()
                return
                
        elif(round(x_coor) >= -380 and round(x_coor) <= -360):
            if(round(segment_y_begin_left) >= round(y_coor) and round(segment_y_end_left) <= round(y_coor)):
                self.GetNewDirection()
                return
        else:
            if(round(x_coor) <= -380):
                self.score_right += 1
            if(round(x_coor) >= 380):
                self.score_left += 1
                
    def GetNewDirection(self):
        self.random_direction = (360 - self.random_direction) % 360
        self.ball.setheading(self.random_direction) 
               
    def Run(self):
            
        self.screen.listen()
        self.screen.onkey(key = "w", fun = self.GoUpLeft)
        self.screen.onkey(key = "s", fun = self.GoDownLeft)
        self.screen.onkey(key = "o", fun = self.GoUpRight)
        self.screen.onkey(key = "l", fun = self.GoDownRight)
        self.ball.setheading(self.GenerateRandomDirection())
        while True:
            self.screen.update()
            self.ball.penup()
            self.ball.forward(self.GRID_SIZE)
            self.ball.pendown()
            self.CheckCollision()
            if(self.score_left == 1 or self.score_right == 1):
                break   
            time.sleep(0.05)
            
        if(self.score_left == 1):
            self.write_turtle.write("Left Side win!", align="center", font=("Arial", 16, "bold"))
            
        if(self.score_right == 1):
            self.write_turtle.write("Right Side win!", align="center", font=("Arial", 16, "bold"))
        self.screen.exitonclick()
            
            
game = PingPong()
game.Run()