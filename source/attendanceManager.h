#ifndef ATTENDANCE_MANAGER_H
#define ATTENDANCE_MANAGER_H

#include "globaldefinitions.h" // Đảm bảo đường dẫn này đúng
#include <string>
#include <vector>

/**
 * @file AttendanceManager.h
 * @brief Định nghĩa lớp AttendanceManager để quản lý dữ liệu chấm công.
 */

/**
 * @class AttendanceManager
 * @brief Lớp quản lý danh sách các bản ghi chấm công của nhân viên.
 *
 * Lớp này chịu trách nhiệm lưu trữ, tải từ file, và cung cấp các phương thức
 * để truy vấn thông tin chấm công như tổng giờ làm, giờ tăng ca, ngày lễ, v.v.
 * Nó làm việc với cấu trúc `AttendanceRecord` bao gồm cả `dayType`.
 */
class AttendanceManager {
private:
    std::vector<AttendanceRecord> _records;
    static std::vector<std::string> _holidays; // Danh sách ngày lễ cố định

public:
    /**
     * @brief Constructor mặc định.
     * Khởi tạo một đối tượng AttendanceManager rỗng.
     */
    AttendanceManager() = default;

    /**
     * @brief Chuyển đổi chuỗi thời gian "HH:MM:SS" thành tổng số giây kể từ đầu ngày.
     * @param timeStr Chuỗi thời gian cần chuyển đổi.
     * @return Tổng số giây. Trả về 0 nếu chuỗi không hợp lệ hoặc rỗng.
     */
    static int timeToSeconds(const std::string& timeStr);

    /**
     * @brief Thêm một bản ghi chấm công mới vào danh sách.
     * @param record Tham chiếu hằng đến đối tượng AttendanceRecord cần thêm.
     */
    void addRecord(const AttendanceRecord& record);

    /**
     * @brief Lấy danh sách tất cả các bản ghi chấm công hiện có.
     * @return Tham chiếu hằng đến vector chứa các AttendanceRecord.
     */
    const std::vector<AttendanceRecord>& getRecords() const;

    /**
     * @brief Tải dữ liệu chấm công từ một file CSV.
     * Xóa dữ liệu cũ trước khi tải. Bỏ qua dòng tiêu đề và các dòng trống.
     * Mong đợi file CSV có các cột: EmployeeID,WorkDate,CheckInTime,CheckOutTime,DayType.
     * `WorkDate` nên ở định dạng "YYYY-MM-DD".
     * @param filename Tên của file CSV chứa dữ liệu chấm công.
     * @return true nếu tải thành công, false nếu có lỗi (ví dụ: không mở được file).
     * @note Hàm này hiện tại trả về void trong file bạn cung cấp, nên sửa để trả về bool.
     */
    void loadFromFile(const std::string& filename);

    /**
     * @brief Kiểm tra xem một ngày (đã cho dưới dạng chuỗi "YYYY-MM-DD") có phải là ngày lễ cố định không.
     * So sánh phần "MM-DD" của ngày với danh sách các ngày lễ đã được định nghĩa.
     * @param date Chuỗi ngày cần kiểm tra, định dạng "YYYY-MM-DD".
     * @return true nếu là ngày lễ, false nếu không phải.
     */
    bool isHoliday(const std::string& date) const;

    // --- CÁC HÀM LẤY DỮ LIỆU CHẤM CÔNG TỔNG HỢP ---
    // Các hàm này tính toán dựa trên toàn bộ dữ liệu chấm công đã tải.
    // Nếu cần tính theo kỳ lương cụ thể, cần truyền thêm month/year và lọc bên trong.

    /**
     * @brief Lấy tổng số giờ làm việc bình thường của một nhân viên.
     * Chỉ tính các bản ghi có `dayType == "normal"`.
     * @param employeeId Mã nhân viên cần truy vấn.
     * @return Tổng số giờ làm việc bình thường (đã làm tròn xuống).
     */
    int getTotalWorkHours(const std::string& employeeId) const;

    /**
     * @brief Lấy tổng số giờ tăng ca của một nhân viên.
     * Chỉ tính các bản ghi có `dayType == "overtime"`.
     * @param employeeId Mã nhân viên cần truy vấn.
     * @return Tổng số giờ tăng ca (đã làm tròn xuống).
     */
    int getOvertimeHours(const std::string& employeeId) const;

    /**
     * @brief Lấy số ngày làm việc trong ngày lễ của một nhân viên.
     * Đếm số bản ghi có `dayType == "holiday"`.
     * @param employeeId Mã nhân viên cần truy vấn.
     * @return Số ngày làm việc trong ngày lễ.
     */
    int getHolidayWorkDays(const std::string& employeeId) const;

    /**
     * @brief Lấy số ngày nghỉ không lương của một nhân viên.
     * Đếm số bản ghi có `dayType == "leave_unpaid"`.
     * @param employeeId Mã nhân viên cần truy vấn.
     * @return Số ngày nghỉ không lương.
     */
    int getLeaveUnpaidDays(const std::string& employeeId) const;

    /**
     * @brief Lấy số ngày nghỉ phép có lương của một nhân viên.
     * Đếm số bản ghi có `dayType == "leave"`.
     * @param employeeId Mã nhân viên cần truy vấn.
     * @return Số ngày nghỉ phép có lương.
     */
    int getLeavePaidDays(const std::string& employeeId) const; // Thêm hàm này nếu cần
};

#endif // ATTENDANCE_MANAGER_H