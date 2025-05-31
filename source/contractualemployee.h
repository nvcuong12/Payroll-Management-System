#ifndef _CONTRACTUAL_EMPLOYEE_H_
#define _CONTRACTUAL_EMPLOYEE_H_

#include "IEmployee.h"

/**
 * @file ContractualEmployee.h
 * @brief Định nghĩa lớp ContractualEmployee, đại diện cho nhân viên hợp đồng.
 */

/**
 * @class ContractualEmployee
 * @brief Lớp đại diện cho Nhân viên Hợp đồng.
 *
 * Nhân viên hợp đồng có một khoản lương cố định được thỏa thuận trong hợp đồng (`_contractAmount`).
 * Lương của họ có thể được tính toán dựa trên số giờ làm việc thực tế với một mức lương giờ
 * nhất định, hoặc là một khoản cố định hàng tháng tùy theo logic cài đặt trong `calculateSalary`.
 * Lớp này kế thừa từ IEmployee và cài đặt các phương thức ảo cần thiết.
 */
class ContractualEmployee : public IEmployee {
private:
    double _contractAmount;  ///< @brief Số tiền lương thỏa thuận trong hợp đồng. Đây là lương cơ bản cố định của nhân viên hợp đồng.
    int _monthsWorked;       ///< @brief Số tháng đã làm việc của nhân viên.

public:
    /**
     * @brief Constructor cho lớp ContractualEmployee.
     * @param id Mã nhân viên duy nhất.
     * @param name Tên đầy đủ của nhân viên.
     * @param addr Địa chỉ liên lạc của nhân viên.
     * @param phone Số điện thoại của nhân viên.
     * @param email Địa chỉ email của nhân viên.
     * @param info Thông tin bổ sung (ví dụ: tên dự án).
     * @param expiryDate Ngày hết hạn hợp đồng, định dạng "YYYY-MM-DD".
     * @param contractAmount Số tiền lương theo hợp đồng (lương cơ bản).
     * @param monthsWorked Số tháng đã làm việc.
     */
    ContractualEmployee(std::string id, std::string name, std::string addr, std::string phone,
        std::string email, std::string info, std::string expiryDate,
        double contractAmount, int monthsWorked);

    // Override các phương thức từ lớp cơ sở IEmployee

    /**
     * @brief Tính toán chi tiết lương cho nhân viên hợp đồng trong một kỳ lương cụ thể.
     * Sử dụng SalaryCalculator để tính các thành phần lương dựa trên giờ làm việc thực tế (nếu có)
     * và lương hợp đồng cố định.
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
     * @brief Lấy mức lương cơ bản theo hợp đồng.
     * @return Giá trị lương cơ bản (_contractAmount).
     */
    double getBaseSalary() const override;
    
    /**
     * @brief Lấy số tháng đã làm việc.
     * @return Số tháng đã làm việc.
     */
    int getMonthsWorked() const override;
    
    /**
     * @brief Chuyển đổi thông tin nhân viên hợp đồng thành chuỗi định dạng CSV.
     * @return Chuỗi CSV biểu diễn thông tin nhân viên.
     */
    std::string toCsvString() const override;

    /**
     * @brief Đặt (cập nhật) số tháng đã làm việc cho nhân viên.
     * @param months Số tháng làm việc mới.
     */
    void setMonthsWorked(int months) override;

    /**
     * @brief Đặt (cập nhật) mức lương cơ bản/hợp đồng cho nhân viên.
     * @param salary Mức lương mới (_contractAmount).
     */
    void setBaseSalary(double salary) override;
};

#endif // _CONTRACTUAL_EMPLOYEE_H_