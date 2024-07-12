# Workshop #8: Virtual functions and Abstract base classes

In this workshop, you will create a hierarchy of classes to practice and understand the role of virtual functions in inheritance. 
The workshop consists of 4 classes:  
- Shape; encapsulates a shape that can be drawn on the screen<br />
(An interface, that is an abstract base class with only pure virtual functions)
- LblShape; encapsulates a shape that can be labelled <br />
(An abstract base class that represents a labelled shape) 
- Line; encapsulates a horizontal line on a screen with the label <br />
(this concrete class draws a labelled line)
- Rectangle; encapsulates a rectangle on the screen that can be labelled <br />
(this concrete class draws a rectangle with a label inside).


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define pure virtual functions
- create abstract base classes
- implement behaviour using virtual functions
- explain the difference between an abstract base class and a concrete class
- describe what you have learned in completing this workshop


## Submission Policy


The workshop is divided into one coding part and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 100% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (reflection): non-coding part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

## Due Dates
Part 1 (lab) is due 2 days after your lab day and Part 2 (Reflection) is due 2 days after your lab day.
 
The Due dates depend on your section. Please choose the "-due" option of the submitter program to see the exact due date of your section:

> Note that the submission usually opens by the end of Monday.
```bash
~profname.proflastname/submit 2??/wX/pY_sss -due<ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

## Late penalties
You are allowed to submit your work up to 2 days after the due date with a 50% penalty for each day. After that, the submission will be closed and the mark will be zero.

## Citation

Every file that you submit must contain (as a comment) at the top:<br />
**your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

### For work that is done partially by you.

If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

> - Add the citation to the file in which you have the borrowed code
> - In the 'reflect.txt` submission of part 2 (Reflection), add exactly what is added to which file and from where (or whom).

