#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H

#include "IEmployee.h"
#include "AttendanceManager.h"
#include "WelfareManager.h"
#include "PayrollPrinter.h"
#include <vector>
#include <memory>
#include <string>

/**
 * @file EmployeeManager.h
 * @brief Định nghĩa lớp EmployeeManager, chịu trách nhiệm quản lý các nghiệp vụ liên quan đến nhân viên.
 */

/**
 * @class EmployeeManager
 * @brief Lớp trung tâm quản lý danh sách nhân viên, phúc lợi, chấm công và tính lương.
 *
 * Lớp này điều phối các hoạt động như thêm, xóa, tìm kiếm nhân viên,
 * tính toán lương và phúc lợi, cũng như xuất báo cáo và phiếu lương.
 * Nó chứa các đối tượng quản lý chuyên biệt cho từng mảng nghiệp vụ.
 */
class EmployeeManager {
private:
    std::vector<std::shared_ptr<IEmployee>> _employeeList; ///< @brief Danh sách các đối tượng nhân viên (dùng con trỏ thông minh).
    AttendanceManager _attendanceManager;                   ///< @brief Đối tượng quản lý dữ liệu chấm công.
    WelfareManager _welfareManager;                         ///< @brief Đối tượng quản lý các loại phúc lợi.
    PayrollPrinter _payrollPrinter;                         ///< @brief Đối tượng dùng để in phiếu lương và các báo cáo.

public:
    /**
     * @brief Constructor của EmployeeManager.
     * Khởi tạo đối tượng PayrollPrinter và tự động thêm các phúc lợi mặc định
     * vào WelfareManager (ví dụ: BHXH, Thưởng, Phụ cấp đi lại).
     */
    EmployeeManager();

    // --- Quản lý Nhân viên (CRUD) ---
    /**
     * @brief Thêm một nhân viên mới vào danh sách quản lý.
     * Kiểm tra xem mã nhân viên đã tồn tại chưa trước khi thêm.
     * @param emp Con trỏ chia sẻ (shared_ptr) đến đối tượng nhân viên cần thêm.
     * @return true nếu thêm thành công, false nếu mã nhân viên đã tồn tại hoặc con trỏ emp là null.
     */
    bool addEmployee(std::shared_ptr<IEmployee> emp);

    /**
     * @brief Xóa một nhân viên khỏi danh sách dựa trên Mã Nhân Viên.
     * @param empId Mã của nhân viên cần xóa.
     * @return true nếu xóa thành công, false nếu không tìm thấy nhân viên với mã đó.
     */
    bool deleteEmployee(const std::string& empId);

    /**
     * @brief Tìm kiếm một nhân viên trong danh sách dựa trên Mã Nhân Viên.
     * @param empId Mã của nhân viên cần tìm.
     * @return Con trỏ chia sẻ (shared_ptr) đến đối tượng nhân viên nếu tìm thấy, ngược lại trả về nullptr.
     */
    std::shared_ptr<IEmployee> findEmployeeById(const std::string& empId) const;

    /**
     * @brief Hiển thị danh sách tóm tắt của tất cả nhân viên ra console.
     * Danh sách được hiển thị trong một khung với các cột MaNV, HoTen, Email, LoaiNV.
     * Có hỗ trợ phân trang nếu danh sách quá dài.
     * @param frameX Tọa độ X của góc trên trái của khung hiển thị.
     * @param frameY Tọa độ Y của góc trên trái của khung hiển thị.
     * @param frameWidth Chiều rộng tổng thể của khung hiển thị.
     * @param frameHeight Chiều cao tổng thể của khung hiển thị.
     */
    void displayAllEmployees(int frameX, int frameY, int frameWidth, int frameHeight) const;

    /**
     * @brief Hiển thị thông tin chi tiết của một nhân viên cụ thể ra console.
     * Hàm này sẽ chuẩn bị màn hình (xóa, vẽ khung, tiêu đề) và sau đó gọi PayrollPrinter.
     * @param empId Mã của nhân viên cần hiển thị chi tiết.
     * @note Phiên bản này tự quản lý màn hình. Nếu muốn App quản lý màn hình, cần sửa để nhận tham số khung.
     * Dựa trên thảo luận trước, phiên bản này sẽ tự clear và vẽ lại.
     * Tuy nhiên, để App quản lý khung cho màn hình "Nhập ID", hàm này cần được
     * gọi từ một handler của App, và handler đó sẽ chuẩn bị vùng content cho PayrollPrinter.
     * Mình sẽ comment theo hướng nó nhận tham số vùng content từ App.
     */
    void displayEmployeeDetails(const std::string& empId) const;

    /**
     * @brief Lấy một tham chiếu hằng đến danh sách nhân viên hiện tại.
     * @return const std::vector<std::shared_ptr<IEmployee>>& Danh sách nhân viên.
     */
    const std::vector<std::shared_ptr<IEmployee>>& getEmployees() const;

    /**
     * @brief Tải danh sách nhân viên từ file, thay thế danh sách hiện tại.
     * Xử lý lỗi đọc file và chuyển đổi dữ liệu.
     * @param filename Tên file chứa dữ liệu nhân viên (thường là "employee_list.txt").
     * @return true nếu tải thành công (có thể không có bản ghi nào được thêm nếu file lỗi), false nếu không mở được file.
     */
    bool loadFromFile(const std::string& filename);

    // --- Quản lý Chấm công ---
    /**
    * @brief Thêm một bản ghi chấm công thủ công.
    * @param record Bản ghi AttendanceRecord cần thêm.
    */
    void addAttendanceRecord(const AttendanceRecord& record);

    /**
    * @brief Tải dữ liệu chấm công từ file CSV.
    * @param filename Tên file CSV (ví dụ: "attendance.csv").
    */
    void loadAttendanceFromFile(const std::string& filename);


    // --- Tính toán & In Lương ---
    /**
     * @brief Tính toán và hiển thị phiếu lương của một nhân viên cụ thể ra console cho một kỳ lương.
     * Đồng thời xuất phiếu lương này ra một file TXT riêng.
     * Tự động tải dữ liệu chấm công mới nhất trước khi tính.
     * Tự quản lý việc xóa màn hình và vẽ giao diện cho phiếu lương.
     * @param empId Mã của nhân viên cần in phiếu lương.
     * @param month Tháng tính lương (1-12).
     * @param year Năm tính lương.
     */
    void printPayroll(const std::string& empId, int month, int year);

    /**
     * @brief Tính toán và xuất bảng lương tổng hợp của tất cả nhân viên ra file cho một kỳ lương.
     * Tự động tải dữ liệu chấm công mới nhất trước khi tính.
     * @param filename Tên file để xuất bảng lương (ví dụ: "payroll_export.txt").
     * @param month Tháng tính lương (1-12).
     * @param year Năm tính lương.
     */
    void printAllPayrolls(const std::string& filename, int month, int year); // Thêm month, year

};

#endif // EMPLOYEE_MANAGER_H