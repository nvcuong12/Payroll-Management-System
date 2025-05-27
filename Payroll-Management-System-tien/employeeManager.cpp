#include "employeeManager.h"

void EmployeeManager::addEmployee(const std::shared_ptr<IEmployee>& emp) {
    employeeList.push_back(emp);
    std::cout << "Đã thêm nhân viên: " << emp->getName() << std::endl;
}

void EmployeeManager::modifyEmployee(int empId, const std::shared_ptr<IEmployee>& updatedEmp) {
    for (auto& emp : employeeList) {
        if (emp->getEmployeeId() == std::to_string(empId)) {
            emp = updatedEmp;
            std::cout << "Hồ sơ nhân viên với mã ID " << empId << " đã được cập nhật." << std::endl;
            return;
        }
    }
    std::cout << "Không tìm thấy nhân viên với mã ID: " << empId << std::endl;
}

void EmployeeManager::deleteEmployee(int empId) {
    auto it = std::remove_if(employeeList.begin(), employeeList.end(),
                             [empId](const std::shared_ptr<IEmployee>& emp) { return emp->getEmployeeId() == std::to_string(empId); });
    if (it != employeeList.end()) {
        employeeList.erase(it, employeeList.end());
        std::cout << "Đã xóa nhân viên với mã ID: " << empId << std::endl;
    } else {
        std::cout << "Không tìm thấy nhân viên với mã ID: " << empId << std::endl;
    }
}

void EmployeeManager::displayEmployeeById(int empId) const {
    for (const auto& emp : employeeList) {
        if (emp->getEmployeeId() == std::to_string(empId)) {
            displayEmployee(emp);
            return;
        }
    }
    std::cout << "Không tìm thấy nhân viên với mã ID: " << empId << std::endl;
}

void EmployeeManager::displayAllEmployees() const {
    std::cout << "Danh sách toàn bộ nhân viên:" << std::endl;
    for (const auto& emp : employeeList) {
        displayEmployee(emp);
        std::cout << "------------------------" << std::endl;
    }
}

void EmployeeManager::printPayroll(int empId) const {
    for (const auto& emp : employeeList) {
        if (emp->getEmployeeId() == std::to_string(empId)) {
            std::cout << "Phiếu lương của nhân viên: " << emp->getName() << std::endl;
            std::cout << "Lương: " << emp->calculateSalary() << std::endl;
            return;
        }
    }
    std::cout << "Không tìm thấy nhân viên với mã ID: " << empId << std::endl;
}

void EmployeeManager::displayEmployee(const std::shared_ptr<IEmployee>& emp) const {
    std::cout << "ID: " << emp->getEmployeeId() << "\n"
              << "Name: " << emp->getName() << "\n"
              << "Address: " << emp->getAddress() << "\n"
              << "Phone: " << emp->getPhone() << "\n"
              << "Additional Info: " << emp->getAdditionalInfo() << "\n"
              << "Contract Expiry: " << emp->getExpiredYear() << "-" << emp->getExpiredMonth() << "-" << emp->getExpiredDay() << "\n"
              << "Type: " << emp->getEmployeeType() << std::endl;
}