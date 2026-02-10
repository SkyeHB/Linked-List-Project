//Skye H Bragg

#ifndef SDDS_CUSTOMERORDER_H__
#define SDDS_CUSTOMERORDER_H__
#include <iostream>
#include <string>
#include "Station.h"

	struct Item
	{
		std::string m_itemName;
		unsigned int m_serialNumber = 0;
		bool m_isFilled = false;

		Item(const std::string& src) : m_itemName(src) {};
	};
	class CustomerOrder
	{
		std::string c_name;
		std::string c_product;
		size_t c_cntItem;
		Item** c_lstItem;
		static size_t c_widthField;
	public:
		CustomerOrder();
		CustomerOrder(const std::string& rec);
		CustomerOrder(const CustomerOrder&);
		CustomerOrder(CustomerOrder&& src) noexcept; 
		CustomerOrder& operator= (const CustomerOrder&) = delete;
		CustomerOrder& operator= (CustomerOrder&& src) noexcept;
		virtual ~CustomerOrder();
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};

#endif


