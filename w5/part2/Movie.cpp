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
#include "Movie.h"

using namespace std;

namespace sdds {
	Movie::Movie() {
		m_title = "";
		m_year = 0;
		m_description = "";
	}

	const std::string& Movie::title() const {
		return m_title;
	}

	Movie::Movie(const std::string& strMovie) {
		//declare variables
		int beginIndex = 0;
		int endIndex = 0;
		const std::string WHITESPACE = " \n\r\t\f\v";

		//get title
		endIndex = strMovie.find(",", beginIndex);
		m_title = strMovie.substr(beginIndex, endIndex);

		size_t start = m_title.find_first_not_of(WHITESPACE);
		m_title = (start == std::string::npos) ? "" : m_title.substr(start);

		size_t end = m_title.find_last_not_of(WHITESPACE);
		m_title = (end == std::string::npos) ? "" : m_title.substr(0, end + 1);

		//get year
		beginIndex = endIndex;
		endIndex = strMovie.find(",", endIndex + 1);
		m_year = std::stoi(strMovie.substr(beginIndex + 1, endIndex - beginIndex - 1));

		//get summary
		beginIndex = endIndex;
		endIndex = strMovie.find(",", endIndex + 1);
		m_description = strMovie.substr(beginIndex + 1);

		start = m_description.find_first_not_of(WHITESPACE);
		m_description = (start == std::string::npos) ? "" : m_description.substr(start);

		end = m_description.find_last_not_of(WHITESPACE);
		m_description = (end == std::string::npos) ? "" : m_description.substr(0, end + 1);
	}

	std::ostream& operator<< (std::ostream& os, const Movie& movie) {

		os.width(40);
		os << std::right;
		os << movie.m_title;
		os << " | ";

		os.width(4);
		os << std::right;
		os << movie.m_year;
		os << " | ";

		os << std::left;
		os << movie.m_description;
		os << endl;

		return os;
	}


}