import os


bidding_dict = {}
another_bid = False
Max = 0
Max_key = ""

while True:
    os.system('clear')
    name = input("What is your name? ")
    bid = int(input("What is your bid? "))
    bidding_dict[name] = bid
    
    while True:
        bid = input("Are there any other bidders? Type 'yes' or 'no' ")
        if(bid == "yes"):
            another_bid = True
            break
        elif(bid == "no"):
            another_bid = False
            break
    
    if(another_bid == False):
        break


for key,value in bidding_dict.items():
    if(value > Max):
        Max = value
        Max_key = key
        
print("The winner is " + Max_key + " with a bid of " + str(Max) + "$")