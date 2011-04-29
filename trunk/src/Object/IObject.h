/*
 * IObject.h
 *
 *  Created on: 28/04/2011
 *      Author: agustin
 */

#ifndef IOBJECT_H_
#define IOBJECT_H_



#include "DebugUtil.h"
#include "identifiableobject.h"


class IObject : public IdentifiableObject {

public:

	// this its real ugly but it the fastest solution :(
	typedef enum {
		NON_TYPE,		// have no type
		TYPE_FUNCTION,
		TYPE_NOTE,
		TYPE_ISSUE,
		TYPE_REQUIREMENT,
		TYPE_MODULE
	} ObjectType_t;

public:
	IObject(ObjectType_t t = NON_TYPE) : mType(t)
	{};
	virtual ~IObject() {};

	ObjectType_t getType(void) const {return mType;}


private:
	IObject();
	IObject(IObject &other);

private:
	ObjectType_t mType;
};

#endif /* IOBJECT_H_ */
