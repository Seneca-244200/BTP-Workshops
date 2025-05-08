#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>

using namespace std;


/// <summary>
/// The number of characters for a title of a shopping record.
/// (not including the null terminator)
/// </summary>
const int MAX_TITLE_LENGTH = 50;
/// <summary>
/// Information about a shopping record (an item that is bought)
/// </summary>
struct ShoppingRec
{
	char m_title[MAX_TITLE_LENGTH + 1];
	int m_quantity;
	bool m_bought;
};

/// <summary>
/// The input file name containing a collection of shopping records.
/// </summary>
const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";
/// <summary>
/// The descriptor of the file once it's opened.
/// </summary>
FILE* g_sfptr = nullptr;

/// <summary>
/// The maximum number of items that a shopping record can have.
/// </summary>
const int MAX_QUANTITY_VALUE = 50;

/// <summary>
/// The capacity of the shopping list.
/// </summary>
const int MAX_NO_OF_RECS = 15;
/// <summary>
/// A collection of shopping records. The capacity of the array
/// is MAX_NO_OF_RECS.
/// </summary>
ShoppingRec g_recs[MAX_NO_OF_RECS]{};
/// <summary>
/// The number of valid shopping records in "g_recs".
/// Must be smaller or equal to the capacity.
/// </summary>
int g_noOfRecs = 0;

/// <summary>
/// Prints to screen a single shopping record.
/// </summary>
/// <param name="shp">The item to be printed to screen. The parameter
/// is not validated; assumes that the client passed the address of
/// an object that contains good data.</param>
void displayShoppingRec(const ShoppingRec* shp)
{
	cout << "[" << (shp->m_bought ? 'X' : ' ') << "]" << shp->m_title <<
		" qty:(" << shp->m_quantity << ")" << endl;
}

/// <summary>
/// Prints all valid shopping records to screen.
/// </summary>
void displayList()
{
	for (int i = 0; i < g_noOfRecs; i++)
	{
		cout << (i + 1) << "-";
		displayShoppingRec(&g_recs[i]);
	}
}

/// <summary>
/// Discards all characters from input stream until the
/// first '\n' (including the '\n').
/// </summary>
void flushkeys()
{
	while (cin.get() != '\n');
}

/// <summary>
/// Read an integer from the keyboard within the specified range.
/// It keeps prompting the user until such an integer is read.
/// </summary>
/// <param name="min">The minimum value of the interval.</param>
/// <param name="max">The maximum value of the interval.</param>
/// <returns>The value read.</returns>
int readInt(int min, int max)
{
	int value = 0;
	bool done = false;
	while (!done)
	{
		cin >> value;
		if (!cin)
		{
			cin.clear();
			cout << "Bad integer, try again: ";
		}
		else
		{
			if (value >= min && value <= max)
				done = true;
			else
				cout << "Value out of range (" << min << "<=value<=" << max << "): ";
		}
		flushkeys();
	}
	return value;
}

/// <summary>
/// Prints the content of the shopping list (all valid records)
/// and the menu to allow users to interract with the list.
/// </summary>
/// <returns>The menu id (operation) that the user wants to
/// execute.</returns>
int listMenu()
{
	cout << "-->>> My Shopping List <<<--" << endl;
	displayList();
	cout << "----------------------------" << endl
		<< "1- Toggle bought Item" << endl
		<< "2- Add Shopping Item" << endl
		<< "3- Remove Shopping Item" << endl
		<< "4- Remove bought Items" << endl
		<< "5- Clear List" << endl
		<< "0- Exit" << endl << "> ";
	return readInt(0, 5);
}

/// <summary>
/// Checks if the parameter is one of the characters
/// 'y', 'Y', 'n', 'N'.
/// </summary>
/// <param name="ch">The character to check.</param>
/// <returns>true if the characters is one from the list,
/// false, otherwise.</returns>
bool validYesResponse(char ch)
{
	return ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n';
}

