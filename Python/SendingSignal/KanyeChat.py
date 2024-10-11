from tkinter import *
from tkinter import simpledialog, messagebox
import requests

window = Tk()
window.title("Kanye app")
window.minsize(width = 350, height = 650)


def PressKanyeFace():
    response = requests.get(url = "https://api.kanye.rest")
    data = response.json()
    centered_label.config(text = data["quote"])
    

kanye_image = PhotoImage(file = "kanye.png")
kanye_image_label = Button(window, image = kanye_image, command = PressKanyeFace)
kanye_image_label.place(x = 120, y = 450)


background_image = PhotoImage(file = "background.png")
background_image_label = Label(window, image = background_image)
background_image_label.place(x = 10, y = 10)

# Create a label with text and customize font and color
centered_label = Label(window, text = "", font = ("Arial", 24), fg = "black",bg = "gold", wraplength = 250, justify = "center")
centered_label.place(x = 35, y = 65)
window.mainloop()