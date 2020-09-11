/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop5: part 1
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/




#include "Book.h"

namespace sdds {
	Book::Book() {
		book_author = "";
		book_title = "";
		book_country = "";
		book_desc = "";
		book_year = 0;
		book_price = 0.0;
	}

	const string Book::title() {
		return book_title;
	}

	const string Book::country() {
		return book_country;
	}

	const int Book::year() {
		return book_year;
	}

	double& Book::price() {
		return book_price;
	}

	Book::Book(const string& _book) {
		string author, title, country, price, year, desc;
		string str = _book;

		// Get info from _book
		author = str.substr(0, str.find(','));

		str.erase(0, str.find(',') + 1);
		title = str.substr(0, str.find(','));

		str.erase(0, str.find(',') + 1);
		country = str.substr(0, str.find(','));

		str.erase(0, str.find(',') + 1);
		price = str.substr(0, str.find(','));

		str.erase(0, str.find(',') + 1);
		year = str.substr(0, str.find(','));

		str.erase(0, str.find(',') + 1);
		desc = str;

		// trim whitespace
		author.erase(author.find_last_not_of(' ') + 1);
		author.erase(0, author.find_first_not_of(' '));

		title.erase(title.find_last_not_of(' ') + 1);
		title.erase(0, title.find_first_not_of(' '));

		country.erase(country.find_last_not_of(' ') + 1);
		country.erase(0, country.find_first_not_of(' '));

		desc.erase(desc.find_last_not_of(' ') + 1);
		desc.erase(0, desc.find_first_not_of(' '));

		// assign temp variables to class variables
		book_author = author;
		book_title = title;
		book_country = country;
		book_price = stod(price);
		book_year = stoi(year);
		book_desc = desc;
	}

	ostream& operator<<(ostream& os, const Book& _book) {
		os << setw(20) << setfill(' ') << _book.book_author << " | ";
		os << setw(22) << setfill(' ') << _book.book_title << " | ";
		os << setw(5) << setfill(' ') << _book.book_country << " | ";
		os << setw(4) << setfill(' ') << _book.book_year << " | ";
		os << setw(6) << setfill(' ') << fixed << setprecision(2) << _book.book_price << " | ";
		os << setw(22) << setfill(' ') << _book.book_desc;
		os << '\n';
		return os;
	}
}