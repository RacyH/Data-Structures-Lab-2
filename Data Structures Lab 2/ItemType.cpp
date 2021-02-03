/*Racy Halterman
* Data Structures Spring 2021
* Due: February 3rd
* Lab 2: Unsorted Link List
*
*/

#include "ItemType.h"

ItemType::ItemType() {
	item = '0';
};

bool ItemType::ComparedTo(ItemType inputItem)
{
	if (item == inputItem.Get()) {
		return true;
	}
	else {
		return false;
	}
}