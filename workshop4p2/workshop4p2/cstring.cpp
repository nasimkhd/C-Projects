//Name: Nasim Khodapanah
// //Student ID: 131929200
// Workshop 4: part 2
// Email: nkhodapanah@myseneca.ca
// Date: 2021/6/15
/////////////////////////////////
#include "cstring.h"
using namespace std;
namespace sdds {
	
	int strLen(const char* s)
	{
		int count = 0, i;
		for (i = 0; i <= s[i]; i++)
		{
			count++;
		}
		return count;
	}
	void strCpy(char* des, const char* src) {
		int a = 0;
		while (src[a] != '\0') {
			des[a] = src[a];
			a++;
		}
		des[a] = '\0';
	}
}