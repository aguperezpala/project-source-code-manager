#include "ssxmlparser.h"


/* Function wich form the "tags" from a element Name, the begin tag and the
 * "end" tag, (i.e: if the element name is: "element" => this function will
 * return two strings: <element> and </element>
 * REQUIRES:
 * 	elementName
 * 	bTag
 * 	eTag
 */
static void ssxmlp_generate_tags(string &elementName, string &bTag, string &eTag)
{	
	bTag = "<";
	eTag = "</";
	
	bTag.append(elementName);
	bTag.append(">");
	eTag.append(elementName);
	eTag.append(">");
	
}

/* function wich extract all the content from a simple tag. Dosn't verify 
 * the data between the tags.
 * REQUIRES:
 * 	data	(where will be extracted the info)
 * 	tag	(element name who will be extracted)
 * 	result	(empty string where it will be copied the parsed data)
 * RETURSN:
 * 	< 0	on error
 * 	>= 0	on succes (the num of bytes copied to result)
 */
int ssxmlp_extract_one_element(string &data, string &tag, string &result)
{
	size_t bP = 0, eP = 0;
	string bTag, eTag;
	
	/* we gonna set the characters of the xml notation */
	ssxmlp_generate_tags(tag, bTag, eTag);
	
	/* we find the tag now */
	
	bP = data.find(bTag);	
	eP = data.find(eTag);
	
	if(bP == string::npos || eP == string::npos || eP <= bP)
		/* nothing to parse */
		return -1;
	
	/* now parse it */
	bP = bP + bTag.length();
	eP = eP - bP;
	result = data.substr(bP, eP);
	
	return (int) eP;
}

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
int ssxmlp_extract_all_elements(string &data, string &tag, list<string> &result)
{
	size_t bP = 0, eP = 0;
	string bTag, eTag;
	
	ssxmlp_generate_tags(tag, bTag, eTag);
	
	/* we clean the list */
	result.clear();
	
	/* start to extract the elements */
	while(bP != string::npos && eP != string::npos)	{
		bP = data.find(bTag, bP);	
		eP = data.find(eTag, bP);
		
		if(bP == string::npos || eP == string::npos || eP <= bP)
			/* nothing to parse */
			break;
		
		/* now parse it */
		bP = bP + bTag.length();
		eP = eP - bP;
		result.push_back(data.substr(bP, eP));
		bP += eP + eTag.length();
	}
	
	return 0;
}

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
			  list<string> &results)
{
	size_t bP = 0, eP = 0, elemEndPos = 0;
	string bTag, eTag, tag;
	
	
	/* first we find the root element */
	ssxmlp_generate_tags(eName, bTag, eTag);
	
	bP = data.find(bTag);
	eP = data.find(eTag);
	
	if(bP == string::npos || eP == string::npos || eP <= bP)
		/* nothing to parse */
		return -1;
	bP += bTag.length();
	elemEndPos = eP;
	
	results.clear();
	eParse.clear();
	
	/* now we have to extract all the elements betwen the bP and eP */
	while(1) {		
		/* we find the char '< ' and we try to find the end tag of
		 * the element */
		
		bP = data.find("<", bP);
		eP = data.find(">", bP);
		
		if(bP == string::npos || eP == string::npos || eP <= bP)
			/* nothing to parse */
			break;
		tag = data.substr(bP + 1, eP - bP - 1);
		/* generate the tag */
		ssxmlp_generate_tags(tag, bTag, eTag);
		/* now we find the end tag, and see if it is inside of the
		 * element */
		eP = data.find(eTag, bP);
		if(eP == string::npos || eP > elemEndPos){
			/* error.... ? something its wrong */
			break;
		}
		
		/* if we are here => there are a element to extract */
		eParse.push_back(tag);
		bP = bP + bTag.length();
		results.push_back(data.substr(bP, eP - bP));
		
		/* actualize the position pointers */
		bP = eP + eTag.length();
	}
	
	return 0;
}


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
			   list<string> &subElemVList, string &result)
{
	list<string>::iterator eIt;
	list<string>::iterator vIt;
	string bTag, eTag;
	
	
	/* check that the size of the list its the same */
	if (subElemNList.size() != subElemVList.size())
		return -1;
	
	result = "";
	
	ssxmlp_generate_tags(eName, bTag, eTag);
	result.append(bTag);
	result.append("\n\n");
	
	eIt = subElemNList.begin();
	vIt = subElemVList.begin();
	
	while(eIt != subElemNList.end() && vIt != subElemVList.end()) {
		/* first create the tags of the elements */
		ssxmlp_generate_tags((*eIt), bTag, eTag);
		result.append(bTag);
		result.append("\n");
		result.append(*vIt);
		result.append("\n");
		result.append(eTag);
		result.append("\n\n");
		
		++eIt;
		++vIt;
	}
	ssxmlp_generate_tags(eName, bTag, eTag);
	result.append(eTag);
	
	return 0;
}
