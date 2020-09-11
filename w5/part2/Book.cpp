/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop5: part 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <string>
#include <iomanip>
#include "Book.h"

using namespace std;

namespace sdds {
	Book::Book() {
		mauthor = "";
		mtitle = "";
		mcountry = "";
		myear = 0;
		mprice = 0.0;
		msummary = "";
	}

	const std::string& Book::title() const {
		return mtitle;
	}

	const std::string& Book::country() const {
		return mcountry;
	}

	const size_t& Book::year() const {
		return myear;
	}

	double& Book::price() {
		return mprice;
	}

	void Book::setPrice(double input) {
		mprice = input;
	}

	Book::Book(const std::string& strBook) {
		//declare variables
		int beginIndex = 0;
		int endIndex = 0;
		const std::string WHITESPACE = " \n\r\t\f\v";


		//get author
		endIndex = strBook.find(",", beginIndex);
		mauthor = strBook.substr(beginIndex, endIndex);

		size_t start = mauthor.find_first_not_of(WHITESPACE);
		mauthor = (start == std::string::npos) ? "" : mauthor.substr(start);

		size_t end = mauthor.find_last_not_of(WHITESPACE);
		mauthor = (end == std::string::npos) ? "" : mauthor.substr(0, end + 1);

		//get title
		beginIndex = endIndex;

		endIndex = strBook.find(",", endIndex + 1);
		mtitle = strBook.substr(beginIndex + 1, endIndex - beginIndex - 1);

		start = mtitle.find_first_not_of(WHITESPACE);
		mtitle = (start == std::string::npos) ? "" : mtitle.substr(start);

		end = mtitle.find_last_not_of(WHITESPACE);
		mtitle = (end == std::string::npos) ? "" : mtitle.substr(0, end + 1);

		//get country
		beginIndex = endIndex;
		endIndex = strBook.find(",", endIndex + 1);
		mcountry = strBook.substr(beginIndex + 1, endIndex - beginIndex - 1);

		start = mcountry.find_first_not_of(WHITESPACE);
		mcountry = (start == std::string::npos) ? "" : mcountry.substr(start);

		end = mcountry.find_last_not_of(WHITESPACE);
		mcountry = (end == std::string::npos) ? "" : mcountry.substr(0, end + 1);
		//get price
		beginIndex = endIndex;
		endIndex = strBook.find(",", endIndex + 1);
		mprice = std::stod(strBook.substr(beginIndex + 1, endIndex - beginIndex - 1));

		//get year
		beginIndex = endIndex;
		endIndex = strBook.find(",", endIndex + 1);
		myear = std::stoi(strBook.substr(beginIndex + 1, endIndex - beginIndex - 1));

		//get summary
		beginIndex = endIndex;
		endIndex = strBook.find(",", endIndex + 1);
		msummary = strBook.substr(beginIndex + 1);

		start = msummary.find_first_not_of(WHITESPACE);
		msummary = (start == std::string::npos) ? "" : msummary.substr(start);

		end = msummary.find_last_not_of(WHITESPACE);
		msummary = (end == std::string::npos) ? "" : msummary.substr(0, end + 1);
	}

	std::ostream& operator<< (std::ostream& os, const Book& book) {
		os.width(20);
		os << std::right;
		os << book.mauthor;
		os << " | ";

		os.width(22);
		os << std::right;
		os << book.mtitle;
		os << " | ";

		os.width(5);
		os << std::right;
		os << book.mcountry;
		os << " | ";

		os.width(4);
		os << std::right;
		os << book.myear;
		os << " | ";

		os.width(6);
		os << std::fixed;
		os << std::setprecision(2);

		os << std::right;
		os << book.mprice;
		os << " | ";

		os << std::left;
		os << book.msummary;
		os << endl;

		return os;
	}


}