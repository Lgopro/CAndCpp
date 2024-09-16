 
import tkinter

window = tkinter.Tk() #Created the window

window.title("My first GUI program")
window.minsize(width = 500, height = 300)

def button_clicked():
    print("I got clicked!")
    my_label.config(text = "I got clicked!")
    print(input.get())
#Label

my_label = tkinter.Label(text = "Im a label", font = ("Arial", 24, "bold"))#created a component.
my_label.pack() #put it on the screen. on the center of the screen. have to write this to put it on the screen.

my_label["text"] = "New Text" #does same thing as new row
my_label.config(text = "New Text")

button = tkinter.Button(text = "Click Me!", command = button_clicked)
button.pack()

input = tkinter.Entry(width = 10)
input.pack()
print(input.get())




window.mainloop() #its like while True that wait till the end. 
#Have to be at the end 
    
