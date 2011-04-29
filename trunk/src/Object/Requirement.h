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
#include <algorithm>
/* own libs */
#include "DebugUtil.h"
#include "IObject.h"




class Requirement : public IObject {
	
public:
	/* We gonna define some possible states that can be the requirement*/
	typedef enum {
		REQ_ST_DONE,		/* requeriment done */
		REQ_ST_OBSOLET,		/* requirement obsolet */
		REQ_ST_NOT_COMPLIED	/* requirement waiting to be done :) */
	} Status_t;

public:
	/* empty consturctor */
	Requirement(void);
	Requirement(const std::string &title, const std::string &desc, Status_t status);

	/* Function to set the description of the requirement
	 * REQUIRES:
	 * 	desc.length() > 0
	 */
	void setDescription(const std::string &desc){mDescription = desc;}
	const std::string &getDescription(void) const {return mDescription;}

	/* Function to set the title of the requirement
	 * REQUIRES:
	 * 	title.length() > 0
	 */
	void setTitle(const std::string &title) {mTitle = title;};
	const std::string &getTitle(void) const {return mTitle;}

	/* Set and get the status */
	Status_t getStatus(void) const {return mStatus;};
	void setStatus(Status_t st){mStatus = st;};

	/* Add a object dependence */
	void addObjectDependence(const IObject *object);

	/* Remove an object dependence */
	void removeObjectDependence(const IObject *object);
	
	/* empty destructor */
	~Requirement(void);

private:
	/* Requirement description */
	std::string mDescription;
	/* Requirement title */
	std::string mTitle;
	/* status of the requirement */
	Status_t mStatus;
	/* the list of the Object Dependencies */
	std::list<const IObject *> mObjectDependencies;

		
};


#endif

