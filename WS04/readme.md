# Workshop #4: Constructors, Destructors, and Current Object

In this workshop, you will use Constructors, a Destructor and a reference of the current object to simulate a Canister to hold liquid products.


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

> [!IMPORTANT]
> This [Submission Policy](#submission-policy) only applies to the workshops. All other assessments in this subject have their own submission policies.


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

> [!NOTE]
> All the code written in workshops and the project must be implemented in the `seneca` namespace, unless instructed otherwise.





## Part 1 (50%)

Your task for this part of the workshop is to create a `Canister` module for holding liquid products.

A **Canister** is a cylindrical container that is created using its height, its diameter, and is labeled with the name of its content (e.g., Milk, Orange Juice, etc.).  The name of the content is dynamically allocated array of characters that you must manage. A canister also holds the volume of the content it is holding making sure the liquid does not exceed its capacity. Any canister can be filled only up to 0.267 centimetres from the top.

The smallest canister can have a height and diameter of 10.0 by 10.0 centimetres and the largest one can be 40 by 30 respectively. To calculate the capacity, use PI with a value of `3.14159265`.


### The `Canister` Module

Your task for this module is to create the module, define the class `Canister`, and implement the member functions according to the specs below.


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


### `canisterTester` Module

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

> [!WARNING]
> Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.





## Part 2 (50%)

Write a program that prints labels to the screen. A label is a text of any length (for simplicity and easy testing, store maximum 70 characters) surrounded by a frame. See the sample output for hints.

The program consists of two module that you must develop (`Label` and `LabelMaker`) and a tester module that is provided (`LabelTester`).

## The `Label` Module  

The `Label` class creates a label by drawing a frame around a one-line text with an unknown size (maximum of 70 chars; the class must store in an attribute the address of a **dynamically allocated array of characters**).

The frame is dictated by a series of 8 characters in a C-string. These characters indicate how the frame is to be drawn:

```txt
character 1: top left corner character.
character 2: character to repeat for the top line.
character 3: top right corner character
character 4: character to repeat for the right line.
character 5: bottom right corner character
character 6: character to repeat for the bottom line.
character 7: bottom left corner character
character 8: character to repeat for the left line.
```

For example the string `"AbCdEfGh"` will generate the following frame around a text:

```txt
AbbbbbbbbbbbbbbbbbbbbbbbbbC
h                         d
h                         d
h                         d
GfffffffffffffffffffffffffE
```

Your solution should contain at least the following public members in the custom type `Label`:

```cpp
/// <summary>
/// Creates an empty label with the frame `"+-+|+-+|"`.
/// </summary>
Label();

/// <summary>
/// Creates an emtpy label specified frame.
/// </summary>
/// <param name="frame">The frame for the label.</param>
Label(const char* frame);

/// <summary>
/// Creates a label with specified frame and content.
/// </summary>
/// <param name="frame">The frame for the label.</param>
/// <param name="content">The text to be displayed inside the label.
///   Must be stored dynamically in an attribute.</param>
Label(const char* frame, const char* content);

/// <summary>
/// Clean-up any dynamic memory used by the current instance.
/// </summary>
~Label();

/// <summary>
/// Reads the label from console up to 70 characters and
///   stores it in the current object.
/// </summary>
void readLabel();

/// <summary>
/// Prints the label to screen by drawing the frame around the content.
/// 
/// Note that no newline is printed after the last line.
/// </summary>
/// <returns>`std::cout`</returns>
std::ostream& print() const;
```


## The `LabelMaker` Module

The `LabelMaker` class creates a dynamic array of objects of type `Label` and gets their content from the user one by one and prints them all at once.

Your solution should contain at least the following public members in the custom type `LabelMaker`:

```cpp
/// <summary>
/// Creates a dynamically allocated array of objects of type
///   `Label` of size specified as a parameter. Stores the
///   address of the array in an attribute and manages it.
/// </summary>
/// <param name="noOfLabels">The number of labels in the array.</param>
LabelMaker(int noOfLabels);

/// <summary>
/// Reads from keyboard the labels and stores them in the array.
/// 
/// **NOTE**: look in the sample output for hints.
/// </summary>
void readLabels();

/// <summary>
/// Prints to screen all the labels stored in current instance.
/// 
/// **NOTE**: look in the sample output for hints.
/// </summary>
void printLabels();

/// <summary>
/// Clean-up any resource used by the current instance.
/// </summary>
~LabelMaker();
```

As general guidelines, consider the following when designing your solution:

- do not add global variables/functions, unless specifically instructed to do so.  Global constants are acceptable.
- add as many private members as your design requires.
- all attributes in a class must be private, unless specifically instructed otherwise.
- all member functions should be queries, unless the needs of the project require otherwise.
- all member functions should be private, unless the needs of the project require otherwise.
- all public functions must validate their parameters before working with them (don't trust that clients provide good values).
- all parameters passed by-address or by-reference should be constants, unless the needs of the code require otherwise.

***You may freely use/copy any logic or code needed from the PART 1!***  You must use *custom types*, *public*/*private members*, *dynamic memory allocation*, *constructors*, and *destructors*.



## Reflection


Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty and how you solved them.

To avoid deductions, refer to code in your solution as examples to support your explanations. You may be asked to talk about your reflection (as a presentation) in class.



### Submission

To test and demonstrate execution of your program use the same data as shown in the sample output.

Upload the header files (`*.h`) and source code files (`*.cpp`) to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly:

- `Label.h`
- `Label.cpp`
- `LabelMaker.h`
- `LabelMaker.cpp`
- `labelTester.cpp`

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


> [!WARNING]
> Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
