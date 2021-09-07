

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
