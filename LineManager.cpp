//Skye H Bragg

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "LineManager.h"

using namespace std;

LineManager::LineManager(const string& fileName, std::vector<Workstation*>& wrk, std::vector<CustomerOrder>& cstOrd) : l_cntCustomerOrder{ 0 }
{
	ifstream fs;
	string key;
	string val;
	size_t i;
	size_t j;
	fs.open(fileName);
	for (i = 0; i < wrk.size(); i++)
	{
		AssemblyLine.push_back(wrk[i]);
	}
	while (!fs.eof())
	{
		getline(fs, key, '|');
		if (fs.peek() != EOF)
		{
			getline(fs, val, '\n');
		}
		else
		{
			val = "";
		}
		for (i = 0; i < AssemblyLine.size(); i++)
		{
			if (AssemblyLine[i]->getItemName() == key)
			{
				for (j = 0; j < AssemblyLine.size(); j++)
				{
					if (AssemblyLine[j]->getItemName() == val)
					{
						AssemblyLine[i]->setNextStation(*AssemblyLine[j]);
					}
				}
			}
		}
	}
	for (i = 0; i < cstOrd.size(); i++)
	{
		ToBeFilled.push_front(move(cstOrd[i]));
		l_cntCustomerOrder++;
	}
}
//fills Items and moves completed items to the completed vector
bool LineManager::run(ostream& os)
{
	static size_t cnt = 0;
	size_t i;
	cnt++;
	os << "Line Manager Iteration: " << cnt << endl;
	if (ToBeFilled.size() != 0)
	{
		AssemblyLine[5]->operator+=(move(ToBeFilled.back()));
		ToBeFilled.pop_back();
	}
	for (i = 0; i < AssemblyLine.size(); i++)
	{
		AssemblyLine[i]->runProcess(os);
	}
	for (i = 0; i < AssemblyLine.size(); i++)
	{
		if (AssemblyLine[i]->moveOrder() == true)
		{
			CustomerOrder cust;
			if (AssemblyLine[i]->getIfCompleted(cust))
			{
				Completed.push_back(move(cust));
			}
		}
	}
	if (Completed.size() == l_cntCustomerOrder)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void LineManager::displayCompletedOrders(ostream& os) const
{
	size_t i;
	for (i = 0; i < Completed.size(); i++)
	{
		Completed[i].display(os);
	}
}
void LineManager::displayStations() const
{
	size_t i;
	for (i = 0; i < AssemblyLine.size(); i++)
	{
		AssemblyLine[i]->display(cout);
	}
}
void LineManager::displayStationsSorted() const
{
	size_t i;
	const Workstation* ws;
	ws = AssemblyLine[5];
	for (i = 0; i < AssemblyLine.size(); i++)
	{
		ws->display(cout);
		ws = ws->getNextStation();
	}
}




