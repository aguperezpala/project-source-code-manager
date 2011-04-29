/*
 * test_StringParser.cpp
 *
 *  Created on: 29/04/2011
 *      Author: agustin
 */

#include <iostream>
#include <string>
#include "DebugUtil.h"
#include "StringParser.h"



int main(void)
{
	std::string data = "KEY1 =  value1, value1.1 |value2|value3|aa\noeoe;";
	std::string result;
	char c;

	if(StringParser::getString(0,data.size(),"KEY1",";",data,result) == std::string::npos){
		std::cout << "Error parsing: " << data << std::endl;
		return 1;
	}
	std::cout << "\nResult = " << result << std::endl;

	std::cout << "Parsing until char: " << std::endl;
	if(StringParser::getStringUntilChar(0, "|zt\n", data, c, result) == std::string::npos){
		std::cout << "Error parsing: " << data << std::endl;
		return 1;
	}
	std::cout << "char: " << c << "\nResult = " << result << std::endl;


	return 0;
}
