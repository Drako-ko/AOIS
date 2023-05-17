#include "Header.h"

long int Binary_system::from_decimal_to_binary(int decimal_number)
{
	int degree = 0;
	if (decimal_number < 0);
	decimal_number = abs(decimal_number);
	long int binary_number = 0;
	while (decimal_number != 0) {
		while (decimal_number - pow(2, degree + 1) >= 0)
			degree++;
		decimal_number -= pow(2, degree);
		binary_number += pow(10, degree);
		degree = 0;
	};
	return binary_number;
}

void Binary_system::change_signed_number(std::string& binary_number)
{
	if (binary_number[0] == '0')
		binary_number[0] = '1';
	else
		binary_number[0] = '0';
}

std::string Binary_system::from_int_to_string(long int binary_number, int byte_quantity)
{
	std::string str = "0";
	for (int i = 8 * byte_quantity - std::to_string(binary_number).length(); i > 1; i--)
		str += "0";
	str += std::to_string(binary_number);
	return str;
}

void Binary_system::reverse(std::string& binary_number)
{
	for (int i = 0; i < binary_number.length(); i++)
		if (binary_number[i] == '1')
			binary_number[i] = '0';
		else
			binary_number[i] = '1';
}

