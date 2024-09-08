# Open the file in read mode
with open('SnakeGameHigestScore.txt', 'r+') as file:
    # Read the entire content of the file
    content = file.read()
    sentence = ''
    index = 0
    int_number = 55
    file.seek(0)
    while(content[index] != '\n'):
        sentence += content[index]
        index += 1
    print(sentence)
    
    str_number_from_file = sentence[22:].strip()
    int_number_from_file = int(str_number_from_file)
    
    str_number = str(int_number)
    if(int_number > int_number_from_file):
        file.seek(22)
        file.write(str_number)