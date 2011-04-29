#ifndef IDENTIFIABLEOBJECT_H
#define IDENTIFIABLEOBJECT_H

#include <string>

using namespace std;

/*! we gonna define the type used to the ID */
typedef int	ObjectId_t;

class IdentifiableObject {

	// private
	static int globalID;

	public:
		/* constructor */
		IdentifiableObject(){mID = ++globalID;} // TODO: not thread safe

		ObjectId_t getID(void){return mID;};
		
		bool operator==(IdentifiableObject &other){return (mID == other.getID());}
		
		virtual ~IdentifiableObject(){};
		
	private:
		ObjectId_t mID;
	
};



#endif
