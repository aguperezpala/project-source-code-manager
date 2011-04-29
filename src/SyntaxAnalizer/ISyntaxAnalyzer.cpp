/*
 * ISyntaxAnalyzer.cpp
 *
 *  Created on: 27/04/2011
 *      Author: agustin
 */

#include <algorithm>

#include "ISyntaxAnalyzer.h"


int ISyntaxAnalyzer::analyzePieceOfData(const std::string &data)
{
	size_t pos = 0;

	if(data.size() == 0){
		debug("ERROR: trying to analyze empty data\n");
		return -1;
	}

	IObjectBuilder *builder;
	std::string key, phrase;
	char c;
	std::map<std::string, IObjectBuilder*>::iterator builderIt;

	while(pos <= data.size()){
		// first jump white characters
		pos = StringParser::jumpChars(pos,data);
		if(pos == std::string::npos) {
			// nothing to parse
			break;
		}

		// get the first word
		pos = StringParser::getStringUntilChar(pos,
				BLANK_SPACES ASSIGNMENT_OPERATOR, data, c, key);
		if(pos == std::string::npos) {
			// this is the last word, but this useless. break
			break;
		}

		// now we have to see if the key is a word that we can parse
		builderIt = mKeyBuilders.find(key);
		if(builderIt == mKeyBuilders.end()){
			// the key cannot be parsed. skip it
			continue;
		}

		// we can parse it! so, we have to get all the frase
		builder = builderIt->second;
		pos = StringParser::getString(pos, data.size(), ASSIGNMENT_OPERATOR,
				TERMINAL_OPERATOR, data, phrase);
		if(builder == std::string::npos){
			// some problem, there are a syntaxis problem
			debug("ERROR: There are some syntaxis problem: \ndata: %s"
					"\nkey: %s\n", data.c_str(), key.c_str());
			return -1;
		}


		pos = pos + std::string(ASSIGNMENT_OPERATOR).size();
		// if we are here then we have the phrase but it is not parsed at all



	}

	return 0;
}


/* Analyze a module.
 * REQUIRES:
 * 		fName		The filename of the module to be analized
 * 		data		the module content (file content)
 * RETURNS:
 * 		module		The moduleClass if success
 * 		NULL		on error.
 * 		errInfo		More info about the error.
 */
Module *ISyntaxAnalyzer::analyzeModule(const std::string &fname,
													const std::string &data,
													std::string &errInfo)
{
	if(fname.size() == 0){
		debug("ERROR: Trying to analyzeModule that have no fileName\n");
		return 0;
	}
	if(data.size() == 0){
		debug("ERROR: Trying to analize module that is empty\n");
		return 0;
	}

	std::list<std::string> dataToAnalize;

	// now get the data to be analized from the module
	int err = parseModule(fname, data, dataToAnalize);
	if(err != 0) {
		// some error ocurred
		debug("ERROR: Error ocurred parsing the module, errNmb: %i\n", err);
		return 0;
	}

	// we have parsed correctly the module, now we extract all the info from it


}

/* Function used to add a new Builder
 * REQUIRES:
 * 		builder		!= 0
 */
void ISyntaxAnalyzer::addBuilder(IObjectBuilder *builder)
{
	ASSERT(builder);
	ASSERT(std::find(mBuilders.begin(), mBuilders.end(), builder) == mBuilders.end());

	mBuilders.push_back(builder);

	// we have to refresh the map of key->builders
	std::list<std::string> newKeys;
	mSyntaxConf->getKeys(builder->getName(), newKeys);

	for(std::list<std::string>::iterator it = newKeys.begin(); it != newKeys.end();
			++it){
		mKeyBuilders[*it] = builder;
	}
}

/* TODO: Removes a builder
void ISyntaxAnalyzer::removeBuilder(IObjectBuilder *builder);
void ISyntaxAnalyzer::removeBuilder(const std::string &name);

*/



ISyntaxAnalyzer::~ISyntaxAnalyzer()
{
	if(conf)
		delete conf;
}
