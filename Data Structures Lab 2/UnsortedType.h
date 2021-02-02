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

	UnsortedType();
	~UnsortedType();
	bool SearchItem(ItemType item);
	void InsertItem(ItemType item);
	void DeleteItem(ItemType del);
	ItemType GetNextItem();
	void MakeEmpty();
	bool IsFull() const;
	void ResetList();
	int GetLength() const;
	void Union(UnsortedType& first, UnsortedType& second, UnsortedType& uni);
	void showlist();
};


#endif  //!UNSORTEDTYPE_H