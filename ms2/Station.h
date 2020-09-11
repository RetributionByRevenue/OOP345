/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Milestones: 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>



class Station {
	int m_id;
	std::string m_name;
	std::string m_desc;
	int m_serial;
	int m_current;
	static size_t m_widthField;
	static int id_generator;
public:
	Station(const std::string&);
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;


};






#endif