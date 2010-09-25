#ifndef MODULE_H
#define MODULE_H

#include <iostream>
#include <list>
#include <string>
#include <assert.h>

#include "identifiableobject.h"
#include "function.h"
#include "issue.h"
#include "note.h"


using namespace std;


/* definimos los tipos de modulos */
enum {
	MODULE_T_CLASS,		/* es una clase */
	MODULE_T_MODULE,	/* es un modulo */
	MODULE_T_UNKNOWN	/* que lo que */
};

class Module : public IdentifiableObject  {
	
	public:
		/* constructor */
		Module(){};
		
		/* Constructor para setear todo de una */
		Module(string &n, int w, string& fname);
		
		/* set/get fname */
		void setFileName(string &fn){this->fname = fn;};
		string &getFileName(void){return this->fname;};
		
		/* set/get name */
		void setName(string &n){this->name = n;};
		string &getName(void){return this->name;};
		
		/* set/get canCompile */
		void setCanCompile(bool c){this->canCompile = c;};
		bool getCanCompile(void){return this->canCompile;};
		
		/* set/get tested*/
		void setTested(bool t){this->tested = t;};
		bool getTested(void){return this->tested;};
		
		/* set/get weight */
		void setWeight(int w){this->weight = w;};
		int getWeight(void){return this->weight;};
		
		/* set/get type*/
		void setType(int t){this->type= t;};
		int getType(void){return this->type;};
		void getStringType(string &t);
		
		/* Funcion que devuelve la lista de funciones del modulo */
		list<Function *> &getFunctions(void){return this->funcList;};
		
		/* funcion que agrega una funcion al modulo 
		 * REQUIRES:
		 * 	func	!= NULL
		 * NOTE: No debe ser eliminada la funcion una vez agregada.
		 */
		void addFunction(Function *func);
		
		/* funcion que libera una function de la lista liberando tambien
		* la memoria.
		* REQUIRES:
		* 	func != NULL
		*/
		void removeFunction(Function *func);
		
		/* Funcion que devuelve la lista de notas */
		list<Note *> &getNotes(void){return this->noteList;};
		
		/* Funcion que permite agregar una nota relacionada al modulo
		 * REQUIRES:
		 * 	note	!= NULL
		 * NOTE: No debe ser liberada la nota una vez agregada 
		 */
		void addNote(Note *note);
		
		/* funcion que libera una nota de la lista liberando tambien
		 * la memoria.
		 * REQUIRES:
		 * 	note != NULL
		 */
		void removeNote(Note *note);
		
		/* Funcion que determina si ya existe una Nota en el 
		* modulo. */
		bool existNote(Note *t);
		
		/* Returns the issues list */
		list<Issue *> &getIssues(void){return this->issuesList;};
		
		/* Functio used to add a issue associated to the module
		* REQUIRES:
		* 	i 	!= NULL
		* NOTE: Do not free the issue once added
		*/
		void addIssue(Issue *t);
		
		/* Remove a issue associated to the module and free their memory
		* REQUIRES:
		* 	issue != NULL
		*/
		void removeIssue(Issue *issue);
		
		/* Function used to check if a issue is associated to the module
		 * REQUIRES:
		 * 	i	!= NULL
		 */
		bool existIssue(Issue *i);
		
		/*! Funcion que devuelve el porcentaje de completado del modulo
		 * teniendo en cuenta los porcentajes de las funciones que
		 * tiene asociado el modulo
		 */
		float getCompleted(void);
		
		
		/* destructor: empty destructor */
		~Module();
		
		/* DEBUG */
		void Print(void);
	
	private:
		
		/*			Atributos			*/
		int weight;	/* peso del modulo en el proyecto */
		string name;
		string fname;	/* file name */
		list<Function *> funcList;
		list<Issue *> issuesList;
		list<Note *> noteList;
		bool canCompile;
		bool tested;
		int type;
		
	
};




#endif
