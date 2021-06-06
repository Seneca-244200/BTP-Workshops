// Workshop 3: 
// Version: 1.0
// Date: 2021-06-03
// Author: Fardad Soleimanloo
// Description:
// This file tests the lab section of your workshop
// Do not modify this code when submitting
/////////////////////////////////////////////
#include "Bill.h"
using namespace sdds;
int main() {
   Bill B;
   B.init("Quick Shopping", 5);
   B.add("Milk 2%", 4.99, false);
   B.display();
   B.add(nullptr, 15.50, true);
   B.add("Frying Pan", 24.99, true);
   B.add("Eggs", -2.99, false);
   B.display();
   B.deallocate();
   B.init("Quick Shopping", 5);
   B.add("Milk 2%", 4.99, false);
   B.add("Spatula", 15.50, true);
   B.add("Frying Pan", 24.99, true);
   B.add("Eggs", 5.99, false);
   B.add("Bug Spray", 9.99, true);
   B.display();
   B.deallocate();
   return 0;
}