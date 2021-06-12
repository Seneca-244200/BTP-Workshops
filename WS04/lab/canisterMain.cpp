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

