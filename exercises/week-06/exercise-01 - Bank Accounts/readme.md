# Week #6, Exercise #1: Member Operators, Helper functions

In this exercise, you will implement different types of operator overload in a partially developed class.

## Learning Outcomes

Upon successful completion of this exercise, you will have gained the abilities to:

- define and create binary member operator
- define and create a type conversion operator
- define and a create unary member operator
- define and create helper binary operator between classes
- define and create a helper operator between a primitive type and a class.


## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written must be implemented in the `seneca` namespace, unless instructed otherwise.








## Bank Accounts

Your task is to complete the implementation of the `Account` module for holding the name of the owner of the account (a statically-allocated C-string of 100 characters), a bank account number (an integer), and the balance of the account (a floating point number in double precision).

### The `Account` module

Your task for this module is to create the module, define the class `Account`, and implement the member functions according to the specs below.

***Private Members in Class `Account`***

```cpp
/// <summary>
/// The holder's name of the account.
///   **Valid value**: any string with at leat one character.
/// </summary>
// TODO: declare the `m_holderName` attribute as a statically-allocated
//         C-string of 100 characters.


/// <summary>
/// The account number.
///   **Valid number**: any integer with exactly 6 digits.
/// </summary>
// TODO: declare the `m_number` attribute as an integer.


/// <summary>
/// The balance of the account.
/// </summary>
// TODO: declare the `m_balance` attribute as a floating point number in
//         double precision.
```


***Public Members in Class `Account`***

