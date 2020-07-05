#include "Date.h";
#include "queue.h"
#include <iostream>

void book_Circulation(queue<string> booksArchived, queue<string> booksCirculation, Date dateOne, Date dateTwo, Date dateThree) {
	string temp;

	while (booksArchived.size() != 0) {
		string temp = booksArchived.front();
		booksArchived.RemoveBook();
		booksCirculation.addBooks(temp);
		cout << temp << endl;
		cout << booksArchived.size() << endl;
		if (booksArchived.size() == 0) {
			break;
		}
	}
}



int main() {
	/*List of books and different list for where books can go*/
	queue<string> books_Archived;
	queue<string> books_in_Circulation;

	books_Archived.addBooks("How to Code with Python");
	books_Archived.addBooks("How to Code with Java");
	books_Archived.addBooks("How to Code with C++");
	books_Archived.addBooks("The Second Coming of Gluttony");
	books_Archived.addBooks("Overgeard");

	/*Setting the date in YYYY-MM-DD format*/
	Date date_1(2020, 2, 10);
	Date date_2(2020, 2, 11);
	Date date_3(2020, 2, 15);
	Date date_4();

	book_Circulation(books_Archived, books_in_Circulation, date_1, date_2, date_3);








	while (date_1 != date_2) //checks whether the first date is equal to the second date
	{
		date_1.add_days(1); // adds a day to the first date
		if (date_1 == date_2) { // checks if the first date is equal to the second date
			break; // breaks the loop
		}
	}

	return 0;
}