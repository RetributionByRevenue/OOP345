/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Milestones: 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/

// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <algorithm>
#include "Utilities.h"

using namespace std;


char Utilities::m_delimiter = ' ';

void Utilities::setFieldWidth(size_t newWidth) {
	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

	string tmp = "";
	size_t first_pos = next_pos;
	//cout << str << first_pos<<"-----"<< next_pos<<endl;

	next_pos = str.find(m_delimiter, first_pos);

	if (next_pos == string::npos) {
		tmp = str.substr(first_pos);
		m_widthField = max(tmp.length(), m_widthField);
		more = false;
	}
	else if (first_pos == next_pos)
	{
		more = false;
		throw "No token between delimiters!";
	}
	else {
		tmp = str.substr(first_pos, next_pos - first_pos);
		m_widthField = max(tmp.length(), m_widthField);
		more = true;
	}
	next_pos++;
	return tmp;

}

void Utilities::setDelimiter(char newDelimiter) {
	m_delimiter = newDelimiter;
}

char Utilities::getDelimiter() {
	return m_delimiter;
}