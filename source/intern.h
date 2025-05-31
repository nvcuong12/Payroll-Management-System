#ifndef _INTERN_H_
#define _INTERN_H_

#include "IEmployee.h"

/**
 * @file Intern.h
 * @brief Định nghĩa lớp Intern, đại diện cho nhân viên thực tập.
 */

/**
 * @class Intern
 * @brief Lớp đại diện cho Nhân viên Thực tập.
 *
 * Nhân viên thực tập nhận một khoản trợ cấp cố định hàng tháng (`_stipend`)
 * và có thông tin về số tháng đã thực tập (`_monthsWorked`).
 * Lương của họ chủ yếu dựa trên khoản trợ cấp này, cộng với các khoản thưởng,
 * phụ cấp (nếu có) và trừ đi các khoản khấu trừ (nếu có).
 * Lớp này kế thừa từ IEmployee và cài đặt các phương thức ảo cần thiết.
 */
class Intern : public IEmployee {
private:
    double _stipend;         ///< @brief Khoản trợ cấp cố định hàng tháng của thực tập sinh. Đây được coi là lương cơ bản của họ.
    int _monthsWorked;       ///< @brief Số tháng đã thực tập hoặc làm việc.

public:
    /**
     * @brief Constructor cho lớp Intern.
     * @param id Mã nhân viên duy nhất.
     * @param name Tên đầy đủ của nhân viên.
     * @param addr Địa chỉ liên lạc của nhân viên.
     * @param phone Số điện thoại của nhân viên.
     * @param email Địa chỉ email của nhân viên.
     * @param info Thông tin bổ sung (ví dụ: tên trường đại học, chuyên ngành).
     * @param expiryDate Ngày hết hạn hợp đồng thực tập (nếu có), định dạng "YYYY-MM-DD".
     * @param stipend Mức trợ cấp hàng tháng.
     * @param monthsWorked Số tháng đã làm việc/thực tập.
     */
    Intern(std::string id, std::string name, std::string addr, std::string phone,
        std::string email, std::string info, std::string expiryDate,
        double stipend, int monthsWorked);

    // --- Override các phương thức từ lớp cơ sở IEmployee ---

    /**
     * @brief Tính toán chi tiết lương cho nhân viên thực tập trong một kỳ lương cụ thể.
     * Lương của thực tập sinh chủ yếu là khoản trợ cấp cố định.
     * Các tham số `attendance`, `month`, `year` hiện không được sử dụng trực tiếp để tính trợ cấp
     * nhưng vẫn cần thiết để đảm bảo chữ ký hàm khớp với lớp cha.
     * @param attendance Đối tượng quản lý chấm công (hiện không dùng cho tính trợ cấp).
     * @param month Tháng cần tính lương (1-12) (hiện không dùng cho tính trợ cấp).
     * @param year Năm cần tính lương (hiện không dùng cho tính trợ cấp).
     * @param bonuses Tổng tiền thưởng đã được tính từ WelfareManager.
     * @param allowances Tổng tiền phụ cấp đã được tính từ WelfareManager.
     * @param deductions Tổng tiền khấu trừ đã được tính từ WelfareManager.
     * @return Đối tượng SalaryDetails chứa các thành phần lương chi tiết.
     */
    SalaryDetails calculateSalary(const AttendanceManager& attendance, int month, int year, double bonuses, double allowances, double deductions) const override;
    
    /**
     * @brief Lấy mức lương cơ bản của thực tập sinh, chính là khoản trợ cấp hàng tháng.
     * @return Giá trị trợ cấp (_stipend).
     */
    double getBaseSalary() const override;

    /**
     * @brief Lấy số tháng đã làm việc/thực tập.
     * @return Số tháng đã làm việc.
     */
    int getMonthsWorked() const override;

    /**
     * @brief Chuyển đổi thông tin nhân viên thực tập thành chuỗi định dạng CSV.
     * @return Chuỗi CSV biểu diễn thông tin nhân viên.
     */
    std::string toCsvString() const override;

    /**
     * @brief Đặt (cập nhật) số tháng đã làm việc/thực tập cho nhân viên.
     * @param months Số tháng làm việc/thực tập mới.
     */
    void setMonthsWorked(int months) override;

    /**
     * @brief Đặt (cập nhật) mức trợ cấp (lương cơ bản) cho thực tập sinh.
     * @param salary Mức trợ cấp mới.
     */
    void setBaseSalary(double salary) override; // Quan trọng: Thêm override này
};

#endif // _INTERN_H_