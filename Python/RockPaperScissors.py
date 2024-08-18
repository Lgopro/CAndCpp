import random

ROCK = 0
PAPER = 1 
SCISSORS = 2

def PrintHand(choise):
    if(choise == ROCK):
        print("ROCK")
    elif(choise == PAPER):
        print("Paper")
    else:
        print("Scissors")

def RockPaperScissors(choise, random_integer):
    PrintHand(choise)
    print("Computer choise: ")
    PrintHand(random_integer)
    ChooseWinner(choise, random_integer)
    
def ChooseWinner(choise, random_integer):
    if(choise == random_integer):
        print("Its A Draw")
    elif(choise > random_integer):
        print("You Win!")
    else:
        print("You Lose!")


choise = int(input("What do you choose? Type 0 for Rock, 1 for Paper or 2 for Scissors "))

random_integer = random.randint(0, 2)

RockPaperScissors(choise, random_integer)


