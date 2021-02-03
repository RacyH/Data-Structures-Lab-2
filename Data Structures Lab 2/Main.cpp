/*Racy Halterman
* Data Structures Spring 2021
* Due: February 3rd
* Lab 2: Unsorted Link List
*
*/

using namespace std;
#include "UnsortedType.h"

UnsortedType list1, list2, uni;

void menu2();
void menulist();
void searchlist(char& input);
void insertitem(char& input);
void deleteitem(char& input);
void forceEmpty(char& input);
void printlist(char& input);
void Unionize();

int main()
{
	char verify = 'z';
	while (verify != 'E' && verify != 'e')
	{
		menu2();
		cout << "Are you sure you would like to exit?\nPress E to exit.\n";
		cin >> verify;
	}

	//Deallocating memory in the lists.
	list1.MakeEmpty();
	list2.MakeEmpty();
	uni.MakeEmpty();

}

/***********************
*
*Preconditions - Requires that the user is able to input things, and that menulist() is loaded correctly.
*Postconditions - Outputs the correct selection from the user input.
*
***********************/
void menu2()
{
	char menuitem, input;
	bool exit = false;
	while (exit == false)
	{
		system("cls");
		menulist();
		cin >> menuitem;
		if (menuitem == 'S' || menuitem == 's')
		{
			cout << "Which list would you like to search?\n";
			cout << "Press 1 for list 1 or 2 for list 2.\n";
			cin >> input;
			searchlist(input);
		}
		else if (menuitem == 'I' || menuitem == 'i')
		{
			cout << "Which list would you like to add to?\n";
			cout << "Press 1 for list 1 or 2 for list 2.\n";
			cin >> input;
			insertitem(input);
		}
		else if (menuitem == 'D' || menuitem == 'd')
		{
			cout << "Which list would you like to delete from?\n";
			cout << "Press 1 for list 1 or 2 for list 2.\n";
			cin >> input;
			deleteitem(input);
		}
		else if (menuitem == 'F' || menuitem == 'f')
		{
			cout << "Which list would you like to empty?\n";
			cout << "Press 1 for list 1 or 2 for list 2.\n";
			cin >> input;
			forceEmpty(input);
		}
		else if (menuitem == 'E' || menuitem == 'e')
		{
			exit = true;
		}
		else if (menuitem == 'O' || menuitem == 'o')
		{
			cout << "Which list would you like to output?\n";
			cout << "Press 1 to output list 1, 2 for list 2, or U for the union list.\n";
			cin >> input;
			printlist(input);
		}
		else if (menuitem == 'U' || menuitem == 'u')
		{
			Unionize();
		}
	}
}

/***********************
*
*Preconditions - Requires std is being used.
*Postconditions - Outputs the correct options for the user.
*
***********************/
void menulist()
{
	cout << "You may choose any of the following items by pressing the corresponding letter.\n";
	cout << "Search List\tS\n";
	cout << "Insert Item\tI\n";
	cout << "Delete Item\tD\n";
	cout << "Force Empty\tF\n";
	cout << "Unionize Lists\tU\n";
	cout << "Output List\tO\n";
	cout << "To exit press E\n";
}

/***********************
*
*Preconditions - Requires an input from the user to select a list to search in.
*Postconditions - Outputs whether the item searched for is in the list selected or not.
*
***********************/
void searchlist(char& input)
{
	ItemType item;
	string search;
	char exit;
	cout << "What is it that you are looking for?\n";
	cin >> search;
	item.Set(search);
	
	switch (input)
	{
	case '1': list1.SearchItem(item);
	{
		cout << search << " was found.\n";
	};
		break;
	case '2': list2.SearchItem(item);
	{
		cout << search << " was found.\n";
	};
		break;
	default: cout << "Your item could not be found.\n";
		break;
	}
	cout << "Press any key and then enter to return to the menu.\n";
	cin >> exit;
}

/***********************
*
*Preconditions - Requires an input for the list that is being added to.
*Postconditions - Inserts an item into the list that was selected.
*
***********************/
void insertitem(char& input)
{
	ItemType item;
	string insert;
	cout << "What do you want to add?\n";
	cin >> insert;
	item.Set(insert);

	switch (input)
	{
	case '1': list1.InsertItem(item);
		break;
	case '2': list2.InsertItem(item);
		break;
	default:
		break;
	}
}

/***********************
*
*Preconditions - Requires an input from the user to know what list is being deleted from.
*Postconditions - Deletes the item that the user selected from the list that was selected.
*
***********************/
void deleteitem(char& input)
{
	ItemType item;
	string del;
	cout << "What do you want to delete?\n";
	cin >> del;
	item.Set(del);

	switch (input)
	{
	case '1': list1.DeleteItem(item);
		break;
	case '2': list2.DeleteItem(item);
		break;
	default:
		break;
	}
}

/***********************
*
*Preconditions - Requires an input from the user to know which list is being emptied.
*Postconditions - Empties the selected list.
*
***********************/
void forceEmpty(char& input)
{
	switch (input)
	{
	case '1': list1.MakeEmpty();
		break;
	case '2': list2.MakeEmpty();
		break;
	default:
		break;
	}
}

/***********************
*
*Preconditions - Requires an input to know which list is being printed.
*Postconditions - Prints the selected list.
*
***********************/
void printlist(char& input)
{
	system("cls");
	char end;
	switch (input)
	{
	case '1': list1.showlist();
		break;
	case '2': list2.showlist();
		break;
	case 'U': uni.showlist();
		break;
	case 'u': uni.showlist();
		break;
	default: cout << "There was an error.\n";
		break;
	}
	cout << "Press any letter, followed by an enter, to exit.\n";
	cin >> end;
}

/***********************
*
*Preconditions - None.
*Postconditions - Unionizes the lists.
*
***********************/
void Unionize()
{
	char exit;
	uni.Union(list1, list2, uni);
	cout << "Press any letter, then press enter, to exit.\n";
	cin >> exit;
}
