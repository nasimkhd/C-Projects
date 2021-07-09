// Workshop 2: 
// Version: 1.0
// Date: 2021/5/28
// Author: Fardad Soleimanloo
// Description:
// This file tests the part 1 section of your workshop
// Do not modify your code
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"

using namespace std;
using namespace sdds;
int main() {
    if (load()) {
        display();
    }
    deallocateMemory();
    return 0;
}