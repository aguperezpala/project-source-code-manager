#include "Requirement.h"

/* empty consturctor */
Requirement::Requirement(void)
{
	/* nothing to do */
}
Requirement::Requirement(const std::string &title, const std::string &desc, Status_t status) :
	mTitle(title),
	mDescription(desc),
	mStatus(status)
{
	// do nothing
}

/* empty destructor */
Requirement::~Requirement(void)
{
	// nothing
}



/* Add a object dependence */
void Requirement::addObjectDependence(const IObject *object)
{
	ASSERT(object);

	if(std::find(mObjectDependencies.begin(), mObjectDependencies.end(), object) ==
			mObjectDependencies.end()) {
		// add the object
		mObjectDependencies.push_back(object);
	} else {
		debug("Error, we are trying to add two times the same object\n");
	}
}

/* Remove an object dependence */
void Requirement::removeObjectDependence(const IObject *object);
