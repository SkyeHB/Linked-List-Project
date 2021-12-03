///////////////////////////////////////////////////////////////////////
//				 Name:	Skye Bragg									 //
//  Seneca Student ID:	107842171									 //
//		 Seneca email:	sbragg@myseneca.ca							 //
// Date of completion:	04/02/2020									 //
//																	 //
// I confirm that the content of this file is created by me,		 //
//   with the exception of the parts provided to me by my professor. //
///////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <string>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;
//namespace sdds
//{ 
size_t CustomerOrder::c_widthField = 0;
CustomerOrder::CustomerOrder() : c_name{ "" }, c_product{ "" }, c_cntItem{ 0 }, c_lstItem{ nullptr } {}
CustomerOrder::CustomerOrder(const string& rec) : c_name{ "" }, c_product{ "" }, c_cntItem{ 0 }, c_lstItem{ nullptr }
{
	Utilities util;
	bool tok = true;
	size_t pos = 0;
	size_t i = 0;
	string tmp;
	Item** tmpItem;
	tmpItem = new Item * [30];
	c_name = util.extractToken(rec, pos, tok);
	pos += c_name.length() + 1;
	c_product = util.extractToken(rec, pos, tok);
	pos += c_product.length() + 1;
	while (pos != rec.size() + 1)
	{
		tmp = util.extractToken(rec, pos, tok);
		pos += tmp.length() + 1;
		tmpItem[i] = new Item(tmp);
		i++;
		c_cntItem++;
	}
	c_lstItem = new Item * [c_cntItem];
	for (i = 0; i < c_cntItem; i++)
	{
		c_lstItem[i] = tmpItem[i];
	}
	delete[] tmpItem;
	if (c_widthField < util.getFieldWidth())
	{
		c_widthField = util.getFieldWidth();
	}
}
CustomerOrder::CustomerOrder(const CustomerOrder&) : c_name{ "" }, c_product{ "" }, c_cntItem{ 0 }, c_lstItem{ nullptr }
{
	string excp = "bad";
	throw excp;
}
CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept : c_name{ "" }, c_product{ "" }, c_cntItem{ 0 }, c_lstItem{ nullptr }
{
	*this = move(src);
}
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
{
	if (this != &src)
	{
		size_t i;
		if (c_lstItem != nullptr)
		{
			for (i = 0; i < c_cntItem; i++)
			{
				delete c_lstItem[i];
			}
		}
		delete[] c_lstItem;
		c_name = src.c_name;
		c_product = src.c_product;
		c_cntItem = src.c_cntItem;
		c_lstItem = src.c_lstItem;
		src.c_name = "";
		src.c_product = "";
		src.c_cntItem = 0;
		src.c_lstItem = nullptr;
	}
	return *this;
}
CustomerOrder::~CustomerOrder()
{
	size_t i;
	for (i = 0; i < c_cntItem; i++)
	{
		delete c_lstItem[i];
	}
	delete[] c_lstItem;
}
bool CustomerOrder::isOrderFilled() const
{
	size_t i;
	for (i = 0; i < c_cntItem; i++)
	{
		if (c_lstItem[i]->m_isFilled == false)
		{
			return false;
		}
	}
	return true;
}
bool CustomerOrder::isItemFilled(const string& itemName) const
{
	size_t i;
	for (i = 0; i < c_cntItem; i++)
	{
		if (c_lstItem[i]->m_itemName == itemName)
		{
			return c_lstItem[i]->m_isFilled;
		}
	}
	return true;
}
void CustomerOrder::fillItem(Station& station, ostream& os)
{
	size_t i;
	for (i = 0; i < c_cntItem; i++)
	{
		if (station.getItemName() == c_lstItem[i]->m_itemName && station.getQuantity() <= 0)
		{
			os << "    Unable to fill " << c_name << ", " << c_product << " [" << c_lstItem[i]->m_itemName << "]" << endl;
		}
		else if (station.getItemName() == c_lstItem[i]->m_itemName)
		{
			station.updateQuantity();
			c_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
			c_lstItem[i]->m_isFilled = true;
			os << "    Filled " << c_name << ", " << c_product << " [" << c_lstItem[i]->m_itemName << "]" << endl;
		}
	}
}
void CustomerOrder::display(ostream& os) const
{
	size_t i;
	os << c_name << " - " << c_product << endl;
	for (i = 0; i < c_cntItem; i++)
	{
		if (c_lstItem[i]->m_isFilled == true)
		{
			os << "[" << right << setw(6) << setfill('0') << c_lstItem[i]->m_serialNumber << "] ";
			os << setfill(' ') << setw(c_widthField) << left << c_lstItem[i]->m_itemName;
			os << " - FILLED" << endl;
		}
		else
		{
			os << "[" << setw(6) << setfill('0') << c_lstItem[i]->m_serialNumber << "] ";
			os << setfill(' ') << setw(c_widthField) << c_lstItem[i]->m_itemName;
			os << " - MISSING" << endl;
		}
	}
}
//}