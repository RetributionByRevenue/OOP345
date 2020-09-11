/**********************************************************
 * Name: stephane kamdem kamguia
 * Student ID: 135736189
 * Milestones: 3
 * Seneca email: skamdem-kamguia@myseneca.ca
 * Section: NAA
 **********************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>

#include "Utilities.h"
#include "Station.h"
#include "LineManager.h"

LineManager::LineManager(const std::string& filename, std::vector<Workstation*>& v_workstation, std::vector<CustomerOrder>& v_order) {
	std::ifstream file(filename);
	if (!file)
		throw std::string("Unable to open [") + filename + "] file.";

	std::string record;
	std::string first="";
	std::string second="";
	Utilities utility;
	size_t next_pos = 0;
	bool more = true;
	Workstation* first_w;
	Workstation* second_w;

	while (!file.eof())
	{
		std::getline(file, record);
		first = utility.extractToken(record, next_pos, more);
		if (more) {
			second = utility.extractToken(record, next_pos, more);
		}
		else {
			second = "";
		}

		first_w = nullptr;
		second_w = nullptr;

		for (std::size_t i = 0; i < v_workstation.size(); ++i) {
			if (v_workstation[i]->getItemName().compare(first) == 0) {
				first_w = v_workstation[i];
			}
			if (second.compare("") != 0 && v_workstation[i]->getItemName().compare(second) == 0) {
				second_w = v_workstation[i];
			}
		}

		if (second_w != nullptr) {
			first_w->setNextStation(*second_w);
		}

	}

	for (std::size_t i = 0; i < v_order.size(); ++i) {
		ToBeFilled.push_back(std::move(v_order[i]));
	}

	for (std::size_t i = 0; i < v_workstation.size(); ++i) {
		AssemblyLine.push_back(v_workstation[i]);
	}

	m_cntCustomerOrder = v_order.size();


}

bool LineManager::run(std::ostream& os) {
	static size_t count = 1;
	os << "Line Manager Iteration: " << count << std::endl;
	count++;

	if (!ToBeFilled.empty()) {
		int start = 0;
		for (std::size_t i = 0; i < AssemblyLine.size(); ++i) {
			start = i;
			for (std::size_t j = 0; j < AssemblyLine.size(); ++j) {
				
				if (AssemblyLine[j]->getNextStation() != nullptr && AssemblyLine[i]->getItemName().compare(AssemblyLine[j]->getNextStation()->getItemName()) == 0) {
					start = -1;
				}
			}

			if (start != -1) {
				break;
			}
		}

		*AssemblyLine[start]+=std::move(ToBeFilled.front());
		ToBeFilled.pop_front();

	}

	for (std::size_t i = 0; i < AssemblyLine.size(); ++i) {
		AssemblyLine[i]->runProcess(os);
	}

	for (std::size_t i = 0; i < AssemblyLine.size(); ++i) {
		if (AssemblyLine[i]->getNextStation() == nullptr)
		{
			CustomerOrder tmp;
			if (AssemblyLine[i]->getIfCompleted(tmp)) {
				Completed.push_back(std::move(tmp));
			}
		}
		else {
			AssemblyLine[i]->moveOrder();
		}
	}

	if (Completed.size() == m_cntCustomerOrder) {
		return true;
	}
	else
		return false;
}

void LineManager::displayCompletedOrders(std::ostream& os) const {
	for (std::size_t i = 0; i < Completed.size(); ++i) {
		Completed[i].display(os);
	}
}

void LineManager::displayStations() const {
	for (std::size_t i = 0; i < AssemblyLine.size(); ++i) {
		AssemblyLine[i]->display(std::cout);
	}
}

void LineManager::displayStationsSorted() const {
	int start = 0;
	for (std::size_t i = 0; i < AssemblyLine.size(); ++i) {
		start = i;
		for (std::size_t j = 0; j < AssemblyLine.size(); ++j) {

			if (AssemblyLine[j]->getNextStation()!=nullptr && AssemblyLine[i]->getItemName().compare(AssemblyLine[j]->getNextStation()->getItemName()) == 0) {
				start = -1;
			}
		}

		if (start != -1) {
			break;
		}
	}

	const Workstation* begin = AssemblyLine[start];

	while (begin != nullptr) {
		begin->display(std::cout);
		begin = begin->getNextStation();
	}
}