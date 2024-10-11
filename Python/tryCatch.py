try:
    file = open("tryCatch.txt", "r")
except:
    file = open("tryCatch.txt", "w")
    file.write("except")
else:
    print("else")
finally:
    print("finally")