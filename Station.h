//Skye H Bragg

#ifndef SDDS_STATION_H__
#define SDDS_STATION_H__
#include <iostream>


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

#endif

