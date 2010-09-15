#include "configmanager.h"


/* Read a file. FIXME: (this its duplicated in FileManager)
* RETURNS:
* 	< 0	on error
* 	0 	if succes (and returns the data into result)
*/
int ConfigManager::readFile(string &fn, string &result)
{
	int length;
	char *buffer = NULL;
	ifstream is;
	
	
	if(fn.length() <= 0)
		return -1;
	
	
	is.open (fn.c_str(), ios::binary);
	
	if(!is.good())
		return -1;
	
	// get length of file:
	is.seekg (0, ios::end);
	length = is.tellg();
	is.seekg (0, ios::beg);
	
	// allocate memory:
	buffer = new char[length];
	if(!buffer)
		return -1;
	
	// read data as a block:
	is.read (buffer,length);
	is.close();
	
	result = buffer;
	delete[] buffer;
	
	return 0;
}



/* consturctor */
ConfigManager::ConfigManager(void)
{
	CONFIGM_KEY_LIST /* the list of keys */
	int i = 0;
	
	
	while(keyList[i].length() > 0) {
		/* insert dummys strings */
		this->valuesHash[keyList[i]] = "";
		i++;
	}
}


/* Function to load the values of the associated keys from
* the config file.
* RETURNS:
* 	< 0 	on error (couldn't open the file)
* 	0	on success
*/
int ConfigManager::loadConfiguration(void)
{
	/* for the moment this will be a ugly implementation but it will work */
	string data = "";
	
	if(readFile(this->fname, data) < 0)
		/* no file name */
		return -1;
	
	/* now we extract the comments, and let the clean data.. */
	/*! FIXME: complete this function */
	
	return 0;
}

/* Function to return a specific string from the config
* file.
* RETURNS:
* 	< 0	if error
* 	0	on success (and return in value the Value of
* 		the key associated)
*/
int ConfigManager::getValue(string &key, string &value);

/* empty destructor */
ConfigManager::~ConfigManager(void)
{
	/* nothing */
}