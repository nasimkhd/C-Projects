//Name: Nasim Khodapanah
// //Student ID: 131929200
// Workshop 3: part 2
// Email: nkhodapanah@myseneca.ca
// Date: 6/8/2021
/////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
using namespace std;
namespace sdds {

    void strnCpy(char* des, const char* src, int len)
    {
        int i;
        for (i = 0; i < len; i++)
        {
            des[i] = src[i];
            des[len] = '\0';
        }
    }
}