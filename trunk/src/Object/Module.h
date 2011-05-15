/*
 * Module.h
 *
 *  Created on: 29/04/2011
 *      Author: agustin
 */

#ifndef MODULE_H_
#define MODULE_H_

#include <string>
#include <list>
#include <map>

#include "DebugUtil.h"
#include "IObject.h"

class Module : public IObject {
public:
	Module();
	virtual ~Module();


	/* Add a new IObject. If the object already exits this function do nothing
	 * REQUIRES:
	 * 		obj		!= 0
	 */
	void addNewObject(IObject *obj);

	/* Remove a IObject
	 * REQUIRES:
	 * 		obj		!= 0
	 */
	void removeObject(IObject *obj);

	/* Get a list of objects of a certain kind (or empty list if haven't) */
	const std::list<IObject*> &getObjects(IObject::ObjectType_t t);



	/* 			This will be the extra values used by the Module 			 */
	/* 			Getters			/			Setters							 */

	const std::string &getDescription() const {return mDescription;}
	const std::string &getFileName() const {return mFileName;}
	const std::string &getModuleName() const {return mModuleName;}
	void setDescription(const std::string &d) {mDescription = d;}
	void setFileName(const std::string &f) {mFileName = f;}
	void setModuleName(const std::string &m) {mModuleName = m;}

private:
	// Description of the module
	std::string mDescription;
	// FileName
	std::string mFileName;
	// Module Name
	std::string mModuleName;

	// Objects associated to the module
	std::map<IObject::ObjectType_t, std::list<IObject*> > mObjects;
};

#endif /* MODULE_H_ */
