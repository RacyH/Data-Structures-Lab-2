/*Racy Halterman
* Data Structures Spring 2021
* Due: February 3rd
* Lab 2: Unsorted Link List
*
*/

#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

#include "ItemType.h"

class UnsortedType
{
private:

	typedef struct node {
		ItemType data; //come back to this
		node* next;
	}*nodePtr;

	int length;
	nodePtr currentPosition;
	nodePtr frontpointer;
	nodePtr temporary;
public:

	/***********************
*
*Preconditions - Constructor. Requires the UnsortedType class has been created.
*Postconditions - Creates the class.
*
***********************/
	UnsortedType();

	/***********************
*
*Preconditions - Destructor. Requires the UnsortedType class has been created.
*Postconditions - Destroys the class.
*
***********************/
	~UnsortedType();

	/***********************
*
*Preconditions - Requires an item input to search for.
*Postconditions - Returns true if the item was found, and false if it was not.
*
***********************/
	bool SearchItem(ItemType item);

	/***********************
*
*Preconditions - Requires an input to add to the list.
*Postconditions - Inputs the item into the list.
*
***********************/
	void InsertItem(ItemType item);

	/***********************
*
*Preconditions - Requires an input to delete from the list.
*Postconditions - Deletes the item from the list.
*
***********************/
	void DeleteItem(ItemType del);

	/***********************
*
*Preconditions - Requires ItemType to be loaded and the node struct to be available.
*Postconditions - Moves the currentPointer to the next spot in the list.
*
***********************/
	ItemType GetNextItem();

	/***********************
*
*Preconditions - Requires the list to have items in it, and the node struct to be available.
*Postconditions - Makes the list empty.
*
***********************/
	void MakeEmpty();

	/***********************
*
*Preconditions - None.
*Postconditions - Checks to see if the list is full. 
*
***********************/
	bool IsFull() const;

	/***********************
*
*Preconditions - None.
*Postconditions - Resets the currentPointer to the front of the list.
*
***********************/
	void ResetList();

	/***********************
*
*Preconditions - The list has a length.
*Postconditions - Return the length of the list.
*
***********************/
	int GetLength() const;

	/***********************
*
*Preconditions - Requires the different lists to be availabe to be inputted into the function.
*Postconditions - Unions the two lists.
*
***********************/
	void Union(UnsortedType& first, UnsortedType& second, UnsortedType& uni);

	/***********************
*
*Preconditions - None.
*Postconditions - Outputs the list.
*
***********************/
	void showlist();
};


#endif  //!UNSORTEDTYPE_H