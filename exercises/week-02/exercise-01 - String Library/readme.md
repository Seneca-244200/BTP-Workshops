# Week #2, Exercise #1: Modules

This exercise is not marked.

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

> Note: All the code written in workshops and the project must be implemented in the `seneca` namespace, unless instructed otherwise.








## String Library

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


### Test Your Code

To test and demonstrate execution of your program use the same data as shown in the sample output.

Upload the source code files to your `matrix` account:

- `cstring.h`
- `cstring.cpp`
- `tester_1.cpp`

Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly. The professor's tester module has been provided in the repository. A sample run can be found in the file `output_sample.txt`.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 200/week-X/ex-Y
```

- Replace `X` with week number: [`1` to `14`]
- Replace `Y` with the exercise number.

and follow the instructions.
