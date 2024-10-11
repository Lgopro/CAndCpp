from tkinter import *
from tkinter import simpledialog,messagebox
import pandas
import random
import sys

BACKGROUND = '#3CB371'  # Hex code for lime color

def right_button_press():
    global current_index
    print("Right Pressed")
    russian_english.loc[current_index, "Learned"] = "Yes"
    russian_english.to_csv("Russian to English.csv", index=False)
    
def wrong_button_press():
    global current_index
    print("Wrong Pressed")
window = Tk()

def continue_loop(current_index):
    card_front_image_label.place(x = 25, y = 50)
    card_back_image_label.place_forget()
    langauge_type_label.config(text = "Русский", background = "snow")
    langauge_label.config(text = russian_english.iloc[current_index]["Russian word"], background = "snow")  
    
def start_loop():
    global current_index
    if((russian_english["Learned"] == "Yes").sum() >= len(russian_english) - 1):
        messagebox.showinfo("Result", "Words Ended! Good job!") 
        window.destroy()  # Close the Tkinter window
        sys.exit()  # End the program
        return
    card_front_image_label.place_forget()
    card_back_image_label.place(x = 25, y = 50)
    current_index = random.randint(0, len(russian_english) - 1)
    print(russian_english.iloc[current_index]["Learned"])
    while(True):    
        if(russian_english.iloc[current_index]["Learned"] == "No"):
            langauge_type_label.config(text = "English", background = "#698B69")
            langauge_label.config(text = russian_english.iloc[current_index]["English translation"], background =  "#698B69")  
            window.after(3000, lambda: continue_loop(current_index))   
            break      
    window.after(6000, start_loop)   

 
russian_english = pandas.read_csv("Russian to English.csv")
russian_english["Learned"] = "No"
russian_english.to_csv("Russian to English.csv", index=False)  # Save changes to CSV


window.title("Langauge learning application")
window.minsize(width = 850, height = 800)
window.config(bg = BACKGROUND)

right_image = PhotoImage(file = "right.png")
right_image_button = Button(window, image = right_image, bg = BACKGROUND, command = right_button_press)
right_image_button.place(x = 575, y = 600)

wrong_image = PhotoImage(file = "wrong.png")
wrong_image_button = Button(window, image = wrong_image, bg = BACKGROUND, command = wrong_button_press)
wrong_image_button.place(x = 175, y = 600)

card_back_image = PhotoImage(file = "card_back.png")
card_back_image_label = Label(image = card_back_image, bg = BACKGROUND)
card_back_image_label.place(x = 25, y = 50)

card_front_image = PhotoImage(file = "card_front.png")
card_front_image_label = Label(image = card_front_image, bg = BACKGROUND)
card_front_image_label.place(x = 25, y = 50)
card_front_image_label.place_forget()

langauge_type_label = Label(text = "", font = ("Times New Roman", 48))
langauge_type_label.place(x = 400, y = 150, anchor = 'center')

langauge_label = Label(text = "", font = ("Times New Roman", 36))
langauge_label.place(x = 400, y = 350, anchor = 'center')

start_loop()

window.mainloop()

