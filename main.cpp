#include <queue>
#include <iostream>
#include <list>
#include "Date.h";

using namespace std;

class Employee {
    public:
        string name;
        int waiting;
        int retaining;
};

class Book {
    public:
        string name;
        //Date start;
        //Date finish;
        Employee reader;
        queue<Employee> line;
};

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
    /*Initializes all of the employees, as well as pushing them to their list*/
	list<Employee> company;
	Employee sam;
	sam.name = "Sam";
	sam.waiting = 0;
	sam.retaining = 0;

	Employee dan;
	dan.name = "Dan";
	dan.waiting = 0;
	dan.retaining = 0;

	Employee jade;
	jade.name = "Jade";
	jade.waiting = 0;
	jade.retaining = 0;

	Employee greg;
	greg.name = "Greg";
	greg.waiting = 0;
	greg.retaining = 0;

	Employee rob;
	rob.name = "Rob";
	rob.waiting = 0;
	rob.retaining = 0;

	Employee joe;
	joe.name = "Joe";
	joe.waiting = 0;
	joe.retaining = 0;

	Employee lisa;
	lisa.name = "Lisa";
	lisa.waiting = 0;
	lisa.retaining = 0;

	Employee mark;
	mark.name = "Mark";
	mark.waiting = 0;
	mark.retaining = 0;

	company.push_back(sam);
	company.push_back(dan);
	company.push_back(jade);
	company.push_back(greg);
	company.push_back(rob);
	company.push_back(joe);
	company.push_back(lisa);
	company.push_back(mark);

	/*Initializes all of the books, as well as pushes them to the library*/
	Book library [5];
	Book archive [5];
	Book a;
	a.name = "How to Code with Python";
	Book b;
	a.name = "How to Code with Java";
	Book c;
	a.name = "How to Code with C++";
	Book d;
	a.name = "The Second Coming of Gluttony";
	Book e;
	a.name = "Overgeared";

	library.push_back(a);
	library.push_back(b);
	library.push_back(c);
	library.push_back(d);
	library.push_back(e);

	for (int i = 0; i < library.size(); i++) {
	    for (int j = 0; j < company.size(); j++)
	    {
	        library
	    }
	}

	/*Setting the starting date in YYYY-MM-DD format*/



	/**
	while (archive.size() < 5)
	{
	    current_date.add_days(1); //A new day has past!
	    for
	}

    **/

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


