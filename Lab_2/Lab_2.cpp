#include "Header.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	std::string formula;
	std::cout << "Введите формулу: ";
	std::getline(std::cin, formula);
	logic_formula lf(formula);
	std::cout << '\n';
	lf.print_table();
	std::cout << "\n\nСДНФ: ";
	lf.print_SDNF();
	std::cout << "\nСКНФ: ";
	lf.print_SKNF();
	std::cout << "\n\nБинарная форма СДНФ: ";
	lf.print_numeric_binary_sdnf();
	std::cout << "\nБинарная форма СКНФ: ";
	lf.print_numeric_binary_sknf();
	std::cout << "\n\nДесятичная форма СДНФ: ";
	lf.print_numeric_decimal_sdnf();
	std::cout << "\nДесятичная форма СКНФ: ";
	lf.print_numeric_decimal_sknf();
	std::cout << "\n\nИндексная форма: ";
	lf.print_index();
	std::cout << "\n\n";
	system("pause");
	return 0;
}