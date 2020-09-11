/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Milestones: 3
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Utilities.h"
#include "Station.h"
#include "CustomerOrder.h"

using namespace std;

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder() {
	m_name = "";
	m_product = "";
	m_cntItem = 0;
	m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(const std::string& str) {
	Utilities utility;
	size_t next_pos = 0;
	bool more = true;
	Item* list[1000];
	m_cntItem = 0;
	m_lstItem = nullptr;
	
	try {
		m_name = utility.extractToken(str, next_pos, more);
		m_product = utility.extractToken(str, next_pos, more);

		
		std::string tmpItem;
		while (more) {
			tmpItem = utility.extractToken(str, next_pos, more);
			list[m_cntItem] = new Item(tmpItem);
			m_cntItem++;
		}

		m_lstItem = new Item*[m_cntItem];

		for (unsigned int i=0; i < m_cntItem; i++) {
			m_lstItem[i] = list[i];
		}

		m_widthField = max(utility.getFieldWidth(), m_widthField);

	}
	catch (string& msg) {
		cout << msg;
	}

}

CustomerOrder::~CustomerOrder() {
	if (m_lstItem == nullptr) {
		return;
	}

	for (unsigned int i = 0; i < m_cntItem; i++) {
		delete m_lstItem[i];
	}

	delete[] m_lstItem;
}

bool CustomerOrder::isOrderFilled() const {
	for (unsigned int i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_isFilled == false) {
			return false;
		}
	}
	return true;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const {
	for (unsigned int i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName.compare(itemName) == 0) {
			return m_lstItem[i]->m_isFilled;
		}
	}
	return true;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os) {
	for (unsigned int i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName.compare(station.getItemName()) == 0) {
			if (station.getQuantity() > 0) {
				station.updateQuantity();
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;
				os << "    Filled "<<m_name<<", "<<m_product<<" [" << m_lstItem[i]->m_itemName <<"]"<< endl;
			}
			else {
				os << "    Unable to fill NAME, PRODUCT " << m_lstItem[i]->m_itemName << endl;
			}
		}
	}
}

void CustomerOrder::display(std::ostream& os) const {
	os << m_name <<" - " <<m_product<< endl;
	for (unsigned int i = 0; i < m_cntItem; i++) {
		os << "[" << setfill('0') << right<< setw(6) << m_lstItem[i]->m_serialNumber << "]"<<" ";

		os << setfill(' ') << left << setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";
		os << (m_lstItem[i]->m_isFilled ? "FILLED" : "MISSING") << endl;
	}
}
