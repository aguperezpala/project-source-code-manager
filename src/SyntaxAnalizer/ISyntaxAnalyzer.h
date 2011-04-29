/*
 * ISyntaxAnalyzer.h
 *
 *  Created on: 27/04/2011
 *      Author: agustin
 */

#ifndef ISYNTAXANALYZER_H_
#define ISYNTAXANALYZER_H_


#include <string>
#include <list>
#include <map>

#include "DebugUtil.h"
#include "StringParser.h"
#include "SyntaxConfiguration.h"
#include "IObject.h"
#include "IObjectBuilder.h"
#include "Module.h"

/* We will define the grammatical syntax operators */
#define ASSIGNMENT_OPERATOR			"="
#define TERMINAL_OPERATOR			";"
#define MULTIVALUE_OPERATOR			"|"




class ISyntaxAnalyzer {
public:
	/* Constructor:
	 * REQUIRES:
	 * 	ext			The file extension supported by this Analyzer
	 * */
	ISyntaxAnalyzer(const std::list<std::string> &ext,
			SyntaxConfiguration *conf) :
		mExtSupported(ext),
		mSyntaxConf(conf)
		{ASSERT(conf);};

	/* Removes the SyntaxConfiguration */
	virtual ~ISyntaxAnalyzer();

	/* Analyze a module.
	 * REQUIRES:
	 * 		fName		The filename of the module to be analized
	 * 		data		the module content (file content)
	 * RETURNS:
	 * 		module		The moduleClass if success
	 * 		NULL		on error.
	 * 		errInfo		More info about the error.
	 */
	Module *analyzeModule(const std::string &fname, const std::string &data,
							std::string &errInfo);

	/* Function used to add a new Builder
	 * REQUIRES:
	 * 		builder		!= 0
	 */
	void addBuilder(IObjectBuilder *builder);


protected:

	/* This function have to be implemented because here we have to real parse
	 * the module. This function takes the filename of the module, the module
	 * data (file content) and returns all the pieces of code that have to
	 * be analyzed (that can contain keys and values, this are the comments).
	 * In case of error returns errCode.
	 */
	virtual int parseModule(const std::string &fName, const std::string &data,
			std::list<std::string> &toAnalize);


private:
	/* Analyze a piece of data.
	 * RETURNS:
	 * 	0			on success
	 *  errCode		otherwise
	 */
	int analyzePieceOfData(const std::string &data);

private:
	// The file extension that this SyntaxAnalizer support
	std::list<std::string> mExtSupported;
	// The Syntax Configuration used
	SyntaxConfiguration *mSyntaxConf;
	// map from Key to builder
	std::map<std::string, IObjectBuilder*> mKeyBuilders;
	// the list of the builders used for this analyzer
	std::list<IObjectBuilder *> mBuilders;

};

#endif /* ISYNTAXANALYZER_H_ */
