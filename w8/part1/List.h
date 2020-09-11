/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop8: part 1
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_LIST_H
#define SDDS_LIST_H



#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class List {
		std::vector <T> list;
	public:
		List() {}

		List(const char* fn) {
			std::ifstream file(fn);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(fn) + std::string(" ***");
			while (file) {
				T e;
				if (e.load(file))
					list.push_back(T(e));
			}
		}

		size_t size() const { return list.size(); }

		const T& operator[](size_t i) const { return list[i]; }

		// TODO: Overload the += operator with a raw pointer
		//       as a second operand.

		void operator+=(T* t) {
			list.push_back(*t);
		}

		void display(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.display(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const List<T>& l) {
		l.display(os);
		return os;
	}
}
#endif