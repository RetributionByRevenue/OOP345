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
#include <string>
#include "Car.h"

using namespace std;

namespace sdds {


	void Car::trim(string& str)const {
		size_t i = 0;
		for (i = 0; i < str.length() && str[i] == ' '; i++);

		str = str.substr(i);

		for (i = str.length(); i > 0 && str[i - 1] == ' '; i--);
		str = str.substr(0, i);

	}

	Car::Car(std::istream& is) {
		std::string substr = "";

		getline(is, maker, ',');
		trim(maker);


		getline(is, substr, ',');
		trim(substr);
		if (substr == "n" || substr == "N" || substr == "") {
			cond = "new";
		}

		else if (substr == "u" || substr == "U") {
			cond = "used";
		}
		else if (substr == "b" || substr == "B") {
			cond = "broken";
		}
		else {
			throw "Invalid Record!";

		}

		size_t start = 0;
		size_t begin = substr.find(',', start);
		std::getline(is, substr, ',');
		start = begin;
		begin = substr.find(',', start + 1);
		try {
			tSpeed = std::stod(substr.substr(start + 1, begin - start - 1));

		}
		catch (...) {
			throw "Invalid Record!";

		}

	}


	std::string Car::condition() const {
		return cond;

	}

	double Car::topSpeed() const {
		return tSpeed;
	}

	void Car::display(std::ostream& out) const {
		out << "| ";
		out.width(10);
		out << std::right;
		out << maker;
		out << " | ";

		out.width(6);
		out << std::left;
		out << cond;
		out << " | ";

		out.width(6);
		out << std::right;
		out << std::fixed;
		out << std::setprecision(2);
		out << topSpeed();
		out << " |";
		//out << endl;

	}

}