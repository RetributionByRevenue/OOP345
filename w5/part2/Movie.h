/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop5: part 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/



#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
#include <string>
//#include "SpellChecker.h"

namespace sdds {

	class Movie {
		std::string m_title;
		size_t m_year = 0;
		std::string m_description;

	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);

		template<class T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}

		friend std::ostream& operator<< (std::ostream& os, const Movie& movie);

	};

}

#endif
