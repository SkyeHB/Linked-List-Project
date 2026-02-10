//Skye H Bragg

#include <iostream>
#include <iomanip>
#include <string>
#include "Workstation.h"

using namespace std;

Workstation::Workstation(const string rec) : Station(rec), w_pNextStation{ nullptr } {}
Workstation::~Workstation() {}
//If Item needs to be filled, item gets filled 
void Workstation::runProcess(ostream& os)
{
	if (!w_orders.empty())
	{
		if (w_orders.back().isOrderFilled() == false)
		{ 
			if (w_orders.back().isItemFilled(this->getItemName()) == false)
				{
					w_orders.back().fillItem(*this, os);
				}
			}
		}
}
bool Workstation::moveOrder()
{
	if (!w_orders.empty())
	{
		if (w_orders.back().isItemFilled(this->getItemName()))
		{
			if (w_pNextStation != nullptr)
			{
				w_pNextStation->operator+=(move(w_orders.back()));
				w_orders.pop_back();
			}
			return true;
		}
	}
	return false;
}
void Workstation::setNextStation(Workstation& station) 
{
	 w_pNextStation = &station; 
}
const Workstation* Workstation::getNextStation() const
{
	return w_pNextStation;
}
bool Workstation::getIfCompleted(CustomerOrder& order)
{
	if (!w_orders.empty())
	{
		if (w_orders.back().isOrderFilled())
		{
			order.operator=(move(w_orders.back()));
			w_orders.pop_back();
			return true;
		}
	}
	return false;
}
void Workstation::display(ostream& os) const
{
	if (w_pNextStation != nullptr)
	{
		os << this->getItemName() << " --> " << w_pNextStation->getItemName() << endl;
	}
	else
	{
		os << this->getItemName() << " --> END OF LINE" << endl;
	}
}
Workstation& Workstation::operator+=(CustomerOrder&& co)
{
	w_orders.push_front(move(co));
	return *this;
}

