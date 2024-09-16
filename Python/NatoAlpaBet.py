import pandas

alphabet_list = [chr(i) for i in range(ord('a'), ord('z') + 1)]


nato_alphabet = [
    "Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf",
    "Hotel", "India", "Juliett", "Kilo", "Lima", "Mike", "November",
    "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform",
    "Victor", "Whiskey", "X-ray", "Yankee", "Zulu"
]

letter_nato_alphabet = {letter:word for letter, word in zip(alphabet_list, nato_alphabet)}

input_text = input("Please enter a string with only letters: ")
lower_case_text = input_text.lower()

for index in range (len(lower_case_text)):
    print(letter_nato_alphabet[lower_case_text[index]])
    
result_list = [letter_nato_alphabet[char] for char in lower_case_text if char in letter_nato_alphabet]
print(result_list)