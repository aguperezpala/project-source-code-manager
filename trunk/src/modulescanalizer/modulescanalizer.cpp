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

/* Function wich removes all the comments from the data
* REQUIRES:
* 	data
* 	cB	(commentBegin string)
* 	cE	(commentEnd string)
*/
void ConfigManager::removeComments(string &data, string &cB, string &cE)
{
	size_t bPos = 0, ePos = 0;
	
	/* we will start to extract the comments */
	while(1) {
		bPos = data.find(cB, bPos);
		
		if(bPos == string::npos)
			/* nothing else to extract */
			break;
		
		ePos = data.find(cE, bPos + 1);
		if(bPos == string::npos)
			/* mmm, we gonna extract this, it cannot be posible */
			ePos = data.length();
		else
			ePos = ePos + cE.length();
		
		/* do the erase */
		
		data.erase(bPos, ePos - bPos);
		
	}
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
	string commentB = CONFIGM_COMMENT_STR, commentE = "\n";
	string key = "", value = "", line = "";
	size_t bPos = 0, eolP = 0;
	size_t eqPos = 0;
	
	
	
	if(readFile(this->fname, data) < 0)
		/* no file name */
		return -1;
	
	/* now we extract the comments, and let the clean data.. */
	removeComments(data, commentB, commentE);
	
	/* now to have a clean parse we append a \n */
	if(data[data.length()-1] != '\n')
		data.append("\n");
	
	/* here we have the clean file, now extract the values of the vars 
	 * NOTE: we aren't recognizing the differents sectiosn [Section1] */
	while(1){
		eolP = data.find('\n', bPos);
		
		if(eolP == string::npos)
			break;
		
		line = data.substr(bPos, eolP - bPos);
		bPos = eolP + 1;
		
		// now we extract the key and the value 
		eqPos = line.find("=");
		if(eqPos == string::npos)
			continue;
		
		key = line.substr(0,eqPos);
		value = line.substr(eqPos + 1, line.length() - eqPos - 1);
		
		// insert the value if there are a key equivalent
		if(this->valuesHash.find(key) == this->valuesHash.end())
			// there isnt... debug("the key dsnt match...")
			continue;
		else
			this->valuesHash[key] = value;
	}
	
	
	return 0;
}

/* Function to return a specific string from the config
* file.
* RETURNS:
* 	< 0	if error
* 	0	on success (and return in value the Value of
* 		the key associated)
*/
int ConfigManager::getValue(string &key, string &value)
{
	if(this->valuesHash.find(key) == this->valuesHash.end())
		return -1;
	
	value = this->valuesHash[key];
	
	return 0;
}

/* empty destructor */
ConfigManager::~ConfigManager(void)
{
	/* nothing */
}