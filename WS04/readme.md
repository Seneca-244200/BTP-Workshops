# Workshop #4: Constructors Destructors and Current object
* Version 1.0

In this workshop, you will use Constructors, a Destructor and a reference of the current object to simulate a Canister to hold liquid food products.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define a default constructor
- define custom constructors with different number of arguments
- define a Destructor to prevent memory leaks.
- Use the reference of the current object 
- describe to your instructor what you have learned in completing this workshop

## Submission Policy

This workshop is divided into two coding parts and one non-coding part:

- Part 1: A step-by-step guided workshop, worth 50% of the workshop's total mark that is due on **Thursday at 23:59:59** of the week of your scheduled lab.
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your OOP244 class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (**DIY**): A Do It Yourself type of workshop that is much more open-ended and is worth 50% of the workshop's total mark. This part is due on **Sunday at 23:59:59** of the week of your scheduled lab.  
- *reflection*: non-coding part, to be submitted together with *DIY* part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
- Submissions of part 2 that do not contain the *reflection* (that is the **non-coding part**) are not considered valid submissions and are ignored.


If at the deadline the workshop is not complete, there is an extension of **one day** when you can submit the missing parts.  **The code parts that are submitted late receive 0%.**  After this extra day, the submission closes; if the workshop is incomplete when the submission closes (missing at least one of the coding or non-coding parts), **the mark for the entire workshop is 0%**.

Every file that you submit must contain (as a comment) at the top:<br />
**your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

If the file contains only your work or work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as following to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind ws
```

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **sdds** namespace.

# PART 1 (50%) The Canister Module

Your task for this part of the workshop is to create a **Canister** module for holding liquid edible products. 

A **Canister** is a cylindrical container that is created using its height and its diameter and is Labeled by the name of its content with an unknown length(i.e. Milk, Orange juice, etc...)  that is dynamically held by a Canister. A Canister also holds the volume of the content it is holding making sure the liquid does not exceed its capacity. Any container that is filled higher than 0.267 centimetres from the top of the canister is considered unusable. 

The smallest Canister can have a height and diameter of 10.0 by 10.0 centimetres and the largest one can be 40 by 30 respectively. 

#### Calculating the capacity
A Canister's capacity (i.e. maximum amount of content it can hold) is calculated as follows:  
```Text
PI: 3.14159265  (a global constant double value created in Canister.cpp)
H: Height
D: Diameter
Capacity = PI x (H - 0.267) x (D/2) x (D/2)
```


The **Canister** can be created in three different ways; 
- By default a **Canister** is created with the following **height** and **diameter**: 13.0 x 10.0 with no name and content amount of 0 (empty)
- Also a Canister can be created with its **content name**. In this case, the dimensions will be set to default values like the previous case and it will be empty.
- Finally, a Canister can be created using its height, diameter and content name. 

> In any case, when a Canister is created using initial values and any of the values provided is invalid, the Canister is rendered unusable.  

#### Pouring contents of one canister into another
You can fill the Canisters with the content they are labelled for. If too much is poured into the Canister, it will overflow and rendered unsalable.


You can pour all or some of the content of one Canister into another. If this results in mixed content, the target will be rendered unusable.

For example, if you can fill an empty orange juice Canister with the contents of a Canister holding Olive oil. Since the Orange juice Canister was empty everything will be OK and the Canister will be re-labelled as Olive oil. But if the orange juice canister has some orange juice in it, then it would have been rendered unusable.

To reuse an unusable Canister it must be reset and cleared. 

You must design your code in a way that re-labelling and destruction of Canisters do not result in a memory leak.



## Implementation 

Create a class in a Module called Canister.

### Private attributes (member variables)

```C++
    char* m_contentName; // points to a dynamically allocated Cstring.
    double m_diameter; // in centimeters 
    double m_hieght;   // in centimeters
    double m_contentVolume;  // in CCs
    bool m_usable; // a flag to identify if the Canister is usable or unusable
```

### Private methods (member functions)

```C++
      void setToDefault();
```  
This function sets the attributes to their default values. It sets the content name pointer to null, height to 13.0, diameter to 10.0, content volume to 0.0 and usable flag to true.

```C++
      bool isEmpty()const;
