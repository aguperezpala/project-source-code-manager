/*
 * SyntaxConfiguration.h
 *
 *  Created on: 27/04/2011
 *      Author: agustin
 */

#ifndef SYNTAXCONFIGURATION_H_
#define SYNTAXCONFIGURATION_H_


#include <list>
#include <map>
#include <string>


#include "DebugUtil.h"


class SyntaxConfiguration {
public:
	// TODO: setear alguna por defecto..
	SyntaxConfiguration();
	virtual ~SyntaxConfiguration();

	/* Returns the list of categories defined */
	void getCategories(std::list<std::string> &result) const;

	/* Returns the Keys associated to a certain "Category".
	 * RETURNS:
	 * 		emptyList	if the category not exists
	 * 		list		the keys associated to category
	 */
	void getKeys(const std::string &category, std::list<std::string> &list) const;

	/* Insert a new key in a category. If the category doesnt exists, then it is
	 * created */
	void insertKeys(const std::string &category, const std::string &key);

	/* Removes a Key from a category.
	 * If the category doesnt exists, this function do nothing */
	 void removeKey(const std::string &category, const std::string &key);

	 /* Removes a complete category */
	 void removeCategory(const std::string &category);


private:
	// the map of the Categories and Keys. This map will contain a first position
	// the name of the categories ("ISSUE_KEYS", "TASKS_KEYS", "REQUIREMENT_KEYS")
	// that will map to a list of strings, this will be the "keys" that will
	// be used to create a object of that kind (categories). This is for user-define
	std::map<std::string, std::list<std::string> > mCategoriesKeys;

};

#endif /* SYNTAXCONFIGURATION_H_ */
