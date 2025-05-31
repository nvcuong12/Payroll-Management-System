#ifndef _SALARY_CALCULATOR_H_
#define _SALARY_CALCULATOR_H_

#include "GlobalDefinitions.h"

class AttendanceManager; // Khai báo chuyển tiếp

/**
 * @file SalaryCalculator.h
 * @brief Định nghĩa lớp SalaryCalculator, chịu trách nhiệm tính toán chi tiết các thành phần lương.
 */

/**
 * @class SalaryCalculator
 * @brief Lớp chuyên dùng để tính toán các thành phần lương chi tiết cho một nhân viên.
 *
 * Lớp này nhận dữ liệu chấm công (thông qua AttendanceManager), các khoản thưởng, phụ cấp, khấu trừ,
 * và các mức lương giờ (bình thường, tăng ca, ngày lễ) đã được thiết lập để tính ra
 * lương làm việc thực tế trong kỳ, lương tăng ca, lương ngày lễ và tổng lương ròng cuối cùng.
 */
class SalaryCalculator {
private:
    double _hourlyRate;   ///< @brief Mức lương cho một giờ làm việc bình thường.
    double _overtimeRate; ///< @brief Mức lương cho một giờ làm thêm (tăng ca).
    double _holidayRate;  ///< @brief Mức lương cho một giờ làm việc vào ngày lễ.

public:
    /**
     * @brief Constructor cho lớp SalaryCalculator.
     * Khởi tạo đối tượng SalaryCalculator với các mức lương giờ được chỉ định.
     * @param hrRate Mức lương giờ làm việc bình thường.
     * @param otRate Mức lương giờ làm thêm (tăng ca).
     * @param hdRate Mức lương giờ làm việc vào ngày lễ.
     */
    SalaryCalculator(double hrRate, double otRate, double hdRate);

    /**
     * @brief Tính lương chi tiết cho nhân viên.
     * @param attendance Tham chiếu đến đối tượng quản lý chấm công.
     * @param employeeId Mã nhân viên cần tính lương.
     * @param baseSalary Lương cơ bản (nếu có, dùng cho các loại trừ lương).
     * @param bonuses Tổng thưởng.
     * @param allowances Tổng phụ cấp.
     * @param deductions Tổng khấu trừ (từ phúc lợi).
     * @return Đối tượng SalaryDetails chứa thông tin lương chi tiết.
     */
    SalaryDetails calculateSalary(const AttendanceManager& attendance, const std::string& employeeId, int month, int year, double baseSalary,
        double bonuses, double allowances, double deductions); // Thêm month, year
};

#endif // _SALARY_CALCULATOR_H_