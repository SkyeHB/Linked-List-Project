//Skye H Bragg

#ifndef SDDS_UTILITIES_H__
#define SDDS_UTILITIES_H__
#include <iostream>

	class Utilities
	{
		static size_t u_widthField;
		static char u_delimiter;
	public:
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};

#endif