/// <summary>
/// Reads from the keyboard a single character that represents the
/// response to a Yes/No question.  Keeps promting user until it reads
/// a valid answer.
/// </summary>
/// <returns>true if the user selected Yes, false otherwise.</returns>
bool yes()
{
	char ch = 0;
	do
	{
		cin >> ch;
		flushkeys();
	}
   while (!validYesResponse(ch) && cout << "Only (Y/y) or (N/n) is acceptable: ");
	
	return ch == 'y' || ch == 'Y';
}

/// <summary>
/// Reads an array of characters from the keyboard (including spaces).
/// </summary>
/// <param name="cstr">The address of a memory block where to store
/// the characters read.</param>
/// <param name="len">The amount of memory available at the address
/// received in the first parameter.</param>
void readCstr(char cstr[], int len)
{
	char buf[1024]{};
	int i;
	cin.getline(buf, 1024);
	for (i = 0; i < len - 1 && buf[i]; i++)
		cstr[i] = buf[i];
	cstr[i] = '\0';
}

/// <summary>
/// Read from keyboard a single shopping record.
/// </summary>
/// <returns>the record read.</returns>
ShoppingRec getShoppingRec()
{
	ShoppingRec R{};
	cout << "Item name: ";
	readCstr(R.m_title, MAX_TITLE_LENGTH);
	cout << "Quantity: ";
	R.m_quantity = readInt(1, MAX_QUANTITY_VALUE);
	return R;
}

/// <summary>
/// Flips the "bought" flag of a single shopping record.
/// </summary>
/// <param name="rec"></param>
void toggleBoughtFlag(ShoppingRec* rec)
{
	rec->m_bought = !rec->m_bought;
}

/// <summary>
/// Checks if a shopping record contains valid data and can be used.
/// </summary>
/// <param name="shp">the shopping record to check.</param>
/// <returns>true if the shopping record is valid,
/// false otherwise.</returns>
bool isShoppingRecEmpty(const ShoppingRec* shp)
{
	return shp->m_title[0] == '\0';
}

/// <summary>
/// Open the input file for reading.
/// </summary>
/// <returns>true if it was successful, false otherwise.</returns>
bool openFileForRead()
{
	g_sfptr = fopen(SHOPPING_DATA_FILE, "r");
	return g_sfptr != nullptr;
}

/// <summary>
/// Open the a file for writting.
/// </summary>
/// <returns>true if it was successful, false otherwise.</returns>
bool openFileForOverwrite()
{
	g_sfptr = fopen(SHOPPING_DATA_FILE, "w");
	return g_sfptr != nullptr;
}

/// <summary>
/// Close the file if it's open; do nothing otherwise.
/// </summary>
void closeFile()
{
	if (g_sfptr)
	{
		fclose(g_sfptr);
		g_sfptr = nullptr;
	}
}

/// <summary>
/// Read a single shopping record from the file (the file must
/// be opened before this function is called).
/// </summary>
/// <param name="rec">The address of a shopping record object
/// where to store the read data.</param>
/// <returns>true if the record was successfully read, false otherwise.</returns>
bool freadShoppingRec(ShoppingRec* rec)
{
	int flag = 0;
	bool success = fscanf(g_sfptr, "%[^,],%d,%d\n", rec->m_title, &rec->m_quantity, &flag) == 3;
	rec->m_bought = !!flag;
	return success;
}

/// <summary>
/// Write a shopping record into the file. The file must be opened for writting
/// before this function is called, and the parameter must contain valid data.
/// </summary>
/// <param name="rec">The shopping record to write into the file.</param>
void fwriteShoppintRec(const ShoppingRec* rec)
{
	fprintf(g_sfptr, "%s,%d,%d\n", rec->m_title, rec->m_quantity, rec->m_bought);
}

/// <summary>
/// Load the content of the file into the array of shopping records.
/// This function will open the file, and close it after finishing.
/// </summary>
/// <returns></returns>
bool loadList()
{
	ShoppingRec shpr{};
	bool ok = false;
	if (openFileForRead())
	{
		ok = true;
		while (g_noOfRecs < MAX_NO_OF_RECS && freadShoppingRec(&shpr))
			g_recs[g_noOfRecs++] = shpr;
		closeFile();
	}
	return ok;
}

