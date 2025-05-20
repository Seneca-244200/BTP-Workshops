#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "Item.h"
#include "Item.h" // intentional
#include "Bill.h"
#include "Bill.h" // intentional

int cout = 0; // won't compile if headers don't follow convention


void billTesterSimple()
{
	seneca::Bill B;

	// TEST: Too few items in the bill
	std::cout << "\n\nT2: Invalid Bill  --->   number of items < capacity\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	B.init("Quick Shopping", 5);
	B.add("Milk 2%", 4.99, false);
	B.display();

	// TEST: add items to the bill, but some of them are not valid
	std::cout << "\n\nT3: Invalid Bill  --->   some items are not valid\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	B.add(nullptr, 15.50, true);
	B.add("Frying Pan", 24.99, true);
	B.add("Eggs", -2.99, false);
	B.add("Bug Spray", 9.99, true);
	B.display();
	B.cleanup();

	// TEST: make a valid bill
	std::cout << "\n\nT4: Valid Bill\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	B.init("Quick Shopping", 5);
	B.add("Milk 2%", 4.99, false);
	B.add("Spatula", 15.50, true);
	B.add("Frying Pan", 24.99, true);
	B.add("Eggs", 5.99, false);
	B.add("Bug Spray", 9.99, true);
	B.display();
	B.cleanup();
}

void billTesterFile(const char* filename)
{
	// Test 4: Data loaded from file
	std::cout << "\n\nT4: Data loaded from file\n";
	std::cout << "==========:==========:==========:==========:==========\n";

	std::FILE* fptr = std::fopen(filename, "r");
	if (fptr != nullptr)
	{
		int recs{};
		char ch{};

		// count the number of records from the file.
		while (std::fscanf(fptr, "%c", &ch) == 1)
			recs += (ch == '\n');

		// go back to the begining of the file
		std::rewind(fptr);

		char name[256]{};
		double price{};
		int taxed{};

		// create a `Bill` object ready to receive data from file.
		seneca::Bill B;
		B.init("Grocery for a Month", recs);

		// read one record at a time and store it in the `Bill` object.
		while (std::fscanf(fptr, "%[^\t]\t%lf%d\n", name, &price, &taxed) == 3)
			B.add(name, price, taxed == 1);

		B.display();
		B.cleanup();
		std::fclose(fptr);
	}
	else
		std::cout << "File [" << filename << "] not found!\n";
}

/// <summary>
/// Prints a string, an integer, and a floating point number to the screen
///   using current formatting options (alignment & precision).
/// </summary>
/// <param name="title"></param>
void checkOutputFomatting(const char* title)
{
	std::cout << title << "\n";
	std::cout << "==========:==========:==========:==========:==========\n";

	// check filling character and alignment for strings
	std::cout << '*';
	std::cout.width(52);
	std::cout << "ABC" << "*\n";

	// check formatting for floating point numbers
	std::cout << '*';
	std::cout.width(52);
	std::cout << 1.23456789 << "*\n";

	// check formatting for integers
	std::cout << '*';
	std::cout.width(52);
	std::cout << 123 << "*\n";
}

int main()
{
	// change the filling character
	std::cout.fill('*');

	// checking the default formatting options
	checkOutputFomatting("T1: Default output formatting options");

	// test with a small bill, and invalid items
	billTesterSimple();

	// after student's code printed some data, check
	//   if the formatting options are the same or
	//   were side effects (should not be side effects)
	checkOutputFomatting("\n\nT5: Current output formatting options");
	std::cout.fill('#');
	std::cout.precision(10);

	// test with a lot of data loaded from a file
	billTesterFile("grocery.txt");

	// the filling character should be '#', and precision should be "10"
	checkOutputFomatting("\n\nT7: Current output formatting options");

	return cout;
}
