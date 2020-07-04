#include "Date.h";
#include <stack>
#include <iostream>


int main() {
	/*List of books and different list for where books can go*/
	stack<string> books_In_Circulation;
	stack<string> books_Archived;
	stack<string> books;
	/*Sending books into the books stack*/
	books.push("How to Code with Javascript");
	books.push("How to Code with Python");
	books.push("How to Code with Java");
	books.push("How to Code with C++");

	/*Setting the date in YYYY-MM-DD format*/
	Date date_1(2020, 2, 10); 
	Date date_2(2020, 3, 21);
	Date date_3();
	Date date_4();
	Date date_5();

	while (date_1 != date_2) //checks whether the first date is equal to the second date
	{
		date_1.add_days(1); // adds a day to the first date
		string firstDate = date_1.toString(); // converts the date into a string
		cout << firstDate << endl; // outputs the first date to the console

		if (date_1 == date_2) { // checks if the first date is equal to the second date
			break; // breaks the loop
		}
	}

	
}