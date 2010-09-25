#include "requirement.h"

/* empty consturctor */
Requirement::Requirement(void)
{
	/* nothing to do */
}
Requirement::Requirement(string &t, string &desc, int st)
{
	this->title = t;
	this->description = desc;
	this->status = st;
}
/* Function to set the description of the requirement
* REQUIRES:
* 	desc.length() > 0 
*/
void Requirement::setDescription(string &desc)
{
	this->description = desc;
}

/* Function to set the title of the requirement
* REQUIRES:
* 	title.length() > 0 
*/
void Requirement::setTitle(string &t)
{
	this->title = t;
}


/* Function to add a issue who the requirements depends of
* REQUIRES:
* 	issue	!= NULL
*/
void Requirement::addIssueDependency(Issue *issue)
{
	assert(issue != NULL);
	this->issueDependenciesList.push_back(issue);
}

/* Removes the issue dependency (do not free the memory)
* REQUIRES:
* 	issue != NULL
*/
void Requirement::removeIssueDependency(Issue *issue)
{
	assert(issue != NULL);
	this->issueDependenciesList.remove(issue);
}

/* Function to add a module who the requirements depends of
* REQUIRES:
* 	mod	!= NULL
*/
void Requirement::addModuleDependency(Module *mod)
{
	assert(mod != NULL);
	this->moduleDependenciesList.push_back(mod);
}

/* Removes the module dependency (do not free the memory)
* REQUIRES:
* 	mod != NULL
*/
void Requirement::removeModuleDependency(Module *mod)
{
	assert(mod != NULL);
	this->moduleDependenciesList.remove(mod);
}

/* empty destructor */
Requirement::~Requirement(void)
{
	// nothing
}