/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop5: part 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/



#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>
#include <string>

namespace sdds {

	class SpellChecker {
		std::string m_badWords[5];
		std::string m_goodWords[5];

	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;

	};

}

#endif