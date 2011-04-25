/*
*  Useful functions used in debug
*
*  Created on: 18/11/2010
*      Author: agustin
*/

#ifndef DEBUGUTIL_H_
#define DEBUGUTIL_H_



#ifdef DEBUG
	#include <assert.h>
#include <stdio.h>

	#define ASSERT(x)	assert(x);
	#define debug(format, ...) {fprintf(stderr, "DEBUG[%s, %s, %d]: ", \
					 __FILE__, __FUNCTION__, __LINE__); \
					fprintf(stderr, format, ## __VA_ARGS__);}

#else
	#define ASSERT(x)
	#define debug(format,...)

#endif


#endif /* DEBUGUTIL_H_ */
