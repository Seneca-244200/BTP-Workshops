#include <iostream>
#include "cstring.h"

using namespace std;

#ifndef SENECA_CSTRING_H
	#error "The header guard for 'cstring.h' doesn't follow the convention!"
#endif

int main()
{
   char str1[80] = "abcdefghijklmnopqrstuvwxyz";
   char str2[80];
   const char* fadd;

   seneca::strCpy(str2, str1);
   cout << str2 << endl;

   seneca::strnCpy(str2, "@@@", 2);
   cout << str2 << endl;

   seneca::strnCpy(str2, "@@@", 3);
   cout << str2 << endl;

   seneca::strnCpy(str2, "@@@", 4);
   cout << str2 << endl;

   cout << seneca::strCmp("aab", "aaa") << endl;
   cout << seneca::strnCmp("aab", "aaa", 2) << endl;
   cout << seneca::strnCmp("aab", "aaa", 3) << endl;
   cout << seneca::strLen("") << endl;
   cout << seneca::strLen(str1) << endl;

   fadd = seneca::strStr(str1, "jkl");
   cout << fadd << endl;

   fadd = seneca::strStr(str1, "bbb");
   if (!fadd)
      cout << "Not found" << endl;

   seneca::strCpy(str2, "John ");
   seneca::strCat(str2, "Doe");
   cout << str2 << endl;
   
   return 0;
}
