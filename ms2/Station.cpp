/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Milestones: 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Utilities.h"
#include "Station.h"

using namespace std;



size_t Station::m_widthField = 0;
int Station::id_generator = 1;

Station::Station(const std::string& str) {
	m_id = id_generator;

	Utilities utility;
	size_t next_pos = 0;
	bool more = true;

	try {
		m_name = utility.extractToken(str, next_pos, more);
		m_serial = stoi(utility.extractToken(str, next_pos, more));
		m_current = stoi(utility.extractToken(str, next_pos, more));
		m_widthField = max(utility.getFieldWidth(), m_widthField);
		m_desc = utility.extractToken(str, next_pos, more);
	}
	catch (string& msg) {
		cout << msg;
	}



	id_generator++;

}

const std::string& Station::getItemName() const {
	return m_name;
}

unsigned int Station::getNextSerialNumber() {
	m_serial++;
	return m_serial - 1;
}

unsigned int Station::getQuantity() const {
	return m_current;
}

void Station::updateQuantity() {
	m_current--;
	if (m_current < 0) {
		m_current = 0;
	}
}

void Station::display(std::ostream& os, bool full) const {
	ios init(NULL);
	init.copyfmt(cout);
	os << right;
	os << "[";
	os << setw(3);
	os << setfill('0');
	os << m_id;
	os << "]";
	os << left;

	os << " Item: ";
	os << setw(m_widthField);
	os << setfill(' ');
	os << m_name;
	os << right;

	os << " [";
	os << setw(6);
	os << setfill('0');
	os << m_serial;
	os << "]";
	os << left;

	if (full == false) {
		os << endl;

	}
	else {
		os << " Quantity: ";
		os << setw(m_widthField);
		os << setfill(' ');
		os << m_current;

		os << " Description: ";
		os.copyfmt(init);
		os << m_desc;
		os << endl;


	}
}
