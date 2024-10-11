from tkinter import *
from tkinter import simpledialog, messagebox
import random
import string
import json


BACKGROUND = '#FEF9D9'

# ---------------------------- UI SETUP ------------------------------- #
def generate_button_clicked():
    
    length = random.randint(10,12)
    password_input.delete(0, END)
    letters = string.ascii_letters # Both lowercase and uppercase letters
    digits = string.digits # Numbers 0-9
    special_chars = string.punctuation # Special characters (!, @, #, etc.)
    all_characters = letters + digits + special_chars
    password = ''.join(random.choice(all_characters) for _ in range(length))
    password_input.insert(0, password)
    
    
   
def clear_button_clicked():
    print("clear_button_clicked")
    website_input.delete(0, END)
    password_input.delete(0, END)
    email_username_input.delete(0, END)
    
    
def add_button_clicked():
    print("add_button_clicked")
    web_text = website_input.get()
    pass_text = password_input.get()
    mail_text = email_username_input.get()
    
    new_data = {
        web_text: {
            "email ": mail_text,
            "password ": pass_text
        }
    }
    
    # Check if any of the fields are empty
    if not web_text or not pass_text or not mail_text:
        messagebox.showwarning("Warning", "Please fill in all fields!")
    else:
        try:
            with open("data.json", "r") as file:
                data = json.load(file)
                data.update(new_data)
                
            with open("data.json", "w") as file:
                json.dump(data, file, indent = 4)
               
        except:
            with open("data.json", "w") as file:
                json.dump(new_data, file, indent = 4)
                
        messagebox.showinfo("Success", "Data added successfully!")

def search_button_clicked():
    web_text = website_input.get()
    
    try:
        with open("data.json", "r") as file:
            data = json.load(file)
            if web_text in data:
                email = data[web_text]["email "]  # Notice the space after 'email'
                password = data[web_text]["password "]  # Notice the space after 'password'
                messagebox.showinfo("Success", "Email: " + email + "\n" + "Password: " + password)
            elif web_text not in data:
                messagebox.showwarning("Warning", "No such data located! Please try again!") 
    except:
        messagebox.showwarning("Warning", "No such data located! Please try again!") 
        
window = Tk()

window.title("Password Generating App")
window.minsize(width = 525, height = 400)
window.config(bg = BACKGROUND)

image = PhotoImage(file = "logo.png")
image_label = Label(window, image=image, bg=BACKGROUND)
image_label.place(x=170, y=20)

website_text = Label(text="Website:", bg=BACKGROUND)
website_text.place(x=100, y=225)

website_input = Entry(width = 12)
website_input.place(x=200, y=225)

email_username_text = Label(text="Email/Username:", bg=BACKGROUND)
email_username_text.place(x=70, y=250)

email_username_input = Entry(width = 30)
email_username_input.place(x=200, y=250)

password_text = Label(text="Password:", bg=BACKGROUND)
password_text.place(x=90, y=270)

password_input = Entry(width = 12)
password_input.place(x=200, y=270)

generate_button = Button(text = "Generate Password", width = 14, command = generate_button_clicked)
generate_button.place(x=305, y=270)

add_button = Button(text="Add", width = 27, command = add_button_clicked)
add_button.place(x=200, y=300)

clear_button = Button(text="Clear", width = 27, command = clear_button_clicked)
clear_button.place(x=200, y=330)

search_button = Button(text="Search", width = 14, command = search_button_clicked)
search_button.place(x=305, y=220)
window.mainloop()