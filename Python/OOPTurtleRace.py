import turtle
import random
import threading

class Turtle:
    def __init__(self, turtle, color, x_location, y_location, final_x, user_color_choise):
        self.turtle = turtle
        self.turtle.shape("turtle")
        self.color = color
        self.turtle.color(color)
        self.x_location = x_location
        self.y_location = y_location
        self.user_color_choise = user_color_choise
        self.final_x = final_x
        self.turtle.penup()
        self.turtle.goto(x_location, y_location)
        self.turtle.pendown()
        self.flag = True
        
    def GetRandomMove(self):
        return random.randint(1, 20)  
      
    def Run(self):
        while self.flag:
            self.turtle.penup()
            move = self.GetRandomMove()
            self.turtle.forward(move) 
            self.turtle.pendown()
            self.x_location += move
            if self.x_location >= self.final_x:
                if(self.color == self.user_color_choise):
                    print("You Chose the right color! You Won!")
                else:
                    print("The color you chose is: " + self.user_color_choise + ". The color that won is: " + self.color + ". You LOSE!")
                return True
            
    def Stop(self):
        self.flag = False
        
# Set up the screen
screen = turtle.Screen()
screen.title("Turtle Circle Drawing")
screen.setup(width=600, height=600)

x_location = -screen.window_width() // 2 + 10
y_location =  -screen.window_height() // 2
user_color_bet = screen.textinput(title = "Make your bet!", 
                                  prompt = "Which turtle will win the race? Enter one of the colors: blue, red, yellow, green, purple, orange." )
# Create a turtle object
blue_turtle = Turtle(turtle.Turtle(), "blue", x_location, y_location + 180, 300, user_color_bet)
red_turtle = Turtle(turtle.Turtle(), "red", x_location, y_location + 240, 300, user_color_bet)
yellow_turtle = Turtle(turtle.Turtle(), "yellow", x_location, y_location + 300, 300, user_color_bet)
green_turtle = Turtle(turtle.Turtle(), "green", x_location, y_location + 360, 300, user_color_bet)
purple_turtle = Turtle(turtle.Turtle(), "purple", x_location, y_location + 420, 300, user_color_bet)
orange_turtle = Turtle(turtle.Turtle(), "orange", x_location, y_location + 480, 300, user_color_bet)

# Run each turtle in a separate thread
threads = []
for turtle_race in [blue_turtle, red_turtle, yellow_turtle, green_turtle, purple_turtle, orange_turtle]:
    thread = threading.Thread(target=turtle_race.Run)
    #threads.append(thread)
    thread.start()

# Wait for all threads to complete
for thread in threads:
    thread.detach()



# if(status_blue == True or status_red == True or status_yellow == True or status_green == True or status_purple == True or status_orange == True):
#     blue_turtle.Stop()
#     red_turtle.Stop()
#     yellow_turtle.Stop()
#     green_turtle.Stop()
#     purple_turtle.Stop()
#     orange_turtle.Stop()


screen.exitonclick()