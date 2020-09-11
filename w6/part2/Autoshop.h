/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop6: part 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/


#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include <functional>
#include "Vehicle.h"
#include <list>

namespace sdds {

	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
		template <class T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			//auto ptr = m_vehicles.begin();
			for (auto ptr = m_vehicles.begin(); ptr < m_vehicles.end(); ptr++) {
				if (test(*ptr)) {
					vehicles.push_back(*ptr);
				}
			}

		}

	};

}

#endif