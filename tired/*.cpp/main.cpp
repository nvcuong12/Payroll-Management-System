#include <iostream>
#include <memory> // For std::make_shared
#include <vector>

// Bao gồm các header cần thiết
#include "employeeManager.h"
#include "fulltimeemployee.h"
#include "contractualemployee.h"
#include "intern.h"
#include "Attendance.h" // Chỉ cần nếu muốn tạo AttendanceRecord trực tiếp
#include "Salary.h"     // Chỉ cần nếu muốn hiển thị SalaryDetails riêng lẻ

int main() {
    // Khởi tạo EmployeeManager (đã tự động khởi tạo WelfareManager bên trong)
    EmployeeManager empManager;

    // 1. Thêm nhân viên
    std::cout << "--- Thêm nhân viên ---" << std::endl;
    auto emp1 = std::make_shared<FulltimeEmployee>("EMP001", "Nguyen Van A", "Quan 1, TP.HCM", "0901234567", 24, 15000000);
    empManager.addEmployee(emp1);

    auto emp2 = std::make_shared<ContractualEmployee>("EMP002", "Tran Thi B", "Di An, Binh Duong", "0908765432", 8000000, 10, "2025-12-31");
    empManager.addEmployee(emp2);

    auto emp3 = std::make_shared<Intern>("EMP003", "Le Van C", "Quan 7, TP.HCM", "0912345678", 3000000, 3, "2024-08-31");
    empManager.addEmployee(emp3);

    std::cout << "\n--- Danh sách tất cả nhân viên ---" << std::endl;
    empManager.displayAllEmployees();

    // 2. Thêm bản ghi chấm công
    std::cout << "\n--- Thêm bản ghi chấm công ---" << std::endl;
    empManager.addAttendanceRecord({ "EMP001", "2024-05-01", 8, 17, "normal" });
    empManager.addAttendanceRecord({ "EMP001", "2024-05-02", 8, 19, "overtime" }); // 2 giờ tăng ca
    empManager.addAttendanceRecord({ "EMP001", "2024-05-03", 8, 17, "normal" });
    empManager.addAttendanceRecord({ "EMP001", "2024-05-04", 0, 0, "leave" }); // Nghỉ phép có lương

    empManager.addAttendanceRecord({ "EMP002", "2024-05-01", 8, 17, "normal" });
    empManager.addAttendanceRecord({ "EMP002", "2024-05-02", 8, 17, "normal" });
    empManager.addAttendanceRecord({ "EMP002", "2024-05-03", 0, 0, "leave_unpaid" }); // Nghỉ không lương
    empManager.addAttendanceRecord({ "EMP002", "2024-05-04", 8, 17, "normal" });

    empManager.addAttendanceRecord({ "EMP003", "2024-05-01", 8, 17, "normal" });
    empManager.addAttendanceRecord({ "EMP003", "2024-05-02", 8, 17, "normal" });

    empManager.addAttendanceRecord({ "EMP004", "2024-05-01", 9, 18, "normal" });
    empManager.addAttendanceRecord({ "EMP004", "2024-05-02", 9, 18, "normal" });


    // 3. In phiếu lương
    std::cout << "\n--- In phiếu lương nhân viên EMP001 ---" << std::endl;
    empManager.printPayroll("EMP001");

    std::cout << "\n--- In phiếu lương nhân viên EMP002 ---" << std::endl;
    empManager.printPayroll("EMP002");

    std::cout << "\n--- In phiếu lương nhân viên EMP003 ---" << std::endl;
    empManager.printPayroll("EMP003");

    std::cout << "\n--- In phiếu lương nhân viên EMP004 ---" << std::endl;
    empManager.printPayroll("EMP004");

    // 4. Sửa thông tin nhân viên
    std::cout << "\n--- Sửa thông tin nhân viên EMP001 ---" << std::endl;
    auto updatedEmp1 = std::make_shared<FulltimeEmployee>("EMP001", "Nguyen Van A (Updated)", "Quan 3, TP.HCM", "0900000000", 25, 16000000);
    empManager.modifyEmployee("EMP001", updatedEmp1);
    empManager.displayEmployeeById("EMP001");

    // 5. Xóa nhân viên
    std::cout << "\n--- Xóa nhân viên EMP003 ---" << std::endl;
    empManager.deleteEmployee("EMP003");
    empManager.displayAllEmployees();

    std::cout << "\nChương trình kết thúc." << std::endl;

    return 0;
}