```cpp
/// <summary>
/// Creates a new empty account.
/// </summary>
/* TODO: define the default constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* Account()
*
* - sets the attributes to default values:
*   - all numbers to 0
*   - the name to the empty string
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Creates a new account and stores the values of the parameters into the
///   attributes of the current instance.
/// </summary>
/// <param name="name">The holder's name of the account.</param>
/// <param name="number">The account number.</param>
/// <param name="balance">The balance of the account.  This parameter is
///   optional with a default value 0.</param>
/* TODO: define the custom constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* Account(name, number, balance)
*
* - set object to the default state using the default constructor
* - if the name is valid
*   - store name in the attribute
* - if the name is valid AND the number is valid
*   - store name and number into the attributes
*
* **HINT**: you can use delegated constructors to set the object to default
*             state with the default constructor.  See the
*             *"Delegating Constructor"* section in the documentation:
*             https://en.cppreference.com/w/cpp/language/constructor
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Print to screen the information stored in the current instance.
///  (this function is fully provided)
/// </summary>
void display() const;

/// <summary>
/// Return the holder's name.
/// </summary>
/* TODO: define conversion-to-string query
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* operator const char*()
* 
* - this conversion operator cannot be used in automatic conversions.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Return the account number,
/// </summary>
/* TODO: define conversion-to-int query
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* operator int()
* 
* - this conversion operator cannot be used in automatic conversions.
* 
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Return the account balance.
/// </summary>
/* TODO: define conversion-to-double query
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* operator double()
*
* - this conversion operator cannot be used in automatic conversions.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Checks if the account is valid or not. Returns `true` if
///   the account is valid, `false` otherwise.
/// </summary>
/* TODO: define conversion-to-bool query
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* operator bool()
* 
* - if the holder's name is not empty string and the account number is more than 0
*     return true, false otherwise.
* - this conversion operator cannot be used in automatic conversions.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Checks if the account is valid or not. Returns `true` if
///   the account is NOT valid, `false` otherwise.
/// </summary>
/* TODO: define the negation operator query
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* operator!()
* 
* - return the opposite of conversion-to-bool operator.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Sets the holder's name to the parameter, if the parameter is not null and not empty.
/// 
///   If the parameter is not valid, this function does nothing.
/// </summary>
/// <param name="name">The new holder name, as a C-string.</param>
/// <returns>A reference to the current instance.</returns>
/* TODO: define the assignment operator as a mutator
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* operator=(name)
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Sets the account number to the value of the parameter only if there is
///   no account number already set and there is a name on the account.
/// 
///   If the parameter is not a valid account number, this function does nothing.
/// </summary>
/// <param name="number">The account new number as an integer.</param>
/// <returns>A reference to the current instance.</returns>
/* TODO: define the assignment operator as a mutator
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* operator=(number)
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Sets the balance to the value of the parameter only if the account is valid.
/// </summary>
/// <param name="balance">The new balance as a floating point number in double
///   precision.</param>
/// <returns>A reference to the current instance.</returns>
/* TODO: define the assignment operator as a mutator
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* operator=(balance)
* 
* - use conversion-to-bool operator to check if the account is valid.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Add the balances of the two accounts together and return the result as a
///   floating point number in double precision.
/// 
/// If any of the accounts are not valid this function returns 0.
/// 
/// This overload enables expressions "Account + Account".
/// </summary>
/// <param name="acc">A constant reference to an `Account` object.</param>
/// <returns>The sum of balances of the two accounts or 0 if any account is
/// invalid, as floating point number in double precision.</returns>
/* TODO: define the addition operator as a query
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* operator+(acc)
*
* - use conversion-to-bool operator to check if the accounts are valid.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Add the balance of the current account to the value of the parameter and
///   return the result as a floating point number in double precision.
/// 
/// If the current instance is not a valid account this function returns 0.
/// 
/// This overload enables expressions "Account + double".
/// </summary>
/// <param name="amount">A floating point number in double precision.</param>
/// <returns>The sum of amount and balance from the current account as
///   a floating point number in double precision, or 0 if the account is
///   not valid.</returns>
/* TODO: define the addition operator as a query
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* operator+(amount)
*
* - use conversion-to-bool operator to check if the account is valid.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Adds 1000 to the balance if the account is valid.
/// </summary>
/// <returns>A reference to the current object.</returns>
/* TODO: define the prefix increment operator as a mutator
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* operator++()
*
* - use conversion-to-bool operator to check if the account is valid.
* - if current account is valid, add 1000 to the balance
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Adds 1000 to the balance if the account is valid.
/// </summary>
/// <returns>A constant object of `Account` type.</returns>
/* TODO: define the postfix increment operator as a mutator
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* operator++(int)
*
* - create a local `Account` object. Copy into it the content from the current
*     instance: localObject = *this;
* - use the prefix increment operator to add 1000 to the balance of
*     current instance: ++(*this)
* - return the local object.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Add the parameter to the balance of the current account if the current
///   instance is a valid account.
/// </summary>
/// <param name="amount">The amount to add as a floating point number
///   in double precision.</param>
/// <returns>A reference to the current object.</returns>
/* TODO: define the addition-assignment operator as a mutator
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* operator+=(amount)
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Checks if the account number is the same as the parameter.
/// 
/// If the current account is valid, return `true` if the account has the same
///   number as the parameter, `false` otherwise.
/// </summary>
/// <param name="number">The integer to check against the account number.</param>
/// <returns>A Boolean value.</returns>
/* TODO: define the comparison operator as a query
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* operator==(number)
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


// return true if it's the same name
/// <summary>
/// Checks if the account holder is the same as the parameter.
/// 
/// If the current account is valid, return `true` if the account has the same
///   holder as the parameter, `false` otherwise.
/// </summary>
/// <param name="name">A C-string to check against the account holder.</param>
/// <returns>A Boolean value.</returns>
/* TODO: define the comparison operator as a query
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* operator==(name)
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// If both instances are valid, transfer balance from parameter into
///   current instance.
/// </summary>
/// <param name="acc">A reference to the account to take balance from.</param>
/// <returns>A reference to the current instance.</returns>
/* TODO: define the insertion operator as a mutator
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* operator<<(acc)
* 
* - if both instances are valid (use the conversion-to-bool operator) and the
*   two instances are not the same object (compare the address of the current
*   instance with the address of the parameter):
*   - take the balance from the parameter and add it to the current instance
*   - set the balance of the parameter to 0
* - return current instance
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


// transfer balance from current instance into parameter
/// <summary>
/// If both instances are valid, transfer balance from the current instance into
///   the parameter.
/// </summary>
/// <param name="acc">A reference to the account to put current balance into.</param>
/// <returns>A reference to the current instance.</returns>
/* TODO: define the extraction operator as a mutator
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* operator>>(acc)
*
* - use the insertion operator to transfer the balance: acc << (*this)
* - return current instance
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
```

