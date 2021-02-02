/*Racy Halterman
* Data Structures Spring 2021
* Due: February 3rd
* Lab 2: Unsorted Link List
*
*/

#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
#include <iomanip>
using namespace std;
//#include "UnsortedType.h"

const int MAX_ITEMS = 100;
//typedef int type;//come back to all of this.

enum RelationType
{
	NotEqual,
	EQUAL,
};

class ItemType
{
public:

	ItemType();
	RelationType ComparedTo(ItemType item_);
	void Set(string item_) { item = item_; };
	string Get() { return item; };


private:

	string item;
};


#endif  //!ITEMTYPE_H