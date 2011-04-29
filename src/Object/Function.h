#ifndef FUNCTION_H
#define FUNCTION_H


#include <string>

#include "DebugUtil.h"
#include "IObject.h"



class Function : public IObject {
	
	public:
		/* constructor */
		Function(int completed, int weight, bool tested,
				const std::string &name, const std::string &signature = "");
		
		Function():IObject(IObject::TYPE_FUNCTION){};
		
		/* setea/obtiene el nombre de la funcion */
		void setName(const std::string &n){mName = n;}
		const std::string &getName(void) const {return mName;}
		
		/* setea/obtiene el porcentaje completado */
		void setCompleted(int c){mCompleted = c;};
		int getCompleted(void){return mCompleted;};
		
		/* setea/obtiene el peso */
		void setWeight(int w){mWeight = w;};
		int getWeight(void){return mWeight;};
		
		/* setea/obtiene tested*/
		void setTested(bool t){mTested = t;};
		bool getTested(void){return mTested;};
		
		// signature
		void setSignature(const std::string &s){mSignature = s;}
		const std::string &getSignature(void) const {return mSignature;}


		/* destructor */
		virtual ~Function(){};
		
		/*! DELETE_ME: debug */
		void Print(void);
	
	private:
		int mCompleted;	/* % de completado de la funcion */
		int mWeight;	/* peso de la funcion en el modulo */
		bool mTested;
		std::string mName;
		std::string mSignature;
	
};




#endif
