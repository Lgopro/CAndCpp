from tkinter import *

window = Tk()

window.title("Mile to Km Converter")
window.minsize(width = 300, height = 100)

def button_clicked():
    
    km_value = 1.6 * float(input.get())
    my_text_number.config(text = f"{km_value:.2f}")

my_text_empty = Label(text = "")
my_text_empty.grid(row=0, column=0)


input = Entry(width = 10)
input.grid(row=0, column=1)

my_text_miles = Label(text = "Miles")
my_text_miles.grid(row=0, column=2)

my_text_equal = Label(text = "is equal to")
my_text_equal.grid(row=1, column=0)

my_text_number = Label(text = "0")
my_text_number.grid(row=1, column=1)

my_text_km = Label(text = "Km")
my_text_km.grid(row=1, column=2)

button = Button(text = "Calculate", command=button_clicked)
button.grid(row=2, column=1)


# Configure the rows and columns to expand and fill the screen
for i in range(3):
    window.grid_rowconfigure(i, weight=1)   # Make each row expandable
    window.grid_columnconfigure(i, weight=1)  # Make each column expandable


window.mainloop()