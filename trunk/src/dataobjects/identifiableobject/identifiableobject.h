#ifndef IDENTIFIABLEOBJECT_H
#define IDENTIFIABLEOBJECT_H

#include <string>

using namespace std;

/*! we gonna define the type used to the ID */
typedef int	ObjectId_t;

class IdentifiableObject {
      
	public:
		/* constructor */
		IdentifiableObject(ObjectId_t id = 0){this->ID = id;};
		
		void setID(ObjectId_t id){this->ID = id;};
		
		ObjectId_t getID(void){return this->ID;};
		
		bool operator==(IdentifiableObject &other);
		
		~IdentifiableObject(){};
		
		
	private:
		ObjectId_t ID;
	
};




#endif
