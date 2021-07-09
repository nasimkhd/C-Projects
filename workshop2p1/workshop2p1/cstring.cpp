//Name: Nasim Khodapanah
// //Student ID: 131929200
// Workshop 2: part 1
// Email: nkhodapanah@myseneca.ca
// Date: 2021/6/2
/////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"

using namespace std;
namespace sdds
{
	void strCpy(char* des, const char* src) {
		int a = 0;
		while (src[a] != '\0') {
			des[a] = src[a];
			a++;
		}
		des[a] = '\0';
	}

	int strLen(const char* s)
	{
		int count = 0, i;
		for (i = 0; i < s[i]; i++)
		{
			count++;
		}
		return count;
	}

}
