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
#include "Racecar.h"

using namespace std;

namespace sdds {
	Racecar::Racecar(std::istream& in) :Car(in) {
		char ch;
		in >> ch >> m_booster;


	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + m_booster);
	}


}