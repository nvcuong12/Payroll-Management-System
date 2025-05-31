#ifndef _FULLTIMEEMPLOYEE_H_
#define _FULLTIMEEMPLOYEE_H_

#include "IEmployee.h"

/**
 * @file FulltimeEmployee.h
 * @brief Định nghĩa lớp FulltimeEmployee, đại diện cho nhân viên chính thức.
 */

/**
 * @class FulltimeEmployee
 * @brief Lớp đại diện cho Nhân viên Chính thức (Full-time).
 *
 * Nhân viên chính thức có một mức lương cơ bản cố định hàng tháng (`_baseSalary`)
 * và thâm niên làm việc (`_monthsWorked`). Lương của họ được tính toán chi tiết
 * dựa trên giờ làm việc thực tế, giờ tăng ca, ngày lễ, cùng với các khoản thưởng,
 * phụ cấp và khấu trừ.
 * Lớp này kế thừa từ IEmployee và cài đặt các phương thức ảo cần thiết.
 */
class FulltimeEmployee : public IEmployee {
private:
    double _baseSalary;     ///< @brief Lương cơ bản cố định hàng tháng của nhân viên.
    int _monthsWorked;      ///< @brief Số tháng đã làm việc (thâm niên) của nhân viên.

public:
    /**
     * @brief Constructor cho lớp FulltimeEmployee.
     * @param id Mã nhân viên duy nhất.
     * @param name Tên đầy đủ của nhân viên.
     * @param addr Địa chỉ liên lạc của nhân viên.
     * @param phone Số điện thoại của nhân viên.
     * @param email Địa chỉ email của nhân viên.
     * @param info Thông tin bổ sung (ví dụ: "Kinh nghiem 5 nam").
     * @param expiryDate Ngày hết hạn hợp đồng (thường là không xác định hoặc "0-0-0" cho nhân viên chính thức), định dạng "YYYY-MM-DD".
     * @param baseSalary Mức lương cơ bản hàng tháng.
     * @param monthsWorked Số tháng đã làm việc.
     */
    FulltimeEmployee(std::string id, std::string name, std::string addr, std::string phone,
        std::string email, std::string info, std::string expiryDate,
        double baseSalary, int monthsWorked);

    // --- Override các phương thức từ lớp cơ sở IEmployee ---

    /**
     * @brief Tính toán chi tiết lương cho nhân viên chính thức trong một kỳ lương cụ thể.
     * Sử dụng SalaryCalculator để tính các thành phần lương dựa trên giờ làm việc thực tế,
     * lương cơ bản, thưởng, phụ cấp và khấu trừ.
     * @param attendance Đối tượng quản lý chấm công.
     * @param month Tháng cần tính lương (1-12).
     * @param year Năm cần tính lương.
     * @param bonuses Tổng tiền thưởng.
     * @param allowances Tổng tiền phụ cấp.
     * @param deductions Tổng tiền khấu trừ.
     * @return Đối tượng SalaryDetails chứa các thành phần lương chi tiết.
     */
    SalaryDetails calculateSalary(const AttendanceManager& attendance, int month, int year, double bonuses, double allowances, double deductions) const override;
    
    /**
     * @brief Lấy mức lương cơ bản cố định của nhân viên.
     * @return Giá trị lương cơ bản (_baseSalary).
     */
    double getBaseSalary() const override;

    /**
     * @brief Lấy số tháng đã làm việc (thâm niên).
     * @return Số tháng đã làm việc.
     */
    int getMonthsWorked() const override;

    /**
     * @brief Chuyển đổi thông tin nhân viên chính thức thành chuỗi định dạng CSV.
     * @return Chuỗi CSV biểu diễn thông tin nhân viên.
     */
    std::string toCsvString() const override;

    /**
     * @brief Đặt (cập nhật) số tháng đã làm việc cho nhân viên.
     * @param months Số tháng làm việc mới.
     */
    void setMonthsWorked(int months) override;

    /**
     * @brief Đặt (cập nhật) mức lương cơ bản cho nhân viên.
     * @param salary Mức lương cơ bản mới.
     */
    void setBaseSalary(double salary) override;

};

#endif // _FULLTIMEEMPLOYEE_H_