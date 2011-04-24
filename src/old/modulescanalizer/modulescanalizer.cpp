#include "modulescanalizer.h"

/*! ###			PRIVATE FUNCTIONS			### */

/* Function wich extracts all the Comments from the data to
	* analize and inserts it in a list.
	* Use the ConfigManager to know how the comments are formed
	*/
void ModuleSCAnalizer::createCommentList(void);

/* Used to clean all the class data (attributes).
* NOTE: This NOT free the data.  
*/
void ModuleSCAnalizer::freeAndCleanAll(void)
{
	list<Module *>::iterator mIt;
	list<Function *>::iterator fIt;
	list<Issue *>::iterator iIt;
	list<Notes *>::iterator nIt;
	
	this->commentList.clear();
	/* the Module list last parse */
	for(mIt = this->modList.begin(); mIt != this->modList.end(); ++mIt)
		if((*mIt) != NULL)
			delete (*mIt);
	this->modList.clear();
	
	for(fIt = this->funcList.begin(); fIt != this->funcList.end(); ++fIt)
		if((*fIt) != NULL)
			delete (*fIt);
	this->funcList.clear();
	
	for(iIt = this->issueList.begin(); iIt != this->issueList.end(); ++iIt)
		if((*iIt) != NULL)
			delete (*iIt);
	this->issueList.clear();
	
	for(nIt = this->noteList.begin(); nIt != this->noteList.end(); ++nIt)
		if((*nIt) != NULL)
			delete (*nIt);
	this->noteList.clear();
}

/* This method extract all the Keys (patterns) and returns
* a list of the results. In case that a pattern couldn't
* be finded, then the corresponding result will be filled
* with an empty string ("").
* NOTE: For precaution only pass one comment (NOT ALL THE DATA).
* REQUIRES:
* 	comment		(the comment where it is the "function")
* 	patternList	(the Keys to search an parse)
* 	resultList	(the list where be added the results)
* RETURNS:
* 	< 0		on error
* 	0		if success
*/
int ModuleSCAnalizer::parsePatterns(string &comment, list<string> &patternList, 
			list<string> &resultList)
{
	string endStr, eqStr, cmKey;
	string value;
	list<string>::iterator it;
	
	
	// pre condition
	assert(this->cm != NULL);
	
	// we do some minimun check
	if((comment.length() <= 1) || (patternList.size() == 0))
		// nothing to do, so you are calling this function without sense
		return -1;
	
	// now we set the "enviroment"
	cmKey = "END_VALUE_STRING";
	if(this->cm->getValue(cmKey, endStr) < 0){
		debug("cannot get value\n");
		return -1;
	}
	eqStr = ASSIGN_STRING;
	
	// now parse all the patterns
	resultList.clear();
	for(it = patternList.begin(); it != patternList.end(); ++it) {
		if(parser_extract_value(comment, 0, (*it), eqStr, endStr, value) < 0){
			debug("Cannot parse the %s key\n", (*it).c_str());
			value = "";
		}
		
		// we always add a result, empty or not, dosnt matter
		resultList.push_back(value);
	}
	
	return 0;
}


/* Function to create a function from a patternList and the 
* associated valuesList.
* REQUIRES:
* 	patternList	(indicates the list of "fields"
* 	valuesList	(the corresponding values to the patterns)
* RETURNS:
* 	NULL		on error
* 	obj		on success
*/
Function *ModuleSCAnalizer::getFunction(list<string> &patternList, 
			list<string> &valuesList)
{
	Function *result = NULL;
	
}

/* Function to create a function from a patternList and the 
	* associated valuesList.
	* REQUIRES:
	* 	patternList	(indicates the list of "fields"
	* 	valuesList	(the corresponding values to the patterns)
	* RETURNS:
	* 	NULL		on error
	* 	obj		on success
	*/
Module *ModuleSCAnalizer::getModule(list<string> &patternList, 
			list<string> &valuesList);
			
/* Function to create a Issue from a patternList and the 
	* associated valuesList.
	* REQUIRES:
	* 	patternList	(indicates the list of "fields"
	* 	valuesList	(the corresponding values to the patterns)
	* RETURNS:
	* 	NULL		on error
	* 	obj		on success
	*/
Issue *ModuleSCAnalizer::getIssue(list<string> &patternList, 
			list<string> &valuesList);


