/**
 * @file fulltimeEmployee.h
 * @brief Khai báo lớp FulltimeEmployee kế thừa từ IEmployee.
 * @details Định nghĩa cấu trúc và giao diện cho đối tượng Nhân viên Chính thức.
 * Lớp này cụ thể hóa các phương thức trừu tượng từ IEmployee
 * phù hợp với đặc thù của nhân viên chính thức.
 */

 #ifndef _FULLTIMEEMPLOYEE_H_
 #define _FULLTIMEEMPLOYEE_H_
 
 #include "IEmployee.h"
#include "Salary.h" // Cần để tính lương
#include "Attendance.h" // Cần để truyền vào calculateSalary
 
 class FulltimeEmployee : public IEmployee
 {
 private:
     int _baseSalary; ///< Tiền lương gốc của nhân viên chính thức.
     double _hourlyRate = 50; // Ví dụ: 50,000 VND/giờ
     double _overtimeRate = 75; // Ví dụ: 75,000 VND/giờ tăng ca
     double _holidayRate = 100; // Ví dụ: 100,000 VND/giờ làm ngày lễ
     int _monthsWorked; ///< Số tháng đã làm việc.
 public:
 public:
     /**
      * @brief Constructor cho lớp FulltimeEmployee.
      *
      * Khởi tạo một đối tượng Nhân viên Chính thức với các thông tin cơ bản.
      * Constructor này gọi constructor của lớp cơ sở IEmployee để khởi tạo
      * các thuộc tính chung.
      *
      * @param id ID duy nhất của nhân viên chính thức.
      * @param n Tên đầy đủ của nhân viên chính thức.
      * @param addr Địa chỉ liên lạc.
      * @param p Số điện thoại liên lạc.
      * @param monthsWorked Số tháng đã làm việc (để tính thưởng thâm niên, v.v.).
      * @param baseSalary Lương cơ bản của nhân viên chính thức.
      */
     FulltimeEmployee(std::string id, std::string n, std::string addr, std::string p,
         int monthsWorked, double baseSalary);

     /**
      * @brief Lấy loại nhân viên là "Nhân viên Chính thức".
      *
      * Đây là cài đặt cụ thể của phương thức thuần ảo getEmployeeType()
      * từ lớp cơ sở IEmployee cho loại nhân viên Chính thức.
      *
      * @return Chuỗi "Nhân viên Chính thức".
      * @override
      */
     std::string getEmployeeType() const override;

     /**
      * @brief Tính toán tổng lương của nhân viên Chính thức.
      *
      * Triển khai phương thức thuần ảo calculateSalary() từ IEmployee.
      * Sử dụng SalaryCalculator để tính toán dựa trên chấm công và các khoản phúc lợi/khấu trừ.
      *
      * @param attendance Đối tượng Attendance chứa thông tin chấm công.
      * @param bonuses Tổng các khoản thưởng.
      * @param allowances Tổng các khoản phụ cấp.
      * @param deductions Tổng các khoản khấu trừ.
      * @return double Giá trị lương ròng của nhân viên Chính thức.
      * @override
      */
     double calculateSalary(const Attendance& attendance, double bonuses, double allowances, double deductions) const override;

     /**
      * @brief Lấy lương cơ bản của nhân viên Chính thức.
      * Triển khai phương thức thuần ảo getBaseSalary() từ IEmployee.
      * @return double Giá trị lương cơ bản của nhân viên Chính thức.
      * @override
      */
     double getBaseSalary() const override { return _baseSalary; }

     /**
      * @brief Lấy số tháng nhân viên đã làm việc.
      * @return int Số tháng đã làm việc.
      * @override
      */
     int getMonthsWorked() const override { return _monthsWorked; }
 };
 
 #endif