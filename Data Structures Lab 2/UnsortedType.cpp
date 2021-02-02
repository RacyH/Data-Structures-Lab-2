/*Racy Halterman
* Data Structures Spring 2021
* Due: February 3rd
* Lab 2: Unsorted Link List
*
*/

#include <cstdlib>
#include <iostream>
#include "UnsortedType.h"

UnsortedType::UnsortedType()
{
	frontpointer = nullptr;
	length = 0;//Set to 0 while the pointers are set to point at nothing.
	currentPosition = nullptr;
	temporary = nullptr;
}

UnsortedType::~UnsortedType()
{
	MakeEmpty();
}

bool UnsortedType::SearchItem(ItemType item)
{
	temporary = frontpointer;

	while (temporary != NULL) {
		if (temporary->data.ComparedTo(item) == EQUAL) 
		{
			return true;
		}
		else 
		{
			temporary = temporary->next;
		}
	}
	return false;
}

void UnsortedType::InsertItem(ItemType item)
{
	nodePtr n = new node;
	n->next = NULL;
	n->data = item;

	if (IsFull())
	{
		cout << "There is no more room in this list.\n";
		return;
	}

	if (frontpointer != NULL)
	{
		currentPosition = frontpointer;
		while (currentPosition->next != NULL)
		{
			currentPosition = currentPosition->next;
		}
		currentPosition->next = n;
	}
	else
	{
		frontpointer = n;
	}
	length++;
}

void UnsortedType::DeleteItem(ItemType del)
{
	nodePtr delpointer = nullptr;
	temporary = frontpointer;
	currentPosition = frontpointer;

	while (currentPosition != NULL && currentPosition->data.ComparedTo(del) != EQUAL)
	{
		temporary = currentPosition;
		currentPosition = currentPosition->next;
	}

	if (currentPosition == NULL)
	{
		cout << "The item was not found, and could not be deleted.\n";
		delete delpointer;
	}
	else
	{
		delpointer = currentPosition;
		currentPosition = currentPosition->next;
		temporary->next = currentPosition;
		delete delpointer;
		cout << "The item has been deleted.\n";
		length--;
	}

}

ItemType UnsortedType::GetNextItem()
{
	if (currentPosition->next == NULL) 
	{
		currentPosition = frontpointer;
		return currentPosition->data;
	}
	else 
	{
		currentPosition = currentPosition->next;
		return currentPosition->data;
	}
}

void UnsortedType::MakeEmpty()
{
	temporary = frontpointer;
	nodePtr trailer = NULL;

	while (temporary != NULL) {
		trailer = temporary;
		temporary = temporary->next;
		delete trailer;
	}

	frontpointer = NULL;
	currentPosition = NULL;
	length = 0;
}

bool UnsortedType::IsFull() const
{
	return(length == MAX_ITEMS);
}

void UnsortedType::ResetList()
{
	currentPosition = frontpointer;
}

int UnsortedType::GetLength() const
{
	return length;
}

void UnsortedType::Union(UnsortedType& first, UnsortedType& second, UnsortedType& uni)
{
	ItemType item;
	first.ResetList();
	second.ResetList();

	while (first.currentPosition != NULL)
	{
		item = first.currentPosition->data;
		if ((uni.SearchItem(item)) != true)
		{
			uni.InsertItem(item);
			first.currentPosition = first.currentPosition->next;
		}
	}
	while (second.currentPosition != NULL)
	{
		item = second.currentPosition->data;
		if ((uni.SearchItem(item)) != true)
		{
			uni.InsertItem(item);
			second.currentPosition = second.currentPosition->next;
		}
	}
	cout << "Succesful.\n";
}

void UnsortedType::showlist()
{
	currentPosition = frontpointer;

	while (currentPosition != NULL)
	{
		cout << currentPosition->data.Get() << endl;
		currentPosition = currentPosition->next;
	}
}
