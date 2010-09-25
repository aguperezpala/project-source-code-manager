#include "project.h"

Project::Project(string &dir)
{
	this->projDir = dir;
}

/* funcion que agrega un modulo al proyecto
* REQUIRES:
* 	module != NULL
* NOTE: No debe ser eliminada la funcion una vez agregada.
*/
void Project::addModule(Module *module)
{
	assert(module != NULL);
	this->moduleList.push_back(module);
}

/* Remove the module from the project
* REQUIRES:
* 	obj 	!= NULL
*/
void Project::removeModule(Module *obj)
{
	assert(obj != NULL);
	this->moduleList.remove(obj);
}

/* Funcion que permite agregar una nota relacionada al modulo
* REQUIRES:
* 	note	!= NULL
* NOTE: No debe ser liberada la nota una vez agregada 
*/
void Project::addNote(Note *note)
{
	assert(note != NULL);
	this->noteList.push_back(note);
}

/* Remove the note from the project
* REQUIRES:
* 	obj 	!= NULL
*/
void Project::removeNote(Note *obj)
{
	assert(obj != NULL);
	this->noteList.remove(obj);
}

/* Funcion que permite agregar una tarea relacionada al modulo
* REQUIRES:
* 	t 	!= NULL
* NOTE: No debe ser liberada la tarea una vez agregada 
*/
void Project::addIssue(Issue *t)
{
	assert(t != NULL);
	this->issuesList.push_back(t);
}

/* Remove the issue from the project
* REQUIRES:
* 	obj 	!= NULL
*/
void Project::removeIssue(Issue *obj)
{
	assert(obj != NULL);
	this->issuesList.remove(obj);
}

/*! Funcion que devuelve el porcentaje de completado del modulo
* teniendo en cuenta los porcentajes de las funciones que
* tiene asociado el modulo
*/
float Project::getCompleted(void)
{
	float completed = 0;
	int totalW = 0;
	list<Module *>::iterator it;
	
	for(it = this->moduleList.begin(); it != this->moduleList.end(); ++it) {
		assert(*it != NULL);
		completed += (float)(*it)->getWeight() * (*it)->getCompleted();
		totalW += (*it)->getWeight();
	}
	completed = completed / (float) totalW;
	
	
	return completed;
}


/* destructor: empty */
Project::~Project()
{
	// nothing to do
}


/* DEBUG */
void Project::Print(void)
{
	list<Module *>::iterator fit;
	list<Note *>::iterator nit;
	list<Issue *>::iterator tit;	
	
	cout << "\nProject Name: " << this->name;
	cout << "\nProject Dir: " << this->projDir;
	cout << "\nProject Completed" << getCompleted();
	cout << "\nCan compile: " << this->canCompile;
	cout << "\tTested: " << this->tested;
	
	cout << "\nModulos del proyecto \n";
	
	for(fit = this->moduleList.begin(); fit != this->moduleList.end(); ++fit) {
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



