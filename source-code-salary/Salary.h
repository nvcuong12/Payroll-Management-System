#ifndef SALARY_H
#define SALARY_H

#include "Attendance.h"
#include <iostream>

// Cấu trúc chứa thông tin chi tiết về lương
struct SalaryDetails {
    double basicSalary;     // Lương cơ bản
    double overtimeSalary;  // Lương làm thêm giờ
    double holidaySalary;   // Lương làm trong ngày lễ
    double bonuses;         // Các khoản thưởng
    double allowances;      // Các khoản trợ cấp
    double deductions;      // Các khoản khấu trừ
    double totalSalary;     // Tổng lương sau khi tính toán
};

// Lớp tính lương dựa trên dữ liệu chấm công
class SalaryCalculator {
private:
    double hourlyRate;       // Lương theo giờ làm việc bình thường
    double overtimeRate;     // Lương làm thêm giờ
    double holidayRate;      // Lương làm trong ngày lễ

public:
    // Hàm khởi tạo với các mức lương theo giờ
    SalaryCalculator(double hrRate, double otRate, double hdRate);

    // Hàm tính lương dựa trên thông tin chấm công
    SalaryDetails calculateSalary(const Attendance& attendance, const std::string& employeeId,
        double bonuses, double allowances, double deductions);
};

class ShowSalary {
public:
    void showSalary(const SalaryDetails& details);
};

#endif // SALARY_H
