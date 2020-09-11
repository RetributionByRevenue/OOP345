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
#include <fstream>
#include <sstream>
#include "SpellChecker.h"

using namespace std;

namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {

		std::ifstream file(filename);


		if (!file) {
			throw "Bad file name!";
		}



		std::string line;
		int count = 0;

		do
		{
			std::getline(file, line);

			// if the previous operation failed, the "file" object is
			//   in error mode
			if (file)
			{

				istringstream iss(line);
				string subs;
				iss >> subs;
				m_badWords[count] = subs;
				iss >> subs;
				m_goodWords[count] = subs;
				count++;
			}
		} while (file);
		file.close();
	}

	void SpellChecker::operator()(std::string& text) const {
		size_t n;
		for (int i = 0; i < 5; i++) {
			while ((n = text.find(m_badWords[i])) != std::string::npos) {
				text.replace(n, m_badWords[i].length(), m_goodWords[i]);
			}
		}
	}


}
