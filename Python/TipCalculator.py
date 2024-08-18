print("Welcome to the tip Calculator!")
bill_amount_str = input("What was the total bill? ")
tip_str = input("How much tip would you like to give? ")
people_amount_str = input("How many people to slpit the bill? ")

try:
    bill_amount = float(bill_amount_str)
    tip = float(tip_str)
    people_amount = float(people_amount_str)
    result = (bill_amount + tip) / people_amount
    print(f"Each person should pay: ${result:.2f}")
except ValueError:
    print("Please enter a valid number.")

