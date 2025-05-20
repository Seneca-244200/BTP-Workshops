# Week #3, Workshop #2: Dynamic Memory

In this workshop, you will use *references* to modify content of variables in other scopes, overload functions and allocate memory at run-time and deallocate that memory when it is no longer required.


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- allocate and deallocate dynamic memory for an array;
- overload functions;
- create and use references;



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





## Population Report

Write a **postal-code-based population report** program that reads series of records of Canadian regions from a comma-separated-values file and prints a report to the screen.  Each region is identified by a postal code and the number of people living in that region.  When printing, the client has the option to require the regions to be sorted ascending by population.

The data is stored in two input files: `toronto.csv` and `canada.csv`. The format of the file is:

  ```txt
  POSTAL_CODE,POPULATION<NEWLINE>
  ```

  where, `POSTAL_CODE` is an array of exactly 3 characters, and `POPULATION` is an integer.

Your task is to implement two modules (`File` and `Region`) that read the data from a file, stores it in a *dynamically-allocated array* of objects (each object stores the information about a single region), and prints it to the screen as shown in the sample output.

Your solution should contain at least the following:

```cpp
/// <summary>
/// A custom type storing information about a single region.
/// </summary>
struct Region
{
    ???
};

/// <summary>
/// Loads from a file a collection of administrative regions; stores retrieved
///   data into a dynamically-allocated array.  Each region will have a "Postal Code"
///   and the number of people living there.
/// </summary>
/// <param name="filename">the file containing data.</param>
/// <returns>true if the data was successfully loaded, false otherwise.</returns>
??? load(??? filename);

/// <summary>
/// Prints to screen the collection of regions loaded from a file.
/// </summary>
/// <param name="areaName">the name of administrative area where those regions
///    are located (i.e., the city, province, country, etc.)</param>
/// <param name="sorted">optional parameter to specify if the regions should
///   be sorted based on the population or not. The default value is `false`.</param>
??? display(??? areaName, ??? sorted);

/// <summary>
/// Deallocated all the dynamic memory used by the program.
/// </summary>
void cleanUp();
```

***You may freely use/copy any logic or code needed from your exercise solution!***  You can add as many functions, custom types, and variables as your design requires. You must use *function overloading*, *references* and *dynamic memory allocation*.



## Reflection

Study your final solution of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty and how you solved them.

In this week exercise, you were instructed to overload the function `read` multiple times. The parameter received by these overloads is called an **out parameter**. Do some research and explain what is an **out parameter** for a function and compare it with an **in parameter**.  In your code, can you identify any function that receives an **in parameter**? Justify your answer.

To avoid deductions, refer to code in your solution as examples to support your explanations. You may be asked to talk about your reflection (as a presentation) in class.



### Submission

To test and demonstrate execution of your program use the same data as shown in the sample output.

Upload the header files (`*.h`), source code files (`*.cpp`), and the data files (`*.csv`) to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly:

- `File.h`
- `File.cpp`
- `Region.h`
- `Region.cpp`
- `tester_1.cpp`
- `toronto.csv`
- `canada.csv`

Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly. A sample run can be found in the file `output_sample.txt`.

Then, run the following command from your matrix account:

```bash
~profname.proflastname/submit 200/wsX_SSS
```

- replace `X` with workshop number: [`1` to `10`]
- replace **SSS** with the section: [`naa`, `nbb`, `nra`, `zaa`, etc.]
and follow the instructions.

> **:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
