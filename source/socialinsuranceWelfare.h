#ifndef _SOCIAL_INSURANCE_WELFARE_H_
#define _SOCIAL_INSURANCE_WELFARE_H_

#include "IWelfare.h" // Bao gồm định nghĩa của IWelfare
#include "IEmployee.h" // Bao gồm định nghĩa của IEmployee

/**
 * @file SocialInsuranceWelfare.h
 * @brief Định nghĩa lớp SocialInsuranceWelfare, một loại phúc lợi cụ thể liên quan đến Bảo hiểm Xã hội.
 */

/**
 * @class SocialInsuranceWelfare
 * @brief Lớp triển khai phúc lợi Bảo hiểm Xã hội (BHXH) cho nhân viên.
 *
 * Lớp này kế thừa từ IWelfare và cài đặt các phương thức để xác định điều kiện tham gia BHXH
 * và tính toán số tiền khấu trừ BHXH từ lương của nhân viên dựa trên tỷ lệ đóng góp.
 */
class SocialInsuranceWelfare : public IWelfare
{
private:
    WelfareDetails details; ///< @brief Thông tin chi tiết về phúc lợi Bảo hiểm Xã hội (tên, mô tả, loại).
    double employeeContributionRate = 0.105; ///< @brief Tỷ lệ đóng góp BHXH của nhân viên (ví dụ: 0.105 cho 10.5%). Giá trị này được thiết lập khi khởi tạo.
 
public:
    /**
     * @brief Constructor cho lớp SocialInsuranceWelfare.
     * Khởi tạo phúc lợi BHXH với tỷ lệ đóng góp được chỉ định của nhân viên.
     * @param employeeRate Tỷ lệ đóng góp BHXH của nhân viên (dưới dạng số thập phân, ví dụ: 0.08 cho 8%).
     */
    SocialInsuranceWelfare(double employeeRate);

    /**
     * @brief Lấy thông tin chi tiết (tên, mô tả, loại) của phúc lợi Bảo hiểm xã hội.
     * @return Tham chiếu hằng đến đối tượng WelfareDetails.
     */
    const WelfareDetails& getDetails() const override;

    /**
     * @brief Tính toán giá trị tiền khấu trừ BHXH từ lương của nhân viên.
     * Tác động này thường là một khoản âm (biểu thị sự khấu trừ).
     * Số tiền khấu trừ được tính bằng Lương cơ bản của nhân viên nhân với tỷ lệ đóng góp.
     * @param employee Tham chiếu hằng đến đối tượng IEmployee để lấy thông tin lương cơ bản.
     * @return Số tiền khấu trừ BHXH (giá trị này sẽ là số âm).
     */
    double calculateImpact(const IEmployee& employee) const override;

    /**
     * @brief Kiểm tra xem nhân viên có đủ điều kiện tham gia/đóng BHXH hay không cho một kỳ lương cụ thể.
     * Điều kiện hiện tại là nhân viên phải có thâm niên làm việc từ một số tháng tối thiểu trở lên (ví dụ: 6 tháng).
     * @param employee Tham chiếu hằng đến đối tượng IEmployee cần kiểm tra.
     * @param attendanceManager Tham chiếu hằng đến đối tượng AttendanceManager (hiện không được sử dụng trong logic kiểm tra điều kiện này).
     * @param month Tháng của kỳ lương cần kiểm tra điều kiện (1-12) (hiện không được sử dụng trong logic này).
     * @param year Năm của kỳ lương cần kiểm tra điều kiện (hiện không được sử dụng trong logic này).
     * @return true nếu nhân viên đủ điều kiện, false nếu ngược lại.
     */
    bool isEligible(const IEmployee& employee, const AttendanceManager& attendanceManager, int month, int year) const override;
};

#endif // _SOCIAL_INSURANCE_WELFARE_H_