```
Returns true is the content volume is less than 0.00001 CCs.
```C++
      bool hasSameContent(const Canister& C)const;
```
Compares the content name of this Canister with the one received from the argument **C**.
Using strCmp in **cstring.h**, it returns true if both content names are not null and are identical. Otherwise, it returns false;
> Note: If you have not completed your **cstring** module in workshop one, either you can get it from a friend and cite it in the comment section of the file, or use the standard <cstring> header file and leave the **cstring** module files empty. 
```C++
      void setName(const char* Cstr);
```
Sets the content name of the current Canister.<br />
If the incoming **Cstr** is not null and the Canister is usable, it will delete the current content name, allocate memory to the length of Cstr (+1 for null) and copies the Cstr into the newly allocated memory. Otherwise, it will silently do nothing.


### Constructors
#### No argument Constructor (defualt)
Sets the attributes to their default values
#### One argument Constructor:
```C++
Canister(const char* contentName);
```
- Sets the attributes to their default values (note: reuse code)
- Sets the Name to the incoming **contentName** argument.
```C++
Canister(double hieght, double diameter, const char* contentName);
```
- Sets the attributes to their default values.

If the dimensions are within acceptable values:
- it will set the m_height and m_diameter to the corresponding argument values
- it will set the content volume to 0.
- it will set the content name to the corresponding argument value.

If any of the dimensions have invalid values, it will set the Canister **unusable**

### The Destructor
Deallocates the dynamic memory pointed by the content name attribute.

### Public Methods (member variables)
```C++
      void clear();
```
Clears an unusable Canister back to an empty Canister by:  
- deallocating the memory pointed by the content name attribute
- sets the content name attribute to **nullptr**
- sets the content volume attribute to 0.0
- set the usable flag attribute to true
```C++
      double capacity()const;
```
returns the capacity as stated in [Calculating the capacity](#calculating-the-capacity)
```C++
      double volume()const;
```
returns the content volume attribute
```C++
      Canister& setContent(const char* contentName);
```
It will set the Content name of the canister using the following rule and then returns the reference of the current object (i.e. *this):

If the **contentName** argument is null it will render the Canister unusable<br />
else if the Canister is empty it will set the Name to the value pointed by the argument<br />
else if the name of the Canister is not the same as the contentName argument it will render the Canister unusable.
```C++
      Canister& pour(double quantity);
```
Adds the **quantity** argument to the content volume of the Canister if the **quantity** fits in the Canister. Otherwise, it will render the Canister unusable and then returns the reference of the current object.<br />
Use this rule to accomplish the above:<br />
If the Canister is **usable** and the **quantity**  is more than zero and if the sum of the quantity and the **volume()** is less than or equal to the **capacity()**, add the  **quantity** to the content volume, otherwise set usable flag attribute to false.
```C++
      Canister& pour(Canister& C);
```
Pours the content of the Canister argument into the current Canister following the [Specs stated at the top](#pouring-contents-of-one-canister-into-another)

Set the content name to the Canister argument using **setContent()**.<br />
if the **volume()** of the argument is greater than the **capacity()** minus the **volume()**<br />
Reduce the **content volume** of the argument by **capacity()** minus **volume()** and then set the content volume to **capacity()**<br />
else pour the **content volume** of the argument using **pour()** method and set the **content volume** of the argument to 0.0.<br />
return the reference of the current object at the end.

```C++
      std::ostream& display()const;
