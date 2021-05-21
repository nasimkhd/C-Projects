//Name: Nasim Khodapanah
//Student ID: 131929200
//Seneca Email: nkhodapanah@myseneca.ca
//Section: NAA


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"

using namespace std;
namespace sdds
{
	void strCpy(char* des, const char* src){
		int a = 0;
		while (src[a] != '\0') {
			des[a] = src[a];
			a++;
		}
		des[a] = '\0';
	}


	void strnCpy(char* des, const char* src, int len)
	{
		int i;
		for ( i = 0; i < len; i++)
		{
			des[i] = src[i];
		}
	}

	int strCmp(const char* s1, const char* s2)
	{
		int result=0,i;
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

	int strnCmp(const char* s1, const char* s2, int len)
	{
		int result=0,i;
		for (i = 0; i < len; i++)
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
		int count = 0,i;
		for (i = 0; i < s[i]; i++)
		{
			count++;
		}
		return count;
	}

	const char* strStr(const char* str1, const char* str2)
	{
		int result = 0,i,j;
		int length = strLen(str1);
		int length2 = strLen(str2);
		for ( i = 0; i < length; i++)
		{
			for ( j = 0; j < length2; j++)
			{
				if (str1[i+j] == str2[j])
					result++;
			}
			if (result == length2) 
				return &str1[i];
		}
		return nullptr;
	}

	void strCat(char* des, const char* src)
	{
		int i = 0;
		int length = strLen(des);
		while (src[i] != '\0') {
			des[length] = src[i];
			length++;
			i++;
		}
		des[length] = '\0';
	}
}
