/*
 * ISyntaxAnalyzer.cpp
 *
 *  Created on: 27/04/2011
 *      Author: agustin
 */

#include <algorithm>
#include <vector>

#include "ISyntaxAnalyzer.h"


/* Parse a frase ("<KEY> = <value1> | <value2> | .. | <valueN> ;")
 * Returns a list of the values. Empty if have not values
 * RETURNS:
 * 		0			on success
 * 		errcode		otherwise
 */
/******************************************************************************/
int ISyntaxAnalyzer::parsePhrase(const std::string &phrase,
		std::list<std::string> &values)
{
	std::string aux;
	size_t pos = 0;
	char c;


	values.clear();

	while(pos < phrase.size()){
		pos =  StringParser::getStringUntilChar(pos, MULTIVALUE_OPERATOR
				TERMINAL_OPERATOR, phrase, c, aux);

		if(std::string(TERMINAL_OPERATOR).find(c) != std::string::npos){
			// finish.
			values.push_back(aux);
			break;
		}

		values.push_back(aux);

		if(pos == std::string::npos){
			debug("ERROR: a phrase bad formed ?\n");
			return -1;
		}

		// avoid the last char
		++pos;
	}


	return 0;
}

/******************************************************************************/
int ISyntaxAnalyzer::analyzePieceOfData(const std::string &data,
		std::list<IObject*> &objects, std::string &error)
{
	size_t pos = 0;

	if(data.size() == 0){
		debug("ERROR: trying to analyze empty data\n");
		return -1;
	}

	objects.clear();

	IObjectBuilder *builder;
	IObject *object = 0;
	std::list<std::string> values;
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

		// we can parse it! so, we have to get all the phrase
		builder = builderIt->second;
		pos = StringParser::getString(pos, data.size(), ASSIGNMENT_OPERATOR,
				TERMINAL_OPERATOR, data, phrase);
		if(pos == std::string::npos){
			// some problem, there are a syntax problem
			debug("ERROR: There are some syntax problem: \ndata: %s"
					"\nkey: %s\n", data.c_str(), key.c_str());
			return -1;
		}


		pos = pos + std::string(ASSIGNMENT_OPERATOR).size();
		// if we are here then we have the phrase but it is not parsed at all
		if(parsePhrase(phrase, values) != 0){
			debug("ERROR: Some error occur parsing the values\n");
			return -1;
		}

		// we have the values of the phrase parsed. Build the object

		object = builder->buildObject(values, error);
		if(!object){
			debug("ERROR: %s\n", error.c_str());
			return -1;
		}
		objects.push_back(object);

	}

	error = "";
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
/******************************************************************************/
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
	std::map<std::string, std::string> extraValues;

	// now get the data to be analyzed from the module (comments)
	int err = parseModule(fname, data, dataToAnalize, errInfo, extraValues);
	if(err != 0) {
		// some error ocurred
		debug("ERROR: Error (%s) ocurred parsing the module, errNmb: %i\n",
				errInfo.c_str(), err);
		return 0;
	}

	// we have parsed correctly the module, now we extract all the info from it
	// we will put in a list of IObjects every piece of data to analyze
	std::vector<std::list<IObject *> > objectsVec;
	std::list<IObject*> objects;
	bool error = false;

	for(std::list<std::string>::iterator it = dataToAnalize.begin(); it !=
			dataToAnalize.end(); ++it) {
		if(analyzePieceOfData(*it, objects, errInfo) != 0){
			debug("ERROR: parsing \n\n%s\n\n. Error: %s\n", (*it).c_str(),
					errInfo.c_str());
			error = true;
			break;
		}

		// everything ok. put in the vector
		objectsVec.push_back(objects);
		objects.clear();
	}

	if(error){
		// remove every object allocated
		for(int i = objectsVec.size() - 1; i >= 0; ++i) {
			cleanIObjectsList(objectsVec[i]);
		}
	}

	// if there are no error then put every object into the Module
	Module *result = new Module();
	ASSERT(result);

	/* put the extra data. ULTRA UGLY HARDCODED! :(, no time */
	if(extraValues.find("MODULE_NAME") != extraValues.end()){
		result->setModuleName(extraValues["MODULE_NAME"]);
	} else {
		result->setModuleName("UNKNOWN!!!");
	}
	if(extraValues.find("MODULE_DESCRIPTION") != extraValues.end()){
		result->setModuleName(extraValues["MODULE_DESCRIPTION"]);
	}

	result->setFileName(fname);

	// now put all the IObjects
	for(int i = 0; i < objectsVec.size(); ++i) {
		for(std::list<IObject*>::iterator it = objectsVec[i].begin();
				it != objectsVec[i].end(); ++it){
			result->addNewObject(*it);
		}
	}

	return result;
}

/* Function used to add a new Builder
 * REQUIRES:
 * 		builder		!= 0
 */
/******************************************************************************/
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


/******************************************************************************/
ISyntaxAnalyzer::~ISyntaxAnalyzer()
{

}
