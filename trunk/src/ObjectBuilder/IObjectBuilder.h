/*
 * IObjectBuilder.h
 *
 *  Created on: 29/04/2011
 *      Author: agustin
 */

#ifndef IOBJECTBUILDER_H_
#define IOBJECTBUILDER_H_


#include <string>
#include <map>

#include "DebugUtil.h"
#include "IObject.h"

class IObjectBuilder {
public:
	/* Constructor: Take the builder name to identify it */
	IObjectBuilder(const std::string &builderName) : mName(builderName){};
	virtual ~IObjectBuilder();

	/* Get the builder Name */
	const std::string &getName(void) const {return mName;}

	/* Builds the object.
	 * REQUIRES:
	 * 		data	The list of data
	 *  RETURNS:
	 *  	object	On error is NULL, if not, returns the Object allocated.
	 *  			Who call this functions is now the owner of the memory
	 *  	error	Error info (if there are some error, else this will be empty)
	 */
	virtual IObject *buildObject(const std::list<std::string> &data,
													std::string &error)
	{error = "Not implemented" ; return 0;}


private:
	std::string mName;

};

#endif /* IOBJECTBUILDER_H_ */