> :warning: This [Submission Policy](#submission-policy) only applies to the workshops. All other assessments in this subject have their own submission policies.

### If you have helped someone with your code

If you have helped someone with your code. Let them know of these regulations and in your 'reflect.txt' of part 2 (Reflection), write exactly which part of your code was copied and who was the recipient of this code.<br />By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.

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

> Note: All the code written in workshops and the project must be implemented in the **seneca** namespace, unless instructed otherwise.

### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in the workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.


# Part 1 - LAB (100%)

Implement four modules for the following classes; **Shape, LblShape, Line** and **Rectangle**

![Classes](images/classes.png)


## 1- The `Shape` interface

### Create the following two [Pure virtual functions](https://intro2oop.sdds.ca/E-Polymorphism/abstract-base-classes#pure-virtual-function):
>  In C++, a [Pure virtual function](https://intro2oop.sdds.ca/E-Polymorphism/abstract-base-classes#pure-virtual-function) is a virtual function that has no implementation in the base class. It is declared by setting its prototype to zero (`= 0;`) in the class declaration. This makes the class an interface, which cannot be instantiated. Any derived class must provide an implementation for this function, unless the derived class is also abstract. 

#### draw  
Returns void and receives a reference to **ostream** as an argument.  This pure virtual function can not modify the current object.

#### getSpecs
Returns void and receives a reference to **istream** as an argument. 

### `destructor`
Create a default virtual destructor for the shape interface. 
> To create a default virtual destructor for a class , you would declare it in the class definition using `virtual ~ClassName() = default;`. This tells the compiler to generate a default destructor. This guarantees that any dynamically allocated derived class from the Shape interface pointed by a Shape pointer will be removed properly from memory when deleted. No implementation is required in this case, as the compiler automatically generates it. This is a good practice in object-oriented programming in C++.

### `Shape` helper functions
Overload the insertion and extraction operators (using draw and getSpecs functions) so any shape object can be written or read using ostream and istream.


## 2- The `LblShape` abstract Class (the Labeled Shape class)
Inherit an abstract class from the interface `Shape` called `LblShape`.  This class adds a label to a `Shape`.

This class will implement the pure virtual function **getSpecs** but will not implement the draw function; therefore it remains abstract.

### Private Member variable
Add a character pointer member variable called **m_label** and initialize it to null.  This member variable will be used to hold the dynamically allocated label for the `Shape`.


### Protected members 
#### ``` label() ```
Add a query called **label** that returns the unmodifiable value of m_label member variable. 

### public members
#### Default (no argument) constructor
Sets the label pointer to null. (You don't need to do this if the **m_label** is already initialized to null)
#### One argument constructor
Allocates memory large enough to hold the incoming Cstring argument pointed by the **m_label** member variable.  Then copies the Cstring argument to the newly allocated memory.
#### Destructor
Deletes the memory pointed by **m_label** member variable.
#### deleted actions
The copy constructor and assignment operator are deleted to prevent copying or assignment of instances of this class.
#### getSpecs
Reads a comma-delimited Cstring form istream: <br /> 
Override the **Shape::getSpecs** pure virtual function to receive a Cstring (a label) from **istream** up to the **','** character (and then extract and ignore the **comma**).  Afterward, follow the same logic as was done in the one argument constructor; allocate memory large enough to hold the Cstring and copy the Cstring into the newly allocated memory. 

## 3- The `Line` concrete class
Line inherits the **LblShape** class to create a horizontal line with a label.

### Private Member variable
Create a member variable called **m_length** to hold the length of the **Line** in characters.

#### Default (no argument) constructor
Sets the **m_length** member variable to zero, and invokes the default constructor of the base class. 
#### Two argument constructor
Receives a Cstring and a value for the length of the line.  Passes the Cstring to the constructor of the base class and sets the **m_length** member variable to the value of the second argument.

#### Destructor
This class has no destructor implemented.

#### getSpecs
Reads comma-separated specs of the **Line** from istream.<br />
This function overrides the **getSpecs** function of the base class as follows.<br />
First, it will call the **getSpecs** function of the base class then it will read the value of the m_length attribute from the istream argument, and then it will ignore The rest of the characters up to and including the newline character **'\n'**.

#### draw
This function overrides the draw function of the base class.<br />
If the **m_length** member variable is greater than zero and the **label()** is not null, this function will first print the **label()** and then go to the new line.  Afterwards it keeps printing the **'='** (assignment character) to the value of the **m_length** member variable.<br />
Otherwise, it will take no action.

For example, if the Cstring returned by the label query is "Separator" and the length is 40, the draw function should insert the following into ostream:

```Text
Separator
========================================
```
## 3- The `Rectangle` concrete class
The Rectangle class inherits the **LblShape** class to create a frame with a label inside.

### Private Member variable
Create two member variables called **m_width** and **m_height** to hold the width and the height of a rectangular frame (number of characters).

#### Default (no argument) constructor
Sets the width and height member variables to zero.  It will also invoke the default constructor of the base class.

#### Three argument constructor
Receives a Cstring for the label, and two values for the width and height of the **Rectangle** from the argument list.  Passes the Cstring to the constructor of the base class and sets the **m_width** and **m_height** member variables to the corresponding values received from the argument list.
However if the **m_height** is less than 3 or **m_width** is less the length of the **label() + 2** it will set the Rectangle to an empty state.

#### Destructor
This class has no destructor implemented.

#### getSpecs
Reads comma-separated specs of the **Rectangle** from istream.<br />
This function overrides the **getSpecs** function of the base class as follows.<br />
First, it will call the **getSpecs** function of the base class, then it will read two comma-separated values from istream for **m_width** and **m_length** and then ignores the rest of the characters up to and including the newline character (**'\n'**).

#### draw
This function overrides the draw function of the base class.<br />
If the Rectangle is not in an empty state, this function will draw a rectangle with a label inside as follows, otherwise, it will do nothing:

First line:<br />
prints '+', then prints the '-' character (m_width - 2) times and then prints '+' and goes to newline.

Second line:<br />
prints '|', then in (m_width-2) spaces it prints the **label()** left justified and then prints '|' and goes to new line.

In next (m_height - 3) lines:<br />
prints '|', (m_width-2) spaces then prints '|' and goes to new line.

Last line: <b />
exactly like first line.

For example, if the Cstring returned by the label query is "Container", the width is 30 and the height is 5, this function should insert the following into ostream:

```Text
+----------------------------+
|Container                   |
|                            |
|                            |
+----------------------------+
```



## `main` Module (supplied)

[main.cpp](lab/main.cpp)

**Do not modify this module!**  Walk through the code and make sure you understand it.

### Correct output

[correct_output.txt](lab/correct_output.txt)

## PART 1 Submission 
### Files to submit
```Text
Shape.h
Shape.cpp
LblShape.h
LblShape.cpp
Line.h
Line.cpp
Rectangle.h
Rectangle.cpp
main.cpp
```
### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss  <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

and follow the instructions.


#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```text
~profname.proflastname/submit 2??/wX/upY_sss  <ENTER>
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> :warning:**Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty


# Part 2: Reflection

Study your final solutions for each deliverable of the workshop **and the most recent milestones of the project if applicable**, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be between 150 to 300 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and **the project milestones if applicable** and mention any issues that caused you difficulty.


### Reflection Submission Process:

Upload `reflect.txt` to matrix containing the reflection

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss  <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

and follow the instructions.

> :warning:**Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
act a penalty
