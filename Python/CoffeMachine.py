
    
class CoffeeMachine:
    def __init__(self):
        self.m_coffe_type = {}
        
    def AddCoffeType(self, coffee_type, price):
        self.m_coffe_type[coffee_type] = price
        
    def PrintAllCoffeeTypes(self):
        for coffee_type,price in self.m_coffe_type.items():
            print(f"Coffee type: {coffee_type}, Price: ${price:.2f}")
    
    def BuyCoffee(self):
        found = False
        final_price = 0
        exit = False
        
        while True:
            self.PrintAllCoffeeTypes()
            coffee = input("Enter the type of coffee you want to get: ")
            
            for coffee_type,price in self.m_coffe_type.items():
                if(coffee_type == coffee):
                    print("Please pay up",price,)
                    found = True
                    final_price = price
                    break
                
                if(coffee == "exit"):
                    exit = True
                    break
            if(exit == True):
                break
                
            if(found == True):
                Money_entered = 0
                
                while Money_entered < final_price:
                    Money_to_add = float(input("Please enter the amount of money you entered"))
                    Money_entered += Money_to_add
            
                if(Money_entered > final_price):
                    print("Here is your change of",Money_entered - final_price, ".Thank you for your patrionage.")
                    
                
                    

coffee_machine = CoffeeMachine()
coffee_machine.AddCoffeType("Capuchino", 5.5)
coffee_machine.AddCoffeType("Black Coffee", 4)
coffee_machine.AddCoffeType("Super coffee", 6)
coffee_machine.BuyCoffee()