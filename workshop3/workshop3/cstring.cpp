//Name: Nasim Khodapanah
// //Student ID: 131929200
// Workshop 3: part 1
// Email: nkhodapanah@myseneca.ca
// Date: 6/8/2021
/////////////////////////////////

#include "cstring.h"
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