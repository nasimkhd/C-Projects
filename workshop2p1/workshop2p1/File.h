//Name: Nasim Khodapanah
// //Student ID: 131929200
// Workshop 2: part 1
// Email: nkhodapanah@myseneca.ca
// Date: 2021/6/2
/////////////////////////////////
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#include "Employee.h"
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();

	bool read(char address[]);
	bool read(int& employeeNum);
	bool read(double& employeeSalary);

}
#endif // !SDDS_FILE_H_