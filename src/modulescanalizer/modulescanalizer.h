/*! This class its the Module Source Code analizer, wich takes a source code of 
 * a module, and extracts all the things found in it, looking for the tags that 
 * had been parsed with the ConfigManager.
 * This module have to be edited if some change occur in the ConfigManager or 
 * some of the CObject modules.
 */
#ifndef MODULESCANALIZER_H
#define MODULESCANALIZER_H

#include <string>
#include <iostream>
#include <fstream>
#include <map>
/* own libs */
#include "configmanager.h"
/* the ADT's that can be readed from a source file */
#include "module.h"
#include "function.h"
#include "note.h"
#include "issue.h"



using namespace std;




class ConfigManager {
	
	public:
		/* consturctor */
		ConfigManager(void);
		
		/* Function to set the Config File Name (path) */
		void setConfigFile(string &cfn){this->fname = cfn;};
		
		/* Function to load the values of the associated keys from
		 * the config file.
		 * RETURNS:
		 * 	< 0 	on error (couldn't open the file)
		 * 	0	on success
		 */
		int loadConfiguration(void);
		
		/* Function to return a specific string from the config
		 * file.
		 * RETURNS:
		 * 	< 0	if error
		 * 	0	on success (and return in value the Value of
		 * 		the key associated)
		 */
		int getValue(string &key, string &value);
		
		
		/* empty destructor */
		~ConfigManager(void);
	
	private:
		/*! 			Function			*/
		/* Read a file. FIXME: (this its duplicated in FileManager)
		 * RETURNS:
		 * 	< 0	on error
		 * 	0 	if succes (and returns the data into result)
		 */
		int readFile(string &fname, string &result);
		
		/* Function wich removes all the comments from the data
		* REQUIRES:
		* 	data
		* 	cB	(commentBegin string)
		* 	cE	(commentEnd string)
		*/
		void removeComments(string &data, string &cB, string &cE);
		
		
		
		/*! 			Attributes			*/
		/* the hash of keys and values parsed */
		map<string, string> valuesHash;
		/* the config file name */
		string fname;
		
		
		
};


#endif

