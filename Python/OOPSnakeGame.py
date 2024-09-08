from turtle import Screen, Turtle
import time
import random



class SnakeGame:
    def __init__(self):
        self.CURRENT_LENGTH = 3
        self.GRID_SIZE = 20  # Size of the grid cells
        # Set up the screen
        self.screen = Screen()
        self.screen.title("Snake Game")
        self.screen.bgcolor("black")
        self.screen.setup(width = 800, height = 800)
        self.coordinates = [[20, 0], [0, 0], [-20, 0]]

        # Create a turtle object
        self.write_turtle = Turtle()
        self.write_turtle.hideturtle()  # Hide the turtle arrow for a clean look
        self.write_turtle.penup()       # Don't draw while moving

        # Print text on the screen
        self.write_turtle.goto(0, 360)  # Position the turtle at the center of the screen
        self.write_turtle.color("white")
        self.score = 0
        with open('SnakeGameHigestScore.txt', 'r') as file:
            # Read the entire content of the file
            file.seek(0)
            content = file.read()
            self.sentence = ''
            index = 0
            
            while(content[index] != '\n'):
                self.sentence += content[index]
                index += 1

        self.write_turtle.write("Score is: " + str(self.score) + ". " + self.sentence + ".", align="center", font=("Arial", 16, "bold"))

        self.random_turtle = Turtle("circle")
        self.random_turtle.color("green")
        self.random_x = random.randint(-360 // self.GRID_SIZE, 360 // self.GRID_SIZE) * self.GRID_SIZE
        self.random_y = random.randint(-360 // self.GRID_SIZE, 360 // self.GRID_SIZE) * self.GRID_SIZE

        segment1 = Turtle("square")
        segment2 = Turtle("square")
        segment3 = Turtle("square")

        self.segments = [segment1 , segment2, segment3]


        for index in range (0, self.CURRENT_LENGTH):
            self.segments[index].color("white")
            self.segments[index].penup()
            self.segments[index].goto(self.coordinates[index])
            self.segments[index].pendown()
    
    
    def RotateLeft(self):
        self.segments[0].left(90)
        
        
    def RotateRight(self):
        self.segments[0].right(90)
        
    def Run(self):
        self.screen.tracer(0)

        self.screen.listen()
        self.screen.onkey(key = "a", fun = self.RotateLeft)
        self.screen.onkey(key = "d", fun = self.RotateRight)
        colision_flag = False


        while True:
            self.screen.update()
            
            # Update the head direction and position based on user input
            self.segments[0].penup()
            self.segments[0].forward(20)    
            self.segments[0].pendown()
            
            for index in range (self.CURRENT_LENGTH - 1, 0, -1):
                self.coordinates[index] = self.coordinates[index - 1]
                
            for index in range (1, self.CURRENT_LENGTH):
                self.segments[index].penup()
                self.segments[index].goto(self.coordinates[index])
                self.segments[index].pendown()
                
            coor_to_inc = self.coordinates[self.CURRENT_LENGTH - 1]
            
            self.coordinates[0] = self.segments[0].pos()
            
            for index in range (1, len(self.segments)):
                if round(self.coordinates[0][0]) == round(self.coordinates[index][0]) and round(self.coordinates[0][1]) == round(self.coordinates[index][1]):
                    self.write_turtle.goto(0, 0)  
                    self.write_turtle.write("You lose! Score is: " + str(self.score), align="center", font=("Arial", 16, "bold"))
                    colision_flag = True

            if colision_flag == True:
                break
                
            if(self.coordinates[0][0] > self.screen.window_width() // 2 or self.coordinates[0][0] < -self.screen.window_width() // 2 or self.coordinates[0][1] > self.screen.window_height() // 2 or self.coordinates[0][1] < -self.screen.window_height() // 2):
                self.write_turtle.goto(0, 0)  
                self.write_turtle.write("You lose! Score is: " + str(self.score), align="center", font=("Arial", 16, "bold"))
                break
            
            if round(self.coordinates[0][0]) == self.random_x and round(self.coordinates[0][1]) == self.random_y:
                self.segments.append(Turtle("square"))
                self.coordinates.append(coor_to_inc)
                self.CURRENT_LENGTH += 1
                self.segments[self.CURRENT_LENGTH - 1].color("white")
                self.segments[self.CURRENT_LENGTH - 1].penup()
                self.segments[self.CURRENT_LENGTH - 1].goto(self.coordinates[self.CURRENT_LENGTH - 1])
                self.segments[self.CURRENT_LENGTH - 1].pendown()
                self.random_x = random.randint(-360 // self.GRID_SIZE, 360 // self.GRID_SIZE) * self.GRID_SIZE
                self.random_y = random.randint(-360 // self.GRID_SIZE, 360 // self.GRID_SIZE) * self.GRID_SIZE
                self.score += 10
                self.write_turtle.clear()
                self.write_turtle.write("Score is: " + str(self.score) + ". " + self.sentence + ".", align="center", font=("Arial", 16, "bold"))
                
            self.random_turtle.penup()
            self.random_turtle.goto((self.random_x, self.random_y))
            self.random_turtle.pendown()
            
            time.sleep(0.1)
        
        # Open the file in read mode
        with open('SnakeGameHigestScore.txt', 'r+') as file:
            # Read the entire content of the file
            content = file.read()
            sentence = ''
            index = 0
            int_number = 55
            file.seek(0)
            while(content[index] != '\n'):
                sentence += content[index]
                index += 1
            
            str_number_from_file = sentence[22:].strip()
            int_number_from_file = int(str_number_from_file)
            
            str_number = str(self.score)
            if(self.score > int_number_from_file):
                file.seek(22)
                file.write(str_number)    
        self.screen.exitonclick()
            
            
snake = SnakeGame()
snake.Run()