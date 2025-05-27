#include "employeeManager.h"

std::vector<std::unique_ptr<IEmployee>>& EmployeeManager::getEmployees() {
	return employees;
}

const std::vector<std::unique_ptr<IEmployee>>& EmployeeManager::getEmployees() const {
	return employees;
}