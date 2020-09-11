/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop5: part 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/


#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>
#include <cstring>



namespace sdds {

	template < class T>
	class Collection {
		std::string m_name = "";
		T* m_result = nullptr;
		unsigned m_elements = 0;
		void (*m_observer)(const Collection<T>&, const T&) = nullptr;

	public:

		Collection(std::string name) {
			m_name = name;
			m_observer = nullptr;
		};

		~Collection() {
			delete[] m_result;
		};

		Collection(const Collection&) = delete;

		const std::string& name() const {
			return m_name;
		};

		size_t size() const {
			return m_elements;
		};

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_observer = observer;

			//std::cout << m_observer;
			//std::cout << observer;
		};

		Collection<T>& operator+=(const T& item) {

			bool found = false;


			for (size_t i = 0; i < m_elements; i++) {
				if (m_result[i].title() == item.title())
					found = true;
			}

			if (found) {
				return *this;
			}

			T* tmp = m_result;

			m_result = new T[m_elements + 1];
			for (size_t i = 0; i < m_elements; i++) {
				m_result[i] = tmp[i];
			}

			m_result[m_elements] = item;

			m_elements++;

			if (m_observer != nullptr) {
				m_observer(*this, item);
			}
			//std::cout << m_observer << std::endl;

			delete[] tmp;

			return *this;

		};

		T& operator[] (size_t idx) const {
			if (idx >= m_elements) {
				//throw "Bad index"+std::to_string(idx)+".Collection has"+ std::to_string(m_elements)+" items.";
				std::string s = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_elements) + "] items.";


				// declaring character array 


				// copying the contents of the 
				// string to char array 

				//char *char_array=nullptr;
				//strcpy(char_array, s.c_str());

				throw std::out_of_range(s);
				//throw "bad index";
			}

			return m_result[idx];
		};

		T* operator[](std::string title) const {
			for (size_t i = 0; i < m_elements; i++) {
				if (m_result[i].title() == title) {
					return &m_result[i];
				}
			}
			return nullptr;
		};


		friend std::ostream& operator<< (std::ostream& os, const Collection& collection) {
			for (size_t i = 0; i < collection.size(); i++) {
				os << collection[i];
			}
			return os;
		};

	};



}

#endif