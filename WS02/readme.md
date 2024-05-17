# Workshop #2: Dynamic Memory

In this workshop, you will use *references* to modify content of variables in other scopes, overload functions and allocate memory at run-time and deallocate that memory when it is no longer required.


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- allocate and deallocate dynamic memory for an array;
- overload functions;
- create and use references;



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

***Employees Salary Report*** is a program that reads an unknown number of `Employee` records from a file and stores them in a dynamically-allocated array. Each record holds the name, number, and salary of an employee in a comma-separated-values format (`csv` file).

The program is partially developed; you can find all the files in the repository. Your responsibility is to complete the code as stated in the comments in the source code.

Create a project and add to it the provided files. From the main menu in Visual Studio, select **`View` » `Task List`**; this will open a window with a list with all your tasks (the tasks are marked with `TODO` in the source code). You can click on each one of them and Visual Studio will take you to the place where you must insert code or make changes.

### The `Employee` Custom Type

The structure holding a record is designed as follows:

```cpp
/// <summary>
/// A structure that encapsulates some information about a
///   single employee.
/// 
/// The name of the employee is a dynamically-allocated array
///   of characters. It requires that the programmer manages
///   the memory (allocation and deallocation).
/// </summary>
struct Employee
{
    char* m_name;
    int m_empNo;
    double m_salary;
};
```

The name of the employee is held in a dynamically-allocated C-style string; an object of type `Employee` will store the address of this dynamically-allocated string. Consider the following visual and note that every circle with an arrow in this diagram shows dynamic memory in use. The green boxes represent dynamic memory.

![DMA](images/mem.png)
  

### Data File

The data in the file has the following format:

```txt
EMPLOYEE NUMBER,SALARY,NAME<NEWLINE>
```

Two input files have been provided.  Test your code with those files.


### `File` Module (Partially Provided)

This module contains functions that facilitate working with files to read data. Look in the provided files and read the comments; make sure to understand the responsibilities of each function.  Read the provided code and make you understand how it accomplishes the goal.  If you need clarifications, contact your professor.



***Your Tasks:***

Implement 3 **overloads** of a function called `read`:

1. `read`: receives as parameter the **address** of an array of characters. Reads from the file the name of the employee and stores it in the parameter.

    Returns `true` if the read was successful, `false` otherwise.

    Use the following `fscanf` function to read the name of the employee from the file and return true if `fscanf` returns 1. See more information [here](https://en.cppreference.com/w/cpp/io/c/fscanf).

    ```C
    std::fscanf(g_fptr, "%[^\n]\n", ...);
    ```

2. `read`: receives as a parameter a **reference** to an integer representing the employee number. Reads from the file the employee number and stores it in the parameter.

    Returns `true` if the read was successful, `false` otherwise.

    Use the following `fscanf` function to read the number from the file and return true if `fscanf` returns 1. See more information [here](https://en.cppreference.com/w/cpp/io/c/fscanf).

    ```C
    std::fscanf(g_fptr, "%d,", ...);
    ```

3. `read`: receives as a parameter a **reference** to a floating-point number in double precision representing the employee's salary. Reads from the file the employee salary and stores it in the parameter.

    Returns `true` if the read was successful, `false` otherwise.

    Use the following `fscanf` function to read the salary from the file and return true if `fscanf` returns 1. See more information [here](https://en.cppreference.com/w/cpp/io/c/fscanf).

    ```C
    return std::fscanf(g_fptr, "%lf,", ...);
    ```


### `Employee` Module (Partially Provided)

This module contains functions and variables related to managing a collection of objects of type `Employee`.  Look in the provided files and read the comments; make sure to understand the responsibilities of each function.  Read the provided code and make you understand how it accomplishes the goal.  If you need clarifications, contact your professor.

***Your Tasks:***

Implement following functions:

- `load`: a function that receives as parameter a **reference** to an object of type `Employee`, loads from the file the information about the employee and returns `true` if it was successful (`false` otherwise).  Look in the provided files for the comments explaining in detail how to implement this function.

- `load`: an overload of the `load` function that receives as a parameter the **address** of C-string representing the file name with the data about employees.  Look in the provided files for the comments explaining in detail how to implement this function.

- `display`: a function that receives as a parameter an **unmodifiable reference** to an object of type `Employee` and prints it in the following format:

    ```txt
    NUMBER: NAME, SALARY<NEWLINE>
    ```

- `display`: an overload of the `display` function that receives an optional parameter of type `bool` (a parameter with a default value) and returns nothing. This function should:
  - print to screen

  ```txt
  Employee Salary Report
  no- Empno, Name, Salary
  -----------------------
  ```

  - if the parameter is `true`, sort the array by calling the `sort` function.
  - iterate over the array and print each employee in the format:

  ```txt
  IDX- EMPLOYEE_NUMBER: EMPLOYEE_NAME, EMPLOYEE_SALARY<NEWLINE>
  ```

  To print the name, salary, and number of an employee call the `display` function that accepts as a parameter a reference to an object of type `Employee`.

  - see sample output for more details.

- `deallocateMemory`: deallocate **all** the dynamic memory used by the collection of employees (make sure to also deallocate the names).  Look in the provided files for the comments explaining in detail how to implement this function.



### `salReport` Module

This module is already provided. Look at it, make sure you understand it, but do not change it.


### Submission

Upload the header files (`*.h`), source code files (`*.cpp`), and the data files (`*.csv`) to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

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

***You may freely use/copy any logic or code needed from the PART 1!***  You can add as many functions, custom types, and variables as your design requires. You must use *function overloading*, *references* and *dynamic memory allocation*.



### Submission

To test and demonstrate execution of your program use the same data as shown in the sample output.

Upload the header files (`*.h`), source code files (`*.cpp`), and the data files (`*.csv`) to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly:

- `File.h`
- `File.cpp`
- `Region.h`
- `Region.cpp`
- `popReport.cpp`
- `toronto.csv`
- `canada.csv`

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




## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty and how you solved them.

In the code above, you were instructed to overload the function `read` multiple times. The parameter received by these overloads is called an **out parameter**. Do some research and explain what is an **out parameter** for a function and compare it with an **in parameter**.  In your code, can you identify any function that receives an **in parameter**? Justify your answer.

To avoid deductions, refer to code in your solution as examples to support your explanations. You may be asked to talk about your reflection (as a presentation) in class.


### Submission

```bash
~profname.proflastname/submit 2??/wX/reflect_sss
```

- Replace `??` with your subject code (`00` or `44`)
- Replace `X` with workshop number: [`1` to `10`]
- Replace `sss` with the section identifier: [`naa`, `nbb`, `nra`, `zaa`, etc.]

and follow the instructions.
