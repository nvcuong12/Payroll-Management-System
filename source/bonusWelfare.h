#ifndef _BONUS_WELFARE_H_
#define _BONUS_WELFARE_H_

#include "IWelfare.h" // Bao gồm định nghĩa của IWelfare
#include "IEmployee.h" // Bao gồm định nghĩa của IEmployee

/**
 * @file BonusWelfare.h
 * @brief Định nghĩa lớp BonusWelfare, một loại phúc lợi cụ thể liên quan đến thưởng.
 */

/**
 * @class BonusWelfare
 * @brief Lớp triển khai phúc lợi Thưởng cho nhân viên.
 *
 * Lớp này kế thừa từ IWelfare và cài đặt các phương thức để xác định điều kiện hưởng thưởng
 * và tính toán số tiền thưởng. Ví dụ, thưởng có thể dựa trên doanh thu hoặc
 * dựa trên việc nhân viên đáp ứng các tiêu chí chấm công nhất định.
 */
class BonusWelfare : public IWelfare
{
private:
    WelfareDetails details;         ///< @brief Thông tin chi tiết về phúc lợi Thưởng (tên, mô tả, loại).
    double revenueBonusAmount;      ///< @brief Số tiền thưởng cố định (ví dụ: thưởng doanh thu). Giá trị này được thiết lập khi khởi tạo.
public:
    /**
     * @brief Constructor cho lớp BonusWelfare.
     * Khởi tạo phúc lợi thưởng với một số tiền thưởng cố định.
     * @param revenueAmount Số tiền thưởng. Mặc định là 0.0.
     */
    BonusWelfare(double revenueAmount = 0.0);

    /**
     * @brief Lấy thông tin chi tiết (tên, mô tả, loại) của phúc lợi Thưởng.
     * @return Tham chiếu hằng đến đối tượng WelfareDetails.
     */
    const WelfareDetails& getDetails() const override;

    /**
     * @brief Tính toán giá trị tiền thưởng mà nhân viên sẽ nhận được.
     * Hiện tại, hàm này trả về giá trị `revenueBonusAmount` đã được thiết lập.
     * @param employee Tham chiếu hằng đến đối tượng IEmployee. (Hiện tại không được sử dụng trong logic tính toán này).
     * @return Số tiền thưởng.
     */
    double calculateImpact(const IEmployee& employee) const override;

    /**
     * @brief Kiểm tra xem nhân viên có đủ điều kiện nhận thưởng hay không cho một kỳ lương cụ thể.
     * Điều kiện hiện tại là nhân viên phải có ít nhất một ngày làm việc thuộc mỗi loại:
     * "normal" (ngày thường), "overtime" (tăng ca), và "holiday" (ngày lễ)
     * trong tháng và năm được chỉ định.
     * @param employee Tham chiếu hằng đến đối tượng IEmployee cần kiểm tra.
     * @param attendanceManager Tham chiếu hằng đến đối tượng AttendanceManager để truy xuất dữ liệu chấm công.
     * @param targetMonth Tháng cần kiểm tra điều kiện (1-12).
     * @param targetYear Năm cần kiểm tra điều kiện.
     * @return true nếu nhân viên đủ điều kiện nhận thưởng, false nếu ngược lại.
     */
    bool isEligible(const IEmployee& employee, const AttendanceManager& attendanceManager, int targetMonth, int targetYear) const override;
};

#endif // _BONUS_WELFARE_H_