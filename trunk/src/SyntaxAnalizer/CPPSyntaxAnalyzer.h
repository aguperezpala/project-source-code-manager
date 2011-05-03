/*
 * CPPSyntaxAnalyzer.h
 *
 *  Created on: 02/05/2011
 *      Author: agustin
 */

#ifndef CPPSYNTAXANALYZER_H_
#define CPPSYNTAXANALYZER_H_


#include <string>

#include "DebugUtil.h"
#include "ISyntaxAnalyzer.h"
#include "StringParser.h"

class CPPSyntaxAnalyzer : public ISyntaxAnalyzer {
public:

	/* Constructor:
	 * REQUIRES:
	 * 	ext			The file extension supported by this Analyzer
	 * */
	CPPSyntaxAnalyzer(const std::list<std::string> &ext, SyntaxConfiguration *conf);
	/* Empty destructor */
	~CPPSyntaxAnalyzer();

protected:
	/* This function have to be implemented because here we have to real parse
	 * the module. This function takes the filename of the module, the module
	 * data (file content) and returns all the pieces of code that have to
	 * be analyzed (that can contain keys and values, this are the comments).
	 * In case of error returns errCode.
	 * Although have to extract some extra info like MODULE_NAME,
	 * MODULE_DESCRIPTION, and all the Keys that we will support (see
	 * the analyzeModule Function)
	 */
	int parseModule(const std::string &fName, const std::string &data,
			std::list<std::string> &toAnalize, std::string &error,
			std::map<std::string, std::string> &extraValues);


private:

	/* Extract all the comments and put it in a list. This function will work
	 * "Intelligently". If we have 2 comments like //a\n//b then we will convert
	 * as one comment. If we have a comment like / * a\n * b\n * c\n * / then
	 * we will extract the * char.
	 * RETURNS:
	 * 		0			on success (and the list filled)
	 * 		errCode		otherwise
	 */
	int parseComments(const std::string &data, std::list<std::string> &comments);

	/* Extract a clean Comment of kind multiline comment
	 * REQUIRES:
	 * 		data		where we will extract the comment
	 * 		pos			where the comment begins (including the / * chars)
	 * 		comment		the comment cleanly parsed
	 * RETURNS:
	 * 		true		on success
	 * 		false		otherwise
	 */
	bool parseMultiLineComment(const std::string &data, size_t pos,
			std::string &comment);

};

#endif /* CPPSYNTAXANALYZER_H_ */
