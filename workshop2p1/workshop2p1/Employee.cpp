//Name: Nasim Khodapanah
// //Student ID: 131929200
// Workshop 2: part 1
// Email: nkhodapanah@myseneca.ca
// Date: 2021/6/2
/////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    bool load(Employee& inf) {
        bool ok = false;
        char name[128];
        if (read(inf.m_empNo) && read(inf.m_salary)&&read(name))
        {
            inf.m_name = new char[strLen(name) + 1];
            strCpy(inf.m_name, name);
            ok = true;
        }
        return ok;
    }

    bool load() {
        bool ok = false;
        int i = 0;
        int numOfRead=0;
        if (openFile(DATAFILE)) {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            for (i = 0; i < noOfEmployees; i++)
            {
                numOfRead += (load(employees[i]));
            }
            if (numOfRead != noOfEmployees) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted";
            }
            else ok = true;

            closeFile();
        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }

    void display(const Employee& inf, int i) {
        cout << i << "- ";
        cout << inf.m_empNo << ": " << inf.m_name << ", " << inf.m_salary << endl;
    }

    void display() {
        int i;
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;
        sort();
        for (i = 0; i < noOfEmployees; i++) {
            display(employees[i], i + 1);
        }
    }

    void deallocateMemory() {
        for (int i = 0; i < noOfEmployees; i++)
        {
            delete[] employees[i].m_name;
            employees[i].m_name = nullptr;
        }
        delete[] employees;
        employees = nullptr;
    }
}