import csv #comma-separated values

file = open("phonebook.csv", "a")

name = input("Name: ")
number = input("Number: ")

writer = csv.writer(file) #open the file and be ready to write on it
writer.writerow([name, number])

file.close()

#another way
#it will automatically close the file
name = input("Name: ")
number = input("Number: ")

with open("phonebook.csv", "a") as file:
    writer = csv.writer(file) #open the file and be ready to write on it
    writer.writerow([name, number])

#now with a dictionary writer
name = input("Name: ")
number = input("Number: ")

with open("phonebook.csv", "a") as file:
    writer = csv.DictWriter(file, fieldnames=["name", "number"])
    writer.writerow({"name": name, "number": number})



