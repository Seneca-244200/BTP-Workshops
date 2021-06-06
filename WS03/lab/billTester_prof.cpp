// Workshop 3: 
// Version: 1.0
// Date: 2021-06-03
// Author: Fardad Soleimanloo
// Description:
// This file tests the lab section of your workshop
//    for submission
// Do not modify this code when submitting
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "Bill.h"
using namespace sdds;
using namespace std;
void billTester();
int main() {
   FILE* list = fopen("grocery.txt","r");
   int recs = 0;
   char ch;
   Bill B;
   billTester();
   if (list) {
      char name[256];
      double price;
      int taxed;
      while (fscanf(list, "%c", &ch)==1) {
         recs += (ch == '\n');
      }
      rewind(list);
      B.init("Gorcery Items", recs);
      while (fscanf(list, "%[^\t]\t%lf%d\n", name, &price,&taxed) == 3) {
         B.add(name, price, taxed == 1);
      }
      B.display();
      B.deallocate();
      fclose(list);
   }
   else {
      cout << "file: grocery.txt not found!" << endl;
   }
   return 0;
}

void billTester() {
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
}