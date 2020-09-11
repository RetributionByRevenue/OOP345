
// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: 
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include <iostream>

struct Item
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};

class CustomerOrder
{
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	Item** m_lstItem;
	static size_t m_widthField;
public:
	CustomerOrder();
	CustomerOrder(const std::string&);

	CustomerOrder(const CustomerOrder& p2) { throw "NO COPY CONSTRUCTOR ALLOWED!!!"; };
	CustomerOrder& operator=(const CustomerOrder& other) = delete;

	CustomerOrder(CustomerOrder&& a) noexcept
	{
		m_name = a.m_name;
		m_product = a.m_product;
		m_cntItem = a.m_cntItem;

		m_lstItem = a.m_lstItem;
		a.m_lstItem = nullptr;
	}
	CustomerOrder& operator=(CustomerOrder&& a) noexcept
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		//
		if (m_lstItem == nullptr) {
		}
		else{
			for (unsigned int i = 0; i < m_cntItem; i++) {
				delete m_lstItem[i];
			}
		}	

		delete[] m_lstItem;

		m_name = a.m_name;
		m_product = a.m_product;
		m_cntItem = a.m_cntItem;

		m_lstItem = a.m_lstItem;
		a.m_lstItem = nullptr; 

		return *this;
	}

	~CustomerOrder();
	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os);
	void display(std::ostream& os) const;


};
#endif

