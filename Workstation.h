///////////////////////////////////////////////////////////////////////
//				 Name:	Skye Bragg									 //
//  Seneca Student ID:	107842171									 //
//		 Seneca email:	sbragg@myseneca.ca							 //
// Date of completion:	04/09/2020									 //
//																	 //
// I confirm that the content of this file is created by me,		 //
//   with the exception of the parts provided to me by my professor. //
///////////////////////////////////////////////////////////////////////

#ifndef SDDS_WORKSTATION_H__
#define SDDS_WORKSTATION_H__
#include <iostream>
#include <string>
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"

//namespace sdds
//{
class Workstation : public Station
{
	std::deque<CustomerOrder> w_orders;
	Workstation* w_pNextStation;
public:
	Workstation(const std::string rec);
	virtual ~Workstation();
	Workstation(const Workstation&) = delete;
	Workstation(Workstation&& src) = delete;
	Workstation& operator= (const Workstation&) = delete;
	Workstation& operator= (Workstation&& src) = delete;
	void runProcess(std::ostream& os);
	bool moveOrder();
	void setNextStation(Workstation& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream&) const;
	Workstation& operator+=(CustomerOrder&&);
};
//}
#endif
