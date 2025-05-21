#ifndef _EMPLOYEEREPOSITORY_H_
#define _EMPLOYEEREPOSITORY_H_

#include "Employee.h"

// class lưu trữ danh sách nhân viên
class EmployeeRepository {
private:
	std::vector<Employee*> employees;
public:
	~EmployeeRepository();
	void addEmployee(Employee* emp);
	void removeEmployee(const std::string& empID);
};

void EmployeeRepository::removeEmployee(const std::string& empID) {
	for (auto it = employees.begin(); it != employees.end(); ++it) {
		if ((*it)->getEmployeeID() == empID) {
			delete* it;
			employees.erase(it);
			break;
		}
	}
}

void EmployeeRepository::addEmployee(Employee* emp) {
	employees.push_back(emp);
}

EmployeeRepository::~EmployeeRepository() {
	for (auto emp : employees) {
		if (emp == nullptr) continue;
		delete emp;
	}
}

#endif // !_EMPLOYEEREPOSITORY_H_

