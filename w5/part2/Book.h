/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop5: part 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/



#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>
//#include "SpellChecker.h"

namespace sdds {

	class Book {
		std::string mauthor;
		std::string mtitle;
		std::string mcountry;
		size_t myear = 0;
		double mprice;
		std::string msummary;

	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		void setPrice(double);
		Book(const std::string& strBook);

		template<class T>
		void fixSpelling(T spellChecker) {
			spellChecker(msummary);
		}

		friend std::ostream& operator<< (std::ostream& os, const Book& book);

	};

}

#endif
