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
#include "Car.h"

using namespace std;

namespace sdds {
	Car::Car(std::istream& is) {

		std::string record;
		char buffer[4096];

		is.getline(buffer, sizeof(buffer));
		record.append(buffer, sizeof(buffer));
		record.append(buffer, is.gcount());


		int beginIndex = 0;
		int endIndex = 0;
		const std::string WHITESPACE = " \n\r\t\f\v";


		//get tag
		endIndex = record.find(",", beginIndex);
		std::string tag = record.substr(beginIndex, endIndex);

		size_t start = tag.find_first_not_of(WHITESPACE);
		tag = (start == std::string::npos) ? "" : tag.substr(start);

		size_t end = tag.find_last_not_of(WHITESPACE);
		tag = (end == std::string::npos) ? "" : tag.substr(0, end + 1);

		if (tag != "C" && tag != "c") {
			maker = "";
			cond = "";
			tSpeed = 0.00;
			return;
		}

		//get maker
		beginIndex = endIndex;

		endIndex = record.find(",", endIndex + 1);
		maker = record.substr(beginIndex + 1, endIndex - beginIndex - 1);

		start = maker.find_first_not_of(WHITESPACE);
		maker = (start == std::string::npos) ? "" : maker.substr(start);

		end = maker.find_last_not_of(WHITESPACE);
		maker = (end == std::string::npos) ? "" : maker.substr(0, end + 1);

		//get condition
		beginIndex = endIndex;

		endIndex = record.find(",", endIndex + 1);
		cond = record.substr(beginIndex + 1, endIndex - beginIndex - 1);

		start = cond.find_first_not_of(WHITESPACE);
		cond = (start == std::string::npos) ? "" : cond.substr(start);

		end = cond.find_last_not_of(WHITESPACE);
		cond = (end == std::string::npos) ? "" : cond.substr(0, end + 1);

		if (cond == "n") {
			cond = "new";
		}

		if (cond == "u") {
			cond = "used";
		}

		if (cond == "b") {
			cond = "broken";
		}

		//get topSpeed
		beginIndex = endIndex;
		//endIndex = record.find(",", endIndex + 1);
		std::string speed = record.substr(beginIndex + 1);

		start = speed.find_first_not_of(WHITESPACE);
		speed = (start == std::string::npos) ? "" : speed.substr(start);

		end = speed.find_last_not_of(WHITESPACE);
		speed = (end == std::string::npos) ? "" : speed.substr(0, end + 1);

		try
		{
			tSpeed = std::stod(speed);

		}
		catch (std::exception& ia)
		{
			tSpeed = 0;
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
		out << std::right;
		out.width(10);
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
		out << tSpeed;
		out << " |";
		out << endl;



	}
}