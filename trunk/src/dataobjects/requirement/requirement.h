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
#include "moodule.h"
#include "function.h"
#include "cobject.h"


/* We gonna define some possible states that can be the requirement*/

class Requirement : public CObject {
	
	public:
		/* empty consturctor */
		Requirement(void);
		
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
		
		/* Function to add a function who the requirements depends of
		 * REQUIRES:
		 * 	func	!= NULL
		 */
		void addFuncDependency(Function *func);
		
		/* Function to add a module who the requirements depends of
		 * REQUIRES:
		 * 	mod	!= NULL
		 */
		void addModuleDependency(Module *mod);
		
		/*! FIXME: we have to add the 2 virtual methods inherited from 
		 * the CObject class. */
		
		/* empty destructor */
		~Requirement(void);
	
	private:
		/* Requirement description */
		string description;
		/* Requirement title */
		string title;
		/* status of the requirement */
		int status;
		/* the list of the function dependencies */
		list<Function *> funcDependenciesList;
		/* the list of the modules dependencies */
		list<Module *> moduleDependenciesList;
		
};


#endif

