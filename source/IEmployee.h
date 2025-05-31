#ifndef _IEMPLOYEE_H_
#define _IEMPLOYEE_H_

#include "GlobalDefinitions.h"
#include <string>
#include <memory>
#include <iostream>

// Khai báo chuyển tiếp để tránh include vòng lặp nếu AttendanceManager cần IEmployee
class AttendanceManager; // Khai báo chuyển tiếp

/**
 * @file IEmployee.h
 * @brief Định nghĩa giao diện cơ sở cho một đối tượng Nhân viên.
 *
 * Lớp này là lớp trừu tượng (abstract class) định nghĩa các thuộc tính 
 * và hành vi chung mà mọi loại nhân viên trong hệ thống phải có hoặc có thể có.
 * Nó đóng vai trò là hợp đồng cho các lớp nhân viên cụ thể.
 */
class IEmployee {
protected:
    std::string _employeeId;      ///< @brief ID duy nhất của nhân viên.
    std::string _name;            ///< @brief Tên đầy đủ của nhân viên.
    std::string _address;         ///< @brief Địa chỉ liên lạc của nhân viên.
    std::string _phone;           ///< @brief Số điện thoại của nhân viên.
    std::string _email;           ///< @brief Địa chỉ email của nhân viên.
    std::string _additionalInfo;  ///< @brief Thông tin bổ sung (ví dụ: kinh nghiệm, dự án, trường học).
    int _expDay = 0;              ///< @brief Ngày hết hạn hợp đồng.
    int _expMonth = 0;            ///< @brief Tháng hết hạn hợp đồng.
    int _expYear = 0;             ///< @brief Năm hết hạn hợp đồng.

    std::string _logicalEmployeeType; ///< @brief Chuỗi mô tả loại nhân viên logic (ví dụ: "Full-time Employee", "Intern", "Contractual Employee").
public:
    /**
     * @brief Constructor cho lớp IEmployee.
     * @param id Mã ID duy nhất của nhân viên.
     * @param name Tên đầy đủ của nhân viên.
     * @param addr Địa chỉ của nhân viên.
     * @param phone Số điện thoại của nhân viên.
     * @param email Địa chỉ email của nhân viên.
     * @param info Thông tin bổ sung cụ thể cho loại nhân viên.
     * @param expiryDate Chuỗi ngày hết hạn hợp đồng, định dạng "YYYY-MM-DD". Có thể là "0-0-0" hoặc "N/A" nếu không áp dụng.
     * @param logicalType Chuỗi mô tả loại nhân viên, ví dụ: "Full-time Employee", "Intern".
     */
    IEmployee(std::string id, std::string name, std::string addr, std::string phone,
        std::string email, std::string info, std::string expiryDate, std::string logicalType);

    /**
     * @brief Destructor ảo.
     * Đảm bảo rằng destructor của lớp con được gọi đúng cách khi đối tượng bị hủy thông qua con trỏ lớp cha.
     */
    virtual ~IEmployee() = default;

    // --- CÁC PHƯƠNG THỨC GETTER ---

    /**
     * @brief Lấy Mã Nhân Viên.
     * @return Chuỗi hằng tham chiếu đến mã nhân viên.
     */
    const std::string& getEmployeeId() const;

    /**
     * @brief Lấy Loại Nhân Viên (dưới dạng chuỗi logic).
     * @return Chuỗi mô tả loại nhân viên (ví dụ: "Full-time Employee").
     */
    virtual std::string getEmployeeType() const;

    /**
     * @brief Lấy Tên Nhân Viên.
     * @return Chuỗi hằng tham chiếu đến tên nhân viên.
     */
    const std::string& getName() const;

    /**
     * @brief Lấy Địa Chỉ Nhân Viên.
     * @return Chuỗi hằng tham chiếu đến địa chỉ.
     */
    const std::string& getAddress() const;

    /**
     * @brief Lấy Số Điện Thoại Nhân Viên.
     * @return Chuỗi hằng tham chiếu đến số điện thoại.
     */
    const std::string& getPhone() const;

    /**
     * @brief Lấy Email Nhân Viên.
     * @return Chuỗi hằng tham chiếu đến email.
     */
    const std::string& getEmail() const;

    /**
     * @brief Lấy Thông Tin Bổ Sung của nhân viên.
     * Ý nghĩa của thông tin này có thể khác nhau tùy loại nhân viên (ví dụ: kinh nghiệm, tên trường, dự án).
     * @return Chuỗi hằng tham chiếu đến thông tin bổ sung.
     */
    const std::string& getAdditionInfo() const;

    /**
     * @brief Lấy ngày hết hạn hợp đồng.
     * @return Số nguyên biểu thị ngày.
     */
    int getExpDay() const;

    /**
     * @brief Lấy tháng hết hạn hợp đồng.
     * @return Số nguyên biểu thị tháng.
     */
    int getExpMonth() const;

    /**
     * @brief Lấy năm hết hạn hợp đồng.
     * @return Số nguyên biểu thị năm.
     */
    int getExpYear() const;

