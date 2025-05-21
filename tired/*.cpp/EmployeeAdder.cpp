#include "Employee.h"
#include "EmployeeRepository.h"

// Th�m nh�n vi�n v�o danh s�chA
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
