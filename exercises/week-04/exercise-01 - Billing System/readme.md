# Week #4, Exercise #1: Member Functions and Privacy

In this exercise, you will use member functions, privacy, safe empty state and formatting the output to complete your work.


## Learning Outcomes

Upon successful completion of this exercise, you will have gained the abilities to:

- to define a class type
- to privatize data within the class type
- to instantiate an object of class type
- to access data within an object of class type through public member functions
- to use standard library facilities to format data inserted into the output stream



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








## Billing System

> Note: In this and future documents a **member function** may be referred to as a **method** and a **member variable** may be referred to as an **attribute**.

Your task for this exercise is to create a program that provides a class named `Bill`, managing a collection of shopping items (objects of type `Item`).

Items will be added to the bill one at a time by their name, the price, and whether they are taxable or not.

The bill can be displayed, listing all the items in a tabular format. At the end of the list, a summary of the prices will be printed.


### The `Item` Module

Implement this module in two files:

- the header `Item.h` containing the `Item` class and global constants definitions.
- the source code file `Item.cpp` containing the implementation for all member functions in `Item` class.

Your task for this module is to create the module, add the global constants to the header, define the class `Item`, and implement the member functions according to the specs below.

***Global Constatnts***

```cpp
/// <summary>
/// An integer representing the number of characters
///   of the `NAME` column (used in printing to screen).
/// </summary>
??? WIDTH_NAME  = 32;

/// <summary>
/// An integer representing the number of characters
///   of the `PRICE` column (used in printing to screen).
/// </summary>
??? WIDTH_PRICE =  8;

/// <summary>
/// An integer representing the number of characters
///   of the `TAX` column (used in printing to screen).
/// </summary>
??? WIDTH_TAX   =  4;
```


***Private Members in Class `Item`***

```cpp
/// <summary>
/// The name of the item.
/// </summary>
// TODO: declare the `m_name` attribute; a statically-allocated
///        array with `WIDTH_NAME` characters (not counting the
///        null terminator).

/// <summary>
/// The price of the item, not including tax.
/// </summary>
// TODO: declare the `m_price` attribute as a floating-point
//         number in double precision.

/// <summary>
/// `true` is the tax should be applied to this item when
///   calculating the total price.
/// </summary>
// TODO: declare the `m_isTaxed` attribute as a boolean flag.
```


***Public Members in Class `Item`***

```cpp
/// <summary>
/// Sets ALL object's attribute to a default value.
/// </summary>
/* TODO: define the `init` MODIFIER
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* init()
* 
* - set the name to empty string (this will be the empty state)
* - set the price to 0
* - the item should be taxed
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// If the parameters are valid, stores the values in
///   the attributes, otherwise sets the `Item`s attributes
///   to their default values.
/// </summary>
/// <param name="name">The name of the item.
/// 
///   **Valid name**: any C-string that is not null and not empty.
/// </param>
/// <param name="price">The price of the item.
/// 
///   **Valid price**: any number bigger than 0.
/// </param>
/// <param name="isTaxed">`true` if this item should be taxed.</param>
/// <returns>`true` if the parameters are valid and were accepted,
///   `false` otherwise.</returns>
/* TODO: define the `set` MODIFIER
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* set(name, price, isTaxed)
* 
* - if ALL parameters are valid store them in the attributes and return `true`
* - it at least one parameter is not valid, call the `init` function,
*     and return `false`.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Prints to screen the content of the `Item`.
/// </summary>
/* TODO: define the `display` QUERY
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* display()
*
* - save in local variables the current filling character and the precision
* - if the object is not in an empty state (the `m_name` attribute is not
*     an empty string), print:
*     "| NAME | PRICE | TAX? |<newline>"
*     where:
*     - `NAME` is a field of `WIDTH_NAME` characters, aligned to the left,
*         and using '.' as a filling character.
*     - `PRICE` is field of `WIDTH_PRICE` characters, aligned to the right,
*         using a space as a filling character, and having exactly two
*         digits after the period.
*     - `TAX?` is field of `WIDTH_TAX` characters, aligned to the right,
*         and using space as a filling character.
* - if the object is in an empty state, print:
*     "| xxx | xxx | xxx |<newline>"
*     - use the same formatting options as described above.
* - remove the formatting options that were set by this function
*   - the filling character and the precision
*   - anything set by "setf()" must be removed with "unsetf()"
* 
* Look in the sample output for hints regarding the formatting.
* 
* Note that the borders are separated from the column content by a space.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Checks if the object is in empty state or not.
/// </summary>
/// <returns>`true` if the object is in empty state, `false` otherwise.</returns>
/* TODO: define the `isEmpty` QUERY
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* isEmpty()
*
* - the object is in empty state if the `m_name` attribute is an empty string.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Return to the client the price of the item before tax.
/// </summary>
/// <returns>the price of the item.</returns>
/* TODO: define the `getPrice` QUERY
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* getPrice()
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Returns to the client the tax that must be paid for the item.
/// </summary>
/// <returns>the tax for the item.</returns>
/* TODO: define the `getTax` QUERY
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* getTax()
* 
* - if the item is not taxable, the tax is `0`
* - if the item is taxable, the tax is 13% of the price.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
```



