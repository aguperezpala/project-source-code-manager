/*! This is the abstraction of a requirement. It can be linked to functions or 
 * modules (if this functions or modules are fully completed, then we can say 
 * that the requirement it is covered) 
*/
#ifndef REQUIREMENT_H
#define REQUIREMENT_H

#include <string>
#include <list>
#include <iostream>
#include <stdio.h>
/* own libs */
#include "identifiableobject.h"
#include "module.h"
#include "issue.h"

using namespace std;

/* We gonna define some possible states that can be the requirement*/
enum {
	REQ_ST_DONE,		/* requeriment done */
	REQ_ST_OBSOLET,		/* requirement obsolet */
	REQ_ST_NOT_COMPLIED	/* requirement waiting to be done :) */
};

class Requirement : public IdentifiableObject {
	
	public:
		/* empty consturctor */
		Requirement(void);
		Requirement(string &title, string &desc, int status);
		
		/* Function to set the description of the requirement
		 * REQUIRES:
		 * 	desc.length() > 0 
		 */
		void setDescription(string &desc);
		
		/* Function to set the title of the requirement
		 * REQUIRES:
		 * 	title.length() > 0 
		 */
		void setTitle(string &title);
		
		/* Set and get the status */
		int getStatus(void){return this->status;};
		void setStatus(int st){this->status = st;};
		
		/* Function to add a issue who the requirements depends of
		 * REQUIRES:
		 * 	issue	!= NULL
		 */
		void addIssueDependency(Issue *issue);
		
		/* Removes the issue dependency (do not free the memory)
		 * REQUIRES:
		 * 	issue != NULL
		 */
		void removeIssueDependency(Issue *issue);
		
		/* Function to add a module who the requirements depends of
		 * REQUIRES:
		 * 	mod	!= NULL
		 */
		void addModuleDependency(Module *mod);
		
		/* Removes the module dependency (do not free the memory)
		* REQUIRES:
		* 	mod != NULL
		*/
		void removeModuleDependency(Module *mod);
		
		/* empty destructor */
		~Requirement(void);
	
	private:
		/* Requirement description */
		string description;
		/* Requirement title */
		string title;
		/* status of the requirement */
		int status;
		/* the list of the Issues dependencies */
		list<Issue *> issueDependenciesList;
		/* the list of the modules dependencies */
		list<Module *> moduleDependenciesList;
		
};


#endif

