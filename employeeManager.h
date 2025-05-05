#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H

#include "IEmployee.h"
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>

class EmployeeManager {
private:
    std::vector<std::shared_ptr<IEmployee>> employeeList; // Danh sách nhân viên

public:
    // Thêm nhân viên mới
    void addEmployee(const std::shared_ptr<IEmployee>& emp);

    // Sửa hồ sơ nhân viên
    void modifyEmployee(int empId, const std::shared_ptr<IEmployee>& updatedEmp);

    // Xóa hồ sơ nhân viên
    void deleteEmployee(int empId);

    // Hiển thị hồ sơ nhân viên cụ thể
    void displayEmployeeById(int empId) const;

    // Hiển thị danh sách toàn bộ nhân viên
    void displayAllEmployees() const;

    // In phiếu lương nhân viên
    void printPayroll(int empId) const;

    // Hiển thị thông tin nhân viên
    void displayEmployee(const std::shared_ptr<IEmployee>& emp) const;
};

#endif // EMPLOYEE_MANAGER_H