### The `Bill` Module

Implement this module in two files:

- the header `Bill.h` containing the `Bill` class definitions.
- the source code file `Bill.cpp` containing the implementation for all member functions in `Bill` class.

Your task for this module is to create the module, define the class `Bill`, and implement the member functions according to the specs below.

***Private Members in Class `Bill`***

```cpp
/// <summary>
/// The title of the bill.
/// </summary>
// TODO: declare the `m_title` attribute; a statically-allocated
///        array with `50` characters (not counting the
///        null terminator).


/// <summary>
/// The collection of items.
/// </summary>
//TODO: declare the `m_items` attribute; this attribute will store
//        the address of a dynamically-allocated array of objects
//        of type `Item`.


/// <summary>
/// The maximum number of items this bill can accommodate.
/// </summary>
//TODO: declare the `m_capacity` attribute as an integer.


/// <summary>
/// The number of items in this bill. Cannot be bigger than capacity.
/// </summary>
//TODO: declare the `m_cntItems` attribute as an integer.


/// <summary>
/// Calculates the tax for all items in the bill.
/// </summary>
/// <returns>the total tax for all items.</returns>
/* TODO: define the `getTotalTax` QUERY
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* getTotalTax()
*
* - create a local variable (floating point number in double precision)
*     to store the total tax
* - iterate over the array of items and add the tax of each one
*     to the local variable (use `Item::getTax()` function).
* - return the total tax
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Calculates the total price of the items in the bill (no tax included).
/// </summary>
/// <returns>the total price for all items.</returns>
/* TODO: define the `getTotalPrice` QUERY
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* getTotalPrice()
*
* - create a local variable (floating point number in double precision)
*     to store the total price
* - iterate over the array of items and add the price of each one
*     to the local variable (use `Item::getPrice()` function).
* - return the total price
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Print to screen the header of the table for the bill content.
/// </summary>
/* TODO: define the `displayHeader` QUERY
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* displayHeader()
*
* - save in a local variable the current filling character
* - print to screen the header in the following format:
*
*     +----------------------------------------------------+
*     | BILL_TITLE                                         |
*     +----------------------------------+----------+------+
*     | Item Name                        |    Price |  Tax |
*     +----------------------------------+----------+------+
*
*     where:
*     - `BILL_TITLE` is a field of `WIDTH_NAME + WIDTH_PRICE + WIDTH_TAX + 6`
*         characters, aligned to the left, and using space as a filling
*         character. If the object is invalid, the title is "Invalid Bill".
* - restore the formatting options the were set by this function
*   - the filling character
* 
* See the sample output for hints about formatting options.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Print to screen the footer of the table for the bill content.
/// </summary>
/* TODO: define the `displayFooter` QUERY
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* displayFooter()
* 
* - if the bill is not valid (use `Bill::isValid` to determine that), print to
*     screen:
* 
*     +----------------------------------+----------+------+
* 
*     and exit the function.
*
* - if the bill is valid:
*     - save in local variables the current filling character and the precision
*     - calculate the price before tax (use `Bill::getTotalPrice`)
*     - calculate the tax (use `Bill::getTotalTax`)
*     - calculate the price after tax (as a sum of price before tax and tax).
*     - print to screen the footer in the following format:
*
*       +----------------------------------+----------+------+
*       |                        Price Before Tax :    NN.NN |
*       |                                     Tax :    NN.NN |
*       |                         Price After Tax :    NN.NN |
*       +----------------------------------------------------+
*
*       where:
*       - `NN.NN` is a field of `WIDTH_PRICE` characters, aligned to the right,
*           using space as a filling character, and having exactly two
*           digits after the period.
*     - restore the formatting options the were set by this function
*       - the filling character and the precision
*       - anything set by "setf()" must be removed with "unsetf()"
*
* See the sample output for hints about formatting options.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Checks if the object contains valid data.
/// </summary>
/// <returns>`true` if the object is valid, `false` otherwise.</returns>
/* TODO: define the `isValid` QUERY
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* isValid()
*
* - return `true` if all the following conditions are met:
*   - `m_items` is not null
*   - `m_title` is not an empty string
*   - ALL items in the array (up to `m_capacity`) are valid. Iterate over the
*       array and use `Item::isEmpty` to check each item.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
```


