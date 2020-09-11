/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop4: part 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include "Reservation.h"

namespace sdds {
    class Restaurant {
        Reservation *rest_reserves;
        int rest_num;
    public:
        Restaurant();

        ~Restaurant();

        Restaurant(Reservation *[], int);

        Restaurant(const Restaurant &);

        Restaurant(Restaurant&&);

        int size() const;

        friend ostream &operator<<(ostream &, const Restaurant &);
    };

}


#endif //SDDS_RESTAURANT_H