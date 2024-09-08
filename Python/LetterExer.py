# Open the file in read mode
with open('letter.txt', 'r+') as letter_file:
    # Read the entire content of the file
    content = letter_file.read()
    print(content)
    
with open('names.txt', 'r') as names_file:
    while True:
        name = names_file.readline()  # Read one line at a time
        if not name:  # If line is an empty string, it means we've reached the end of the file
            print("End of file reached")
            break
        with open('letter_to'+ name + '.txt', 'w') as write_file:
            text = content
            new_text = content.replace('[Name]', name) 
            write_file.write(new_text)
        # Process the line

    