```
> Prints all the number values with one digit after the decimal point.

Prints the Canister in the following format:
```Text
In 7 spaces prints the capacity
"cc ("
height
"x"
diameter
") Canister"
```
if unusable:
```Text
" of Unusable content, discard!"
```
otherwise, if the content name is not null
```Text
" of "
in 7 spaces prints the volume
"cc   "
content name
```
returns the cout at the end.

## Tester program:
```C++
// Workshop 4:
// Version: 1.0
// Date: 2021-06-03
// Author: Fardad Soleimanloo
// Description:
// This file tests the lab section of your workshop
/////////////////////////////////////////////
#include <iostream>
#include "Canister.h"
using namespace std;
using namespace sdds;
void showCans(const char* title, const Canister* boxArray, int num = 1);
int main() {
   int i;
   Canister C[]={
      Canister(),
      Canister(nullptr),
      Canister("Orange Juice"),
      Canister(40,30),
      Canister(20, 10, "Olive Oil"),
      Canister(9,20, "Bad ones"),
      Canister(20,9),
      Canister(41,20, "Bad ones"),
      Canister(20,31, "Bad ones")
   };
   showCans("Five good ones and 4 bad ones:", C, 9);
   for (i = 5; i < 9; i++) C[i].clear();
   showCans("All good:", C, 9);
   C[5].setContent("Milk").pour(500);
   C[6].setContent("MilK");
   showCans("Milk canisters", &C[5], 2);
   C[6].pour(C[5]);
   showCans("Poured one into another", &C[5], 2);
   showCans("Poured 800ccs into the empty canister", &C[5].pour(800), 1);
   C[6].pour(C[5]);
   showCans("Filled one with the milk from another", &C[5], 2);
   showCans("Poured 1500ccs of Olive oil into Olive oil canister", &C[4].pour(1500), 1);
   C[5].pour(C[4]);
   showCans("Filled can of milk with olive oil", &C[4], 2);
   showCans("Poured too much into olive oil canister", &C[4].pour(1500), 1);
   for (i = 3; i < 9; i++) C[i].setContent(nullptr);
   showCans("All bad", &C[3], 6);
   return 0;
}
void showCans(const char* title, const Canister* canArray, int num ) {
   cout << " " << title << endl;
   cout << " Capacity,  Dimensions            Volume     Content" << endl;
   cout << "------------------------------    ---------  ---------------------------" << endl;
   for (int i = 0; i < num; i++) {
      canArray[i].display() << endl;
   }
   cout << "------------------------------------------------------------------------" << endl << endl;
}


```

## Execution sample:
```Text
 Five good ones and 4 bad ones:
 Capacity,  Dimensions            Volume     Content
------------------------------    ---------  ---------------------------
 1000.0cc (13.0x10.0) Canister
 1000.0cc (13.0x10.0) Canister
 1000.0cc (13.0x10.0) Canister of     0.0cc   Orange Juice
28085.6cc (40.0x30.0) Canister
 1549.8cc (20.0x10.0) Canister of     0.0cc   Olive Oil
 1000.0cc (13.0x10.0) Canister of Unusable content, discard!
 1000.0cc (13.0x10.0) Canister of Unusable content, discard!
 1000.0cc (13.0x10.0) Canister of Unusable content, discard!
 1000.0cc (13.0x10.0) Canister of Unusable content, discard!
------------------------------------------------------------------------

 All good:
 Capacity,  Dimensions            Volume     Content
------------------------------    ---------  ---------------------------
 1000.0cc (13.0x10.0) Canister
 1000.0cc (13.0x10.0) Canister
 1000.0cc (13.0x10.0) Canister of     0.0cc   Orange Juice
28085.6cc (40.0x30.0) Canister
 1549.8cc (20.0x10.0) Canister of     0.0cc   Olive Oil
 1000.0cc (13.0x10.0) Canister
 1000.0cc (13.0x10.0) Canister
 1000.0cc (13.0x10.0) Canister
 1000.0cc (13.0x10.0) Canister
------------------------------------------------------------------------

 Milk canisters
 Capacity,  Dimensions            Volume     Content
------------------------------    ---------  ---------------------------
 1000.0cc (13.0x10.0) Canister of   500.0cc   Milk
 1000.0cc (13.0x10.0) Canister of     0.0cc   MilK
------------------------------------------------------------------------

 Poured one into another
 Capacity,  Dimensions            Volume     Content
------------------------------    ---------  ---------------------------
 1000.0cc (13.0x10.0) Canister of     0.0cc   Milk
 1000.0cc (13.0x10.0) Canister of   500.0cc   Milk
------------------------------------------------------------------------

 Poured 800ccs into the empty canister
 Capacity,  Dimensions            Volume     Content
------------------------------    ---------  ---------------------------
 1000.0cc (13.0x10.0) Canister of   800.0cc   Milk
------------------------------------------------------------------------

 Filled one with the milk from another
 Capacity,  Dimensions            Volume     Content
