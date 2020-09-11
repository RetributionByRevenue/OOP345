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
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>

namespace sdds {

	template <class K, class V>
	class Pair {

		K keyz;
		V valuez;

	public:
		//default constructor
		Pair() : keyz{ 0 }, valuez{ 0 } {

		};
		// copies parameter values into instance variables
		Pair(const K& key, const V& value) {

			keyz = key;
			valuez = value;
		};
		// return key
		const K& key() const {

			return keyz;
		};
		//return value
		const V& value() const {
			return valuez;
		};
		virtual void display(std::ostream& os) const {

			os << keyz << " : " << valuez << std::endl;
		};

		friend std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
			pair.display(os);
			return os;

		};
	};




}
#endif