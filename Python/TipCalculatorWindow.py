import tkinter as tk

def on_run_click():
    try:
        # Get input from the entry widgets
        bill_amount = float(bill_amount_str.get())
        tip = float(tip_str.get())
        people_amount = float(people_amount_str.get())
        
        # Calculate and update the result label
        result = (bill_amount + tip) / people_amount
        result_label.config(text=f"Each person should pay: ${result:.2f}")

    except ValueError:
        messagebox.showerror("Invalid Input", "Please enter a valid number.")
        
# Create the main window
root = tk.Tk()
root.title("Tip Calculator")

# Welcome label
welcome_label = tk.Label(root, text="Welcome to the Tip Calculator.", font=("Arial", 12))
welcome_label.pack(pady=10)

# total bill
bill_amount_str = tk.Label(root, text="What was the total bill?")
bill_amount_str.pack(pady=5)
bill_amount_str = tk.Entry(root) # a text input field
bill_amount_str.pack(pady=5)

# tip
tip_str = tk.Label(root, text="How much tip would you like to give?")
tip_str.pack(pady=5)
tip_str = tk.Entry(root)  # a text input field
tip_str.pack(pady=5) # Adds 5 pixels of padding above and below the button

# tip
people_amount_str = tk.Label(root, text="How many people to slpit the bill?")
people_amount_str.pack(pady=5)
people_amount_str = tk.Entry(root)  # a text input field
people_amount_str.pack(pady=5) # Adds 5 pixels of padding above and below the button

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