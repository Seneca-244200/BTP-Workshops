# Workshop #5: Member Operators, Helper functions

In this workshop, you will implement different types of operator overload in a partially developed class.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define and create binary member operator
- define and create a type conversion operator
- define and a create unary member operator
- define and create helper binary operator between classes
- define and create a helper operator between a primitive type and a class.


## General Instructions

### Submission Policy

This workshop is divided into two coding parts and one non-coding part.

- **Part 1** (*LAB*): A *step-by-step* guided workshop, worth 50% of the workshop's total mark.
  Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- **Part 2** (*DIY*): A *do-it-yourself* type of workshop that is much more open-ended and is worth 50% of the workshop's total mark.  
- **reflection**: non-coding part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of "Part 2" mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
  - Submissions of **Part 2** that do not contain the *reflection* (that is the **non-coding part**) are considered incomplete and are ignored.



### Due Dates


The due dates depend on your section. The due date for *Part #1* is at the end of they when your lab is scheduled; the due date for *Part #2* is at the end of the day that is 5 days after the day with the lab.

Please choose the `-due` option of the submitter program to see the exact due date of your section:

```bash
~profname.proflastname/submit 2??/wX/pY_SSS -due
```

- Replace `??` with your subject code (`00` or `44`)
- Replace `X` with workshop number: [`1` to `10`]
- Replace `Y` with the part number: [`1` or `2`]
- Replace `SSS` with the section identifier: [`naa`, `nbb`, `nra`, `zaa`, etc.]



### Late penalties

You are allowed to submit your work up to 2 days after the due date with 30% penalty for each day. After that, the submission will be closed, and the mark will be zero. If the reflection is missing when the submission closes, the mark for **Part 2** will be set to 0.



### Citation

Every file that you submit must contain (as a comment) at the top:

- **your name**,
- **your Seneca email**,
- **Seneca Student ID**,
- the **date** when you completed the work.


#### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#### For work that is done partially by you

If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from**.  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

- Add the citation to the file in which you have the borrowed code (make sure to clearly mark the code that is not created by you and where did you get it from).
- In the `reflect.txt` file, add a summary of the files/portions of code that is not yours (the source files should un-ambiguously identify the portions of code that are not yours).

