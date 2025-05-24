#include "PayrollPrinter.h"
#include <fstream>
#include <iomanip>
#include <sstream>

PayrollPrinter::PayrollPrinter(const std::string& loc) : locale(loc) {}

void PayrollPrinter::printToFile(const std::vector<PaySlip>& slips,
    const std::unordered_map<std::string, double>& advances,
    const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) return;

    CultureInfo culture = CultureInfo::get(locale);

    out << "---------------------------------------------------------------------------------------------\n";
    out << "------------------------------------PHIẾU LƯƠNG NHÂN VIÊN------------------------------------\n";
    out << std::left << std::setw(15) << "Mã nhân viên"
        << std::setw(15) << "Số giờ làm"
        << std::setw(20) << "Lương 1 giờ làm"
        << std::setw(20) << "Lương theo giờ"
        << std::setw(20) << "Lương ứng trước"
        << std::setw(20) << "Thành lương" << "\n";
    out << "---------------------------------------------------------------------------------------------\n";

    for (const auto& slip : slips) {
        double baseSalary = slip.totalSalary;
        double advance = 0.0;
        auto it = advances.find(slip.employeeId);
        if (it != advances.end()) advance = it->second;
        double netSalary = baseSalary - advance;

        out << std::left << std::setw(15) << slip.employeeId
			<< std::setw(15) << slip.hoursWorked
            << std::setw(20) << formatter.format(slip.hourlyRate, culture)
            << std::setw(20) << formatter.format(baseSalary, culture)
            << std::setw(20) << formatter.format(advance, culture)
            << std::setw(20) << formatter.format(netSalary, culture) << "\n";
    }

    out.close();
}
