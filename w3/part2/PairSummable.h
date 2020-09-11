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
#ifndef SDDS_PAIRSUM_H
#define SDDS_PAIRSUM_H
#include <iostream>
#include <cstring>
#include "Pair.h"

namespace sdds {

	template <class K, class V>
	class PairSummable : public Pair<K, V> {

		static V initial;
		static size_t minfield;

	public:
		static const V& getInitialValue() {
			return initial;
		};

		PairSummable() : Pair<K, V>() {

		};

		PairSummable(const K& key, const V& value) :Pair<K, V>(key, value) {
			if (key.size() > minfield) {
				minfield = key.size();
			}
		};


		V sum(const K& key, const V& val) const {
			if (this->key() == key)
			{
				return this->value() + val;

			}
			else
				return val;
		};

		virtual void display(std::ostream& os) const {
			os.width(minfield);
			os << std::left;
			Pair<K, V>::display(os);
			os.width(0);
			os << std::right;
		};


	};

	template<> std::string PairSummable<std::string, std::string>::initial = "";
	template<> int PairSummable<std::string, int>::initial = 0;

	template<> std::string PairSummable<std::string, std::string>::sum(const std::string& key, const std::string& val) const {
		if (this->key() == key)
		{
			if (val[0] == '\0')
				return this->value();
			else
				return val + ", " + this->value();

		}
		else
			return val;

	}

	template<typename K, typename V>
	size_t PairSummable<K, V>::minfield = 0;


}




#endif
