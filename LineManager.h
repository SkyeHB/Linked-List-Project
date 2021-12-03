///////////////////////////////////////////////////////////////////////
//				 Name:	Skye Bragg									 //
//  Seneca Student ID:	107842171									 //
//		 Seneca email:	sbragg@myseneca.ca							 //
// Date of completion:	04/09/2020									 //
//																	 //
// I confirm that the content of this file is created by me,		 //
//   with the exception of the parts provided to me by my professor. //
///////////////////////////////////////////////////////////////////////

#ifndef SDDS_LINEMANAGER_H__
#define SDDS_LINEMANAGER_H__
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include "Workstation.h"

//namespace sdds
//{
class LineManager
{
	std::vector<Workstation*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	size_t l_cntCustomerOrder;
public:
	LineManager(const std::string& fileName, std::vector<Workstation*> &wrk, std::vector<CustomerOrder> &cstOrd);
	bool run(std::ostream& os);
	void displayCompletedOrders(std::ostream& os) const;
	void displayStations() const;
	void displayStationsSorted() const;
};
//}
#endif
