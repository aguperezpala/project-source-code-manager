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
	
	while(pIt != eParse.end() && rIt != results.end()) {
		
		++pIt;
		++rIt;
	}
}


/*! Genera una funcion desde un string respetando el formato
* asignado para guardar las funciones
* RETURNS:
* 	< 0	on error
*	0	if success
*/
int Function::fromString(string &str)
{	
	string value = "";
	
	
	if (getValue(str, 0,"<f-c>", "<f-w>", value) < 0)
		return -1;
	else {
		if (sizeof(this->completed) != value.size())
			return -1;
		memcpy(&this->completed, value.c_str(), value.size());
	}
	
	if (getValue(str, 0,"<f-w>", "<f-n>", value) < 0)
		return -1;
	else {
		if (sizeof(this->weight) != value.size())
			return -1;
		/* debemos copiar lo que leimos en createdTime */
		memcpy(&this->weight, value.c_str(), value.size());
	}
	
	if (getValue(str, 0,"<f-n>", "<f-t>", this->name) < 0)
		return -1;
	
	if (getValue(str, 0,"<f-t>", "<fun;>", value) < 0)
		return -1;
	else {
		if (sizeof(this->tested) != value.size())
			return -1;
			/* debemos copiar lo que leimos en createdTime */
			memcpy(&this->tested, value.c_str(), value.size());
	}
	
	return 0;
	/*<f-c>completed<f-w>weight<f-n>name<fun;>*/
	
}


/* debug */
void Function::Print(void)
{
	cout << "\nFuncion Name " << this->name;
	cout << "\nFunction completed" << this->completed;
	cout << "\nFunction weight " << this->weight;
	cout << endl;	
}
