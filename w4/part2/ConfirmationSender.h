/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop4: part 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace sdds {
    class ConfirmationSender {
        Reservation **cs_res_arr;
        int cs_count;

    public:
        int size() const;

        ConfirmationSender();

        ~ConfirmationSender();

        ConfirmationSender(ConfirmationSender &);

        ConfirmationSender(ConfirmationSender &&);

        ConfirmationSender &operator+=(Reservation &);

        ConfirmationSender &operator-=(Reservation &);

        friend ostream &operator<<(ostream &, ConfirmationSender &);
    };
}

#endif //SDDS_CONFIRMATIONSENDER_H