/*! This class will be in charge to read an interpretate the config files 
 * (templates). From this class will be extracted the strings needed to parse
 * the files where will be search the TAGS to complete the ADT.
 */
#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <string>
#include <iostream>
#include <fstream>
#include <map>


using namespace std;

/* we gonna define the keys that can read the config manager, to load at the
 * startup */
#define CONFIGM_KEY_LIST string keyList[] = 	{"TEMPLATE_NAME", \
						"EXTENSIONS_FILES_ASSOCIATED", \
						"COMMENTS_OPEN", \
						"COMMENTS_CLOSE", \
						"END_VALUE_STRING", \
						"FUNCTION_WEIGTH_INT", \
						"FUNCTION_COMPLETE_BOOL", \
						"FUNCTION_NAME_STRING", \
						"NOTE_KEY_STRING_STRING", \
						"ISSUE_KEY_STRING_STRING", \
						"ISSUE_KIND_KEY_STRING", \
						"ISSUE_PRIORITY_KEY_STRING", \
						"MODULE_NAME_STRING", \
						"MODULE_DESCRIPTION_STRING", \
						"MODEULE_WEIGTH_INT", \
						"MODULE_COMPILABLE_BOOL", \
						"MODULE_TESTED_BOOL", \
						""};


/* define the string wich represents the start of a comment in the config file */
#define CONFIGM_COMMENT_STR		"#"

/* We gonna define the string o char used to assign, used for parse the values 
 * on the source code files */
#define ASSIGN_STRING			"="


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

