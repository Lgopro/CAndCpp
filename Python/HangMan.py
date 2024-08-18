import random


def Hangman(word):
    max_counter = len(word) + 1
    counter = 0
    current_word = ['_'] * len(word)  
    found_letters = 0
    
    while counter < max_counter:
        print("************************", max_counter, "/", max_counter - counter, "lives left ************************")
        print("Word to guess: " + ''.join(current_word)) 
        char_val = input("Guess a letter: ")
        found = False
        
        for i in range(len(word)):
            if char_val == word[i]:
                current_word[i] = word[i]
                found = True
                found_letters += 1
                
        if not found:
            print("You guessed", char_val, ", That's not the right letter. You lost a life.")
            counter += 1
        else:
            print(''.join(current_word))
        
        if found_letters == len(word):
            print("You win!")
            return

    print("You Died!")
    print(''.join(word))

words = [
    "apple", "banana", "orange", "grape", "mango", "strawberry", "blueberry", "kiwi", "pear", "peach",
    "table", "chair", "sofa", "bed", "lamp", "desk", "bookshelf", "drawer", "carpet", "curtain",
    "computer", "keyboard", "mouse", "screen", "printer", "tablet", "laptop", "phone", "charger", "battery",
    "sun", "moon", "star", "planet", "comet", "galaxy", "universe", "asteroid", "nebula", "blackhole",
    "river", "lake", "ocean", "stream", "pond", "waterfall", "beach", "wave", "tide", "current",
    "mountain", "hill", "valley", "cliff", "plateau", "canyon", "desert", "forest", "jungle", "meadow",
    "dog", "cat", "bird", "fish", "horse", "sheep", "cow", "goat", "chicken", "duck",
    "book", "pen", "pencil", "notebook", "paper", "eraser", "sharpener", "ruler", "marker", "crayon",
    "shirt", "pants", "jacket", "shoes", "hat", "gloves", "scarf", "belt", "socks", "sunglasses"
]

random_integer = random.randint(0, 99)
Hangman(words[random_integer])