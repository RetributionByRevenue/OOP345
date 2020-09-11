/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop5: part 1
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/





#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

namespace sdds {
	class Book {
		string book_author;
		string book_title;
		string book_country;
		int book_year;
		double book_price;
		string book_desc;

	public:
		Book();

		const string title();

		const string country();

		const int year();

		double& price();

		Book(const string&);

		friend ostream& operator<<(ostream&, const Book&);
	};
}

#endif //SDDS_BOOK_H