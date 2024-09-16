student_dict = {
    "student": ["Angela", "James", "Lily"],
    "score": [55, 67, 88]
}

#Looping through dictionaries:
for (key, value) in student_dict.items():
    print(key) #student, score
    print(value) #print the dictionary itself
    
import pandas

student_data_frame = pandas.DataFrame(student_dict)
print(student_data_frame)

#Loop through rows of a data frame
for (index, row) in student_data_frame.iterrows():
    print(index) #print 0 1 2
    print(row) #print the table for each student data
    print(row.student) #print student name