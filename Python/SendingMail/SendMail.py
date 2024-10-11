import smtplib
import datetime as dt
import random

def sendMail(message):
    my_email = "lgopro06@gmail.com"
    password = "aipzqehhhpritxzp "

    connection = smtplib.SMTP("smtp.gmail.com")
    connection.starttls()
    connection.login(user = my_email, password = password)
    connection.sendmail(from_addr = my_email, 
    to_addrs = "Metrevelinatela@gmail.com",
                        msg = "Subject:Sup\n\n" + message)
    connection.close()

def LoadSentencesFromFile():
    try:
        with open("quotes.txt", 'r') as file:
            sentences = file.read().splitlines()
            return sentences
    except FileNotFoundError:
        print(f"Error. File is not found.")
        return []

    
now = dt.datetime.now()
year = now.year
month = now.month
day_of_the_week = now.weekday()

sentences = LoadSentencesFromFile()
line_number = random.randint(0, len(sentences))
sendMail(sentences[line_number])
