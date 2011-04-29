/*
 * Module.h
 *
 *  Created on: 29/04/2011
 *      Author: agustin
 */

#ifndef MODULE_H_
#define MODULE_H_

#include <string>

#include "DebugUtil.h"
#include "IObject.h"

class Module : public IObject{
public:
	Module();
	virtual ~Module();
};

#endif /* MODULE_H_ */
