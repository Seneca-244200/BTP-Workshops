# Week #6, Workshop #5: Member Operators, Helper functions

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





## Student Marks

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

***You may freely use/copy any logic or code needed from the exercise!***  You must use *custom types*, *public*/*private members*, *constructors*, and *operator overload*.



### Reflection


## Reflection

Study your final solution of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

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
