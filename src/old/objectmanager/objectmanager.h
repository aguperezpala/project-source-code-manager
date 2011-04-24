/*!This class will contains all the IdenfitiableObjects, and it will be the 
 * owner of these elements.Here will be the only place where it will be free the
 * IdentifiableObject.
 */
#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <string>
#include <map>
/* own libraries */
#include "project.h"
#include "module.h"
#include "issue.h"
#include "requirement.h"
#include "note.h"
#include "debug.h"

using namespace std;




class ObjectManager {
	
	public:
		/* consturctor: */
		ObjectManager(void);
		
		/* returns the class ID */
		ObjectId_t getLastID(void){return this->lastId;};
		
		/* Function to delete (and free the memory allocated for the
		 * elements).
		 */
		void deleteAllObjects(void);

		/*! NOTE: This class will kept the objects pointers, so do not
		 * free the objects once you have call one of the add* function
		 */
		
		/*!		Function to manage the Projects		*/
		bool existsProject(ObjectId_t id);
		void addProject(Project *p);
		void removeProject(ObjectId_t id);
		
		/*!		Function to manage the Modules		*/
		bool existsModule(ObjectId_t id);
		void addModule(Module *m);
		void removeModule(ObjectId_t id);
		
		/*!		Function to manage the Notes		*/
		bool existsNote(ObjectId_t id);
		void addNote(Note *n);
		void removeNote(ObjectId_t id);
		
		/*!		Function to manage the Issues		*/
		bool existsIssue(ObjectId_t id);
		void addIssue(Issue *i);
		void removeIssue(ObjectId_t id);
		
		/*!		Function to manage the Requirements	*/
		bool existsRequirement(ObjectId_t id);
		void addRequirement(Requirement *r);
		void removeRequirement(ObjectId_t id);
		
		
		/* empty destructor, It free all the memory allocated */
		~ObjectManager(void);
		
	
	private:
		/*!		Attributes		*/
		/* this is used to know the las id assigned */
		ObjectId_t lastId;
		map<ObjectId_t, Project *> projHash;
		map<ObjectId_t, Requirement *> reqHash;
		map<ObjectId_t, Module *> modHash;
		map<ObjectId_t, Issue *> issueHash;
		map<ObjectId_t, Note *> noteHash;
		
		
};


#endif

