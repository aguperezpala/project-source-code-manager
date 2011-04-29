/*
 * ISyntaxAnalizer.h
 *
 *  Created on: 27/04/2011
 *      Author: agustin
 */

#ifndef ISYNTAXANALIZER_H_
#define ISYNTAXANALIZER_H_


#include <string>
#include <list>

#include "DebugUtil.h"
#include "SyntaxConfiguration.h"

class ISyntaxAnalizer {
public:
	/* Constructor:	 */
	ISyntaxAnalizer();
	virtual ~ISyntaxAnalizer();


private:
	// The file extension that this SyntaxAnalizer support
	std::list<std::string> mExtSupported;


};

#endif /* ISYNTAXANALIZER_H_ */
