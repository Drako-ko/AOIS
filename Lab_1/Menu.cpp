#include "Header.h"

void Menu::menu()
{
	int byte_quantity, first_decimal_number, second_decimal_number;
	double P1, P2;
	std::string first_binary_number, second_binary_number, str;
	long int first_binary_number_length, second_binary_number_length;
	std::cout << "Enter first number: \n";
	std::cin >> first_decimal_number;
	std::cout << "Enter second number: \n";
	std::cin >> second_decimal_number;
	first_binary_number_length = Binary_system::from_decimal_to_binary(first_decimal_number);
	second_binary_number_length = Binary_system::from_decimal_to_binary(second_decimal_number);
	if (first_binary_number_length > second_binary_number_length)
		byte_quantity = std::to_string(first_binary_number_length).length() + 1;
	else
		byte_quantity = std::to_string(second_binary_number_length).length() + 1;
	double f = (double)byte_quantity / 8.0;
	byte_quantity = ceil(f);
	// main menu
	while (1) {
		std::cout << "\n1 - sum and residual.\n2 - multiplication.\n3 - division.\n4 - sum with floating point numbers.\n5 - exit.\n";
		int a;
		std::cin >> a;
		if (a == 5)
			break;
		switch (a) {
		case 1:
			//menu of task 1
			while (1) {
				std::cout << "\n1 - straight code.\n2 - reverse code.\n3 - additional code.\n4 - back to menu.\n";
				std::cin >> a;
				if (a == 4)
					break;
				switch (a) {
					//прямой код
				case 1:
					first_binary_number = Binary_system::from_int_to_string(Binary_system::from_decimal_to_binary(first_decimal_number), byte_quantity);
					second_binary_number = Binary_system::from_int_to_string(Binary_system::from_decimal_to_binary(second_decimal_number), byte_quantity);
					std::cout << "\n+   +\n"
							  << first_binary_number << "\n"
							  << second_binary_number << "\n"
							  << Sum_and_residual::sum_with_straight_code(first_binary_number, second_binary_number, 1)
							  << "\n+   -\n";
					Binary_system::change_signed_number(second_binary_number);
					if (first_binary_number_length <= second_binary_number_length)
						std::cout << first_binary_number << "\n"
								  << second_binary_number << "\n"
								  << Sum_and_residual::residual_with_straight_code(first_binary_number, second_binary_number, 0, 0);
					else
						std::cout << first_binary_number << "\n"
								  << second_binary_number << "\n"
								  << Sum_and_residual::residual_with_straight_code(first_binary_number, second_binary_number, 1, 1);
					std::cout << "\n-   +\n";
					Binary_system::change_signed_number(first_binary_number);
					Binary_system::change_signed_number(second_binary_number);
					if (first_binary_number_length >= second_binary_number_length)
						std::cout << first_binary_number << "\n"
								  << second_binary_number << "\n"
								  << Sum_and_residual::residual_with_straight_code(first_binary_number, second_binary_number, 1, 1);
					else
						std::cout << first_binary_number << "\n"
								  << second_binary_number << "\n"
								  << Sum_and_residual::residual_with_straight_code(first_binary_number, second_binary_number, 1, 0);
					std::cout << "\n-   -\n";
					Binary_system::change_signed_number(first_binary_number);
					Binary_system::change_signed_number(second_binary_number);
					std::cout << first_binary_number << "\n"
							  << second_binary_number << "\n"
							  << Sum_and_residual::sum_with_straight_code(first_binary_number, second_binary_number, 0) << "\n\n";
					break;
					// обратный код
				case 2:
					first_binary_number = Binary_system::from_int_to_string(Binary_system::from_decimal_to_binary(first_decimal_number), byte_quantity);
					second_binary_number = Binary_system::from_int_to_string(Binary_system::from_decimal_to_binary(second_decimal_number), byte_quantity);
					std::cout << "+   +\n"
							  << first_binary_number << "\n"
							  << second_binary_number << "\n"
						      << Sum_and_residual::sum_with_reverse_code(first_binary_number, second_binary_number, byte_quantity)
							  << "\n+   -\n";
					Binary_system::reverse(second_binary_number);
					std::cout << first_binary_number << "\n"
							  << second_binary_number << "\n"
							  << Sum_and_residual::sum_with_reverse_code(first_binary_number, second_binary_number, byte_quantity)
							  << "\n-   +\n";
					Binary_system::reverse(first_binary_number);
					Binary_system::reverse(second_binary_number);
					std::cout << first_binary_number << "\n"
							  << second_binary_number << "\n"
							  << Sum_and_residual::sum_with_reverse_code(first_binary_number, second_binary_number, byte_quantity)
							  << "\n-   -\n";
					Binary_system::reverse(first_binary_number);
					str = Sum_and_residual::sum_with_reverse_code(first_binary_number, second_binary_number, byte_quantity);
					Binary_system::reverse(first_binary_number);
					Binary_system::reverse(second_binary_number);
					Binary_system::reverse(str);
					std::cout << first_binary_number << "\n"
							  << second_binary_number << "\n"
							  << str << "\n\n";
					break;
					// дополнительный код
				case 3:
					first_binary_number = Binary_system::from_int_to_string(Binary_system::from_decimal_to_binary(first_decimal_number), byte_quantity);
					second_binary_number = Binary_system::from_int_to_string(Binary_system::from_decimal_to_binary(second_decimal_number), byte_quantity);
					std::cout << "+   +\n"
							  << first_binary_number << "\n"
							  << second_binary_number << "\n"
							  << Sum_and_residual::sum_with_additional_code(first_binary_number, second_binary_number)
							  << "\n+   -\n";
					if (second_decimal_number != 0)
					{
						Binary_system::reverse(second_binary_number);
						str = Binary_system::from_int_to_string(1, byte_quantity);
						second_binary_number = Sum_and_residual::sum_with_additional_code(second_binary_number, str);
					};
					std::cout << first_binary_number << "\n"
							  << second_binary_number << "\n"
							  << Sum_and_residual::sum_with_additional_code(first_binary_number, second_binary_number)
							  << "\n-   +\n";
					second_binary_number = Binary_system::from_int_to_string(Binary_system::from_decimal_to_binary(second_decimal_number), byte_quantity);
					if (first_decimal_number != 0)
					{
						Binary_system::reverse(first_binary_number);
						str = Binary_system::from_int_to_string(1, byte_quantity);
						first_binary_number = Sum_and_residual::sum_with_additional_code(first_binary_number, str);
					};
					std::cout << first_binary_number << "\n" 
							  << second_binary_number << "\n"
							  << Sum_and_residual::sum_with_additional_code(first_binary_number, second_binary_number)
							  << "\n-   -\n";
					if (second_decimal_number != 0)
					{
						Binary_system::reverse(second_binary_number);
						str = Binary_system::from_int_to_string(1, byte_quantity);
						second_binary_number = Sum_and_residual::sum_with_additional_code(second_binary_number, str);
					};
					std::cout << first_binary_number << "\n"
							  << second_binary_number << "\n"
							  << Sum_and_residual::sum_with_additional_code(first_binary_number, second_binary_number) << "\n\n";
					break;
				}
			};
			break;
			// произведение двоичных чисел
		case 2:
			std::cout << "+   +\n"
					  << first_binary_number_length << "\n"
					  << second_binary_number_length << "\n"
					  << Multiplication::multiplication(first_binary_number_length, second_binary_number_length)
					  << "\n+   -\n";
			if (second_binary_number_length == 0)
				std::cout << first_binary_number_length << "\n"
						  << second_binary_number_length << "\n0\n";
			else
				if (first_binary_number_length == 0)
					std::cout << first_binary_number_length << "\n-" 
							  << second_binary_number_length << "\n0\n";
				else
					std::cout << first_binary_number_length << "\n-" 
							  << second_binary_number_length << "\n-" 
							  << Multiplication::multiplication(first_binary_number_length, second_binary_number_length) << "\n";
			std::cout << "-   +\n";
			if (first_binary_number_length == 0)
				std::cout << first_binary_number_length << "\n"
						  << second_binary_number_length << "\n0\n";
			else
				if (second_binary_number_length == 0)
					std::cout << '-' << first_binary_number_length << "\n" 
							  << second_binary_number_length << "\n0\n";
				else
					std::cout << '-' << first_binary_number_length << "\n"
							  << second_binary_number_length << "\n-" 
							  << Multiplication::multiplication(first_binary_number_length, second_binary_number_length) << "\n";
			std::cout << "-   -\n";
			if (second_binary_number_length == 0)
				std::cout << first_binary_number_length << "\n" 
						  << second_binary_number_length << "\n0\n";
			else
				if (first_binary_number_length == 0)
					std::cout << first_binary_number_length << "\n" 
							  << second_binary_number_length << "\n0\n";
				else
					std::cout << '-' << first_binary_number_length << "\n-" 
							  << second_binary_number_length << "\n" 
							  << Multiplication::multiplication(first_binary_number_length, second_binary_number_length) << "\n";
			std::cout << "\n";
			break;
			// деление двоичных чисел
		case 3:
			std::cout << "+   +\n"
					  << first_binary_number_length << "\n" 
					  << second_binary_number_length << "\n" 
					  << Division::division(first_binary_number_length, second_binary_number_length)
					  << "\n+   -\n";
			if (second_binary_number_length == 0)
				std::cout << first_binary_number_length << "\n" 
						  << second_binary_number_length << "\nit's impossible.\n";
			else
				if (first_binary_number_length == 0)
					std::cout << first_binary_number_length << "\n-" 
							  << second_binary_number_length << "\n0\n";
				else
					std::cout << first_binary_number_length << "\n-" 
							  << second_binary_number_length << "\n-" 
							  << Division::division(first_binary_number_length, second_binary_number_length) << "\n";
			std::cout << "-   +\n";
			if (first_binary_number_length == 0)
				std::cout << first_binary_number_length << "\n" << second_binary_number_length << "\n0\n";
			else
				if (second_binary_number_length == 0)
					std::cout << '-' << first_binary_number_length << "\n"
							  << second_binary_number_length << "\nit's impossible.\n";
				else
					std::cout << '-' << first_binary_number_length << "\n" 
							  << second_binary_number_length << "\n-" 
							  << Division::division(first_binary_number_length, second_binary_number_length) << "\n";
			std::cout << "-   -\n";
			if (second_binary_number_length == 0)
				std::cout << first_binary_number_length << "\n" 
						  << second_binary_number_length << "\nit's impossible.\n";
			else
				if (first_binary_number_length == 0)
					std::cout << first_binary_number_length << "\n" 
							  << second_binary_number_length << "\n0\n";
				else
					std::cout << '-' << first_binary_number_length << "\n-"
							  << second_binary_number_length << "\n" 
							  << Division::division(first_binary_number_length, second_binary_number_length) << "\n";
			std::cout << "\n";
			break;
			//сложение чисел с плавающей точкой
		case 4:

			Sum_and_residual::Sum_with_float();
			
			break;
		};
	};
}