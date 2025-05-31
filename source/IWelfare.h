/**
 * @file IWelfare.h
 * @brief Định nghĩa các giao diện và cấu trúc dữ liệu liên quan đến phúc lợi nhân viên.
 *
 * File này chứa định nghĩa cho các loại phúc lợi khác nhau mà nhân viên có thể được hưởng.
 * Các phúc lợi này có thể có tác động trực tiếp hoặc gián tiếp đến việc tính toán lương.
 * Thiết kế hướng đến tính mở rộng (Open/Closed Principle) và dễ dàng tích hợp với
 * hệ thống tính lương (Dependency Inversion Principle).
 */

#ifndef _IWELFARE_H_
#define _IWELFARE_H_

#include <string>
#include <vector>
#include <memory> // Dùng cho con trỏ thông minh (smart pointers)
#include <stdexcept> // Dùng cho xử lý ngoại lệ
#include "globalDefinitions.h"
#include "AttendanceManager.h"

 // Khai báo chuyển tiếp (Forward declaration) để tránh include vòng lặp
 // Cần thiết vì IWelfare có thể cần thông tin từ IEmployee để tính toán phúc lợi
class IEmployee;

/**
 * @struct WelfareDetails
 * @brief Cấu trúc chứa thông tin mô tả chi tiết về một loại phúc lợi.
 *
 * Cấu trúc này lưu trữ các thông tin chung như loại, tên, và mô tả của phúc lợi,
 * độc lập với logic tính toán tác động cụ thể của nó.
 */
struct WelfareDetails
{
    WelfareType type;       ///< Loại phúc lợi.
    std::string name;       ///< Tên của phúc lợi.
    std::string description;///< Mô tả chi tiết về phúc lợi.
};

/**
 * @class IWelfare
 * @brief Lớp trừu tượng cơ sở (Interface) cho tất cả các loại phúc lợi.
 *
 * Lớp này định nghĩa một hợp đồng chung mà mọi loại phúc lợi cụ thể phải cài đặt.
 * Nó bao gồm các phương thức để lấy thông tin chi tiết của phúc lợi,
 * tính toán tác động của phúc lợi đó lên lương nhân viên, và kiểm tra
 * xem nhân viên có đủ điều kiện nhận phúc lợi hay không cho một kỳ lương cụ thể.
 */
class IWelfare
{
public:
    /**
     * @brief Destructor ảo mặc định.
     * Đảm bảo rằng destructor của các lớp con được gọi đúng cách khi một đối tượng
     * phúc lợi cụ thể bị hủy thông qua con trỏ của lớp cơ sở IWelfare.
     * Điều này quan trọng để tránh rò rỉ bộ nhớ khi làm việc với đa hình.
     */
    virtual ~IWelfare() = default;

    /**
     * @brief Lấy thông tin chi tiết mô tả về phúc lợi.
     * Phương thức thuần ảo, các lớp con phải cài đặt.
     * @return Tham chiếu hằng đến đối tượng WelfareDetails chứa tên, loại, và mô tả của phúc lợi.
     */
    virtual const WelfareDetails& getDetails() const = 0;

    /**
     * @brief Tính toán tác động tài chính của phúc lợi này lên lương của một nhân viên cụ thể.
     * Phương thức thuần ảo, các lớp con phải cài đặt.
     * Giá trị trả về có thể dương (cộng vào lương, ví dụ: thưởng, phụ cấp)
     * hoặc âm (trừ vào lương, ví dụ: các khoản khấu trừ như bảo hiểm).
     * @param employee Tham chiếu hằng đến đối tượng IEmployee mà phúc lợi này đang được tính toán.
     * @return double Giá trị số biểu thị tác động của phúc lợi.
     */
    virtual double calculateImpact(const IEmployee& employee) const = 0; //

    /**
     * @brief Kiểm tra xem một nhân viên cụ thể có đủ điều kiện nhận phúc lợi này hay không
     * trong một kỳ lương (tháng/năm) nhất định.
     * Phương thức thuần ảo, các lớp con phải cài đặt logic kiểm tra điều kiện riêng.
     * @param employee Tham chiếu hằng đến đối tượng IEmployee cần kiểm tra.
     * @param attendanceManager Tham chiếu hằng đến đối tượng AttendanceManager để truy xuất dữ liệu chấm công (nếu cần).
     * @param month Tháng của kỳ lương cần kiểm tra điều kiện (1-12).
     * @param year Năm của kỳ lương cần kiểm tra điều kiện.
     * @return true nếu nhân viên đủ điều kiện, false nếu ngược lại.
     */
    virtual bool isEligible(const IEmployee& employee, const AttendanceManager& attendanceManager, int month, int year) const = 0; // Thêm month, year
};


#endif // _IWELFARE_H_
