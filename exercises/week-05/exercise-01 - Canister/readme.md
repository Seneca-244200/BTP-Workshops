# Week #5, Exercise #1: Constructors, Destructors, and Current Object

In this exercise, you will use constructors, a destructor and a reference of the current object to simulate a canister to hold liquid products.


## Learning Outcomes

Upon successful completion of this exercise, you will have gained the abilities to:

- define a default constructor.
- define custom constructors with different number of arguments.
- define a destructor to prevent memory leaks.
- use the reference of the current object.



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








## Canister

Your task for this exercise is to create a `Canister` module for holding liquid products.

A **Canister** is a cylindrical container that is created using its height, its diameter, and is labeled with the name of its content (e.g., Milk, Orange Juice, etc.).  The name of the content is dynamically allocated array of characters that you must manage. A canister also holds the volume of the content it is holding making sure the liquid does not exceed its capacity. Any canister can be filled only up to 0.267 centimetres from the top.

The smallest canister can have a height and diameter of 10.0 by 10.0 centimetres and the largest one can be 40 by 30 respectively. To calculate the capacity, use PI with a value of `3.14159265`.


### The `Canister` Module

Your tasks are to create the module, define the class `Canister`, and implement the member functions according to the specs below.


***Private Members in Class `Canister`***

```cpp
/// <summary>
/// The diameter of the canister, measured in centimeters.
/// </summary>
// TODO: declare the `m_diameter` attribute as a floating point
//         number in double precision.





/// <summary>
/// The height of the canister measured in centimeters.
/// </summary>
// TODO: declare the `m_height` attribute as a floating point
//         number in double precision.





/// <summary>
/// The address of a dynamically-allocated C-string of any
///   length containing the name of the content.
/// 
/// NOTE: If the address is null, then the canister should
///   have no content (the canister is empty).
/// </summary>
// TODO: declare the `m_contentName` attribute





/// <summary>
/// The amount of liquid (content) that is in the canister.
///   A value 0 means that the canister is empty.
/// 
/// NOTE: If the volume is more than 0, then the name should
///   be set to a valid string. If the volume is 0, the
///   name should be null.
/// </summary>
// TODO: declare the `m_contentVolume` attribute as a floating point
//         number in double precision.





/// <summary>
/// A boolean value that stores if a canister can be used.
///   A canister that cannot be used is a canister that contains
///   a mix of liquids. Such a canister must emptyed and washed
///   before it can be used again.
/// </summary>
// TODO: declare the `m_usable` attribute.





/// <summary>
/// Retrieve how much content the canister can hold.
/// </summary>
/// <returns>A floating point number in double precision representing
///   the capacity of the current instance.</returns>
/* TODO: define `getCapacity` query
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* getCapacity()
*
* - calculate the capacity of the container using the formula:
*   capacity = PI × (height - 0.267) × (diameter/2)^2
*
* The canister must have `0.267cm` of the height that must remain empty.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
```


***Public Members in Class `Canister`***

