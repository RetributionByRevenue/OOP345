/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop8: part 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/


#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include "List.h"
#include "Element.h"

namespace sdds {
	// both functions recieve a list of Description objects and Price 
	// objects this function creates a list of Products from the matching
	// codes from the two recieved lists
	List<Product> mergeRaw(const List<Description>& desc, 
						const List<Price>& price);

	List<Product> mergeSmart(const List<Description>& desc, 
						const List<Price>& price);
}

#endif // SDDS_UTILITIES_H