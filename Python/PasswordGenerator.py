import random

password = []

letters = int(input("How Many letters do you want? "))
symbols = int(input("How Many symbols do you want? "))
numbers = int(input("How Many numbers do you want? "))

letters_counter = 0
symbols_counter = 0
numbers_counter = 0

while True:
    random_integer = random.randint(33, 126)
    if((random_integer <= 47 and random_integer >= 32) or (random_integer >= 58 and random_integer <= 64) or (random_integer >= 91 and random_integer <= 96) or (random_integer >= 123 and random_integer <= 126)):
        if(symbols_counter < symbols):
            password.append(chr(random_integer))
            symbols_counter += 1
            
            
    elif(random_integer <= 57 and random_integer >= 48):
        if(numbers_counter  < numbers):
            password.append(chr(random_integer))
            numbers_counter += 1
            
            
    elif(random_integer <= 90 and random_integer >= 65 or random_integer <= 122 and random_integer >= 97):
        if(letters_counter  < letters - symbols - numbers):
            password.append(chr(random_integer))
            letters_counter += 1
            
    if(letters_counter == letters - symbols - numbers and symbols_counter == symbols and numbers_counter == numbers):
        break
            
    #print("symbols_counter",symbols_counter,"numbers_counter",numbers_counter,"letters_counter",letters_counter)
    
    
print(password)

for char in password:
    print(char, end = "")
print("")