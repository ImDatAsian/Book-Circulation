"""
Greg Robson & Thomas Yang
CS 303: Data Structures
7/5/2020
"""

from operator import attrgetter
import random


# Class responsible for handling book objects
class Book:
    def __init__(self, name):
        self.name = name
        self.start = 0
        self.queue = []


# Class responsible for handling employee objects
class Employee:
    def __init__(self, name):
        self.name = name
        self.waiting = 0
        self.retaining = 0
        self.delta = 0
        self.books = []

company = []  # List of employees
library = []  # List of books to be circulated
archive = []  # List of archived books
current_day = 1  # The current day, incremented by one every "day"

# Create the company of employees
company.append(Employee("Sam"))
company.append(Employee("Mark"))
company.append(Employee("Jane"))
company.append(Employee("Greg"))
company.append(Employee("Thomas"))
company.append(Employee("Joe"))
company.append(Employee("Stacy"))
company.append(Employee("Rob"))

# Create the library of books
library.append(Book("How to code in C++"))
library.append(Book("How to code in python"))
library.append(Book("How to code in Java"))
library.append(Book("The Second Coming of Gluttony"))
library.append(Book("Overgeared"))


for i in library:  # For each of the books in the library
    temp = company.copy()  # Copy the list of employees so as to be able to pop without harming the original

    for j in company:  # For each of the employees in the company
        rando = random.randint(0, len(temp) - 1)  # Randomly select an employee not already in the queue
        i.queue.append(temp[rando])  # Add that employee to the queue for said book
        temp.pop(rando)  # Pop that employee from the list of those not already in the queue

for i in library:  # For each of the books in the library
    i.queue[0].books.append(i)  # Give the book to the person randomly selected to be first in line
    print("Day " + str(current_day) + ": " + i.queue[0].name + " has checked out " + i.name)
    i.queue.pop(0)  # Remove that employee from that books queue
    i.start = current_day


while len(archive) != len(library):  # While the archive of books is not full
    current_day += 1  # Advance to the next day

    for i in company:  # For each employee in the company
        if len(i.books) > 0:  # If that employee has books
            for j in i.books:  # For each book they have
                i.retaining += 1  # Give them retaining + 1 for each book
        else:
            i.waiting += 1  # If they have no books, give them waiting + 1
        i.delta = i.waiting - i.retaining

    for i in library:  # For each book in the library
        i.queue = sorted(i.queue, key=attrgetter('delta'), reverse=True)  # Resort their queue based on priority

    # Simple for loop that displays the current waiting - retaining of each employee, commented out
    """
    printout = "Day " + str(current_day) + ": "
    for i in company:
        printout += i.name + " " + str("%.2f" % i.delta) + " | "

    print(printout)
    """

    for i in company:  # For each employee in the company
        if len(i.books) > 0:  # If that employee has books
            for j in reversed(range(0, len(i.books))):  # For each book they have (in reverse order for popping)
                rando = random.randint(0, 3)  # Randomly decide if they are done with the book
                held = current_day - i.books[j].start  # Checks how long that book has been held for
                if rando == 0 or held == 7:  # If they are done with the book / have had it for a week
                    if len(i.books[j].queue) != 0:  # If the queue waiting for that book is not empty
                        i.books[j].start = current_day  # Changes the start date to today
                        i.books[j].queue[0].books.append(i.books[j])  # Give the book to that employee

                        # Print that that employee has the book
                        print("Day " + str(current_day) + ": " + i.name + " has passed "
                              + i.books[j].name + " to " + i.books[j].queue[0].name)

                        # Add a tie breaking fraction when they receive a book so that they don't unfairly receive more
                        i.books[j].queue[0].retaining += .1

                        i.books[j].queue.pop(0)  # Remove them from the queue
                        i.books.pop(j)  # Remove the book from the employee who just passed it
                    else:  # If the queue for the book is empty
                        archive.append(i.books[j])  # Put the book in the archive

                        # Print that the book is now in the archive
                        print("Day " + str(current_day) + ": " + i.name + " has passed "
                              + i.books[j].name + " to the archive")

                        i.books.pop(j)  # Remove the book from the employee

print("The archive is full")
