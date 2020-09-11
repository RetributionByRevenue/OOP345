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
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

#include <iostream>

namespace sdds {
	template<typename K, typename V>
	class Pair {
		K p_key;
		V p_value;
	public:
		Pair() {
			p_key = {};
			p_value = {};
		}

		Pair(const K& k, const V& v) {
			p_key = k;
			p_value = v;
		}

		const K& key() const {
			return p_key;
		}

		const V& value() const {
			return p_value;
		}

		void display(std::ostream& os) const {
			os << p_key << " : " << p_value << "\n";
		}
	};

	template<typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const Pair<K, V>& p) {
		p.display(os);
		return os;
	}
}

#endif //SDDS_PAIR_H