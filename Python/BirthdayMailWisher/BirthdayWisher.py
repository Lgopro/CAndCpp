import smtplib
import datetime as dt
import random
import pandas


def sendMail(message, mail):
    my_email = "lgopro06@gmail.com"
    password = "aipzqehhhpritxzp "

    connection = smtplib.SMTP("smtp.gmail.com")
    connection.starttls()
    connection.login(user = my_email, password = password)
    connection.sendmail(from_addr = my_email, to_addrs = mail,
                        msg = "Subject:Sup\n\n" + message)
    connection.close()

def LoadFile():
    letter_type = random.randint(1,3)
    letter_type_str = str(letter_type) 
    
    try:
        with open("letter_templates/letter_" + letter_type_str + ".txt", 'r') as file:
            file_text = file.read()
            return file_text
    except FileNotFoundError:
        print(f"Error. File is not found.")
        return []

    


park_data = pandas.read_csv("birthdays.csv")
time_now = dt.datetime.now()
sentences = LoadFile()


for index in range (0, len(park_data)):
    person = park_data.iloc[index] 
    if(person["month"] == time_now.month and person["day"] == time_now.day):
        new_sentences = sentences.replace("[NAME]", person["name"])
        sendMail(new_sentences, person["email"]) 


