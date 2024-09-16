import csv
import pandas

# with open('weather_data.csv', mode='r') as csv_file:
#     csv_reader = csv.reader(csv_file)
    
#     # Read the header
#     header = next(csv_reader)
    
#     # Print the headers
#     print("Headers:")
#     for index in range(len(header)):
#         print(header[index])
    
#     day = []
#     temperature = []
#     condition = []
    
#     # Print each row
#     print("\nRows:")
#     for row in csv_reader:
#         day.append(row[0])
#         temperature.append(row[1])
#         condition.append(row[2])
        
#     print("day: ", day)
#     print("temperature: ", temperature)
#     print("condition: ", condition)

data = pandas.read_csv("weather_data.csv")
print(data)
print(data["temp"])

data_dict = data.to_dict() #converts into a dictionary
print(data_dict)

temp_list = data["temp"].to_list()
print(temp_list)
sum = 0
for temp in temp_list:
    sum += temp

print("Tne average is: ", sum/len(temp_list))
print(data["temp"].mean())
print(data["temp"].max())

#print row with all the data

print(data[data.day == "Monday"])
max_temp = data["temp"].max()
print(data[data.temp == max_temp])

data_dict = {
    "students": ["Lolka", "Lgo", "Angel"],  # Each student's name is a separate element in the list
    "scores": [75, 70, 100]
}

new_data = pandas.DataFrame(data_dict)
new_data.to_csv("dict_data.csv", index=False)  # Saves the DataFrame to a CSV file without including the index
