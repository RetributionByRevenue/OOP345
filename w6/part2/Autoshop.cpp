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
#include "Autoshop.h"
#include "Vehicle.h"

using namespace std;

namespace sdds {

	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const {

		auto ptr = m_vehicles.begin();
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;
		for (ptr = m_vehicles.begin(); ptr < m_vehicles.end(); ptr++) {
			(*ptr)->display(out);
			out << endl;
		}
		out << "--------------------------------" << endl;

	}

	Autoshop::~Autoshop() {
		//auto ptr = m_vehicles.begin();
		for (auto ptr = m_vehicles.begin(); ptr < m_vehicles.end(); ptr++)
			delete* ptr;
	}
}