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

const int MAX_ITEMS = 100;

enum RelationType
{
	LESS,
	GREATER, //only included greater because of the requirements, however, I don't see this as being necessary for the way that I approached this program build
	//to note, that I also stayed within the requirements
	EQUAL
};

class ItemType
{
public:

	/***********************
*
*Preconditions - Constructor.
*Postconditions - Creates the ItemType.
*
***********************/
	ItemType();

	/***********************
*
*Preconditions - Requires the input to be compared against.
*Postconditions - Compares the item inputted to the items in the list to see if it returns as true or false.
*
***********************/
	RelationType ComparedTo(ItemType inputItem);

	/***********************
*
*Preconditions - Requires the input from the user so that the item can be set to be passed.
*Postconditions - Sets item as the input.
*
***********************/
	void Set(string item_) { item = item_; };

	/***********************
*
*Preconditions - Item has something in it.
*Postconditions - Returns the item.
*
***********************/
	string Get() { return item; };

private:

	string item; //changed this to string so that the program could accept any variable type. can change back to int if needed
};


#endif  //!ITEMTYPE_H