***Free Helpers***

Add as global functions (outside the class) the following operator overloads:

```cpp
/// <summary>
/// Add the first parameter and the balance of the second parameter and
///   return the result as a floating point number in double precision.
/// 
/// If the `acc` is not a valid account, this function returns 0.
/// 
/// This overload enables expressions "double + Account".
/// </summary>
/// <param name="amount">A floating point number in double precision.</param>
/// <param name="acc">A constant reference to an `Account` object.</param>
/// <returns>The sum of amount and balance from the current account as a
///   floating point number in double precision.</returns>
/* TODO: define the assignment operator as a free helper
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* operator+(amount, acc)
*
* - use conversion-to-bool operator to check if the account is valid.
* - use conversion-to-double operator to retrieve the balance from the account.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Add the balance of the second parameter to the value of the first parameter and
///   return the result as a floating point number in double precision.
/// 
/// If the `Account` instance is not a valid account this function returns 0.
/// 
/// This overload enables expressions "double += Account".
/// </summary>
/// <param name="amount">A reference to a floating point number in double precision.</param>
/// <param name="acc">A constant reference to an `Account` object.</param>
/// <returns>The sum of amount and balance from the `Account` as a reference
///   to a floating point number in double precision.</returns>
/* TODO: define the addition-assignment operator as a free helper
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* operator+=(amount, acc)
*
* - use conversion-to-double operator to retrieve the balance from the account.
* - return the first parameter
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
```

***Already Implemented Function***

Add the following code to your implementation file:

```cpp
const int WIDTH_NAME = 10;
const int WIDTH_NUM = 8;
const int WIDTH_BAL = 10;
void Account::display() const
{
   auto oldFill = std::cout.fill();
   auto oldPrec = std::cout.precision();
   if (m_holderName[0] != '\0')
   {
      // there is account
      std::cout << "| ";
      std::cout.width(WIDTH_NAME);
      std::cout.fill(' ');
      std::cout.setf(std::ios::left);
      std::cout << this->m_holderName << " | ";
      std::cout.unsetf(std::ios::left);
      std::cout.width(WIDTH_NUM);
      if (*this)
         std::cout.fill('0');
      else
         std::cout.fill(' ');
      std::cout.setf(std::ios::right);
      std::cout << this->m_number << " | ";
      std::cout.setf(std::ios::fixed);
      std::cout.width(WIDTH_BAL);
      std::cout.precision(2);
      std::cout.fill(' ');
      std::cout << this->m_balance << " |\n";
      std::cout.unsetf(std::ios::fixed);
      std::cout.unsetf(std::ios::right);
   }
   else
   {
      std::cout.fill('x');
      std::cout << "| ";
      std::cout.width(WIDTH_NAME);
      std::cout << "" << " | ";
      std::cout.width(WIDTH_NUM);
      std::cout << "" << " | ";
      std::cout.width(WIDTH_BAL);
      std::cout << "" << " |\n";
   }
   std::cout.fill(oldFill);
   std::cout.precision(oldPrec);
}
```


***Add as many private members to the module as your design requires!***


### `tester_1` Module

This module is already provided. Look at it, make sure you understand it, but do not change it.


### Test Your Code

To test and demonstrate execution of your program use the same data as shown in the sample output.

Upload the header files (`*.h`), source code files (`*.cpp`), and the data files (`*.csv`) to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 200/week-X/ex-Y
```

- Replace `X` with week number: [`1` to `14`]
- Replace `Y` with the exercise number.

and follow the instructions.
