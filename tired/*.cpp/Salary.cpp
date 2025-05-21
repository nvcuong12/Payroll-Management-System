#include "Salary.h"

// Hàm khởi tạo SalaryCalculator
// Thiết lập mức lương theo giờ làm việc, tăng ca và ngày lễ
SalaryCalculator::SalaryCalculator(double hrRate, double otRate, double hdRate)
    : hourlyRate(hrRate), overtimeRate(otRate), holidayRate(hdRate) {
}

// Hàm tính lương của nhân viên
// Dữ liệu đầu vào:
// - attendance: Đối tượng quản lý chấm công
// - employeeId: Mã nhân viên cần tính lương
// - bonuses: Các khoản thưởng
// - allowances: Các khoản trợ cấp
// - deductions: Các khoản khấu trừ
// Dữ liệu đầu ra:
// - Trả về đối tượng SalaryDetails chứa thông tin chi tiết về lương
SalaryDetails SalaryCalculator::calculateSalary(const Attendance& attendance, const std::string& employeeId,
    double bonuses, double allowances, double deductions) {
    SalaryDetails details;

    // Lấy các thông tin chấm công từ Attendance
    int workHours = attendance.getTotalWorkHours(employeeId);      // Tổng giờ làm việc
    int overtimeHours = attendance.getOvertimeHours(employeeId);   // Tổng giờ tăng ca
    int holidayDays = attendance.getHolidayWorkDays(employeeId);   // Tổng số ngày làm ngày lễ
    int leaveUnpaidDays = attendance.getLeaveUnpaidDays(employeeId); // Số ngày nghỉ không phép

    // Tính lương cơ bản (giờ làm việc * đơn giá theo giờ)
    details.basicSalary = workHours * hourlyRate;

    // Tính lương tăng ca (giờ tăng ca * đơn giá tăng ca)
    details.overtimeSalary = overtimeHours * overtimeRate;

    // Tính lương làm việc trong ngày lễ (ngày lễ * đơn giá ngày lễ)
    details.holidaySalary = holidayDays * holidayRate;

    // Tính khấu trừ cho những ngày nghỉ không phép (ngày nghỉ * giờ làm * đơn giá)
    details.deductions = leaveUnpaidDays * hourlyRate * 8;

    // Gán các khoản thưởng và trợ cấp
    details.bonuses = bonuses;
    details.allowances = allowances;

    // Tính tổng lương
    details.totalSalary = details.basicSalary + details.overtimeSalary + details.holidaySalary
        + details.bonuses + details.allowances - details.deductions;

    // Trả về chi tiết lương sau khi tính toán
    return details;
}

// Hàm hiển thị thông tin lương
// Dữ liệu đầu vào:
// - details: Đối tượng SalaryDetails chứa thông tin chi tiết về lương
// Dữ liệu đầu ra:
// - Lương cơ bản
// - Lương làm thêm giờ
// - Lương làm trong ngày lễ
// - Các khoản thưởng
// - Các khoản trợ cấp
// - Các khoản khấu trừ
// - Tổng lương
void ShowSalary::showSalary(const SalaryDetails& details) {
	std::cout << "Basic Salary: " << details.basicSalary << std::endl;
	std::cout << "Overtime Salary: " << details.overtimeSalary << std::endl;
	std::cout << "Holiday Salary: " << details.holidaySalary << std::endl;
	std::cout << "Bonuses: " << details.bonuses << std::endl;
	std::cout << "Allowances: " << details.allowances << std::endl;
	std::cout << "Deductions: " << details.deductions << std::endl;
	std::cout << "Total Salary: " << details.totalSalary << std::endl;
}
