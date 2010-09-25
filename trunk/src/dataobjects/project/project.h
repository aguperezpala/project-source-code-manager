#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include <string>

#include "identifiableobject.h"
#include "module.h"
#include "note.h"
#include "issue.h"


using namespace std;

class Project : public IdentifiableObject {
	
	public:
		/* constructor */
		Project(string &dir);
		
		
		/* set/get project dir */
		void setDir(string &d){this->projDir = d;};
		string &getDir(void){return this->projDir;};
		
		/* set/get name */
		void setName(string &n){this->name = n;};
		string &getName(void){return this->name;};
		
		/* set/get description */
		void setDesc(string &d){this->desc= d;};
		string &getDesc(void){return this->desc;};
		
		/* set/get canCompile */
		void setCanComiple(bool c){this->canCompile = c;};
		bool getCanComiple(void){return this->canCompile;};
		
		/* set/get tested*/
		void setTested(bool t){this->tested = t;};
		bool getTested(void){return this->tested;};
		
		
		/* Funcion que devuelve la lista de modulos del proyecto */
		list<Module *> &getModules(void){return this->moduleList;};
		
		/* funcion que agrega un modulo al proyecto
		* REQUIRES:
		* 	module != NULL
		* NOTE: No debe ser eliminada la funcion una vez agregada.
		*/
		void addModule(Module *module);
		
		/* Remove the module from the project
		* REQUIRES:
		* 	obj 	!= NULL
		*/
		void removeModule(Module *obj);
		
		/* Funcion que devuelve la lista de notas */
		list<Note *> &getNotes(void){return this->noteList;};
		
		/* Funcion que permite agregar una nota relacionada al modulo
		* REQUIRES:
		* 	note	!= NULL
		* NOTE: No debe ser liberada la nota una vez agregada 
		*/
		void addNote(Note *note);
		
		/* Remove the note from the project
		* REQUIRES:
		* 	obj 	!= NULL
		*/
		void removeNote(Note *obj);
		
		/* Function to retrieve the issue list */
		list<Issue *> &getIssues(void){return this->issuesList;};
		
		/* Function used to add a Issue to the project
		* REQUIRES:
		* 	i 	!= NULL
		* NOTE: The issue doesn't have to be deleted
		*/
		void addIssue(Issue *i);
		
		/* Remove the issue from the project
		 * REQUIRES:
		 * 	obj 	!= NULL
		 */
		void removeIssue(Issue *obj);
		
		/*! Funcion que devuelve el porcentaje de completado del proyecto
		* teniendo en cuenta los porcentajes de los pesos y cuanto
		* estan completados los modulos.
		*/
		float getCompleted(void);
		
		
		/* Destructor: empty destructor */
		~Project();
		
		/* debug */
		void Print(void);
	
	private:
		string name;
		string desc;
		string projDir;
		bool tested;
		bool canCompile;
		list<Module *> moduleList;
		list<Issue *> issuesList;
		list<Note *> noteList;
		
	
};




#endif
