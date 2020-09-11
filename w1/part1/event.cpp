/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop: part 1
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include "even.h"

unsigned long g_sysClock;

namespace sdds {

	Event::Event() {
		desc[0] = '\0';
		seconds = 0;
	}

	void Event::display() {
		static int count = 1;
		int hh = 0, mm = 0, ss = 0;

		hh = seconds / 3600;
		mm = seconds / 60 % 60;
		ss = seconds % 60;

		if (desc[0] == '\0') {
			cout << setw(3) << setfill(' ') << count << ". " << "[ No Event ]\n";
		}
		else {
			cout << setw(3) << setfill(' ') << count << ". " << setw(2) << setfill('0') << hh << ":" << setw(2)
				<< setfill('0') << mm << ":" << setw(2) << setfill('0') << ss << " -> " << desc << "\n";
		}
		count++;
	}

	void Event::setDescription(char arr_in[]) {
		// if arr_in is empty:
		if (arr_in == nullptr || strlen(arr_in) == 0) {
			desc[0] = '\0';
			seconds = 0;
		}
		else { // if arr_in not empty
			strcpy(desc, arr_in);
			seconds = ::g_sysClock;
		}
	}
}