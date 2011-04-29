#ifndef ISSUE_H
#define ISSUE_H

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <time.h>

#include "DebugUtil.h"
#include "IObject.h"




class Issue : public IObject  {
	
public:
	/* Enumeramos las prioridades */
	typedef enum {
		ISSUE_P_LOW,
		ISSUE_P_MEDIUM,
		ISSUE_P_HIGH
	} Priority_t;

	/* enumeramos los tipos */
	typedef enum {
		ISSUE_K_BUGFIX,		/* es una tarea para reparar un bug */
		ISSUE_K_REVISION,	/* es una tarea para revisar algo */
		ISSUE_K_TODO,		/* tarea normal */
		ISSUE_k_IMPROVE,	/* tarea de mejoramiento */
		ISSUE_K_NORMAL		/* tarea normal..? wtf XD */
	} Kind_t;

	/* enumeramos el estado en el que se puede encontrar la tarea */
	typedef enum {
		ISSUE_S_DONE,		/* tarea realizada */
		ISSUE_S_CHECKED		/* tarea vista/chequeada */
	} State_t;

	public:
		/* constructor */
		Issue();
				
		/* setea/obtiene la descripcion */
		void setDescription(const std::string &d){mDesc = d;};
		const std::string &getDescription(void) const {return mDesc;};
		
		/* setea/obtiene titulo */
		void setTitle(const std::string &t){mTitle = t;};
		const std::string &getTitle(void) const {return mTitle;};
		
		/* setea/obtiene el tiempo de creacion */
		void setCreatedTimeNow(void); // sets the actual time
		void setCreatedTime(const time_t &ct);
		const time_t &getCreatedTime(void) const {return mCreatedTime;};
		
		/* setea/obtiene el tiempo de fecha limite */
		void setLimitTime(const time_t &lt);
		const time_t &getLimitTime(void) const {return mLimitTime;};
		
		/* setea/obtiene el estado */
		void setStatus(State_t s){mStatus = s;};
		State_t getStatus(void) const {return mStatus;};

		void getStringStatus(std::string &s) const;
		
		/* setea/obtiene el tipo */
		void setKind(Kind_t k) {mKind = k;};
		Kind_t getKind(void) const {return mKind;};

		void getStringKind(std::string &kind) const;
		
		/* setea/obtiene la prioridad */
		void setPriority(Priority_t p){mPriority = p;};
		Priority_t getPriority(void) const {return mPriority;};

		void getStringPriority(std::string &p) const;
		
		~Issue(){};
		
		/*debug*/
		void Print(void);
	
	private:
		      
		std::string mDesc;
		std::string mTitle;
		time_t mCreatedTime;
		time_t mLimitTime;
		State_t mStatus;
		Kind_t mKind;
		Priority_t mPriority;
	
};




#endif
