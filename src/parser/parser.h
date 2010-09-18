#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define PARSER_BLANKS	"\n\t "


using namespace std;


/* Extract a value from a key, To much parameters...
 * REQUIRES:
 * 	data		data where be searched the key
 * 	pos		from where it will be searched
 * 	key		the to looking for
 * 	eqStr		the "assignation" string (KEY = VALUE, where eqStr is =)
 * 	endStr		the string used to delimit the end of the str.
 * RETURNS:
 * 	ePos		the position of the last character of the endStr mattched
 * 	< 0		on error
 * 	value		(the value, on no error cases)
 */
int parser_extract_value(string &data, size_t pos, string &key, string &eqStr,
			 string &endStr, string &value);



#endif
