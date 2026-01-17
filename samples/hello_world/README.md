---
title: Hello World in C++
---

## Provided

Carefully read the provided tester module `main.cpp'. Do not make any changes to it.

## Task

Create a module consisting of `HelloWorld.h` and `HelloWorld.cpp` files:

**File** HelloWorld.h
- include preprocessor guard, with namespace called seneca
```cpp
#ifndef SENECA_HELLO_WORLD_H
#define SENECA_HELLO_WORLD_H

namespace seneca {
    

}
#endif
```
- inside the namespace, create a struct named HelloWorld:
    - with member character array of size 32.

**File** HelloWorld.cpp
- include `HelloWorld.h`: 
```cpp
#include "HelloWorld.h"
```
- inside namespace `seneca`, define a function named `printHW` with signature:
```cpp
void printHW(struct HelloWorld&, const char*)
```
- this function displays the received C-style arrays stored in the first and second parameters on the same line, spearated by a space character. Print one newline after it. You may use either C++-style output (`cout`) or C-style output (`printf') for printing.

## Submission

To submit, upload the files to your matrix account, and run the command:
```bash
~profname.proflastname/submit 200/samples/hello_world
```

***Note***: this submission is not marked, and does not influence your grade in any way.
