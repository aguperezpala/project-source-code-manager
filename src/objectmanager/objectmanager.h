/*! This class will manage all the objects of the project. It will have 
 * constructor for all the elements in the project (requirements | notes | 
 * modules...).
 * This class will count and set the ID's to the objects.
 * Throw this class we should could load from file all the objects (*.xml).
 */
#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <string>
/* own libraries */
#include "ssxmlparser.h" /* this will be used to the to/from XML functions */
#include "cobject.h"
#include "project.h"
#include "module.h"
#include "function.h"
#include "issue.h"
#include "requirement.h"
#include "note.h"
/* parsers to load the files */
#include "parser.h"
#include "ssxmlparser.h"
/* file manager */
#include "filemanager.h"

using namespace std;




class ObjectManager {
	
	public:
		/* consturctor: We have to set the start id number, From
		 * this number we will start to enumerate the objects.
		 */
		ObjectManager(int startId){this->lastId = startId;};
		
		/* returns the class ID */
		int getLastID(void){return this->lastId;};
		
		
		/*! Here we gonna define the functions to create the different
		 * objects. This functions automatically will */
		
		/* Every this functions are used to create a new empty object.
		* RETURNS:
		* 	obj != NULL 	on success
		* 	NULL		on error
		*/
		Module *createNewModule(void);
		Function *createNewFunction(void);
		Requirement *createNewRequirement(void);
		Note *createNewNote(void);
		Issue *createNewIssue(void);
		
		/* Function to delete (and free the memory allocated for the
		 * elements).
		 */
		void deleteAllObjects(void);
		
		/*! This function will load a complete project from a file
		 * NOTE: Delete all the elements before call this function.
		 * This function load a Project (can be obtained be callin
		 * getProject.
		 * REQUIRES;
		 * 	fname	(file name of the project).
		 * RETURNS:
		 *  	< 0	on error.
		 *	0	if success
		 */
		int loadProjectFromFile(string &fname);
		
		/* Function wiche returns the Project Associated, if there are
		 * one. (if there was a previous call of loadProjectFromFile,
		 * then there will be a project).
		 * RETURNS:
		 * 	project		if there are any one associated
		 * 	NULL		otherwise
		 */
		Project *getProject(void);
		
		/* Function wich returns all the objects in the list. */
		list<Module *> &getModulesList(void){return this->modulesList;};
		list<Issue *> &getissuesList(void){return this->issuesList;};
		list<Function *> &getFunctionsList(void){return this->functionsList;};
		list<Note *> &getNotesList(void){return this->notesList;};
		list<Requirement *> &getRequirementsList(void){return this->requirementsList;};
		
		
		/* empty destructor, It free all the memory allocated */
		~ObjectManager(void);
		
	
	private:
		/*!		Functions		*/
		
		/* function used to load all the Notes from a xml file and 
		 * insert it in the notesList
		 * REQUIRES:
		 * 	fname
		 * RETURNS:
		 * 	< 0	on error
		 * 	>= 0	on success (returns the number of Notes loaded)
		*/
		int loadNotesFromFile(void);
		/* All this others are equivalent */
		int loadIssuesFromFile(void);
		int loadRequirementsFromFile(void);
		int loadModulesFromFile(void);
		int loadFunctionsFromFile(void);
		
		
		
		/*!		Attributes		*/
		/* this is used to know the las id assigned */
		int lastId;
		/* The project loaded */
		Project *project;
		/* the lists used to track all the diferents objects. Probably
		 * a map (hash) using a objectList it will be the best */
		list<Module *> modulesList;
		list<Issue *> issuesList;
		list<Function *> functionsList;
		list<Note *> notesList;
		list<Requirement *> requirementsList;
		
};


#endif

