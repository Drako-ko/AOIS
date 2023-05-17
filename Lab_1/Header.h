#pragma once

#include <iostream>
#include "string"
#include <math.h>
#include <vector>

class Binary_system
{
public:

	long int from_decimal_to_binary(int decimal_number);//перевод десятичного числа в двоичное
	void change_signed_number(std::string& binary_number);// функция смены знака числа в коде
	std::string from_int_to_string(long int binary_number, int byte_quantity);// перевод двоичного числа в прямой код
	void reverse(std::string& binary_number);// перевод прямого кода в обратный

private:

};

class Sum_and_residual : public Binary_system
{
public:

	int MANTISSA = 23;
	int THE_WHOLE_NUMBER = 32;
	int SIGN = 2;
	int EXPONENT = 7;

	typedef union {
		unsigned int ui;
		struct {
			//etc       |  sign     | mantiss                    |
			//0000000   |00/11/01/10| 00000000000000000000000000 |  7|2|23 = 32 bits
			unsigned int mantiss : 23;
			unsigned int sign : 2;
			unsigned int exp : 7;
		} raw;
	}norm_d;

	typedef union {
		float f;
		struct {
			//sign      |  exponent | mantiss                    |
			// 0|1(+|-) |  00000000 | 00000000000000000000000000 |  1|8|23 = 32 bits
			unsigned int mantiss : 23;
			unsigned int exp : 8;
			unsigned int sign : 1;
		} raw;
	}f2bin;

	long int sum_with_int(long int c1, long int c2);//сумма двоичных чисел
	std::string sum_with_string(std::string c1, std::string& c2);// cyмма чисел представленных строками в двоичном виде
	std::string sum_with_straight_code(std::string c1, std::string  c2, bool g);// сумма чисел представленных прямым кодом
	std::string sum_with_reverse_code(std::string c1, std::string c2, int r);//сложение чисел в обратном коде
	std::string sum_with_additional_code(std::string c1, std::string c2);//cумма чисел в дополнительном коде
	std::string sum_floating_point_numbers(std::string P1, std::string P2, std::string m1, std::string m2);// сложение чисел с плавающей точкой
	std::string residual_with_string(std::string c1, std::string c2);// разность чисел представленных строками в двоичном виде
	std::string residual_with_straight_code(std::string c1, std::string c2, bool l, bool g);//разность чисел представленных прямым кодом
	void Mod(std::string& s);
	void printBinaryTetr(int var, int bits);
	void printBinaryFull(int var, int bits);
	void printIEEE(f2bin var);
	int convert2dop(int var);
	void Sum_with_float();


private:

};

class Multiplication : public Binary_system
{
public:
	
	long long int multiplication(long int c1, long int c2);// произведение двоичных чисел

private:

};

class Division : public Binary_system, public Sum_and_residual
{
public:

	std::string division(long int c1, long int c2);// деление двоичных чисел

private:

};

class Menu : public Binary_system, public Sum_and_residual, public Multiplication, public Division
{
public:

	void menu();

private:

};