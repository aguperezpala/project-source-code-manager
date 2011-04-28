/*
 * test_SyntaxConfiguration.cpp
 *
 *  Created on: 27/04/2011
 *      Author: agustin
 */

#include <iostream>

#include "DebugUtil.h"
#include "SyntaxConfiguration.h"



void printSyntaxConfiguration(SyntaxConfiguration &conf)
{
	std::string res;
	std::list<std::string> auxList, auxList2;

	conf.getCategories(auxList);
	for(std::list<std::string>::iterator it = auxList.begin(); it != auxList.end();
			++it) {
		std::cout << "Category: " << *it << std::endl;
		conf.getKeys(*it, auxList2);
		for(std::list<std::string>::iterator it2 = auxList2.begin(); it2 != auxList2.end();
				++it2) {
			std::cout << "\t " << *it2 << std::endl;
		}

		std::cout << std::endl;
	}


}

int main(void)
{
	SyntaxConfiguration conf;


	conf.insertKeys("cat1", "key1");
	conf.insertKeys("cat1", "key2");
	conf.insertKeys("cat1", "key3");

	conf.insertKeys("cat2", "key1");
	conf.insertKeys("cat3", "key02");
	conf.insertKeys("cat4", "key003");

	std::cout << "First print \n";

	printSyntaxConfiguration(conf);

	conf.removeCategory("cat1");
	conf.removeCategory("pepe");
	conf.removeKey("pepe", "key1");

	conf.removeKey("cat4", "key003");

	std::cout << "Second print \n\n";
	printSyntaxConfiguration(conf);


	return 0;
}
