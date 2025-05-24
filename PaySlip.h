#pragma once
#ifndef PAYSLIP_H
#define PAYSLIP_H

#include <string>
#include <vector>
#include <unordered_map>
/**
* @struct PaySlip
* @brief Cấu trúc lưu trữ thông tin tính lương.
*
* Cấu trúc này chứa thông tin về mã nhân viên, giờ làm việc,
* lương theo giờ và tổng lương.
*/

struct PaySlip {
	std::string employeeId; ///< Mã nhân viên
	double hoursWorked;     ///< Số giờ làm việc
	double hourlyRate;      ///< Lương theo giờ (VND)
	double totalSalary;     ///< Tổng lương (VND)
};


#endif // !PAYSLIP_H

