
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

using namespace std;
namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
    // TODO: read functions go here
    bool read(char employee[]) {
        return fscanf(fptr, "%[^\n]\n", employee) == 1;
    }
    bool read(int& employeeNum) {
        return fscanf(fptr, "%d,", &employeeNum) == 1;
    }
    bool read(double& employeeSalary) {
        return fscanf(fptr, "%lf,", &employeeSalary) == 1;
    }
}
