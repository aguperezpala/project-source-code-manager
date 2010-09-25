#include "module.h"


/*!	###		FUNCIONES PUBLICAS		###	*/

/* Constructor para setear todo de una */
Module::Module(string &n, int w, string& fn)
{
	this->name = n;
	this->weight = w;
	this->fname = fn;
	this->canCompile = false;
	this->tested = false;
}


void Module::getStringType(string &t)
{
	switch(this->type) {
		case MODULE_T_CLASS:
			t = "Class type";
			break;
			
		case MODULE_T_MODULE:
			t = "Normal Module type";
			break;
			
		default:
			t = "unknown type";
			break;
	}
}

/* funcion que agrega una funcion al modulo 
* REQUIRES:
* 	func	!= NULL
* NOTE: No debe ser eliminada la funcion una vez agregada.
*/
void Module::addFunction(Function *func)
{
	assert(func != NULL);
	this->funcList.push_back(func);
}

/* funcion que libera una function de la lista liberando tambien
* la memoria.
* REQUIRES:
* 	func != NULL
*/
void Module::removeFunction(Function *func)
{
	assert(func != NULL);
	this->funcList.remove(func);
	
	delete func;
}

/* Funcion que permite agregar una nota relacionada al modulo
* REQUIRES:
* 	note	!= NULL
* NOTE: No debe ser liberada la nota una vez agregada 
*/
void Module::addNote(Note *note)
{
	assert(note != NULL);
	this->noteList.push_back(note);
}

/* funcion que libera una nota de la lista liberando tambien
* la memoria.
* REQUIRES:
* 	note != NULL
*/
void Module::removeNote(Note *note)
{
	assert(note != NULL);
	this->noteList.remove(note);
	delete note;
}

/* Funcion que determina si ya existe una Nota en el 
* modulo. */
bool Module::existNote(Note *n)
{
	list<Note *>::iterator nit;
	
	if(n == NULL)
		return false;
	
	for(nit = this->noteList.begin(); nit != this->noteList.end(); ++nit) {
		assert(*nit != NULL);
		if(*(*nit) == *n)
			return true;
	}
	return false;
}

/* Functio used to add a issue associated to the module
* REQUIRES:
* 	i 	!= NULL
* NOTE: Do not free the issue once added
*/
void Module::addIssue(Issue *t)
{
	assert(t != NULL);
	this->issuesList.push_back(t);
}

/* Remove a issue associated to the module and free their memory
* REQUIRES:
* 	issue != NULL
*/
void Module::removeIssue(Issue *issue)
{
	assert(issue != NULL);
	this->issuesList.remove(issue);
	delete issue;
}

/* Funcion que determina si ya existe una tarea en el 
* modulo. */
bool Module::existIssue(Issue *t)
{
	list<Issue *>::iterator tit;
	
	if(t == NULL)
		return false;
	
	for(tit = this->issuesList.begin(); tit != this->issuesList.end(); ++tit) {
		assert(*tit != NULL);
		if (*(*tit) == *t)
			return true;
	}
	return false;
}

/*! Funcion que devuelve el porcentaje de completado del modulo
* teniendo en cuenta los porcentajes de las funciones que
* tiene asociado el modulo
*/
float Module::getCompleted(void)
{
	float completed = 0;
	int totalW = 0;
	list<Function *>::iterator it;
	
	for(it = this->funcList.begin(); it != this->funcList.end(); ++it) {
		assert(*it != NULL);
		completed += (*it)->getWeight() * (*it)->getCompleted();
		totalW += (*it)->getWeight();
	}
	completed = completed / (float) totalW;
	
	
	return completed;
}


/* destructor: empty destructor */
Module::~Module()
{
	// nothing to do
}


/* DEBUG */
void Module::Print(void)
{
	list<Function *>::iterator fit;
	list<Note *>::iterator nit;
	list<Issue *>::iterator tit;
	
	
	cout << "\nModule Name " << this->name;
	cout << "\nModule File Name " << this->fname;
	cout << "\nModule weight " << this->weight;
	cout << "\nCan compile: " << this->canCompile;
	cout << "\tTested: " << this->tested;
	cout << "\tModule Type " << this->type;
	
	cout << "\nFunciones del modulo \n";
	
	for(fit = this->funcList.begin(); fit != this->funcList.end(); ++fit) {
		assert(*fit != NULL);
		(*fit)->Print();
		
	}
	cout << "\n\n\nNotas: \n";
	for(nit = this->noteList.begin(); nit != this->noteList.end(); ++nit) {
		assert(*nit != NULL);
		(*nit)->Print();
	}
	cout << "\n\n\nTareas: \n";
	for(tit = this->issuesList.begin(); tit != this->issuesList.end(); ++tit) {
		assert(*tit != NULL);
		(*tit)->Print();
	}
	
}