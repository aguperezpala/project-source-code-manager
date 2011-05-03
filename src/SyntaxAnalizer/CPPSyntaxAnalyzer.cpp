/*
 * CPPSyntaxAnalyzer.cpp
 *
 *  Created on: 02/05/2011
 *      Author: agustin
 */

#include "CPPSyntaxAnalyzer.h"

/* Extract a clean Comment of kind multiline comment
 * REQUIRES:
 * 		data		where we will extract the comment
 * 		pos			where the comment begins (including the / * chars)
 * 		comment		the comment cleanly parsed
 */
bool CPPSyntaxAnalyzer::parseMultiLineComment(const std::string &data, size_t pos,
												std::string &comment)
{
	ASSERT((data[pos] == '/') && (data[pos+1] == '*'));

	comment.clear();

	size_t endPos = data.find("*/");

	if(endPos == std::string::npos){
		debug("ERROR: The comment never close? The .cpp is bad! \n");
		return false;
	}

	// we have a good comment, now extract all the possibilities of * chars

}

/* Extract all the comments and put it in a list. This function will work
 * "Intelligently". If we have 2 comments like //a\n//b then we will convert
 * as one comment. If we have a comment like / * a\n * b\n * c\n * / then
 * we will extract the * char.
 * RETURNS:
 * 		0			on success (and the list filled)
 * 		errCode		otherwise
 */
int CPPSyntaxAnalyzer::parseComments(const std::string &data,
									std::list<std::string> &comments)
{
	size_t pos = 0;

	comments.clear();

	while(pos != std::string::npos) {
		// find a possible comment
		pos = data.find('/');

		if((pos == std::string::npos) || (pos == data.size() - 1) ) {
			break;
		}

		// check if is a comment
		if((data[pos+1] == '/') || (data[pos+1] == '*'))
	}

}


CPPSyntaxAnalyzer::CPPSyntaxAnalyzer(const std::list<std::string> &ext,
		SyntaxConfiguration *conf) : ISyntaxAnalyzer(ext, conf)
{
	// TODO Auto-generated constructor stub

}

CPPSyntaxAnalyzer::~CPPSyntaxAnalyzer()
{

}



/* This function have to be implemented because here we have to real parse
 * the module. This function takes the filename of the module, the module
 * data (file content) and returns all the pieces of code that have to
 * be analyzed (that can contain keys and values, this are the comments).
 * In case of error returns errCode.
 * Although have to extract some extra info like MODULE_NAME,
 * MODULE_DESCRIPTION, and all the Keys that we will support (see
 * the analyzeModule Function)
 */
int CPPSyntaxAnalyzer::parseModule(const std::string &fName, const std::string &data,
		std::list<std::string> &toAnalize, std::string &error,
		std::map<std::string, std::string> &extraValues)
{

}
