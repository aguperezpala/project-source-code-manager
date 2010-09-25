#include "identifiableobject.h"


bool IdentifiableObject::operator==(IdentifiableObject &other)
{
	return (this->ID == other.getID());
}