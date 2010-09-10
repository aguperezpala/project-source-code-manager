/*! This class will be a wrapper class. Every class will inehrit from this one.
 * Probably we can use the ID to "link" the different classes
 */
#ifndef COBJECT_H
#define COBJECT_H

#include <string>
/* own libraries */
#include "ssxmlparser.h" /* this will be used to the to/from XML functions */


using namespace std;

class CObject {
	
	public:
		/* empty consturctor */
		CObject(void){};
		
		/* returns the class ID */
		int getID(void){return this->id;};
		
		/* set the class ID */
		void setID(int ID){this->id = ID;};
		
		
		/*!### Reimplement this methods. */
		
		/*! Virtual method to convert the object in a XML string. */
		virtual void toXML(string &result){};
		
		/*! Virtual method to import the object from a XML string 
		 * RETURNS:
		 * 	< 0	on error
		 * 	0	if success
		*/
		virtual int fromXML(strnig &xml){};
		
		/* This function will be used to compare diferent objects,
		 * in some cases this could be defined in the class itself
		 */
		bool operator==(CObject &o){return (this->id == o.getID());};
		
		/* empty destructor */
		~CObject(void){};
	
	private:
		/* this will be the class id, every object it will have a 
		 * diferent ID */
		int id;
};


#endif

