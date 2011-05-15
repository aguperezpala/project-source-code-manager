/*
 * Module.cpp
 *
 *  Created on: 29/04/2011
 *      Author: agustin
 */

#include "Module.h"

Module::Module():IObject(IObject::TYPE_MODULE) {
	// TODO Auto-generated constructor stub

}

Module::~Module() {
	// TODO Auto-generated destructor stub
}




/* Add a new IObject. If the object already exits this function do nothing
 * REQUIRES:
 * 		obj		!= 0
 */
void Module::addNewObject(IObject *obj)
{
	ASSERT(obj);

	if(mObjects.find(obj->getType()) != mObjects.end()){
		return;
	}

	mObjects[obj->getType()].push_back(obj);
}

/* Remove a IObject
 * REQUIRES:
 * 		obj		!= 0
 */
void Module::removeObject(IObject *obj)
{
	ASSERT(obj);

	if(mObjects.find(obj->getType()) == mObjects.end()){
		return;
	}

	mObjects[obj->getType()].remove(obj);
}

/* Get a list of objects of a certain kind (or empty list if haven't) */
const std::list<IObject*> &Module::getObjects(IObject::ObjectType_t t)
{
	// note that in this case the list is created if it not exists..
	return mObjects[t];
}

