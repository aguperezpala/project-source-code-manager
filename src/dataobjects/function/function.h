#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <assert.h>



using namespace std;


class Function {
	
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
		
		/* destructor */
		~Function(){};
		
		/*! DELETE_ME: debug */
		void Print(void);
	
	private:
		
		int completed;	/* % de completado de la funcion */
		int weight;	/* peso de la funcion en el modulo */
		bool tested;
		string name;
	
};




#endif
