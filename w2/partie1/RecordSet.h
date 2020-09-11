/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop2: part 1
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/




#pragma once
#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <string>
#include <fstream>

using namespace std;

namespace sdds {
	class RecordSet {
	public:
		string* rs_strings;
		int rs_string_count;

		RecordSet();

		~RecordSet();

		RecordSet(char* given_str);

		RecordSet(const RecordSet& given_rs);

		RecordSet& operator=(const RecordSet& given_rs);

		size_t size();

		string getRecord(int given_t);
	};
}

#endif