------------------------------    ---------  ---------------------------
 1000.0cc (13.0x10.0) Canister of   300.0cc   Milk
 1000.0cc (13.0x10.0) Canister of  1000.0cc   Milk
------------------------------------------------------------------------

 Poured 1500ccs of Olive oil into Olive oil canister
 Capacity,  Dimensions            Volume     Content
------------------------------    ---------  ---------------------------
 1549.8cc (20.0x10.0) Canister of  1500.0cc   Olive Oil
------------------------------------------------------------------------

 Filled can of milk with olive oil
 Capacity,  Dimensions            Volume     Content
------------------------------    ---------  ---------------------------
 1549.8cc (20.0x10.0) Canister of   799.9cc   Olive Oil
 1000.0cc (13.0x10.0) Canister of Unusable content, discard!
------------------------------------------------------------------------

 Poured too much into olive oil canister
 Capacity,  Dimensions            Volume     Content
------------------------------    ---------  ---------------------------
 1549.8cc (20.0x10.0) Canister of Unusable content, discard!
------------------------------------------------------------------------

 All bad
 Capacity,  Dimensions            Volume     Content
------------------------------    ---------  ---------------------------
28085.6cc (40.0x30.0) Canister of Unusable content, discard!
 1549.8cc (20.0x10.0) Canister of Unusable content, discard!
 1000.0cc (13.0x10.0) Canister of Unusable content, discard!
 1000.0cc (13.0x10.0) Canister of Unusable content, discard!
 1000.0cc (13.0x10.0) Canister of Unusable content, discard!
 1000.0cc (13.0x10.0) Canister of Unusable content, discard!
------------------------------------------------------------------------

```


## PART 1 Submission (part 1)
Files to submit:  
```Text
Canister.cpp
Canister.h
canisterMain.cpp
cstring.cpp
cstring.h
```

Upload your source code and data file to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```

and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.



# DIY (50%) the LabelMaker
> Please note that you can (and probably should) add more member functions to make the DIY part work better or more efficiently.

Write a program in two modules for a Label Maker application:


The Two modules are used as follows to print labels:  

## Sample main

```C++
// Workshop 4:
// Version: 1.0
// Date: 2021-06-03
// Author: Fardad Soleimanloo
// Description:
// This file tests the lab section of your workshop
/////////////////////////////////////////////
#include <iostream>
#include "Canister.h"
using namespace std;
using namespace sdds;
void showCans(const char* title, const Canister* boxArray, int num = 1);
int main() {
   int i;
   Canister C[]={
      Canister(),
      Canister(nullptr),
      Canister("Orange Juice"),
      Canister(40,30),
      Canister(20, 10, "Olive Oil"),
      Canister(9,20, "Bad ones"),
      Canister(20,9),
      Canister(41,20, "Bad ones"),
      Canister(20,31, "Bad ones")
   };
   showCans("Five good ones and 4 bad ones:", C, 9);
   for (i = 5; i < 9; i++) C[i].clear();
   showCans("All good:", C, 9);
   C[5].setContent("Milk").pour(500);
   C[6].setContent("MilK");
   showCans("Milk canisters", &C[5], 2);
   C[6].pour(C[5]);
   showCans("Poured one into another", &C[5], 2);
   showCans("Poured 800ccs into the empty canister", &C[5].pour(800), 1);
   C[6].pour(C[5]);
   showCans("Filled one with the milk from another", &C[5], 2);
   showCans("Poured 1500ccs of Olive oil into Olive oil canister", &C[4].pour(1500), 1);
   C[5].pour(C[4]);
   showCans("Filled can of milk with olive oil", &C[4], 2);
   showCans("Poured too much into olive oil canister", &C[4].pour(1500), 1);
   for (i = 3; i < 9; i++) C[i].setContent(nullptr);
   showCans("All bad", &C[3], 6);
   return 0;
}
void showCans(const char* title, const Canister* canArray, int num ) {
   cout << " " << title << endl;
   cout << " Capacity,  Dimensions            Volume     Content" << endl;
   cout << "------------------------------    ---------  ---------------------------" << endl;
   for (int i = 0; i < num; i++) {
      canArray[i].display() << endl;
   }
   cout << "------------------------------------------------------------------------" << endl << endl;
}


/////////////////////////////////////////////
#include <iostream>
#include "Label.h"
#include "LabelMaker.h"
using namespace sdds;
using namespace std;
int main() {
   int noOfLabels;
   // Create a lable for the program title 
   // and couple of empty ones:
   Label 
      theProgram("/-\\|/-\\|", "The Label Maker Program"),
      EmptyOne1,
      EmptyOne2("ABCDEFGH");
   theProgram.printLabel() << endl << endl;
   // ask for number of labels to get created
   cout << "Number of labels to create: ";
   cin >> noOfLabels;
   cin.ignore(10000, '\n');
   // Create a LabelMaker for the number of 
   // the labels requested
   LabelMaker lblMkr(noOfLabels);
   // Ask for the label texts
   lblMkr.readLabels();
   // Print the labels
   lblMkr.printLabels();
   return 0;
}
```

