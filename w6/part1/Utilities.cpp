/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop6: part 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Utilities.h"


using namespace std;

namespace sdds {

	Vehicle* createInstance(std::istream& in) {
		char buffer = in.get();
		while (buffer == ' ') {
			buffer = in.get();
		}

		in.putback(buffer);

		if (buffer == 'c' || buffer == 'C') {
			Car* temp2 = new Car(in);
			return temp2;
		}
		else {
			return nullptr;
		}
	}
}