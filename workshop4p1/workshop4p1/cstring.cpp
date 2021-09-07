
#include "cstring.h"
using namespace std;
namespace sdds {
	int strCmp(const char* s1, const char* s2)
	{
		int result = 0, i;
		for (i = 0; i < s2[i]; i++)
		{
			if (s1[i] == s2[i])
			{
				result = 0;
			}
			else result = 1;
		}
		return result;
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
	void strCpy(char* des, const char* src) {
		int a = 0;
		while (src[a] != '\0') {
			des[a] = src[a];
			a++;
		}
		des[a] = '\0';
	}
}
