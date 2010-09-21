/*! This class its the Module Source Code analizer, wich takes a source code of 
 * a module, and extracts all the things found in it, looking for the tags that 
 * had been parsed with the ConfigManager.
 * This module have to be edited if some change occur in the ConfigManager or 
 * some of the CObject modules.
 */
#ifndef MODULESCANALIZER_H
#define MODULESCANALIZER_H

#include <assert.h>
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




class ModuleSCAnalizer {
	
	public:
		/* consturctor: */
		ModuleSCAnalizer(void);
		/* Constructor with the ConfigManager wich be used 
		 * REQUIRES;
		 * 	configM		!= NULL
		 * NOTE: this class will no delete the configManager
		*/
		ModuleSCAnalizer(ConfigManager *configM);
		
		/* Function to set the config manager
		 * NOTE: the configManager shouldnt be deleted in the 
		 *	ModuleSCAnalizer life cycle.
		 * REQUIRES:
		 * 	configM		!= NULL
		 */
		void setConfigManager(ConfigManager *configM);
		
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
		void setDataToAnalize(string *data);
		 
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
		int analizeData(void);
		
		
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
		Module *getModule(void);
		int getModuleCount(void);
		
		/* Function to retrive a Function parsed (if there was one)
		* RETURNS:
		* 	NULL		if no Function was parsed (or there are
		* 			no more Functions)
		* 	func != NULL	if a Function was parsed
		*/
		Function *getFunction(void);
		int getFunctionCount(void);
		
		/* Function to retrive a Issue parsed (if there was one)
		* RETURNS:
		* 	NULL		if no Issue was parsed (or there are
		* 			no more Issue)
		* 	issue != NULL	if a Issue was parsed
		*/
		Issue *getIssue(void);
		int getIssueCount(void);
		
		/* Function to retrive a Note parsed (if there was one)
		* RETURNS:
		* 	NULL		if no Note was parsed (or there are
		* 			no more Note)
		* 	note != NULL	if a Note was parsed
		*/
		Note *getNote(void);
		int getNoteCount(void);
		
		
		
		/* Destructor:
		 * Free all the memory allocated, execpt the ConfigManager
		 */
		~ModuleSCAnalizer(void);
		
		
	
	private:
		/*			FUNCTIONS			*/
		
		/* Function wich extracts all the Comments from the data to
		 * analize and inserts it in a list.
		 * Use the ConfigManager to know how the comments are formed
		 */
		void createCommentList(void);
		
		/* Used to clean all the class data (attributes).
		 * NOTE: This NOT free the data.  
		 */
		void freeAndCleanAll(void);
		
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
		int parsePatterns(string &comment, list<string> &patternList, 
				   list<string> &resultList);
		
		/* Function to create a function from a patternList and the 
		 * associated valuesList.
		 * REQUIRES:
		 * 	patternList	(indicates the list of "fields"
		 * 	valuesList	(the corresponding values to the patterns)
		 * RETURNS:
		 * 	NULL		on error
		 * 	obj		on success
		 */
		Function *getFunction(list<string> &patternList, 
				       list<string> &valuesList);
		
		/* Function to create a function from a patternList and the 
		 * associated valuesList.
		 * REQUIRES:
		 * 	patternList	(indicates the list of "fields"
		 * 	valuesList	(the corresponding values to the patterns)
		 * RETURNS:
		 * 	NULL		on error
		 * 	obj		on success
		 */
		Module *getModule(list<string> &patternList, 
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
		Issue *getIssue(list<string> &patternList, 
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
		Note *getNote(list<string> &patternList, 
				       list<string> &valuesList);
		
		
		
		/*			ATTRIBUTES			*/
		/* Config Manager */
		ConfigManager *cm;
		/* data ptr to parse */
		string *data;
		/* The comments List:FIXME this way its innefficient, but easy */
		list<string> commentList;
		/* the Module list last parse */
		list<Module *> modList;
		/* list of Functions */
		list<Function *> funcList;
		/* list of Issues */
		list<Issue *> issueList;
		/* list of notes */
		list<Notes *> noteList;
		
};


#endif

