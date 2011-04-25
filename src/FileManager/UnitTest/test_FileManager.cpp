/*
 * test_FileManager.cpp
 *
 *  Created on: 24/04/2011
 *      Author: agustin
 */

#include <string>
#include <list>
#include <iostream>
#include "DebugUtil.h"
#include "FileManager.h"



/* TODO: testear las otras funcionalidades del FileManager */

int main(int argc, char **args)
{
	std::list<std::string> folderList;
	std::string folder;

	if(argc <= 1){
		std::cout << "Falta argumento <path>\n";
		return 1;
	}
	folder = args[1];

	std::cout << "RootFoldeR: " << folder << std::endl;

	FileManager::getInstance()->getAllFolders(folder, folderList);

	std::cout << "Printing folders from: " << folder << std::endl;
	for(std::list<std::string>::iterator it = folderList.begin(); it != folderList.end();
			++it){
		std::cout << *it << std::endl;
	}

	return 0;
}
