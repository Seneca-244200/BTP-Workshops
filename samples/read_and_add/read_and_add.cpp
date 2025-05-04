#include <iostream>

using namespace std;

int main()
{
	int sum;
	int number{};

	cout << "Type any number of integers; the program will calculate their sum.\n"
		 << "  Press enter after each one. Type number 0 to stop reading.\n";

	do
	{
		cin >> number;
		sum += number;
	}
	while (number != 0);

	cout << "The sum of the numbers is [" << sum << "]\n";
}
