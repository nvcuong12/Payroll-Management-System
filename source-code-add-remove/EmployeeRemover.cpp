#include "Employee.h"
#include "EmployeeRepository.h"

// Xóa nhân viên khỏi danh sách
class EmployeeRemover {
private:
	EmployeeRepository& empRepo;
public:
	EmployeeRemover(EmployeeRepository& repo) : empRepo(repo) {}
	void removeEmployee(const std::string& empID);
};

void EmployeeRemover::removeEmployee(const std::string& empID) {
	empRepo.removeEmployee(empID);
}