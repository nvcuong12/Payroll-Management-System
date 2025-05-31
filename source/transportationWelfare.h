#ifndef _TRANSPORTATION_WELFARE_H_
#define _TRANSPORTATION_WELFARE_H_

#include "IWelfare.h" // Bao gồm định nghĩa của IWelfare
#include "IEmployee.h" // Bao gồm định nghĩa của IEmployee
#include <map>

/**
 * @file TransportationWelfare.h
 * @brief Định nghĩa lớp TransportationWelfare, một loại phúc lợi cụ thể liên quan đến Phụ cấp đi lại.
 */

/**
 * @class TransportationWelfare
 * @brief Lớp triển khai phúc lợi Phụ cấp đi lại cho nhân viên.
 *
 * Lớp này kế thừa từ IWelfare và cài đặt các phương thức để xác định điều kiện hưởng
 * và tính toán số tiền phụ cấp đi lại. Số tiền phụ cấp dựa trên khoảng cách từ
 * địa chỉ của nhân viên đến công ty (giả định là TP. Thủ Đức) và một mức giá (`ratePerKm`)
 * được thiết lập khi khởi tạo đối tượng.
 */
class TransportationWelfare : public IWelfare
{
private:
    WelfareDetails details; ///< Thông tin chi tiết về phúc lợi Phụ cấp đi lại.
    double ratePerKm = 4000;       ///< Số tiền phụ cấp cho mỗi km di chuyển (được lấy theo thời giá, tại 18/05: 4000đ/km)
    std::map<std::string, double> distancesToThuDuc; // Khoảng cách từ các khu vực đến TP. Thủ Đức

public:
    /**
     * @brief Constructor cho lớp TransportationWelfare.
     * Khởi tạo phúc lợi phụ cấp đi lại với một mức giá trên mỗi km và thiết lập
     * danh sách khoảng cách từ các địa điểm đến công ty.
     * @param rate Số tiền phụ cấp trên mỗi km (ví dụ: 4000 VND/km).
     */
    TransportationWelfare(double rate);

    /**
     * @brief Lấy thông tin chi tiết (tên, mô tả, loại) của phúc lợi Phụ cấp đi lại.
     * @return Tham chiếu hằng đến đối tượng WelfareDetails.
     */
    const WelfareDetails& getDetails() const override;

    /**
     * @brief Tính toán tác động của Phụ cấp đi lại đến lương của nhân viên.
     *
     * Tác động này thường là khoản cộng thêm vào lương, được tính bằng
     * số km di chuyển nhân với tỷ lệ phụ cấp trên mỗi km.
     * * Yêu cầu đối tượng IEmployee cung cấp thông tin về khoảng cách di chuyển từ nhà đến công ty.
     *
     * @param employee Tham chiếu hằng đến đối tượng IEmployee.
     * @return Giá trị tác động lên lương (thường là số dương).
     */
    double calculateImpact(const IEmployee& employee) const override;

    /**
     * @brief Kiểm tra xem nhân viên có đủ điều kiện nhận Phụ cấp đi lại hay không.
     *
     * @param employee Tham chiếu hằng đến đối tượng IEmployee.
     * @return true nếu nhân viên đủ điều kiện, false ngược lại.
     */
    bool isEligible(const IEmployee& employee, const AttendanceManager& attendanceManager, int month, int year) const override;
};

#endif // _TRANSPORTATION_WELFARE_H_