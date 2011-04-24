#include "parser.h"

/*! ### ###		NEW PARSER		### ### */


/* Auxiliar function used to jump the every "cs" characters in data 
* and returns the position of the first character that dont belongs to cs
* REQUIRES:
* 	cs != NULL
* RETURNS:
* 	< 0	on error
* 	pos	otherwise
*/
static int parser_jump_chars(string &d, int from, const char* cs)
{
	int size = d.size();
	string aux = "";
	
	assert(cs != NULL);
	
	aux = cs;
	
	while (from < size)
		if(aux.find(d[from]) != string::npos)
			from++;
		else
			break;
	return from;
}

/*! Funcion que parsea un todos los comentarios que encuentra comenzando
* desde from y terminando en to, los guarda en una lista y los devuelve 
* NOTE: devuelve el comentario sin los caracteres de comentarios
* REQUIRES:
* 	from 	<= to
* 	to	<= data.size()
* 	openComment != NULL
* 	closeComment != NULL
* RETURNS:
* 	NULL		if cant find or error
* 	comment		otherwise
*/
list<string> *parser_get_comments(string &data, int from, int to,
				  string &openComment, string &closeComment)
{
	list<string> *result = NULL;
	int pos = 0, endPos = 0;
	string aux = "";
	int size = (int) data.size();
	
	
	if (from > to || to > size){
		return result;
	}
	
	result = new list<string>();
	if(result == false)
		return result;
	
	while (from <= to) {
		/* buscamos la posicion donde comienza el comentario */
		pos = data.find(openComment, from);
		
		if (pos < 0)
			break;
		
		endPos = data.find(closeComment, pos + 1);
		if (endPos < 0)
			break;
		pos = pos + (int)openComment.size();
		from = endPos + closeComment.size();
		aux = data.substr(pos, endPos - pos);
		result->push_back(aux);
	}
	
	if((int) result->size() == 0){
		delete result;
		result = NULL;
	}
	
	return result;
}



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
 * 	value		the value parsed (on no error case)
 */
int parser_extract_value(string &data, size_t pos, string &key, string &eqStr,
			 string &endStr, string &value)
{
	int result = 0;
	size_t ePos = 0, eqPos = 0, bPos = 0;
	
	if((data.length() <= 1) || (pos > data.length()) || (key.length() == 0)
		|| (eqStr.length() == 0) || (endStr.length() == 0))
		// there are nothing to do... returns error
		return -1;
	
	// find the begin of the key
	bPos = data.find(key, pos);
	if(bPos == string::npos)
		return -1;
	
	// now find the assign string in a smart way
	bPos = bPos + key.length();
	eqPos = data.find(eqStr, bPos);
	if((int) eqPos != parser_jump_chars(data, bPos + 1, PARSER_BLANKS))
		// we are in other key assign string, this is an error.
		return -1;
	
	// if we are here then everything its ok. Now parse the value
	eqPos = eqPos + eqStr.length() + 1;
	ePos = data.find(endStr, eqPos);
	if(ePos == string::npos)
		// there are not end pos?? error
		return -1;
	
	// here we have what are we looking for, so we parse it
	value = data.substr(eqPos, ePos - eqPos);
	result = (int) ePos + endStr.length();
	
	return result;
}




