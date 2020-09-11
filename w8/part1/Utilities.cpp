/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop8: part 1
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (size_t i = 0; i < desc.size(); ++i) {
			for (size_t j = 0; j < price.size(); ++j) {
				if (desc[i].code == price[j].code) {
					auto* tmp = new Product(desc[i].desc, price[j].price);
					tmp->validate();
					priceList += tmp;
					delete tmp;
				}
			}
		}
		return priceList;
	}
}