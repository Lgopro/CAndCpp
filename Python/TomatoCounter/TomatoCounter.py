from tkinter import *
from tkinter import simpledialog, messagebox

# ---------------------------- CONSTANTS ------------------------------- #
PINK = "#e2979c"
RED = "#e7305b"
GREEN = "#9bdeac"
YELLOW = "#f7f5dd"
FONT_NAME = "Courier"
BACKGROUND = '#FADFA1'
WORK_MIN = 25
SHORT_BREAK_MIN = 5
LONG_BREAK_MIN = 20

window = Tk()

def count_itself(count):
    # Recalculate minutes and seconds each time
    minutes = count // 60
    seconds = count % 60
    # Format the time as MM:SS
    # timer_text_counter.config(text=f"{minutes:02}:{seconds:02}")
    canvas.itemconfig(timer_text_counter, text=f"{minutes:02}:{seconds:02}")
    if count > 0:
        # Update the label after 1 second (1000 milliseconds)
        window.after(1000, count_itself, count - 1)
    else:
        # When the countdown finishes, call the next round
        countdown()

# Function to start the countdown based on work or rest
def start_countdown(work_min, rest_min, mode):
    if mode == "work":
        count = 60 * work_min
        timer_text.config(text="Work", fg="green")
    else:
        count = 60 * rest_min  
        timer_text.config(text="Rest", fg="red")
    
    count_itself(count)

# Variable to track current round and total rounds
current_round = 0
total_rounds = 0
work_minutes = 0
rest_minutes = 0

def countdown():
    global current_round
    if current_round >= total_rounds:
        timer_text.config(text="Done", fg="green")
        return
    
    if current_round % 2 == 0:  # Work round
        window.lift()
        start_countdown(work_minutes, rest_minutes, "work")
    else:  # Rest round
        window.lift()
        start_countdown(work_minutes, rest_minutes, "rest")
    
    current_round += 1

def start_button_clicked():
    global work_minutes, rest_minutes, total_rounds, current_round
    current_round = 0
    work_min = simpledialog.askstring("Input", "Please enter number of minutes to work: ")
    rest_min = simpledialog.askstring("Input", "Please enter number of minutes to rest: ")
    rounds = simpledialog.askstring("Input", "Please enter the number of rounds: ")
    
    work_minutes = int(work_min)
    rest_minutes = int(rest_min)
    total_rounds = int(rounds) * 2  # Each round has a work and rest phase
    
    countdown()  # Start the first round

def reset_button_clicked():
    global current_round
    
    current_round = 0
    canvas.itemconfig(timer_text_counter, text="00:00")
    timer_text.config(text="Timer", fg="green")
    messagebox.showinfo("Reset", "Reset Complete!")

window.title("Tomato Work App")
window.minsize(width=500, height=500)
window.config(bg=BACKGROUND)

# UI setup
image = PhotoImage(file="tomato.png")

canvas = Canvas(width=200, height=224, bg=BACKGROUND, highlightthickness=0)
tomato_img = PhotoImage(file="tomato.png")
canvas.create_image(100, 112, image=tomato_img)
timer_text_counter = canvas.create_text(100, 130, text="00:00", fill="white", font=(FONT_NAME, 35, "bold"))
canvas.place(x=150, y=150)

timer_text = Label(text="Timer", bg=BACKGROUND, font=("Arial", 24), fg="green")
timer_text.place(x=210, y=100)

button_start = Button(text="Start", command=start_button_clicked)
button_start.place(x=120, y=400)

button_reset = Button(text="Reset", command=reset_button_clicked)
button_reset.place(x=320, y=400)


window.mainloop()
