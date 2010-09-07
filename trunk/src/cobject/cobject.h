/*! This class will be a wrapper class. Every class will inehrit from this one.
 * Probably we can use the ID to "link" the different classes
 */
#ifndef COBJECT_H
#define COBJECT_H


class CObject {
	
	public:
		/* empty consturctor */
		CObject(void){};
		
		/* returns the class ID */
		int getID(void){return this->Id;};
		
		/* set the class ID */
		void setID(int ID){this->Id = ID;};
		
		/* empty destructor */
		~CObject(void){};
	
	private:
		/* this will be the class id, every object it will have a 
		 * diferent ID */
		int Id;
};


#endif

