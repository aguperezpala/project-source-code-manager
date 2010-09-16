#include "function.h"


/* Constructor para setear todo de una */
Function::Function(string &n, int comp, int w)
{
	this->name = n;
	this->completed = comp;
	this->weight = w;
}

/* Virtual method to convert the object in a XML string. */
void Function::toXML(string &result)
{
	list<string> elemName;
	list<string> elemValues;
	string tagElement = "Function";
	string aux = "";
	
	/*! FIXME: here we have to fill the elements and the respective
	 * values */
	aux = "ObjectId";	
	elemName.push_back(aux);
	aux = /*FIXME*/this->getID();
	elemValues.push_back(aux);
	
	aux = "Completed";	
	elemName.push_back(aux);
	aux = /*FIXME*/this->getCompleted();
	elemValues.push_back(aux);
	
	aux = "Weight";	
	elemName.push_back(aux);
	aux = /*FIXME*/this->getWeight();
	elemValues.push_back(aux);
	
	aux = "Tested";	
	elemName.push_back(aux);
	if(this->getTesteed())
		auxx = "True";
	else
		aux = "False";
	elemValues.push_back(aux);
	
	aux = "Name";	
	elemName.push_back(aux);
	aux = this->getName();
	elemValues.push_back(aux);
	
	
	if (ssxmlp_create_element(tagElement, elemName, elemValues, result) < 0)
		perror("we cannot create the xml of the function...??");
	
	return;
}

/* Virtual method to import the object from a XML string 
	* RETURNS:
	* 	< 0	on error
	* 	0	if success
*/
int Function::fromXML(strnig &xml)
{
	string eName = "Function";
	list<string> eParse;
	list<string>::iterator pIt;
	list<string> results;
	list<string>::iterator rIt;
	
	
	
	if(ssxmlp_parse_element(xml, eName, eParse, results) < 0 || 
		eParse.length() != results.length())
		/* an error has ocurred */
		return -1;
	
	/* everything its ok, now we fill the object */
	
	pIt = eParse.begin();
	rIt = results.begin();
	
	/* FIXME: there are no error checking, review this */
	while(pIt != eParse.end() && rIt != results.end()) {
		
		/* now we have to parse every field and fill the fields 
		 * associated to the class */
		
		if((*pIt).find("ObjectId") != string::npos){
			int parsedId = atoi((*rIt).c_str());
			
			/* we have to parse the ID */
			this->setID(persedId);
			
		} else if((*pIt).find("Completed") != string::npos){
			string res = (*rIt);
			
			/* we convert to upper the result */
			parser_transform_upper(res);
			
			if(res.find("TRUE") != string::npos)
				this->setCompleted(true);
			else
				/* we are supposing that there is false other wise */
				this->setCompleted(false);
			
		} else if((*pIt).find("Weight") != string::npos) {
			int parsedWeight = atoi((*rIt).c_str());
			
			this->setWeight(parsedWeight);
		} else if((*pIt).find("Name") != string::npos) {
			this->setName((*rIt));
		} else if((*pIt).find("Completed") != string::npos){
			/* we convert to upper the result */
			string res = (*rIT);
			
			parser_transform_upper(res);
			
			if(res.find("TRUE") != string::npos)
				this->setCompleted(true);
			else
				/* we are supposing that there is false other wise */
				this->setCompleted(false);
		} else
			/* Some error ocurr, so we return -1. NOTE: here we ar
			 * letting the class in a inconsistent state, probably 
			 * the best in this case will be erase all the fields
			 * or the class itslef. */
			return -1;
		
		++pIt;
		++rIt;
	}
	
	return 0;
}



/* debug */
void Function::Print(void)
{
	cout << "\nFuncion Name " << this->name;
	cout << "\nFunction completed" << this->completed;
	cout << "\nFunction weight " << this->weight;
	cout << endl;	
}
