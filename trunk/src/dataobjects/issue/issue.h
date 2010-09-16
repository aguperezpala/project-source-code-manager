#ifndef ISSUE_H
#define ISSUE_H

#include <iostream>
#include <string>
#include <string.h>
#include <stringstream>
#include <time.h>
/* own libs */
#include "cobject.h"
#include "parser.h"
#include "ssxmlparser.h"


using namespace std;


/* Enumeramos las prioridades */
enum {
	ISSUE_P_LOW,	
	ISSUE_P_MEDIUM,	
	ISSUE_P_HIGH
};
/* enumeramos los tipos */
enum {
	ISSUE_K_BUGFIX,		/* es una tarea para reparar un bug */
	ISSUE_K_REVISION,	/* es una tarea para revisar algo */
	ISSUE_K_TODO,		/* tarea normal */
	ISSUE_k_IMPROVE,	/* tarea de mejoramiento */
	ISSUE_K_NORMAL		/* tarea normal..? wtf XD */
};
/* enumeramos el estado en el que se puede encontrar la tarea */
enum {
	ISSUE_S_DONE,		/* tarea realizada */
	ISSUE_S_CHECKED		/* tarea vista/chequeada */
};

class Issue : public CObject {
	
	public:
		/* constructor */
		Issue(){};
				
		/* setea/obtiene la descripcion */
		void setDescription(string &d){this->desc = d;};
		string &getDescription(void){return this->desc;};
		
		/* setea/obtiene titulo */
		void setTitle(string &t){this->title = t;};
		string &getTitle(void){return this->title;};
		
		/* setea/obtiene el tiempo de creacion */
		void setCreatedTime(time_t &ct);
		time_t &getCreatedTime(void){return this->createdTime;};
		
		/* setea/obtiene el tiempo de fecha limite */
		void setLimitTime(time_t &lt);
		time_t &getLimitTime(void){return this->limitTime;};
		
		/* setea/obtiene el estado */
		void setStatus(int s){this->status = s;};
		int getStatus(void){return this->status;};
		void getStringStatus(string &s);
		
		/* setea/obtiene el tipo */
		void setKind(int k){this->kind= k;};
		int getKind(void){return this->kind;};
		void getStringKind(string &kind);
		
		/* setea/obtiene la prioridad */
		void setPriority(int p){this->priority= p;};
		int getPriority(void){return this->priority;};
		void getStringPriority(string &p);
		
		
		/*! Virtual method to convert the object in a XML string. */
		void toXML(string &result);
		
		/*! Virtual method to import the object from a XML string 
		* RETURNS:
		* 	< 0	on error
		* 	0	if success
		*/
		int fromXML(strnig &xml);
		

		~Issue(){};
		
		/*debug*/
		void Print(void);
	
	private:
		      
		string desc;
		string title;
		time_t createdTime;
		time_t limitTime;
		int status;
		int kind;
		int priority;
	
};




#endif
