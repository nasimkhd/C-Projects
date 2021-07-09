//Name: Nasim Khodapanah
// //Student ID: 131929200
// Workshop 2: part 1
// Email: nkhodapanah@myseneca.ca
// Date: 2021/6/2
/////////////////////////////////
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#define DATAFILE "employees.csv"
namespace sdds {
    struct Employee {
        char* m_name;
        int m_empNo;
        double m_salary;
    };
   
    void sort();
    bool load(Employee& inf);
    bool load();
    void display(const Employee& inf, int i);
    void display();
    void deallocateMemory();
}
#endif // SDDS_EMPLOYEE_H_