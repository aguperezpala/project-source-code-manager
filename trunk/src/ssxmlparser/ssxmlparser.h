/*! This it will be the Super Simpliest Xml parser... It will be used by all 
 *  the objects (toXmlString(), and fromXmlString() functions).
 */
#ifndef SSXMLPARSER_H
#define SSXMLPARSER_H

#include <iostream>
#include <list>
#include <string>
#include <string.h>
#include <assert.h>


using namespace std;


/* function wich extract all the content from a simple tag. Dosn't verify 
 * the data between the tags.
 * REQUIRES:
 * 	data	(where will be extracted the info)
 * 	tag	(element name who will be extracted NOTE: without the '<','>')
 * 	result	(empty string where it will be copied the parsed data)
 * RETURSN:
 * 	< 0	on error
 * 	>= 0	on succes (the num of bytes copied to result)
 */
int ssxmlp_extract_one_element(string &data, string &tag, string &result);

/* function will split the string in elements from an element name (and will
* put every element parsed in a list wich will be returned)
* REQUIRES:
* 	data	(where will be extracted the info)
* 	tag	(element name who will be extracted)
* 	result	(empty string where it will be copied the parsed data)
* RETURSN:
* 	< 0	on error
* 	>= 0	on succes (the num of bytes copied to result)
*/
int ssxmlp_extract_all_elements(string &data, string &tag, list<string> &result);

/* function to extract all the elements inside one specify element.
 * This function will return two lists, the first will contain the 
 * element name, and the second one will contain the value, and it will be
 * a biyection between the two lists (if no value are found, then a empty string
 * will be inserted in the list).
 * NOTE: if there elements inside others, the parser do not will consider this.
 * NOTE: We assume that there are only one element with that elementName, if not
 * 	only the first one will be parsed :(.
 * REQUIRES:
 * 	data			(wich will be parsed)
 * 	eName			(element name where will be parsed his content)
 * 	list<string> &eParse	(elements to parse)
 * 	list<string> &results	(value of the elements parsed)
 * RETURNS:
 * 	< 0			on error
 * 	0			if success
 */
int ssxmlp_parse_element(string &data, string &eName, list<string> &eParse,
			  list<string> &results);

/* Function wich creates a xmlobject from a list of elementsNames and the values
 * associated.
 * REQUIRES:
 * 	eName		(the element name)
 * 	subElemNList	(list of the sub elements name to be added)
 * 	subElemVList	(list of the sub elements value to be added)
 * 	result		(the string wich contains the xmlString)
 * RETURNS:
 * 	< 0		on error
 * 	0		if success
 */
int ssxmlp_create_element(string &eName, list<string> &subElemNList,
			   list<string> &subElemVList, string &result);
	
#endif
