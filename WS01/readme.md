# Workshop #1: Modules

In the process of doing your first workshop, in part 1 (**LAB**) section you are to sub-divide a program into modules, compile each module separately and construct an executable from the results of each compilation.



## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- organize source code into modules, using header and implementation files;
- compile and link modular programs;
- distinguish the contents of a header and an implementation file;
- describe to your instructor what you have learned in completing this workshop.



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

***Shopping List*** is a program that keeps track of your shopping list up to 15 items. You can add items to the list, remove and check the items you bought. Also, you can remove all the checked items and clear the list.


### Step 1: *Test the Program*


#### On Windows, using Visual Studio

- Open Visual studio 2022 and create an Empty C++ Windows Console Project:
  ![Empty Project](images/emptyproj.png)
- copy the file `w1p1.cpp` (provided) into the project folder.
- in VS, open `Solution Explorer` (click on `View` » `Solution Explorer` if it's not visible already), and then add `w1p1.cpp` file to your project:
  - Right-click on **`Source Files`**
  - Select **`Add` » `Existing Item`**
  - Select **`w1p1.cpp`** from the file browser
  - Click on **`Ok`**
- Now you can run the program by selecting **`Debug` » `Start Debugging`** or pressing the **`F5`** button.


#### On Linux, in your Matrix account

- connect to Seneca with [Global Protect VPN](https://inside.senecacollege.ca/its/services/vpn/studentvpn.html)
- upload `w1p1.cpp` and `shoppinglist.csv` to your matrix account (ideally, to a designated directory for your workshop solutions). Then, enter the following command to compile the source file and create an executable called `ws`:

  ```bash
  g++ w1p1.cpp -Wall -std=c++11 -o ws
  ```

- Type the following to run and test the execution:

  ```bash
  ws
  ```

The expected output of the program can be found in the file `sample_output.txt` (provided). Use the same input data as in the sample run and compare that the output is correct.



### Step 2: Create the Modules

It's time to break the program into multiple modules. In the solution explorer, add five new modules to your project:

- `shoppingListApp`: a module to hold the `main()` function and its relative functions (see below).
- `File`: a module to hold the functions and global variables related to file processing.
- `ShoppingList`: a module to hold the direct shopping list related functions, global variables and constants.
- `ShoppingRec`: a module to hold the shopping record related functions, variables, constants and the `ShoppingRec` custom type.
- `Utils`: a module to hold the general utility functions for the applications. This file may be moved to other workshops and assignments if needed.

The `shoppingListApp` module has an implementation (`.cpp`) file but no header file. The `File`,  `ShoppingList`, `ShoppingRec` and `Utils` modules have both implementation (`.cpp`) and header (`.h`) files:


#### Header files

Add `File.h`, `ShoppingList.h`, `ShoppingRec.h` and `Utils.h` to the project directory (right click on project name and select *`Add` » `New Item`* and add a header file).  

Make sure you add the compilation safeguards and have all the C++ code in the last four modules in a namespace called `seneca`. **Compilation Safeguards** refers to a technique to guard against multiple inclusion of headers in *the same module*. It does so by applying macros that check against a defined name:

```cpp
#ifndef NAMESPACE_HEADERFILENAME_H // replace with relevant names, each header should have it's own header guard
#define NAMESPACE_HEADERFILENAME_H

// Your header file content goes here

#endif
```

If the name isn’t yet defined, the `#ifndef` will allow the code to proceed onward to then define that same name. Following that the header is then included. If the name is already defined, meaning the file has been included prior (otherwise the name wouldn’t have been defined), the check fails, the code proceeds no further and the header is not included again.

Compilation safeguards prevent multiple inclusions of a header in a module. They do not protect against including the header again in a different module (remember that each module is compiled independently from other modules).

Additionally, here is an instructional video showing how the compiler works and why you need these safeguards in all your header files. Do note that this video describes the intent and concept behind safeguards, the naming scheme isn’t the standard for our class. Follow the standard for safeguards as described in your class.

[Compilation Safeguards: https://www.youtube.com/watch?v=EGak2R7QdHo](https://www.youtube.com/watch?v=EGak2R7QdHo)


#### C++ Source Files

Add `shoppingListApp.cpp`, `File.cpp`,  `ShoppingList.cpp`, `ShoppingRec.cpp` and `Utils.cpp` to the project (right click on project name and select *`Add` » `New Item`* and add a C++ file). In each one of this file, include the corresponding header.


## Step 3: The `shoppingListApp` Module

At the top of the file, add the following:

```cpp
#include <iostream>
#include "File.h"
#include "ShoppingList.h"
#include "Utils.h"

using namespace std;
using namespace seneca;
```

From the provided file `w1p1.cpp`, add in this module the functions (these functions are not part of any namespace):

- `main` function
- `listMenu` function


## Step 4: Organize the Rest of the Code in Modules

Separate the remaining functions from `w1p1.cpp` into modules. Copy the body of the functions into the cpp files and the prototypes into the header files.


### Guideline for creating modules


- ***Included Headers***
  Avoid unnecessary random includes and only include a header file in another file in which the header file functions are called or the header file identifiers are used.
- ***Global Variables***
  Global variable declarations must be in the source files (`*.cpp`).
- ***Structure Definitions***
  Structure definitions must be kept in the header file to be visible to all the modules using it.
- ***Constant Value Definitions***
  The constant value definitions are to be added to the file they are used in; if they are used in a header file, they must be added to the header file otherwise they must be added to the source file they are used in.
- ***Namespaces***
  All your code (in header files and source files) must be surrounded by the `seneca` namespace except in the module holding the `main` function. The main module should only use the `seneca` namespace (`using namespace seneca;`).
  > Important: Never use the **using namespace ...** statement in a header file.

Add to each module the following:

- ***`ShoppingRec` module***
  - `ShoppingRec` custom type
  - `getShoppingRec` function
  - `displayShoppingRec` function
  - `toggleBoughtFlag` function
  - `isShoppingRecEmpty` function
  - `MAX_QUANTITY_VALUE` constant
  - `MAX_TITLE_LENGTH` constant

- ***`Utils` module***
  - `flushkeys` function
  - `validYesResponse` function
  - `yes` function
  - `readCstr` function
  - `readInt` function

- ***`ShoppingList` module***
  - `loadList` function
  - `displayList` function
  - `removeBoughtItems` function
  - `removeItem` function
  - `saveList` function
  - `clearList` function
  - `toggleBought` function
  - `addItemToList` function
  - `removeItemfromList` function
  - `listIsEmpty` function
  - `MAX_NO_OF_RECS` constant
  - `g_recs` global variable
  - `g_noOfRecs` global variable

- ***`File` module***
  - `openFileForRead` function
  - `openFileForOverwrite` function
  - `closeFile` function
  - `freadShoppingRec` function
  - `fwriteShoppintRec` function
  - `SHOPPING_DATA_FILE` constant
  - `g_sfptr` global variable


### Step 5: Testing

#### Windows

To test that you have done this correctly, you can compile each module separately, by right-clicking on `shoppingListApp.cpp`, `File.cpp`,  `ShoppingList.cpp`, `ShoppingRec.cpp` and `Utils.cpp` separately and select `Compile` from the menu. If the compilation is successful, most likely you have done it correctly.

Now remove `w1p1.cpp` from the project. You can do this by right-clicking on the filename in solution explorer and selecting `Remove` in the menu (make sure you do not delete this file but only remove it).

Compile and run the project (as you did before in Step 1) and make sure everything works.


#### Linux (in your Matrix account)

On Linux, in your matrix account, upload all the module files and the data file `shoppinglist.csv` to your matrix account and compile the source code using the following command.

To compile a single module add `-c` to the compile command:

```bash
g++ File.cpp –Wall -std=c++11 –c
```

This example will only compile `File.cpp` (only the first two stages of compilation) and will not create an executable.

To compile the whole project, use the command

```bash
g++ shoppingListApp.cpp File.cpp ShoppingList.cpp ShoppingRec.cpp Utils.cpp -Wall -std=c++11 -o ws
```

Run the program like before and make sure that everything still works properly and the output matches the expected one.


### Submission

The professor's testing module is slightly different and can be found in the file `shoppingListApp_prof.cpp`. During this term, the tester will check that you implemented correctly various features; as such it might contain specialized statements, or use different input files. Look at the provided tester, and ask your professor in class if it contains things that you don't understand.

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_SSS
```

- Replace `??` with your subject code (`00` or `44`)
- Replace `X` with workshop number: [`1` to `10`]
- Replace `Y` with the part number: [`1` or `2`]
- Replace **SSS** with the section: [`naa`, `nbb`, `nra`, `zaa`, etc.]
and follow the instructions.

> **Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty



## Part 2 (50%)

Create a `cstring` module that contains functions for string manipulation. The module will have two files: `cstring.cpp` and `cstring.h`.

> **:warning:Important:** You are not allowed to use any C or CPP library functions in this module!

### Functions to implement

```cpp
// Copies the source character string into the destination.
void strCpy(char* des, const char* src);

// Copies the source character string into the destination up to "count"
// characters. The destination will be null terminated only if the number
// of the characters copied is less than "count".
void strnCpy(char* des, const char* src, int count);

// Compares lexicographically two C-strings.
// - returns 0 if they are the same
// - return > 0 if s1 > s2
// - return < 0 if s1 < s2
int strCmp(const char* s1, const char* s2);

// Compares lexicographically the first "count" characters of two C-strings.
// - returns 0 if they are the same
// - return > 0 if s1 > s2
// - return < 0 if s1 < s2
int strnCmp(const char* s1, const char* s2, int count);

// Finds the size of a C-string.
// - returns the number of characters in "s".
int strLen(const char* s);

// Search if a string is a substring in another string.
// - returns the address of first occurance of "needle" in "haystack".
// - returns nullptr if no match is found.
const char* strStr(const char* haystack, const char* needle);

// Concantinates "src" C-string to the end of "dest".
void strCat(char* dest, const char* src);
```

These functions are similar in functionality with those already implemented in the standard `<cstring>` module. Look at the documentation of the standard functions for details in behaviour:

- [strcpy](https://en.cppreference.com/w/cpp/string/byte/strcpy)
- [strncpy](https://en.cppreference.com/w/cpp/string/byte/strncpy)
- [strcmp](https://en.cppreference.com/w/cpp/string/byte/strcmp)
- [strncmp](https://en.cppreference.com/w/cpp/string/byte/strncmp)
- [strlen](https://en.cppreference.com/w/cpp/string/byte/strlen)
- [strstr](https://en.cppreference.com/w/cpp/string/byte/strstr)
- [strcat](https://en.cppreference.com/w/cpp/string/byte/strcat)


## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a **text** file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty and how you solved them. Include in your explanation-**but do not limit it to**-the following points:

- what happens if you put the function `main` in the `seneca` namespace?
- what are the benefits of putting the code into multiple modules instead of putting everything in a single file?

To avoid deductions, refer to code in your solution as examples to support your explanations. You may be asked to talk about your reflection (as a presentation) in class.



### Submission

To test and demonstrate execution of your program use the same data as shown in the sample output.

Upload the source code files to your `matrix` account:

- `cstring.h`
- `cstring.cpp`
- `cstringTester.cpp`
- `reflect.txt`

Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly. The professor's tester module has been provided in the repository. A sample run can be found in the file `output_sample.txt`.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_SSS
```

- Replace `??` with your subject code (`00` or `44`)
- Replace `X` with workshop number: [`1` to `10`]
- Replace `Y` with the part number: [`1` or `2`]
- Replace `SSS` with the section identifier: [`naa`, `nbb`, `nra`, `zaa`, etc.]

and follow the instructions.


> **⚠Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