## DIY Execution sample
```Text
EmptyOne1

EmptyOne2

/-------------------------\
|                         |
| The Label Maker Program |
|                         |
\-------------------------/

Number of labels to create: 3
Enter 3 labels:
Enter label number 1
> Introduction to Programming Using C
Enter label number 2
> Introduction to Object Oriented Programming
Enter label number 3
> Object-Oriented Software Development Using C++
+-------------------------------------+
|                                     |
| Introduction to Programming Using C |
|                                     |
+-------------------------------------+
+---------------------------------------------+
|                                             |
| Introduction to Object Oriented Programming |
|                                             |
+---------------------------------------------+
+------------------------------------------------+
|                                                |
| Object-Oriented Software Development Using C++ |
|                                                |
+------------------------------------------------+

```

## The Label Module  

The label class creates a label by drawing a frame around a one-line text with an unknown size (maximum of 70 chars, **must be kept dynamically**).

The frame is dictated by series of 8 characters in a Cstring. These characters indicate how the frame is to be drawn:
```Text
character 1: top left corner character.
character 2: character to repeat for the top line.
character 3: top right corner character
character 4: character to repeat for the right line.
character 5: bottom right corner character
character 6: character to repeat for the bottom line.
character 7: bottom left corner character
character 8: character to repeat for the left line.
```
For example the following CString: ``` "AbCdEfGh" ``` <br />
will generate the following frame around a text:
```Text
AbbbbbbbbbbbbbbbbbbbbbbbbbC
h                         d
h                         d
h                         d
GfffffffffffffffffffffffffE
```

## Mandatory constructors and methods:
### Label()
Creates an empty label and defaults the frame to ```"+-+|+-+|"```
### Label(const char* frameArg)
Creates an empty label and sets the frame to the **frameArg** argument.
### Label(const char* frameArg, const char* content)
Creates a Label with the **frame** set to **frameArg** and the content of the Label set to the corresponding argument. Note that you must keep the content dynamically even though it should never be more than 70 characters.

### destructor
Makes sure there is no memory leak when the label goes out of scope.

###  void readLabel();
Reads the label from console up to 70 characters and stores it in the Label as shown in the [Execution sample](#diy-execution-sample)
###  std::ostream& printLabel()const;
Prints the label by drawing the frame around the content ad shown in the [Execution sample](#diy-execution-sample). Note that no newline is printed after the last line and cout is returned at the end.

## The LabelMaker Module  

The LabelMaker class creates a dynamic array of Labels and gets their content from the user one by one and prints them all at once. 

## Mandatory constructors and methods:
### LabelMaker(int noOfLabels);
creates a dynamic array of Labels to the size of **noOfLabels**
### void readLabels();
Gets the contents of the Labels as demonstrated in the [Execution sample](#diy-execution-sample)
### void printLabels();
Prints the Labels as demonstrated in the [Execution sample](#diy-execution-sample)
### ~LabelMaker();
Deallocates the memory when LabelMaker goes out of scope.


> Modify the tester program to test are the different circumstances/cases of the application if desired and note that the professor's tester may have many more samples than the tester program here.

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## DIY Submission (part 2)
Files to submit:  
```Text
Label.cpp
Label.h
LabelMaker.cpp
LabelMaker.h
w4_tester.cpp
cstring.cpp
cstring.h
```

Upload your source code and data file to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```

and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.


