#ifndef PAYROLL_PRINTER_H
#define PAYROLL_PRINTER_H

#include "GlobalDefinitions.h"
#include "NumberFormatter.h"
#include "IEmployee.h"
#include <vector>
#include <string>
#include <memory>
#include "utils.h"

/**
 * @file PayrollPrinter.h
 * @brief Định nghĩa lớp PayrollPrinter, chuyên dụng để hiển thị và xuất thông tin lương.
 */

/**
 * @class PayrollPrinter
 * @brief Lớp chịu trách nhiệm định dạng và hiển thị thông tin chi tiết của nhân viên,
 * phiếu lương cá nhân (ra console và file), và bảng lương tổng hợp (ra file).
 * Sử dụng NumberFormatter và CultureInfo để định dạng các giá trị tiền tệ.
 */
class PayrollPrinter {
private:
    NumberFormatter _formatter; ///< @brief Đối tượng dùng để định dạng số (ví dụ: thêm dấu phân cách hàng nghìn).
    CultureInfo _culture;       ///< @brief Thông tin văn hóa (ví dụ: "vi-VN") để định dạng số cho phù hợp.

public:
    /**
     * @brief Constructor cho PayrollPrinter.
     * Khởi tạo đối tượng NumberFormatter và CultureInfo dựa trên locale được cung cấp.
     * @param locale Chuỗi định danh văn hóa, ví dụ "vi-VN" (mặc định) hoặc "en-US".
     */
    PayrollPrinter(const std::string& locale = "vi-VN");

    /**
     * @brief In thông tin chi tiết cơ bản của một nhân viên ra console.
     * Hàm này sẽ vẽ nội dung vào vùng được chỉ định bởi contentX, contentY, contentWidth.
     * @param emp Con trỏ chia sẻ (shared_ptr) đến đối tượng nhân viên cần hiển thị.
     * @param contentX Tọa độ X bắt đầu của vùng nội dung để in chi tiết.
     * @param contentY Tọa độ Y bắt đầu của vùng nội dung để in chi tiết.
     * @param contentWidth Chiều rộng tối đa của vùng nội dung.
     */
    void printEmployeeDetails(const std::shared_ptr<IEmployee>& emp, int contentX, int contentY, int contentWidth) const;

    /**
     * @brief In phiếu lương chi tiết của một nhân viên ra màn hình console.
     * Phiếu lương được vẽ trên một màn hình đã được chuẩn bị (thường là bởi EmployeeManager::printPayroll),
     * bắt đầu từ các tọa độ nội bộ cố định (ví dụ: dòng 5 hoặc 6).
     * @param emp Con trỏ chia sẻ (shared_ptr) đến đối tượng nhân viên.
     * @param details Đối tượng SalaryDetails chứa thông tin lương chi tiết đã được tính toán.
     */
    void printPaySlip(const std::shared_ptr<IEmployee>& emp, const SalaryDetails& details) const;

    /**
     * @brief Ghi nội dung phiếu lương chi tiết của một nhân viên ra file văn bản (TXT).
     * Định dạng file tương tự như hiển thị ra console nhưng không dùng gotoXY.
     * @param emp Con trỏ chia sẻ (shared_ptr) đến đối tượng nhân viên.
     * @param details Đối tượng SalaryDetails chứa thông tin lương chi tiết.
     * @param filename Tên file (bao gồm đường dẫn nếu cần) để ghi phiếu lương.
     */
    void printPaySlipToFile(const std::shared_ptr<IEmployee>& emp, const SalaryDetails& details, const std::string& filename) const;

    /**
     * @brief In bảng lương tổng hợp của tất cả nhân viên trong danh sách payrollData ra một file văn bản.
     * File được định dạng bảng với các cột thông tin chính.
     * @param payrollData Vector chứa các cặp (con trỏ nhân viên, chi tiết lương của nhân viên đó).
     * @param filename Tên file để xuất bảng lương tổng hợp (ví dụ: "payroll_export.txt").
     */
    void printToFile(const std::vector<std::pair<std::shared_ptr<IEmployee>, SalaryDetails>>& payrollData, const std::string& filename) const;
};

#endif // PAYROLL_PRINTER_H