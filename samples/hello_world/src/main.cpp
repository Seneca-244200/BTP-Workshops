#include<iostream>
#include<cstring>
#include "HelloWorld.h"

using namespace seneca;
using namespace std;

int main(){

    HelloWorld hw;
    strcpy(hw.content,"Hello");

    cout << endl;
    printHW(hw,"World");
    printHW(hw,"Seneca");
    printHW(hw,"BSD Students");
    cout << endl;


}