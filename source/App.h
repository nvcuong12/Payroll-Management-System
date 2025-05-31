#ifndef APP_H
#define APP_H

#include "EmployeeManager.h"

/**
 * @file App.h
 * @brief Định nghĩa lớp App, lớp chính điều khiển toàn bộ ứng dụng quản lý lương.
 */

/**
 * @class App
 * @brief Lớp ứng dụng chính, điều khiển toàn bộ luồng chạy của chương trình.
 *
 * Lớp này khởi tạo các đối tượng quản lý cần thiết (như EmployeeManager),
 * xử lý vòng lặp chính của ứng dụng, và điều hướng các tương tác của người dùng 
 * thông qua một giao diện dòng lệnh (CLI) đơn giản.
 */
class App {
private:
    EmployeeManager _empManager; ///< @brief Đối tượng quản lý danh sách nhân viên và các nghiệp vụ liên quan.

    /// --- Các phương thức private để xử lý từng chức năng của menu ---
    /**
     * @brief Hiển thị menu chính các lựa chọn cho người dùng.
     * Menu bao gồm các chức năng như thêm, xóa, hiển thị nhân viên, tính lương, v.v.
     */
    void showMenu() const;

    /**
     * @brief Khởi tạo dữ liệu ban đầu cho ứng dụng.
     * Hiện tại, hàm này tải danh sách nhân viên từ file "employee_list.txt".
     * Trước đó, nó có thể đã được dùng để tạo một số nhân viên mẫu.
     */
    void seedData();

    /**
     * @brief Xử lý màn hình và logic đăng nhập của người dùng.
     * Yêu cầu nhập username và password. Thực hiện xác thực cơ bản.
     * @return true nếu đăng nhập thành công, false nếu thất bại sau một số lần thử nhất định.
     */
    bool handleLogin();

    /**
     * @brief Xử lý logic và giao diện cho việc thêm một nhân viên mới.
     * Hiển thị form nhập liệu trong một khung được căn chỉnh. Yêu cầu người dùng nhập thông tin chi tiết,
     * có kiểm tra tính hợp lệ cho một số trường và cho phép nhập lại.
     * @param contentX Tọa độ X bắt đầu của vùng nội dung bên trong khung.
     * @param contentY Tọa độ Y bắt đầu của vùng nội dung bên trong khung.
     * @param contentWidth Chiều rộng của vùng nội dung.
     * @param messageDisplayY Dòng Y cố định để hiển thị thông báo kết quả cuối cùng.
     */
    void handleAddEmployee(int contentX, int contentY, int contentWidth, int contentFrameY2);

    /**
     * @brief Xử lý logic và giao diện cho việc sửa thông tin một nhân viên.
     * Yêu cầu nhập Mã NV cần sửa. Nếu tìm thấy, hiển thị thông tin hiện tại và menu các trường có thể sửa.
     * Cho phép sửa nhiều trường, có kiểm tra tính hợp lệ và yêu cầu nhập lại.
     * @param contentX Tọa độ X bắt đầu của vùng nội dung bên trong khung.
     * @param contentY Tọa độ Y bắt đầu của vùng nội dung bên trong khung.
     * @param contentWidth Chiều rộng của vùng nội dung.
     * @param messageDisplayY Dòng Y cố định để hiển thị thông báo kết quả cuối cùng.
     */
    void handleEditEmployee(int contentX, int contentY, int contentWidth, int contentFrameY2);

    /**
     * @brief Xử lý logic và giao diện cho việc xóa một nhân viên.
     * Yêu cầu nhập Mã NV cần xóa. Nếu tìm thấy, hiển thị thông tin và yêu cầu xác nhận trước khi xóa.
     * @param contentX Tọa độ X bắt đầu của vùng nội dung bên trong khung.
     * @param contentY Tọa độ Y bắt đầu của vùng nội dung bên trong khung.
     * @param contentWidth Chiều rộng của vùng nội dung.
     * @param messageDisplayY Dòng Y cố định để hiển thị thông báo kết quả cuối cùng.
     */
    void handleDeleteEmployee(int contentX, int contentY, int contentWidth, int contentFrameY2);

    /**
     * @brief Xử lý logic và giao diện cho việc hiển thị thông tin chi tiết của một nhân viên.
     * Yêu cầu nhập Mã NV cần xem. Sau đó gọi EmployeeManager để hiển thị chi tiết.
     * @param contentX Tọa độ X bắt đầu của vùng nội dung bên trong khung (dùng cho lời nhắc nhập ID).
     * @param contentY Tọa độ Y bắt đầu của vùng nội dung bên trong khung.
     * @param contentWidth Chiều rộng của vùng nội dung.
     * @param messageDisplayY Dòng Y cố định để hiển thị thông báo (ví dụ: nếu không tìm thấy NV).
     */
    void handleShowEmployeeDetails(int contentX, int contentY, int contentWidth, int contentFrameY2);
    // displayAllEmployees sẽ được gọi thông qua _empManager, nên cần sửa EmployeeManager
    
    /**
     * @brief Tạo ID nhân viên mới dựa trên tiền tố và kiểm tra tính duy nhất.
     * @param prefix Tiền tố cho ID nhân viên mới (ví dụ: "FT", "IT", "CT").
     * @return Chuỗi ID nhân viên mới hợp lệ và duy nhất, hoặc chuỗi rỗng nếu không thể tạo.
     */
    std::string generateAndValidateNewEmployeeId(const std::string& prefix);


public:
    /**
     * @brief Constructor mặc định của lớp App.
     * Khởi tạo đối tượng EmployeeManager và gọi seedData() để tải dữ liệu ban đầu.
     */
    App();

    /**
     * @brief Phương thức chính để bắt đầu và chạy vòng lặp ứng dụng.
     * Xử lý màn hình đăng nhập, sau đó hiển thị menu, nhận lựa chọn từ người dùng,
     * chuẩn bị giao diện (khung, tiêu đề) và điều hướng đến các chức năng tương ứng.
     * Vòng lặp tiếp tục cho đến khi người dùng chọn thoát.
     */
    void run();

    /**
     * @brief Lưu trữ danh sách nhân viên hiện tại từ bộ nhớ ra file "employee_list.txt".
     * Ghi đè lên file cũ nếu đã tồn tại. File được ghi với dòng tiêu đề ở đầu.
     */
    void saveData();
};

#endif // APP_H