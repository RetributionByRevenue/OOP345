/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Workshop2: part 1
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.*/



#include "RecordSet.h"

namespace sdds {
	RecordSet::RecordSet() {
		rs_strings = nullptr;
		rs_string_count = 0;
	}

	RecordSet::~RecordSet() {
		delete[] rs_strings;
		rs_strings = nullptr;
	}

	RecordSet::RecordSet(char* given_str) {
		string _buffer;
		ifstream file(given_str);
		int i = 0;
		while (!file.eof()) {
			getline(file, _buffer, ' ');
			++i;
		}
		rs_strings = new string[i + 1];
		_buffer = {};
		file.close();
		file.open(given_str);
		i = 0;
		while (getline(file, _buffer, ' ')) {
			rs_strings[i] = _buffer;
			++i;
		}
		rs_string_count = i;
	}

	RecordSet::RecordSet(const RecordSet& given_rs) {
		*this = given_rs;
	}

	RecordSet& RecordSet::operator=(const RecordSet& given_rs) {
		rs_string_count = given_rs.rs_string_count;
		rs_strings = new string[rs_string_count];
		for (int i = 0; i < rs_string_count; ++i) {
			rs_strings[i] = given_rs.rs_strings[i];
		}
		return *this;
	}

	size_t RecordSet::size() {
		return rs_string_count;
	}

	string RecordSet::getRecord(int given_t) {
		if (rs_strings != nullptr) {
			return string(rs_strings[given_t]);
		}
		else {
			return "";
		}
	}
}