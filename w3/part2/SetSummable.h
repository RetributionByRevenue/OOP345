/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop3: part 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/




#pragma once
#ifndef SDDS_SETSUM_H
#define SDDS_SETSUM_H
#include <iostream>
#include "Set.h"

namespace sdds {

	template <class T, unsigned int N, class K, class V >
	class SetSummable : public Set<T, N> {
	public:
		V accumulate(const K& key) const {
			V accumulator;
			accumulator = T::getInitialValue();
			for (unsigned int i = 0; i < this->size(); i++) {
				accumulator = (*this)[i].sum(key, accumulator);
			}
			return accumulator;

		};

	};
}
#endif