```cpp
/// <summary>
/// Creates an empty canister of default size.
/// </summary>
/* TODO: define the default constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* Canister()
*
* - sets the attributes to default values:
*   - name to null
*   - height to 13cm
*   - diameter to 10cm
*   - content volume to 0cc
*   - the canister is usable
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/





/// <summary>
/// Creates an empty canister of specified dimensions.
/// </summary>
/// <param name="diameter">A floating point number in double precision
///   representing the diameter in centimeters.</param>
/// <param name="height">A floating point number in double precision
///   representing the height in centimeters.</param>
/// </param>
/* TODO: define a custom constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* Canister(diameter, height)
*
* - if both parameters are valid, store them in the attributes. The remainder
*     attributes should be set to default values
* - if at least one parameter is not valid, set all attributes to their
*     default values
* 
* **HINT**: you can use delegated constructors to set the object to default
*             state with the default constructor.  See the
*             *"Delegating Constructor"* section in the documentation:
*             https://en.cppreference.com/w/cpp/language/constructor
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/





/// <summary>
/// Creates a canister of default size that has some content.
/// </summary>
/// <param name="contentName">The address of a C-style string of any
///   length.</param>
/// <param name="contentVolume">A floating point number in double precision
///   representing the amount of liquid (content) that is in the canister.</param>
/* TODO: define a custom constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* Canister(contentName, contentVolume)
*
* - initialize the diameter and height to the default values, and set
*     the canister in usable state.
* - call the function Canister::pour() and pass the parameters
*
* **HINT**: you can use delegated constructors to set the object to default
*             state with the default constructor.  See the
*             *"Delegating Constructor"* section in the documentation:
*             https://en.cppreference.com/w/cpp/language/constructor
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/





/// <summary>
/// Creates a canister of specified size that has some content.
/// </summary>
/// <param name="diameter">A floating point number in double precision
///   representing the diameter in centimeters.</param>
/// <param name="height">A floating point number in double precision
///   representing the height in centimeters.</param>
/// <param name="contentName">The address of a C-style string of any
///   length.</param>
/// <param name="contentVolume">A floating point number in double precision
///   representing the amount of liquid (content) that is in the canister.</param>
/* TODO: define a custom constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* Canister(diameter, height, contentName, contentVolume)
*
* - if both diameter and height parameters are valid, store them in the
*     attributes. If they are not valid set the attributes with to their default
*     values (use the constructor with 2 parameters to do this).
* - call the function Canister::pour() and pass the last two parameters
*
* **HINT**: you can use delegated constructors to validate and set the
*             diameter and height.  See the
*             *"Delegating Constructor"* section in the documentation:
*             https://en.cppreference.com/w/cpp/language/constructor
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/





/// <summary>
/// Cleanup any resource used by the current instance.
/// </summary>
/* TODO: define destructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* - deallocate the dynamic memory used by `m_contentName`.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/





/// <summary>
/// Add content to the current instance.
/// </summary>
/// <param name="what">The address of a C-string of any length
///   representing the name of the content to be added.</param>
/// <param name="howMuch">A floating point number
///   in double precision representing the amount of content
///   to be added.</param>
/// <returns>A reference to the current instance.</returns>
/* TODO: define `pour` modifier
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* pour(what, howMuch)
*
* - if the canister is usable, the `what` is not null and not empty string, and
*     `howMuch` is more than 0, then:
*     - if the canister is empty (the name is not set), allocate dynamic memory
*         for `m_contentName` and copy into it the content of `what` parameter.
*     - if `howMuch` is less or equal than the available capacity, add
*         `howMuch` to the `m_contentVolume`
*     - if `howMuch` is more than the available capacity, fill the canister
*         to capacity.
*     - if `what` is different from `m_contentName`, then:
*         - dynamically create a new C-string to store the value
*             "Mix of [CONTENT_NAME] and [WHAT]"
*         - delete the old content name
*         - store into the pointer `m_contentName` the address of the new string
*         - set the canister to not usable
* - return a reference to the current instance
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/





/// <summary>
/// Add content to the current instance and take it out from the parameter.
/// </summary>
/// <param name="src">A reference to a `Canister` object. The content
///   will be taken out from the parameter, and added to the current
///   instance.  If the parameter has different type of content, then
///   the current instance becomes unusable.</param>
/// <returns>A reference to the current instance.</returns>
/* TODO: define `pour` modifier
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* pour(src)
*
* - if both canisters are usable, then:
*     - calculate how much content can be transfered to the current instance
*         taking into account the capacity and the volume existing in the 
*         current instance, and how much content exists in `src`
*     - use `Canister::pour(contentName, contentVolume)` to add content
*         to current instance (this function will handle the case where
*         the content type is different in the two canisters)
*     - remove the transfered content from the parameter
*     - if all content from `src` was transfered, call the function
*         `Canister::emptyAndWash()` on the parameter
* - return a reference to the current instance
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/





/// <summary>
/// Remove the content from the canister (makes it empty). The canister
///   becomes usable.
/// </summary>
/* TODO: define `emptyAndWash` modifier
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* emptyAndWash()
*
* - deallocate any dynamic memory used by the current instance
* - set content name to null
* - set content volume to 0
* - the canister is usable
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/





/// <summary>
/// Inserts into the parameter the information about the state of the
/// current instance.
/// </summary>
/// <param name="out">A reference to an output streaming object where
///   to insert information about the state of the current instance.
///   This parameter has `std::cout` as a default value.</param>
/// <returns>A reference to an output streaming object, the same
///   received as parameter.</returns>
/* TODO: define `display` query
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* display()
*
* - if the canister is usable and has content, insert into the parameter
*   "CAPACITYcc (HEIGHTxDIAMETER) canister of VOLUMEcc  NAME"
* - if the canister is usable and is empty, insert into the parameter
*   "CAPACITYcc (HEIGHTxDIAMETER) canister of VOLUMEcc"
* - if the canister is not usable usable, insert into the parameter
*   "CAPACITYcc (HEIGHTxDIAMETER) canister of VOLUMEcc  NAME -> unusable content. Discard and wash!"
* 
*   where:
*   - CAPACITY and VOLUME are printed on a field of size 8,
*       with exactly one digit after period
*   - HEIGHT and DIAMETER are printed with exactly one digit after the period
* 
* - return the parameter
* 
* Before the function finishes, remove and restore all formating options to
*   the original ones.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
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
