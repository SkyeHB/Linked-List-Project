///////////////////////////////////////////////////////////////////////
//				 Name:	Skye Bragg									 //
//  Seneca Student ID:	107842171									 //
//		 Seneca email:	sbragg@myseneca.ca							 //
// Date of completion:	03/10/2020									 //
//																	 //
// I confirm that the content of this file is created by me,		 //
//   with the exception of the parts provided to me by my professor. //
///////////////////////////////////////////////////////////////////////

#ifndef SDDS_STATION_H__
#define SDDS_STATION_H__
#include <iostream>

//namespace sdds
//{
class Station
{
	static size_t s_widthField;
	static int id_generator;
	size_t s_stationID;
	std::string s_item;
	std::string s_description;
	size_t s_serialNo;
	size_t s_quantity;
public:
	Station();
	Station(const std::string& rec);
	virtual ~Station();
	const std::string& getItemName() const;
	size_t getNextSerialNumber();
	size_t getQuantity() const;
	void updateQuantity();
	virtual void display(std::ostream& os, bool full) const;
};
//}
#endif