> ⚠ This [Submission Policy](#submission-policy) only applies to the workshops. All other assessments in this subject have their own submission policies.


#### If you have helped someone with your code

If you have helped someone with your code, let them know of these regulations and, in your `reflect.txt` file, write exactly which part of your code was copied and who was the recipient of this code. By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.



### Compiling and Testing Your Program

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

> Note: All the code written in workshops and the project must be implemented in the `seneca` namespace, unless instructed otherwise.





## Part 1 (50%)

Your task for this part of the workshop is to complete the implementation of the `Account` module for holding the name of the owner of the account (a statically-allocated C-string of 100 characters), a bank account number (an integer), and the balance of the account (a floating point number in double precision).

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


### `accountTester` Module

This module is already provided. Look at it, make sure you understand it, but do not change it.


### Submission

Upload the header files (`*.h`) and source code files (`*.cpp`) to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss
```

- Replace `??` with your subject code (`00` or `44`)
- Replace `X` with workshop number: [`1` to `10`]
- Replace `Y` with the part number: [`1` or `2`]
- Replace `sss` with the section: [`naa`, `nbb`, `nra`, `zaa`, etc.]
and follow the instructions.

> **Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.





## Part 2 (50%)

Create a module named `Mark` to encapsulate a mark that a student receives in a course. A mark is an integer between `0` and `100`; any other value is considered invalid.  The program should overload operators that would allow changing a mark and converting it to a different representation (a letter grade, or a GPA scale score). The table below shows how the conversion happens.

| Mark                 | Grade | GPA scale |
|----------------------|-------|-----------|
|  0 <= Mark <   50    | F     | 0.0       |
| 50 <= Mark <   60    | D     | 1.0       |
| 60 <= Mark <   70    | C     | 2.0       |
| 70 <= Mark <   80    | B     | 3.0       |
| 80 <= Mark <= 100    | A     | 4.0       |

Your solution should contain at least the following public members in the custom type `Mark`:

```cpp
/// <summary>
/// Initializes the current instance with setting the mark to
///   the value of the parameter.
/// </summary>
/// <param name="value">An integer representing the mark.  This
///   parameter is optional, with a default value of 0. Only values
///   between 0 and 100 are considered valid.</param>
Mark(value)

/// <summary>
/// Increase the mark by the value received as parameter.  If the current
///   mark is not valid, this operator does nothing.
/// </summary>
/// <param name="value">An integer, representing how much to increase
///   the current mark.</param>
/// <returns>A reference to the current instance.</returns>
operator+=(value)

/// <summary>
/// The assignment operator sets the mark to the value received as parameter.
/// </summary>
/// <param name="value">An integer, representing the new mark.</param>
/// <returns>A reference to the current instance.</returns>
operator=(name)

/// <summary>
/// A conversion-to-integer operator overload. Returns the number representing
///   the mark in the interval [0, 100]. If the mark is not valid, this
///   operator returns 0.
/// </summary>
operator int()

/// <summary>
/// A conversion-to-char operator overload. Returns the letter representation
///   of the mark (see the provided table). If the mark is not valid, this
///   operator returns `X`.
/// </summary>
operator char();

/// <summary>
/// A conversion-to-double operator overload. Returns the GPA equivalent of the
///   mark (see the provided table). If the mark is not valid, this operator
///   returns 0.
/// </summary>
operator double();
```

None of the conversion operators mentioned above, or casting constructors, can be used in automatic conversions. Use the appropriate syntax to tell this to the compiler.

Your solution should contain at least the following helper function:

```cpp
/// <summary>
/// An overload of the addition-assignment operator that allows to add the mark
///   to an integer (received as the first parameter), returning the integer
///   after the operation. Invalid marks will not add any value to the integer.
/// </summary>
/// <param name="value">A reference to an integer.</param>
/// <param name="theMark">The mark to add to the first parameter.</param>
/// <returns>A reference to the first parameter.</returns>
operator+=(val, theMark)
```

As general guidelines, consider the following when designing your solution:

- do not add global variables/functions, unless specifically instructed to do so.  Global constants are acceptable.
- add as many private members as your design requires.
- all attributes in a class must be private, unless specifically instructed otherwise.
- all member functions should be queries, unless the needs of the project require otherwise.
- all member functions should be private, unless the needs of the project require otherwise.
- all public functions must validate their parameters before working with them (don't trust that clients provide good values).
- all parameters passed by-address or by-reference should be constants, unless the needs of the code require otherwise.

***You may freely use/copy any logic or code needed from the PART 1!***  You must use *custom types*, *public*/*private members*, *constructors*, and *operator overload*.



## Reflection


Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty and how you solved them. Include in your explanation—**but do not limit it to**—the following points:

- Why the prefix increment operator can return by reference, but the postfix increment operator can only return by value? Do some experiments and report the result.
- Why the `+=` can return by reference, but the `+` operator cannot?
- How did you prevent the conversion operators/casting constructors to be used in automatic conversions?
- Why the helper operators in this workshop cannot be implemented as members? Discuss.

To avoid deductions, refer to code in your solution as examples to support your explanations. You may be asked to talk about your reflection (as a presentation) in class.



### Submission

To test and demonstrate execution of your program use the same data as shown in the sample output.

Upload the header files (`*.h`) and source code files (`*.cpp`) to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly:

- `Mark.h`
- `Mark.cpp`
- `markTester.cpp`

Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly. A sample run can be found in the file `output_sample.txt`.

Then, run the following command from your matrix account:

```bash
~profname.proflastname/submit 2??/wX/pY_sss
```

- Replace `??` with your subject code (`00` or `44`)
- Replace `X` with workshop number: [`1` to `10`]
- Replace `Y` with the part number: [`1` or `2`]
- Replace `sss` with the section identifier: [`naa`, `nbb`, `nra`, `zaa`, etc.]

and follow the instructions.


> **:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
