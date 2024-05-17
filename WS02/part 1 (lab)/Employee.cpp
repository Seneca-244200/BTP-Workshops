// This prevents VS compiler from issuing warnings/errors related to utilization
//   of unsafe string functions.  Has no effect in g++.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Employee.h"
#include "File.h"

using namespace std;

namespace seneca
{
	/// <summary>
	/// The address of a dynamically-allocated array of
	///   objects of type `Employee`.
	/// </summary>
	Employee* g_employees = nullptr;

	/// <summary>
	/// The number of `Employee` object in the array `g_employees`.
	/// </summary>
	int g_noOfEmployees = 0;

	void sort()
	{
		for (int i = g_noOfEmployees - 1; i > 0; --i)
			for (int j = 0; j < i; ++j)
				if (g_employees[j].m_empNo > g_employees[j + 1].m_empNo)
				{
					auto temp = g_employees[j];
					g_employees[j] = g_employees[j + 1];
					g_employees[j + 1] = temp;
				}
	}



	// TODO: add here the prototype of the `load` function that receives as a parameter
	//         the address of an unmodifiable C-string and returns a boolean value.
	... load(...)
	{
		bool ok = true;
		if (openFile(filename))
		{
			/* TODO: Finish the implementation
			* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
			* 
			* - use `noOfRecordsInFile` to find out how many records are in the file
			* - calculate the size of the new array
			*     (`g_noOfEmployees` + number of records in the file)
			* - create a new array of the new size
			* - iterate over old array (`g_employees`) and copy each Employee
			*     into the new array (allocate dynamic memory for the name of each employee)
			* - iterate over records in the file, and load one employee at a time
			*     (use `load(Employee&)` to load a single employee, pass to
			*     this function an element of the new array ready to receive data).
			* - deallocate the memory used by the old array (use `deallocateMemory`)
			* - update `g_employees` to point to the new array
			*     and `g_noOfEmployees` to store the size of the new array.
			* - close the file
			* 
			* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
			*/

		}
		else
		{
			cout << "Could not open data file: " << filename << endl;
			ok = false;
		}
		return ok;
	}



	// TODO: add here the prototype of the `load` function that receives as a parameter
	//         a **reference** to to an object of type `Employee`. The function should
	//         return a boolean value.
	... load(...)
	{
		bool ok = false;
		char name[128];
		/* TODO: Finish the implementation
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* - use the `read` functions to load from file the number,
		*     the salary, and the name of an employee (the order of
		*     reads is important). Read the name into the local variable `name`
		*     defined above.
		* - if all reads are successful, store the read data into the
		*     parameter (don't forget to allocate memory
		*     for the `m_name` attribute; allocate an extra character for `\0`).
		* - set the `ok` flag to true if all reads were successfull
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/


		return ok;
	}



	// TODO: add here the prototype of the `display` function that receives a parameter
	//         of type `bool`.  Do not put the default value for the parameter here.
	//         The function doesn't return anything.
	... display(...)
	{
		/* TODO: Implement the `display` function here
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* - see the format of the output in the sample provided
		* - print the header text (see the expected output)
		* - if the parameter is `true`, call the function `sort`
		* - iterate over the array `g_employees`, and call the other overload of `display`
		*     for each object in the array.
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/

	}



	// TODO: Implement the `display` overload function here. This overload should
	//         print to screen the information about a single employee received as
	//         parameter.
	... display(...)
	{
	}



	/* TODO: Implement the `deallocateMemory` function here
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* - iterate over the array `g_employees` and delete the name of each emplyee
	* - delete the array of employees
	* - set the `g_employees` to null
	* - set the number of employees to 0
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
}
