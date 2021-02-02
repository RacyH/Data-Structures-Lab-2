/*Racy Halterman
* Data Structures Spring 2021
* Due: February 3rd
* Lab 2: Unsorted Link List
*
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;
//#include "ItemType.h"
#include "UnsortedType.h"

UnsortedType list1, list2, uni;

void menu();
void menu2();
void menulist();
void searchlist(char& input);
void insertitem(char& input);
void deleteitem(char& input);
void forceEmpty(char& input);
void printlist(char& input);
void Unionize();
void Unionmenu();

int main()
{
	char verify = 'z';
	while (verify != 'E' && verify != 'e')
	{
		menu2();
		cout << "Are you sure you would like to exit?\nPress E to exit.\n";
		cin >> verify;
	}
}

/*void menu()
{
	char input = 'a';
	while (input != '3')
	{
		cout << "You may save up to two lists. Press 1 to alter the first, or 2 to alter the second.\n";
		cout << "You may also choose to view the Unionized Lists' menu by pressing U.\n";
		cout << "If you would like to exit, press 3.\n";

		cin >> input;
		cout << endl;
		if (input == '1')
		{
			menu2(input);
			break;
		}
		else if (input == '2')
		{
			menu2(input);
			break;
		}
		else if (input == 'U' || input == 'u')
		{
			Unionmenu();
		}
		else
		{
			system("cls");
			cout << "That was not a correct input.\n";
		}
	}
}*/

void menu2()
{
	//menulist();
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
			cin >> input;
			printlist(input);
		}
		else if (menuitem == 'U' || menuitem == 'u')
		{
			Unionize();
		}
		else
		{
			cout << "Invlaid option. Try again.\n";
		}
	}
}

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
	case '1': if (list1.SearchItem(item) == true)
	{
		cout << search << " was found.\n";
	};
		break;
	case '2': if (list2.SearchItem(item) == true)
	{
		cout << search << " was found.\n";
	};
		break;
	default: cout << "There was an error.\n";
		break;
	}
	cout << "Press any key and then enter to return to the menu.\n";
	cin >> exit;
}

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
	default: cout << "There was an error.\n";
		break;
	}
}

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

void forceEmpty(char& input)
{
	switch (input)
	{
	case '1': list1.MakeEmpty();
		break;
	case '2': list2.MakeEmpty();
		break;
	default: cout << "There was an error.\n";
		break;
	}
}

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
	cout << "Press any letter to exit.\n";
	cin >> end;
}

void Unionize()
{
	char exit;
	uni.Union(list1, list2, uni);
	cout << "Press any letter, then press enter, to exit.\n";
	cin >> exit;
}
