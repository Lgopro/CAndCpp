from tkinter import *
from tkinter import simpledialog, messagebox
import requests
import random

amount = 10
question_type = "boolean"

parameters = {
    "amount" : amount,
    "type" : question_type,
}

def PressedYes():
    global random_num, pressed, score
    pressed = True
    if(answers[random_num] == 'True'):   
        canvas.config(bg = 'green')
        score += 1
        centered_label.config(text = "score:" + str(score))
        
    else:
        canvas.config(bg = 'red')
    del questions[random_num]
    del answers[random_num]
    parameters["amount"] -= 1 
    window.after(2000, StartQuestions)
    
def PressedNo():
    global random_num, pressed, score
    pressed = True
    
    if(answers[random_num] == 'True'):   
        canvas.config(bg = 'red')
    else:
        canvas.config(bg = 'green')
        score += 1
        centered_label.config(text = "score:" + str(score))
    del questions[random_num]
    del answers[random_num]
    parameters["amount"] -= 1 
    window.after(2000, StartQuestions)
    

def StartQuestions():
    global random_num, pressed
    pressed = False
    if(parameters["amount"] <= 0):
        messagebox.showinfo("Result", "Your score is: " + str(score) + " out of " + str(max_amount_of_points)) 
        window.destroy()
        return 
    canvas.config(bg = 'snow')
    random_num = random.randint(0, parameters["amount"] - 1)
    canvas.itemconfig(text_id, text = questions[random_num])
    
    
   
        


window = Tk()

window.title("Quizzer App")
window.minsize(width = 600, height = 700)

yes = PhotoImage(file = "true.png")
yes_button = Button(image = yes, command = PressedYes)
yes_button.place(x = 350, y = 500)

no = PhotoImage(file = "false.png")
no_button = Button(image = no, command = PressedNo)
no_button.place(x = 150, y = 500)

centered_label = Label(window, text = "score: 0", font = ("Arial", 24), fg = "black", wraplength = 250, justify = "center")
centered_label.place(x = 380, y = 30)
score  = 0

# Create a canvas to draw a square with a different background color
canvas = Canvas(window, width = 500, height = 400, bg = 'snow', highlightthickness = 0)
canvas.place(x = 50, y = 85)

text_id = canvas.create_text(250, 100, width = 400, text="", font=("Arial", 20), fill="black")

user_text = simpledialog.askstring("Quizzer", "Enter the amount of questions you want to get:")
parameters["amount"] = int(user_text)

response = requests.get(url = "https://opentdb.com/api.php", params = parameters)
data = response.json()

# Iterate over the results to extract questions and answers
questions = [item["question"] for item in data["results"]]
answers = [item["correct_answer"] for item in data["results"]]

# print(questions)
# print(answers)

pressed = False
score = 0
max_amount_of_points = parameters["amount"]
# print(len(questions))
# print(type(answers[1]))
StartQuestions()

window.mainloop()