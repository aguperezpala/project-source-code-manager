#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>
/* own libs */
#include "parser.h"
#include "cobject.h"


using namespace std;


class Function : public CObject {
	
	public:
		/* constructor */
		Function(){};
		
		/* Constructor para setear todo de una */
		Function(string &n, int comp, int w);
		
		/* setea/obtiene el nombre de la funcion */
		void setName(string &n){this->name = n;};
		string &getName(void){return this->name;};
		
		/* setea/obtiene el porcentaje completado */
		void setCompleted(int c){this->completed = c;};
		int getCompleted(void){return this->completed;};
		
		/* setea/obtiene el peso */
		void setWeight(int w){this->weight= w;};
		int getWeight(void){return this->weight;};
		
		/* setea/obtiene tested*/
		void setTested(bool t){this->tested = t;};
		bool getTested(void){return this->tested;};
		
		/*! the CObject virtual methods... */
		
		/* Virtual method to convert the object in a XML string. */
		void toXML(string &result);
		
		/* Virtual method to import the object from a XML string 
		 * RETURNS:
		 * 	< 0	on error
		 * 	0	if success
		*/
		int fromXML(strnig &xml);
		
		/*! Genera una funcion desde un string respetando el formato
		* asignado para guardar las funciones
		* RETURNS:
		* 	< 0	on error
		*	0	if success
		*/
		int fromString(string &str);
		
		/*! Convierte una funciones en un string listo para ser guardada
		* en un archivo.
		* RETURNS:
		*	NULL		if error
		*	funcStr		otherwise
		* NOTE: Genera memoria
		*/
		string *toString(void);
		
		
		~Function(){};
		
		/* debug */
		void Print(void);
	
	private:
		int completed;	/* % de completado de la funcion */
		int weight;	/* peso de la funcion en el modulo */
		bool tested;
		string name;
	
};




#endif
