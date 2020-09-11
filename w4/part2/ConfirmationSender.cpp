/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop4: part 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/

#include "ConfirmationSender.h"

namespace sdds {
    ConfirmationSender::ConfirmationSender() {
        cs_res_arr = nullptr;
        cs_count = 0;
    }

    ConfirmationSender::~ConfirmationSender() {
        delete[] cs_res_arr;
        cs_res_arr = nullptr;
    }

    int ConfirmationSender::size() const {
        return cs_count;
    }

    ConfirmationSender &ConfirmationSender::operator+=(Reservation &res) {
        bool found = false;
        if (cs_count <= 0) {
            cs_count++;
            cs_res_arr = new Reservation *[1];
            cs_res_arr[0] = &res;
        } else {
            for (int i = 0; i < cs_count; i++) {
                found = (&res == cs_res_arr[i]);
            }
            if (!found) {
                Reservation *temp_arr[10];
                for (int i = 0; i < cs_count; i++) {
                    temp_arr[i] = cs_res_arr[i];
                }
                cs_count++;
                delete[] cs_res_arr;
                cs_res_arr = nullptr;
                cs_res_arr = new Reservation *[cs_count];
                for (int i = 0; i < cs_count - 1; i++) {
                    cs_res_arr[i] = temp_arr[i];
                }
                cs_res_arr[cs_count - 1] = &res;
            }
        }
        return *this;
    }

    ConfirmationSender &ConfirmationSender::operator-=(Reservation &res) {
        bool found = false;
        int i = 0;
        if (cs_res_arr != nullptr) {
            while (i < cs_count && !found) {
                found = (&res == cs_res_arr[i++]);
            }
            if (found) {
                cs_res_arr[i - 1] = nullptr;
            }
        }
        return *this;
    }

    ostream &operator<<(ostream &os, ConfirmationSender &cs) {
        if (cs.cs_count == 0) {
            os << "--------------------------\n";
            os << "Confirmations to Send\n";
            os << "--------------------------\n";
            os << "The object is empty!\n";
            os << "--------------------------\n";
        } else {
            os << "--------------------------\n";
            os << "Confirmations to Send\n";
            os << "--------------------------\n";
            for (int i = 0; i < cs.size(); i++) {
                if (cs.cs_res_arr[i] != nullptr) {
                    os << *cs.cs_res_arr[i];
                }
            }
            os << "--------------------------\n";
        }
        return os;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender &cs) {
        if (cs.cs_res_arr != nullptr) {
            cs_res_arr = new Reservation *[cs.size()];
            for (int i = 0; i < cs.size(); ++i) {
                cs_res_arr[i] = cs.cs_res_arr[i];
            }
            cs_count = cs.cs_count;
        }
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender &&cs) {
        if (cs.cs_res_arr != nullptr) {
            swap(cs_res_arr, cs.cs_res_arr);
            cs_count = cs.cs_count;
            cs.cs_count = 0;
            cs.cs_res_arr = nullptr;
        }
    }
}