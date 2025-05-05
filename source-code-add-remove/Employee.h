// Quản lí cái danh sách nhân viên
#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_


#include <iostream>
#include <fstream>
#include <vector>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>

class Employee {
private:
	std::string employeeID;
	std::string name;
	std::string address;
	std::string joiningDate;
	std::string phone;
	std::string designation;
	std::string grade;
public:
	std::string getEmployeeID() const { return employeeID; }
};

#endif // !_EMPLOYEE_H_