***Public Members in Class `Bill`***

```cpp
/// <summary>
/// Initializes the `Bill` object to the values received as parameters.
///   If the parameters are invalid, set the object to a default state.
/// </summary>
/// <param name="title">A C-string representing the title for this bill.
/// 
///   **Valid title**: any array of characters that is not null and
///                    not empty.</param>
/// <param name="capacity">An integer representing the maximum number of
///   items this bill can accommodate.
/// 
///   **Valid capacity**: any number bigger than 0.
/// </param>
/* TODO: define the `init` MODIFIER
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* init(title, capacity)
*
* - if all parameters are valid
*   - copy at most 50 characters from the parameter into the attribute.
*   - copy the capacity parameter into the attribute.
*   - dynamically allocate an array of `Item` objects (of size `capacity`).
*       Store it's address into the `m_items` attribute.
*   - iterate over the dynamic array, and for each item call the `Item::init()"
*       function.
*   - set the attribute `m_cntItems` to 0.
* - if at least one parameter is not valid
*   - set title to empty string
*   - set capacity to 0
*   - set the `m_items` pointer to null
*   - set the `m_cntItems` to 0
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Add a new item to the bill, if there is capacity.
/// </summary>
/// <param name="item_name">The new item's name.</param>
/// <param name="item_price">The new item's price.</param>
/// <param name="isTaxed">`true` if the new item should be taxed.</param>
/// <returns>`true` if the item was successfully added.</returns>
/* TODO: define the `add` MODIFIER
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* add(item_name, item_price, isTaxed)
*
* - if there is still capacity in the array (the number of items is
*     smaller than the capacity)
*     - call the `Item::set()` on the item at index `m_cntItems`, passing
*         the parameters received.
*     - increment `m_cntItems`
*     - return the value returned by `Item::set()`
* - if there is no capacity, return `false` and do nothing else.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Prints to screen the content of the bill formatted like a table.
/// </summary>
/* TODO: define the `display` QUERY
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* display()
*
* - display the table header
* - iterate over the array of items, and call `Item::display()` on each one
* - display the table footer
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


/// <summary>
/// Deallocate all the dynamic memory used by the `Bill` object,
///   and set all the attributes to their default values.
/// </summary>
/* TODO: define the `cleanup` MODIFIER
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* cleanup()
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
```



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
