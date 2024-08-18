import tkinter as tk

def on_run_click():
    # Get input from the entry widgets
    city_name = city_entry.get()
    pet_name = pet_entry.get()
    
    # Generate the band name
    band_name = city_name + " " + pet_name
    
    # Update the result label with the band name
    result_label.config(text=f"Your band name should be: {band_name}")

# Create the main window
root = tk.Tk()
root.title("First Python code")

# Welcome label
welcome_label = tk.Label(root, text="Welcome to the Band Name Generator.", font=("Arial", 12))
welcome_label.pack(pady=10)

# City name label and entry
city_label = tk.Label(root, text="What's the name of the city you grew up in?")
city_label.pack(pady=5)
city_entry = tk.Entry(root) # a text input field
city_entry.pack(pady=5)

# Pet name label and entry
pet_label = tk.Label(root, text="What's your pet's name?")
pet_label.pack(pady=5)
pet_entry = tk.Entry(root)  # a text input field
pet_entry.pack(pady=5) # Adds 5 pixels of padding above and below the button

# Run button
run_button = tk.Button(root, text="Run", fg="green", command=on_run_click)
run_button.pack(pady=20) # Adds 20 pixels of padding above and below the button

# Result label (initially empty)
result_label = tk.Label(root, text="", font=("Arial", 12, "bold"))
result_label.pack(pady=10) # Adds 10 pixels of padding above and below the button

# Run the application
root.mainloop()



#pady: Vertical padding (space above and below the widget).
#padx: Horizontal padding (space to the left and right of the widget).