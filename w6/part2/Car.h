/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop6: part 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/




#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include "Vehicle.h"
using namespace std;
namespace sdds {


	class Car : public Vehicle {
		std::string maker;
		std::string cond;
		double tSpeed;
	public:
		Car(std::istream&);
		Car();
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		void trim(std::string& str) const;
	};

}

#endif