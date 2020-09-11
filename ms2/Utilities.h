/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Milestones: 2
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/


// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>



class Utilities {
	size_t m_widthField = 1;
	static char m_delimiter;
public:
	void setFieldWidth(size_t newWidth);
	size_t getFieldWidth() const;
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(char newDelimiter);
	static char getDelimiter();
};




#endif