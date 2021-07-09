
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
 namespace sdds {
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