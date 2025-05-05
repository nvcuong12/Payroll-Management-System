#include "Employee.h"
#include "EmployeeRepository.h"

// Thêm nhân viên vào danh sáchA
class EmployeeAdder {
private:
	EmployeeRepository& empRepo;
public:
	EmployeeAdder(EmployeeRepository& repo) : empRepo(repo) {}
	void addEmployee(Employee* emp);
};

void EmployeeAdder::addEmployee(Employee* emp) {
	empRepo.addEmployee(emp);
}
