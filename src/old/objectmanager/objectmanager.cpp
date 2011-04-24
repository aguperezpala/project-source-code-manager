#include "objectmanager.h"


/* consturctor: */
ObjectManager::ObjectManager(void)
{
	this->lastId = 0;
}

/* Function to delete (and free the memory allocated for the
* elements).
*/
void ObjectManager::deleteAllObjects(void)
{
	map<ObjectId_t, Project*>::iterator pi;
	map<ObjectId_t, Note*>::iterator ni;
	map<ObjectId_t, Requirement*>::iterator ri;
	map<ObjectId_t, Issue*>::iterator ii;
	map<ObjectId_t, Module*>::iterator mi;
	
	for(pi = this->projHash.begin(); pi != this->projHash.end(); ++pi)
		if((*pi).second != NULL)
			delete (*pi).second;
	
	for(ni = this->noteHash.begin(); ni != this->noteHash.end(); ++ni)
		if((*ni).second != NULL)
			delete (*ni).second;
	
	for(ri = this->reqHash.begin(); ri != this->reqHash.end(); ++ri)
		if((*ri).second != NULL)
			delete (*ri).second;
	
	for(ii = this->issueHash.begin(); ii != this->issueHash.end(); ++ii)
		if((*ii).second != NULL)
			delete (*ii).second;
	
	for(mi = this->modHash.begin(); mi != this->modHash.end(); ++mi)
		if((*mi).second != NULL)
			delete (*mi).second;
	
}

/*! NOTE: This class will kept the objects pointers, so do not
* free the objects once you have call one of the add* function
*/

/*!		Function to manage the Projects		*/
bool ObjectManager::existsProject(ObjectId_t id)
{
	return (this->projHash.find(id) != this->projHash.end());
}

void ObjectManager::addProject(Project *p)
{
	assert(p != NULL);
	assert(!existsProject(p->getID()));
	
	if(this->lastId < p->getID()) 
		this->lastId = p->getID();
	
	this->projHash[p->getID()] = p;
}
void ObjectManager::removeProject(ObjectId_t id)
{	
	assert(!existsProject(id));
	
	delete this->projHash[id];
	this->projHash.erase(id);
}


/*!		Function to manage the Modules		*/
bool ObjectManager::existsModule(ObjectId_t id)
{
	return (this->modHash.find(id) != this->modHash.end());
}
void ObjectManager::addModule(Module *m)
{
	assert(m != NULL);
	assert(!existsModule(m->getID()));
	
	if(this->lastId < m->getID()) 
		this->lastId = m->getID();
	
	this->modHash[m->getID()] = m;
}
void ObjectManager::removeModule(ObjectId_t id)
{	
	assert(!existsModule(id));
	
	delete this->modHash[id];
	this->modHash.erase(id);
}



/*!		Function to manage the Notes		*/
bool ObjectManager::existsNote(ObjectId_t id)
{
	return (this->noteHash.find(id) != this->noteHash.end());
}
void ObjectManager::addNote(Note *n)
{
	assert(n != NULL);
	assert(!existsNote(n->getID()));
	
	if(this->lastId < n->getID()) 
		this->lastId = n->getID();
	
	this->noteHash[n->getID()] = n;
}
void ObjectManager::removeNote(ObjectId_t id)
{	
	assert(!existsNote(id));
	
	delete this->noteHash[id];
	this->noteHash.erase(id);
}




/*!		Function to manage the Issues		*/
bool ObjectManager::existsIssue(ObjectId_t id)
{
	return (this->issueHash.find(id) != this->issueHash.end());
}
void ObjectManager::addIssue(Issue *i)
{
	assert(i != NULL);
	assert(!existsIssue(i->getID()));
	
	if(this->lastId < i->getID()) 
		this->lastId = i->getID();
	
	this->issueHash[i->getID()] = i;
}
void ObjectManager::removeIssue(ObjectId_t id)
{	
	assert(!existsIssue(id));
	
	delete this->issueHash[id];
	this->issueHash.erase(id);
}




/*!		Function to manage the Requirements	*/
bool ObjectManager::existsRequirement(ObjectId_t id)
{
	return (this->reqHash.find(id) != this->reqHash.end());
}
void ObjectManager::addRequirement(Requirement *r)
{
	assert(r != NULL);
	assert(!existsRequirement(r->getID()));
	
	if(this->lastId < r->getID()) 
		this->lastId = r->getID();
	
	this->reqHash[r->getID()] = r;
}
void ObjectManager::removeRequirement(ObjectId_t id)
{	
	assert(!existsRequirement(id));
	
	delete this->reqHash[id];
	this->reqHash.erase(id);
}





/* empty destructor, It free all the memory allocated */
ObjectManager::~ObjectManager(void)
{
	deleteAllObjects();
}

