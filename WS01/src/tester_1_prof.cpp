#include <iostream>
#include "File.h"
#include "ShoppingList.h"
#include "Utils.h"

using namespace std;
using namespace seneca;

// Cheching if header guards exist and follow convention.
#ifndef SENECA_FILE_H
	#error "The header guard for 'File.h' doesn't follow the convention!"
#endif

#ifndef SENECA_SHOPPINGLIST_H
	#error "The header guard for 'ShoppingList.h' doesn't follow the convention!"
#endif

#ifndef SENECA_UTILS_H
	#error "The header guard for 'Utils.h' doesn't follow the convention!"
#endif

int listMenu()
{
	cout << "-->>> My Shopping List <<<--" << endl;
	seneca::displayList();
	cout << "----------------------------" << endl
		 << "1- Toggle bought Item" << endl
         << "2- Add Shopping Item" << endl
         << "3- Remove Shopping Item" << endl
         << "4- Remove bought Items" << endl
         << "5- Clear List" << endl
         << "0- Exit" << endl << "> ";
	return seneca::readInt(0, 5);
}

int main()
{
	bool done = false;
	seneca::loadList();
	while (!done)
	{
		switch (listMenu())
		{
		case 1:
			seneca::toggleBought();
			break;
		case 2:
			seneca::addItemToList();
			break;
		case 3:
			removeItemfromList();
			break;
		case 4:
			seneca::removeBoughtItems();
			break;
		case 5:
			seneca::clearList();
			break;
		default:
			done = true;
			break;
		}
	}
	seneca::saveList();
	return 0;
}