/// <summary>
/// Save into the file the current list of shopping records.
/// This function will open the file, and close it after finishing.
/// </summary>
/// <returns>true if the list was saved in the file, false otherwise.</returns>
bool saveList()
{
	bool ok = false;
	if (openFileForOverwrite())
	{
		ok = true;
		for (int i = 0; i < g_noOfRecs; i++)
			fwriteShoppintRec(&g_recs[i]);
		closeFile();
	}
	return ok;
}

/// <summary>
/// Remove the specified item from the list of shopping records.
/// </summary>
/// <param name="index">The index of the item to be removed.
/// If the index is not valid, this function does nothing.</param>
void removeItem(int index)
{
	if (index >= 0 && index < g_noOfRecs)
	{
		g_noOfRecs--;
		for (int i = index; i < g_noOfRecs; i++)
			g_recs[i] = g_recs[i + 1];
	}
}

/// <summary>
/// Remove all the items from the list of shopping items.
/// </summary>
void clearList()
{
	cout << "This will remove all the items from the list;" << endl
		<< "Are you sure? (Y)es/(N)o" << endl;
	if (yes())
		g_noOfRecs = 0;
	else
		cout << "Cancelled!" << endl;
}

/// <summary>
/// Changes the bought flag for a single shopping item.
/// Will prompt the user for input about which shopping item
/// should be modified.
/// </summary>
void toggleBought()
{
	cout << "Item number: ";
	toggleBoughtFlag(&g_recs[readInt(1, g_noOfRecs) - 1]);
}

/// <summary>
/// If there is still capacity in the list, will read from
/// the keyboard a shopping record and add it at the end of the list.
/// </summary>
void addItemToList()
{
	if (g_noOfRecs < MAX_NO_OF_RECS)
	{
		g_recs[g_noOfRecs] = getShoppingRec();
		g_noOfRecs += !isShoppingRecEmpty(&g_recs[g_noOfRecs]);
	}
	else
	{
		cout << "Shopping List is full!" << endl;
	}
}

/// <summary>
/// Check if the are any items in the shopping list.
/// </summary>
/// <returns>true if the list contains no items.</returns>
bool listIsEmpty()
{
	return g_noOfRecs == 0;
}

/// <summary>
/// Removes an item from the list. Will interract with the user
/// about which item to be removed.
/// </summary>
void removeItemfromList()
{
	if (!listIsEmpty())
	{
		int value = 0;
		cout << "Item number to delete: ";
		value = readInt(1, g_noOfRecs);
		cout << "Deleting following item, are you sure?" << endl;
		displayShoppingRec(&g_recs[value - 1]);
		cout << "(Y)es/(N)o: ";
		if (yes())
			removeItem(value - 1);
		else
			cout << "Cancelled!" << endl;
	}
	else
	{
		cout << "List is empty!" << endl;
	}
}

/// <summary>
/// Remove from the list of items all items that are already bought.
/// </summary>
void removeBoughtItems()
{
	if (!listIsEmpty())
	{
		cout << "Removing bought items, are you sure?" << endl;
		cout << "(Y)es/(N)o: ";
		if (yes())
		{
			for (int i = 0; i < g_noOfRecs; i++)
			{
				if (g_recs[i].m_bought)
					removeItem(i--);
			}
		}
		else
		{
			cout << "Cancelled!" << endl;
		}
	}
	else
	{
		cout << "List is empty!" << endl;
	}
}


int main()
{
	bool done = false;
	loadList();
	while (!done)
	{
		switch (listMenu())
		{
		case 1:
			toggleBought();
			break;
		case 2:
			addItemToList();
			break;
		case 3:
			removeItemfromList();
			break;
		case 4:
			removeBoughtItems();
			break;
		case 5:
			clearList();
			break;
		default:
			done = true;
			break;
		}
	}
	saveList();
	return 0;
}
