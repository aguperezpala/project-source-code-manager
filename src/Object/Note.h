#ifndef NOTE_H
#define NOTE_H

#include <string>


#include "DebugUtil.h"
#include "IObject.h"





class Note : public IObject {
	
	public:
		/* constructor */
		Note(const std::string &note, const std::string &Title = "")
		: mNote(note), mTitle(title)
		{};
		
		Note(){};
		
		
		/* setea/obtiene el nombre de la funcion */
		void setNote(const std::string &n){mNote = n;};
		const std::string &getNote(void) const {return mNote;};
		
		void setTitle(const std::string &t){mTitle = t;};
		const std::string &getTitle(void) const {return mTitle;};
		
		
		virtual ~Note(){};
		
		/*debug */
		void Print(void){std::cout << "note: " << note << std::endl;};
	
	private:
		std::string mNote;
		std::string mTitle;
	
};




#endif