    /**
     * @brief Lấy ngày hết hạn hợp đồng dưới dạng chuỗi định dạng "YYYY-MM-DD".
     * @return Chuỗi ngày tháng đã định dạng. Trả về "N/A" nếu không có ngày hợp lệ.
     */
    std::string getFormattedExpiryDate() const;

    /**
     * @brief Lấy số tháng đã làm việc/thâm niên.
     * Lớp cơ sở trả về 0. Các lớp con nên override nếu có lưu trữ thông tin này.
     * @return Số tháng làm việc.
     */

    /**
     * @brief Lấy số tháng đã làm việc/thâm niên.
     * Lớp cơ sở trả về 0. Các lớp con nên override nếu có lưu trữ thông tin này.
     * @return Số tháng làm việc.
     */
    virtual int getMonthsWorked() const { return 0; }



    // --- CÁC PHƯƠNG THỨC THUẦN ẢO (CÁC LỚP CON BẮT BUỘC PHẢI CÀI ĐẶT) ---

    /**
     * @brief Tính toán chi tiết lương cho nhân viên trong một kỳ lương cụ thể.
     * @param attendance Đối tượng quản lý chấm công, chứa dữ liệu chấm công cần thiết.
     * @param month Tháng cần tính lương (1-12).
     * @param year Năm cần tính lương.
     * @param bonuses Tổng tiền thưởng đã được tính từ WelfareManager.
     * @param allowances Tổng tiền phụ cấp đã được tính từ WelfareManager.
     * @param deductions Tổng tiền khấu trừ đã được tính từ WelfareManager.
     * @return Đối tượng SalaryDetails chứa các thành phần lương chi tiết.
     */
    virtual SalaryDetails calculateSalary(const AttendanceManager& attendance, int month, int year, double bonuses, double allowances, double deductions) const = 0; // Thêm month, year

    /**
     * @brief Lấy mức lương cơ bản/cố định của nhân viên.
     * Giá trị này thường được đọc từ file thông tin nhân viên.
     * @return Giá trị lương cơ bản.
     */
    virtual double getBaseSalary() const = 0;

    /**
     * @brief Chuyển đổi thông tin nhân viên thành một chuỗi định dạng CSV.
     * Hữu ích cho việc lưu trữ dữ liệu nhân viên ra file.
     * @return Chuỗi CSV biểu diễn thông tin nhân viên.
     */
    virtual std::string toCsvString() const = 0;

    /**
     * @brief Đặt (cập nhật) mức lương cơ bản/cố định cho nhân viên.
     * Được sử dụng khi loại nhân viên thay đổi và lương cơ bản cần được cập nhật theo.
     * @param salary Mức lương cơ bản mới.
     */
    virtual void setBaseSalary(double salary) = 0; // Pure virtual, lớp con phải cài đặt

    // --- CÁC PHƯƠNG THỨC SETTER ẢO (CÁC LỚP CON CÓ THỂ OVERRIDE) ---

    /** 
     * @brief Đặt tên mới cho nhân viên. 
     * @param name Tên mới. 
    */
    virtual void setName(const std::string& name) { _name = name; }

    /** 
     * @brief Đặt địa chỉ mới cho nhân viên. 
     * @param address Địa chỉ mới. 
    */
    virtual void setAddress(const std::string& address) { _address = address; }

    /** 
     * @brief Đặt số điện thoại mới cho nhân viên. 
     * @param phone Số điện thoại mới. 
    */
    virtual void setPhone(const std::string& phone) { _phone = phone; }

    /** 
     * @brief Đặt email mới cho nhân viên. 
     * @param email Email mới. 
    */
    virtual void setEmail(const std::string& email) { _email = email; }

    /** 
     * @brief Đặt thông tin bổ sung mới cho nhân viên.
     * @param info Thông tin bổ sung mới.
    */
    virtual void setAdditionalInfo(const std::string& info) { _additionalInfo = info; }

    /**
     * @brief Đặt ngày hết hạn hợp đồng từ một chuỗi.
     * Phân tích chuỗi đầu vào (mong đợi "YYYY-MM-DD") và cập nhật các thành phần _expYear, _expMonth, _expDay.
     * Nếu chuỗi không hợp lệ, các thành phần ngày sẽ được reset về 0.
     * @param expiryDateStr Chuỗi ngày hết hạn hợp đồng.
     */
    virtual void setExpiryDate(const std::string& expiryDateStr);

    /**
     * @brief Đặt số tháng làm việc/thâm niên cho nhân viên.
     * Lớp cơ sở có thể không làm gì hoặc ném lỗi. Các lớp con cụ thể sẽ override phương thức này.
     * @param months Số tháng làm việc mới.
     */
    virtual void setMonthsWorked(int months) { /* Lớp cơ sở không làm gì, hoặc throw lỗi */ }

    /** @brief Đặt mã nhân viên mới. @param id Mã nhân viên mới. */
    virtual void setEmployeeId(const std::string& id) { _employeeId = id; }

    /** @brief Đặt loại nhân viên logic mới. @param type Chuỗi mô tả loại nhân viên mới. */
    virtual void setLogicalEmployeeType(const std::string& type) { _logicalEmployeeType = type; }
};

#endif // _IEMPLOYEE_H_