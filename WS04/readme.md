# Week #5, Workshop #4: Constructors, Destructors, and Current Object

In this workshop, you will use Constructors, a Destructor and a reference of the current object to simulate a Canister to hold liquid products.


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define a default constructor.
- define custom constructors with different number of arguments.
- define a destructor to prevent memory leaks.
- use the reference of the current object.
- describe to your instructor what you have learned in completing this workshop


## General Instructions

### Submission Policy

This workshop is divided into one coding part and one non-coding part.

- **coding part**: A *step-by-step* guided workshop, worth 100% of the workshop's total mark.
  Please note that the workshop is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- **reflection**: non-coding part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
  - Submissions that do not contain the *reflection* (that is the **non-coding part**) are considered incomplete and are ignored.



### Due Dates


The due is at the end of the day that is 5 days after the day with the lab.

Choose the `-due` option of the submitter program to see the exact due date of your section:

```bash
~profname.proflastname/submit 200/wsX_SSS -due
```

- Replace `X` with workshop number: [`01` to `10`]
- Replace `SSS` with the section identifier: [`naa`, `nbb`, `nra`, `zaa`, etc.]



### Late penalties

You are allowed to submit your work up to 2 days after the due date with 30% penalty for each day. After that, the submission will be closed, and the mark will be zero. If the reflection is missing when the submission closes, the mark will be set to 0.



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





## Label Maker

Write a program that prints labels to the screen. A label is a text of any length (for simplicity and easy testing, store maximum 70 characters) surrounded by a frame. See the sample output for hints.

The program consists of two module that you must develop (`Label` and `LabelMaker`) and a tester module that is provided (`LabelTester`).

### The `Label` Module

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


### The `LabelMaker` Module

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

***You may freely use/copy any logic or code needed from the exercise!***  You must use *custom types*, *public*/*private members*, *dynamic memory allocation*, *constructors*, and *destructors*.



### Reflection


Study your final solution of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty and how you solved them.

To avoid deductions, refer to code in your solution as examples to support your explanations. You may be asked to talk about your reflection (as a presentation) in class.



### Submission

To test and demonstrate execution of your program use the same data as shown in the sample output.

Upload the header files (`*.h`) and source code files (`*.cpp`) to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly:

- `Label.h`
- `Label.cpp`
- `LabelMaker.h`
- `LabelMaker.cpp`
- `tester_1.cpp`

Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly. A sample run can be found in the file `output_sample.txt`.

Then, run the following command from your matrix account:

```bash
~profname.proflastname/submit 200/wsX_SSS
```

- replace `X` with workshop number: [`1` to `10`]
- replace **SSS** with the section: [`naa`, `nbb`, `nra`, `zaa`, etc.]
and follow the instructions.

> **:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
