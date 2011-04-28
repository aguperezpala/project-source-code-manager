/*
 * SyntaxConfiguration.cpp
 *
 *  Created on: 27/04/2011
 *      Author: agustin
 */

#include "SyntaxConfiguration.h"

SyntaxConfiguration::SyntaxConfiguration()
{
	// nothing

}

SyntaxConfiguration::~SyntaxConfiguration()
{
	// nothing
}


/******************************************************************************/
void SyntaxConfiguration::getCategories(std::list<std::string> &result) const
{
	std::map<std::string, std::list<std::string> >::const_iterator it;

	result.clear();

	for(it = mCategoriesKeys.begin(); it != mCategoriesKeys.end(); ++it) {
		result.push_back((*it).first);
	}
}

/******************************************************************************/
void SyntaxConfiguration::getKeys(const std::string &category,
										std::list<std::string> &rlist) const
{
	rlist.clear();

	std::map<std::string, std::list<std::string> >::const_iterator it = mCategoriesKeys.find(category);

	if(it != mCategoriesKeys.end()){
		for(std::list<std::string>::const_iterator kit = (*it).second.begin();
				kit != (*it).second.end(); ++kit) {
			rlist.push_back(*kit);
		}
	}

}

/* Insert a new key in a category. If the category doesnt exists, then it is
 * created */
/******************************************************************************/
void SyntaxConfiguration::insertKeys(const std::string &category, const std::string &key)
{
	mCategoriesKeys[category].push_back(key);
}

/* Removes a Key from a category.
 * If the category doesnt exists, this function do nothing */
/******************************************************************************/
 void SyntaxConfiguration::removeKey(const std::string &category, const std::string &key)
 {
	 if(mCategoriesKeys.find(category) != mCategoriesKeys.end()){
		mCategoriesKeys[category].remove(key);
	}
 }

 /* Removes a complete category */
 /******************************************************************************/
 void SyntaxConfiguration::removeCategory(const std::string &category)
 {
	 mCategoriesKeys.erase(category);
 }

