#ifndef _IEMPLOYEE_H_
#define _IEMPLOYEE_H_

#include <string>
#include <iostream>
#include <sstream>

/**
 * @brief Lớp trừu tượng cơ sở đại diện cho một Nhân viên.
 *
 * Lớp này định nghĩa các thuộc tính và hành vi chung
 * mà mọi loại nhân viên trong hệ thống đều có.
 *
 * @see Intern
 * @see FulltimeEmployee
 * @see ContractualEmployee
 */

class Attendance;
class IWelfare;

class IEmployee 
{
protected:
    std::string employeeId; ///< ID duy nhất của nhân viên.
    std::string name; ///< Tên của nhân viên.
    std::string address; ///< Địa chỉ của nhân viên.
    std::string phone; ///< SĐT của nhân viên.
    std::string expiryDate; ///< Ngày hết hạn hợp đồng (YYYY-MM-DD).
public:
/**
     * @brief Constructor cho lớp IEmployee.
     *
     * Khởi tạo một đối tượng Nhân viên với các thông tin cơ bản.
     * Nó cũng phân tích chuỗi ngày hết hạn hợp đồng từ định dạng YYYY-MM-DD.
     *
     * @param id ID duy nhất của nhân viên.
     * @param n Tên đầy đủ của nhân viên.
     * @param addr Địa chỉ của nhân viên.
     * @param p Số điện thoại liên lạc.
     * @param info Thông tin bổ sung về nhân viên.
     * @param expiryDateString Chuỗi ngày hết hạn hợp đồng theo định dạng "YYYY-MM-DD".
     */
    IEmployee(std::string id, std::string n, std::string addr, std::string p,
        std::string expiryDateString = "");

    /**
     * @brief Destructor ảo mặc định.
     * Đảm bảo giải phóng bộ nhớ đúng khi làm việc với các đối tượng dẫn xuất thông qua con trỏ lớp cơ sở.
     */
    virtual ~IEmployee() = default;
    
    /**
     * @brief Lấy loại nhân viên cụ thể.
     *
     * Đây là phương thức thuần ảo, phải được cài đặt bởi các lớp kế thừa
     * để trả về chuỗi mô tả loại nhân viên đó (ví dụ: "Intern", "Official Employee",...).
     *
     * @return Chuỗi đại diện cho loại nhân viên.
     */
    virtual std::string getEmployeeType() const = 0;

    /**
     * @brief Lấy ID nhân viên.
     * @return Chuỗi ID nhân viên.
     */
    const std::string& getEmployeeId() const;

    /**
     * @brief Lấy tên nhân viên.
     * @return Chuỗi tên nhân viên.
     */
    const std::string& getName() const;

    /**
     * @brief Lấy địa chỉ nhân viên.
     * @return Chuỗi địa chỉ nhân viên.
     */
    const std::string& getAddress() const;

    /**
     * @brief Lấy SĐT nhân viên.
     * @return Chuỗi SĐT nhân viên.
     */
    const std::string& getPhone() const;

    /**
     * @brief Tính toán lương của nhân viên.
     *
     * Đây là phương thức thuần ảo, phải được cài đặt bởi các lớp kế thừa.
     * Nó sẽ sử dụng thông tin chấm công và các khoản phúc lợi/trừ lương
     * để tính toán tổng lương ròng.
     *
     * @param attendance Đối tượng Attendance chứa thông tin chấm công.
     * @param bonuses Tổng các khoản thưởng.
     * @param allowances Tổng các khoản phụ cấp.
     * @param deductions Tổng các khoản khấu trừ (ví dụ: bảo hiểm).
     * @return double Giá trị lương ròng của nhân viên.
     */
    virtual double calculateSalary(const Attendance& attendance, double bonuses, double allowances, double deductions) const = 0;

    /**
     * @brief Lấy lương cơ bản (trước khi tính phúc lợi/trừ lương) của nhân viên.
     * Đây là phương thức thuần ảo, phải được cài đặt bởi các lớp kế thừa.
     * @return double Giá trị lương cơ bản của nhân viên.
     */
    virtual double getBaseSalary() const = 0;

    /**
     * @brief Lấy số tháng nhân viên đã làm việc.
     * Được sử dụng để tính toán tự động tăng lương theo yêu cầu thâm niên.
     * @return int Số tháng đã làm việc.
     */
    virtual int getMonthsWorked() const { return 0; } // Mặc định là 0.
};

#endif