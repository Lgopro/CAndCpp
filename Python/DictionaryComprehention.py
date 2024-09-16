import random

names = ['Alex', 'Beth', 'Caroline', 'Dave', 'Shlomke', 'Darius']
student_scores = {student:random.randint(1, 100) for student in names}

print(student_scores)

passed_students = {student:score for student, score in student_scores.items() if score > 70}
failed_students = {student:score for student, score in student_scores.items() if score <= 70
                   }
print("Passed students", passed_students)
print("Failed students", failed_students)