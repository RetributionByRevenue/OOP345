/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: part 1
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

/*I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.*/

#pragma once
#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

extern unsigned long g_sysClock;

namespace sdds {
	class Event {
	private:
		char desc[128];
		unsigned long seconds;
	public:
		Event();

		void display();

		void setDescription(char arr_in[]);
	};
}

#endif
