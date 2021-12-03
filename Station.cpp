///////////////////////////////////////////////////////////////////////
//				 Name:	Skye Bragg									 //
//  Seneca Student ID:	107842171									 //
//		 Seneca email:	sbragg@myseneca.ca							 //
// Date of completion:	03/10/2020									 //
//																	 //
// I confirm that the content of this file is created by me,		 //
//   with the exception of the parts provided to me by my professor. //
///////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <string>
#include "Station.h"
#include "Utilities.h"

using namespace std;
//namespace sdds
//{
int Station::id_generator = 1;
size_t Station::s_widthField = 0;
Station::Station() :s_stationID{ 0 }, s_item{ "" }, s_description{ "" }, s_serialNo{ 0 }, s_quantity{0} {}
Station::Station(const string& rec)
{
	Utilities util;
	bool more = true;
	size_t pos = 0;
	string tmp;
	s_stationID = id_generator;
	try
	{
		s_item = util.extractToken(rec, pos, more);
		pos += s_item.length() + 1;
		s_serialNo = stoi(util.extractToken(rec, pos, more));
		pos = rec.find_first_of(util.getDelimiter(), pos) + 1;
		s_quantity = stoi(util.extractToken(rec, pos, more));
		pos = rec.find_first_of(util.getDelimiter(), pos) + 1;
		s_description = rec.substr(pos);
		if (s_widthField > util.getFieldWidth())
		{
			util.setFieldWidth(s_widthField);
		}
		else
		{
			s_widthField = util.getFieldWidth();
		}
		id_generator++;
	}
	catch (...)
	{
		cout << "Delimiter error" << endl;
	}
}
Station::~Station() {}
const string& Station::getItemName() const
{
	return s_item;
}
size_t Station::getNextSerialNumber()
{
	return s_serialNo++;
}
size_t Station::getQuantity() const
{
	return s_quantity;
}
void Station::updateQuantity()
{
	if (s_quantity > 1)
	{
		s_quantity -= 1;
	}
}
void Station::display(std::ostream& os, bool full) const
{
	if (full)
	{
		os << "[" << right << setfill('0') << setw(3) << s_stationID << "] ";
		os << left << setfill(' ');
		os << "Item: " << setw(s_widthField) << left << s_item << " ";
		os << right << "[" << setfill('0') << setw(6) << s_serialNo << "]";
		os << left << setfill(' ') <<" Quantity: "  << setw(s_widthField)<< s_quantity;
		os << setw(s_widthField) << " Description: " << s_description << endl;
	}
	else
	{
		os << "[" << right << setfill('0') << setw(3) << s_stationID << "] ";
		os << left << setfill(' ');
		os << "Item: " << setw(s_widthField) << left << s_item << " ";
		os << right << "[" << setfill('0') << setw(6) << s_serialNo << "]" << endl;
	}
}
//}