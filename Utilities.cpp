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
#include <string>
#include "Utilities.h"

using namespace std;
//namespace sdds
//{
size_t Utilities::u_widthField = 0;
char Utilities::u_delimiter = '\0';
void Utilities::setFieldWidth(size_t newWidth)
{
	u_widthField = newWidth;
}
size_t Utilities::getFieldWidth() const
{
	return u_widthField;
}
string Utilities::extractToken(const string& str, size_t& next_pos, bool& more)
{
	string newStr = "";
	newStr = str.substr(next_pos, str.find_first_of(u_delimiter, next_pos) - next_pos);
	if (newStr == "")
	{
		more = true;
	}
	else if (newStr[0] == u_delimiter)
	{
		throw "exeption"; 
	}
	else
	{
		more = false;
	}
	if (u_widthField < newStr.length())
	{
		u_widthField = newStr.length();
	}
	return newStr;
}
void Utilities::setDelimiter(char newDelimiter)
{
	u_delimiter = newDelimiter;
}
char Utilities::getDelimiter()
{
	return u_delimiter;
}
//}