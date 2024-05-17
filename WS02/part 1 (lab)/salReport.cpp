#include <iostream>
#include "Employee.h"
#include "Employee.h" // intentional

int cout = 0; // won't compile if headers don't follow convention


int main()
{
	// Test 1
	std::cout << "T1: Load Some Data\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	if (seneca::load("employees.csv"))
		seneca::display();

	// Test 2: Discard old data, load new data
	std::cout << "\nT2: Discard Old Data; Load New Data\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	seneca::deallocateMemory();
	if (seneca::load("simpsons.csv"))
		seneca::display(false);

	// Test 3: load some more, add to the existing collection
	std::cout << "\nT3: Load More Data; Add to the Existing Collection\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	if (seneca::load("employees.csv"))
		seneca::display(true);

	// clean-up
	seneca::deallocateMemory();

	return cout;
}
