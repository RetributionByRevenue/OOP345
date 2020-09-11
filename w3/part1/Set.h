/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop3: part 1
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/



#pragma once
#ifndef SDDS_SET_H
#define SDDS_SET_H

#include <cstring>

namespace sdds {
	template<typename T, unsigned int N>
	class Set {
		T arr[N];
		size_t count;
	public:
		Set() {
			count = 0;
		}

		size_t size() const {
			return count;
		}

		const T& operator[](size_t pos) const {
			return arr[pos];
		}

		void operator+=(const T& i) {
			if (count < N) {
				arr[count] = i;
				count++;
			}
		}
	};
}

#endif //SDDS_SET_H