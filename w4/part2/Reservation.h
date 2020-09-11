/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop4: part 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>

using namespace std;

namespace sdds {
    class Reservation {
    protected:
        string res_id;
        string res_name;
        string res_email;
        int res_people;
        int res_day;
        int res_hour;
    public:
        Reservation();

        Reservation(const string &res);

        friend ostream &operator<<(ostream &os, Reservation &res);
    };
}

#endif