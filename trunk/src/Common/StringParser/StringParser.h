/*
 * StringParser.h
 *
 *  Created on: 29/04/2011
 *      Author: agustin
 */

#ifndef STRINGPARSER_H_
#define STRINGPARSER_H_

#include <string>

#include "DebugUtil.h"

#define	BLANK_SPACES  		"\n\t\r"

class StringParser {

public:

	/* Function used to retrieve a value from a startPosition, and endPosition,
	 * with that begins with strStart, and ends with strEnd.
	 * RETURNS:
	 * 		@result		The string parsed
	 * 		endPos		the position of the strEnd or npos in error case
	 */
	static size_t getString(size_t startPosition, size_t endPosition,
						const std::string &startStr, const std::string &endStr,
						const std::string &data, std::string &result);

	/* Function used to parse from a startingPoint, until find a certain character
	 * inside of charArray. If some of the characters is found, then is returned
	 * over charFound, and the position of the ocurrence. Otherwise npos is returned
	 */
	static size_t getStringUntilChar(size_t startPos, const std::string &charArray,
									const std::string &data, char &charFound,
									std::string &result);

	/* This functions jumps chars from a list passed as argument from a string
	 * (data) starting in a startPosition and returns the position of the
	 * first char that is not in the jumpChars list.
	 * In case that every char of data is one of jumpChars, then npos is returned
	 */
	static size_t jumpChars(size_t startPos, const std::string &data,
									const std::string &jumpChars = BLANK_SPACES);

	virtual ~StringParser();
private:
	StringParser();
	StringParser(StringParser &other);

};

#endif /* STRINGPARSER_H_ */