/* Function to create a note from a patternList and the 
	* associated valuesList.
	* REQUIRES:
	* 	patternList	(indicates the list of "fields"
	* 	valuesList	(the corresponding values to the patterns)
	* RETURNS:
	* 	NULL		on error
	* 	obj		on success
	*/
Note *ModuleSCAnalizer::getNote(list<string> &patternList, 
			list<string> &valuesList);



/*! ###			PUBLIC FUNCTIONS			### */

/* consturctor: */
ModuleSCAnalizer::ModuleSCAnalizer(void)
{
	this->cm = NULL;
	this->data = NULL;
}
/* Constructor with the ConfigManager wich be used 
* REQUIRES;
* 	configM		!= NULL
* NOTE: this class will no delete the configManager
*/
ModuleSCAnalizer::ModuleSCAnalizer(ConfigManager *configM)
{
	assert(configM != NULL);
	
	this->cm = configM;
	this->data = NULL;
}

/* Function to set the config manager
* NOTE: the configManager shouldnt be deleted in the 
*	ModuleSCAnalizer life cycle.
* REQUIRES:
* 	configM		!= NULL
*/
void ModuleSCAnalizer::setConfigManager(ConfigManager *configM)
{
	assert(configM != NULL);
	this->cm = configM;
}

/* Function to set the data to analize (all the source of a 
* module, or whatever else).
* The data passed couldn't be recovered, this class is now
* the owner (and will used and deleted here).
* NOTE: If a data was seted before, it will overwrite it 
* (freeing the other one).
* 
* REQUIRES:
*	data	!= NULL 
*/
void ModuleSCAnalizer::setDataToAnalize(string *d)
{
	assert(d != NULL);
	
	if(this-data != NULL)
		delete this->data;
	
	this->data = d;
}

/*! This function will analize the data seted before.
* 
* Functionality: It will extract all the Functions, Notes, 
* Issues, and a Module info, and will save it in new objects
* wich will can be obtained by the respectives methods.
* And all the elements wich contains* this class will be 
* freeded to. (so extract it before call this function).
* NOTE: The data will be lost (this call could be done once
* per data setted, this its for performance purposes)
* 
* REQUIRES:
* 	have seted the ConfigManager
* 	have seted data To analize
* RETURNS:
* 	< 0		on error
* 	numItems	the number of items extracted/created
*/
int ModuleSCAnalizer::analizeData(void)
{
	
	// check if we have a configManager or data seted.. 
	assert(this->cm != NULL);
	assert(this->data != NULL);
	
	// we do a complete clean
	freeAndCleanAll();
	
	// create the comments list (we will work over this list)
	// FIXME: this it is the inefficient way... IMPROVE this :)
	createCommentList();
	delete data; data = NULL;
	
	
}


/*!	Function associated to the elements parsed
* All this functions once retrieved an element, the elements
* belongs to the class wich asked it (so its responsability of
* this class to freeit, the ModuleSCAnalizer isnt anymore the
* owner of the object 
*/


/* Function to retrive a Module parsed (if there was one)
* RETURNS:
* 	NULL		if no Modules was parsed (or there are
* 			no more Modules)
* 	mod != NULL	if a Module was parsed
*//*!NOTE: if there are more than 1 module => we have to 
* divide the functions in the corresponding modules...
* So... write one module per file or "data" :) */
Module *ModuleSCAnalizer::getModule(void);
int ModuleSCAnalizer::getModuleCount(void);

/* Function to retrive a Function parsed (if there was one)
* RETURNS:
* 	NULL		if no Function was parsed (or there are
* 			no more Functions)
* 	func != NULL	if a Function was parsed
*/
Function *ModuleSCAnalizer::getFunction(void);
int ModuleSCAnalizer::getFunctionCount(void);

/* Function to retrive a Issue parsed (if there was one)
* RETURNS:
* 	NULL		if no Issue was parsed (or there are
* 			no more Issue)
* 	issue != NULL	if a Issue was parsed
*/
Issue *ModuleSCAnalizer::getIssue(void);
int ModuleSCAnalizer::getIssueCount(void);

/* Function to retrive a Note parsed (if there was one)
* RETURNS:
* 	NULL		if no Note was parsed (or there are
* 			no more Note)
* 	note != NULL	if a Note was parsed
*/
Note *ModuleSCAnalizer::getNote(void);
int ModuleSCAnalizer::getNoteCount(void);



/* Destructor:
* Free all the memory allocated, execpt the ConfigManager
*/
ModuleSCAnalizer::~ModuleSCAnalizer(void);