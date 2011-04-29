/*
 * StringParser.cpp
 *
 *  Created on: 29/04/2011
 *      Author: agustin
 */

#include "StringParser.h"

StringParser::StringParser()
{

}

StringParser::~StringParser()
{

}


/* Function used to retrieve a value from a startPosition, and endPosition,
 * with that begins with strStart, and ends with strEnd.
 * RETURNS:
 * 		@result		The string parsed
 * 		endPos		the position of the strEnd or npos in error case
 */
size_t StringParser::getString(size_t from, size_t to,
					const std::string &startStr, const std::string &endStr,
					const std::string &data, std::string &result)
{
	size_t pos = 0, endPos = 0;
	size_t size = data.size();


	if (from > to || to > size){
		debug("ERROR: The startPosition is bigger than the EndPosition\n");
		return std::string::npos;
	}

	/* buscamos la posicion donde comienza el comentario */
	pos = data.find(startStr, from);

	if (pos == std::string::npos){
		debug("ERROR: We cant find startStr\n");
		return std::string::npos;
	}

	endPos = data.find(endStr, pos + 1);
	if ((endPos == std::string::npos) || (endPos > to)){
		debug("ERROR: We cant find endStr\n");
		return std::string::npos;
	}

	pos = pos + startStr.size();
	result = data.substr(pos, endPos - pos);

	return endPos;
}

/* Function used to parse from a startingPoint, until find a certain character
 * inside of charArray. If some of the characters is found, then is returned
 * over charFound, and the position of the ocurrence. Otherwise npos is returned
 */
size_t StringParser::getStringUntilChar(size_t startPos, const std::string &charArray,
								const std::string &data, char &charFound,
								std::string &result)
{
	size_t pos = startPos;

	while((pos < data.size()) &&
			(charArray.find(data[pos]) == std::string::npos)){
		pos++;
	}

	if(pos >= data.size()) {
		return std::string::npos;
	}

	charFound = data[pos];
	result = data.substr(startPos, pos - startPos);

	return pos;
}


/* This functions jumps chars from a list passed as argument from a string
 * (data) starting in a startPosition and returns the position of the
 * first char that is not in the jumpChars list.
 * In case that every char of data is one of jumpChars, then npos is returned
 */
size_t StringParser::jumpChars(size_t startPos, const std::string &data,
												const std::string &jumpChars)
{
	while((startPos < data.size()) &&
			(charArray.find(data[startPos]) != std::string::npos)){
		startPos++;
	}

	if(startPos >= data.size()) {
		return std::string::npos;
	}

	return startPos;
}



