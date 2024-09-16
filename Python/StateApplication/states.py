import turtle
import tkinter as tk
from tkinter import simpledialog, messagebox
import pandas

states_data = pandas.read_csv("50_states.csv")

# Initialize all statuses to "No"
states_data["status"] = "No"
states_data.to_csv("50_states.csv", index=False)  # Save changes to CSV

# Function to display text at a specific location on the Turtle screen
def display_text_at_location(text, x, y):
    
    text_turtle.goto(x, y)
    text_turtle.write(text, align="center", font=("Arial", 10, "normal"))

# Function to prompt the user for input and update the Turtle screen
def prompt_for_input(states_data, counter):
    user_text = simpledialog.askstring(f"{counter} of 50", "Enter your text:")
    state_names = states_data["state"]
    matching_rows = states_data[state_names.str.contains(user_text, case=False, na=False)]
    
    if not matching_rows.empty:
        row = matching_rows.iloc[0]
        x = row["x"]
        y = row["y"]
        status = row["status"]
        if(status == "No"):
            display_text_at_location(user_text, x, y)  
            counter += 1
            index = row.name  # Get the index of the matching row
            states_data.at[index, "status"] = "Yes"  # Update the status column
            states_data.to_csv("50_states.csv", index=False)
    if(counter == 50):
        messagebox.showinfo("Result", "You Win!") 
        screen.bye()  # Close the Turtle screen
        root.quit() 
        return       
    # Continue to prompt for input
    root.after(2500, prompt_for_input(states_data, counter))  # Wait 1 second before asking again

# Set up the Turtle screen
screen = turtle.Screen()
screen.title("Image Viewer")
screen.bgpic("blank_states_img.gif")  # Use the correct path to your image file

# Create a Turtle for writing text
text_turtle = turtle.Turtle()
text_turtle.hideturtle()
text_turtle.penup()

# Create a Tkinter window
root = tk.Tk()
root.withdraw()  # Hide the main Tkinter window

# Start the input prompt loop
prompt_for_input(states_data, 0)

# Run the Tkinter main loop
root.mainloop()

# Keep the Turtle window open
turtle.done()
