#include "Header.h"



std::string Sum_and_residual::sum_with_string(std::string c1, std::string& c2)
{
	for (int i = c1.length(); i >= 0; i--)
	{
		if ((c1[i] - '0') + (c2[i] - '0') > 1)
			if (i == 0)
			{
				c1[i] = ((c1[i] - '0') - 2 + (c2[i] - '0') + '0');
				c2[0] = 'x';
			}
			else
			{
				c1[i - 1] = (((c1[i - 1] - '0') + 1) + '0');
				c1[i] = ((c1[i] - '0') - 2 + (c2[i] - '0') + '0');
			}
		else
		{
			c1[i] = ((c1[i] - '0') + (c2[i] - '0') + '0');
		}
	};
	return c1;
}

std::string Sum_and_residual::sum_with_straight_code(std::string c1, std::string  c2, bool g)
{
	int t = c1.length();
	for (int i = t - 1; i >= 1; i--)
	{
		if ((c1[i] - '0') + (c2[i] - '0') > 1)
		{
			c1[i - 1] = (((c1[i - 1] - '0') + 1) + '0');
			c1[i] = ((c1[i] - '0') - 2 + (c2[i] - '0') + '0');
		}
		else {
			c1[i] = ((c1[i] - '0') + (c2[i] - '0') + '0');
		}
	}
	if (g)
		c1[0] = '0';
	else
		c1[0] = '1';
	return c1;
}

std::string Sum_and_residual::sum_with_reverse_code(std::string c1, std::string c2, int r)
{
	int t = c1.length();
	for (int i = t - 1; i >= 0; i--)
	{
		if ((c1[i] - '0') + (c2[i] - '0') > 1)
		{
			if (i - 1 < 0)
			{
				c1[i] = '0';
				c1[i] = ((c1[i] - '0') - 2 + (c2[i] - '0') + '0');
				std::string h = from_int_to_string(1, r);
				c1 = sum_with_straight_code(c1, h, 1);
			}
			else
			{
				c1[i - 1] = (((c1[i - 1] - '0') + 1) + '0');
				c1[i] = ((c1[i] - '0') - 2 + (c2[i] - '0') + '0');
			}
		}
		else
		{
			c1[i] = ((c1[i] - '0') + (c2[i] - '0') + '0');
		}
	};

	return c1;
}

std::string Sum_and_residual::sum_with_additional_code(std::string c1, std::string c2)
{
	int t = c1.length();
	for (int i = t - 1; i >= 0; i--)
	{
		if ((c1[i] - '0') + (c2[i] - '0') > 1)
		{
			if (i - 1 < 0)
			{
				c1[i] = ((c1[i] - '0') - 2 + (c2[i] - '0') + '0');
			}
			else
			{
				c1[i - 1] = (((c1[i - 1] - '0') + 1) + '0');
				c1[i] = ((c1[i] - '0') - 2 + (c2[i] - '0') + '0');
			}
		}
		else
		{
			c1[i] = ((c1[i] - '0') + (c2[i] - '0') + '0');
		}
	};

	return c1;
}

std::string Sum_and_residual::residual_with_string(std::string c1, std::string c2)
{
	std::string c4 = c2;
	std::string c5;
	int t = c1.length();
	if (c2.length() < c1.length())
		while (c1.length() != c4.length())
		{
			c5 = c4;
			c4 = '0' + c5;
		};
	std::string c3 = c1;
	for (int i = t - 1; i >= 0; i--)
	{
		if ((c3[i] - '0') - (c4[i] - '0') < 0)
		{
			c3[i - 1] = (((c3[i - 1] - '0') - 1) + '0');
			c3[i] = ((c3[i] - '0') + 2 - (c4[i] - '0') + '0');
		}
		else {
			c3[i] = ((c3[i] - '0') - (c4[i] - '0') + '0');
		}
	}
	return c3;
}

std::string Sum_and_residual::residual_with_straight_code(std::string c1, std::string c2, bool l, bool g)
{
	int t;
	std::string c3;
	std::string c4;
	if (g)
	{
		c3 = c1;
		c4 = c2;
		t = c3.length();
	}
	else
	{
		c3 = c2;
		c4 = c1;
		t = c4.length();
	}

	for (int i = t - 1; i > 0; i--)
	{
		if ((c3[i] - '0') - (c4[i] - '0') < 0)
		{
			c3[i - 1] = (((c3[i - 1] - '0') - 1) + '0');
			c3[i] = ((c3[i] - '0') + 2 - (c4[i] - '0') + '0');
		}
		else {
			c3[i] = ((c3[i] - '0') - (c4[i] - '0') + '0');
		}
	}
	if (l)
		c3[0] = '0';
	else
		c3[0] = '1';
	return c3;
}

void Sum_and_residual::Mod(std::string& s)
{
	if (s[0] == '0')
		s = "0" + s;
	else
		s = "1" + s;
}

void Sum_and_residual::printBinaryTetr(int var, int bits)
{
	int count;
	int space_count = 1;
	for (count = bits - 1; count >= 0; count--) {
		if ((var >> count) & 1)
			std::cout << "1";
		else
			std::cout << "0";
		if (space_count < 4)
			space_count++;
		else {
			space_count = 1;
			std::cout << " ";
		}
	}
}

void Sum_and_residual::printBinaryFull(int var, int bits)
{
	int count;
	for (count = bits - 1; count >= 0; count--) {
		if ((var >> count) & 1)
			std::cout << "1";
		else
			std::cout << "0";
	}
}

void Sum_and_residual::printIEEE(f2bin var)
{
	printf("%d | ", var.raw.sign);
	printBinaryFull(var.raw.exp, EXPONENT + 1);
	std::cout << " | ";
	printBinaryFull(var.raw.mantiss, MANTISSA);
	std::cout << "\n";

}

int Sum_and_residual::convert2dop(int var) {
	if (var < 0) {
		var = ~(-var) + 1;
		//var &= 0x0fffffff;//clear not used bits
	}
	return var;
}

void Sum_and_residual::Sum_with_float()
{
	f2bin a, b, result;

	while (true) {

		//input data
		std::cout << "Input first float: ";
		std::cin >> a.f;
		std::cout << "Input second float: ";
		std::cin >> b.f;


		//print data to screen
		printIEEE(a);
		printIEEE(b);

		//get exponent from input data
		int expA = int(a.raw.exp);
		int expB = int(b.raw.exp);

		printf("-------------------------------------------------------------\n");
		std::cout << "real exponent first: " << expA << '\n';
		std::cout << "real exponent second: " << expB << '\n';
		printf("-------------------------------------------------------------\n");

		//declare temporary variables
		int M_a = 0;//first var
		int M_b = 0;//second xar
		int M_R = 0;//result var

		int diffExp = 0;// different exponents
		int expR = 0;// result exponent                                    max_M   mantiss 23 bits length
		unsigned int max_M = (1 << MANTISSA);// max mantiss (+1 to mantiss  ==>  |  1 |  0000000000000000000000 )
		result.f = 0;

		printf("-------------------------------------------------------------\n");
		printBinaryTetr(max_M, THE_WHOLE_NUMBER);
		printf("--maxM\n");
		printf("-------------------------------------------------------------\n");


		//for normalized digit IEEE754  add 1 in high byte
		if (a.raw.mantiss >= 0 && a.raw.exp > 0 && a.raw.exp != 0xFF) {
			M_a = a.raw.mantiss | max_M;
			printBinaryTetr(M_a, THE_WHOLE_NUMBER);
			printf("--Ma after +1 \n");
		}


		if (b.raw.mantiss >= 0 && b.raw.exp > 0 && b.raw.exp != 0xFF) {
			M_b = b.raw.mantiss | max_M;
			printBinaryTetr(M_b, THE_WHOLE_NUMBER);
			printf("--Mb after +1 \n");
		}


		//for denormalized digit IEEE754
		if (((a.raw.mantiss > 0) && (a.raw.exp == 0))) {
			M_a = a.raw.mantiss;
			printBinaryTetr(M_a, THE_WHOLE_NUMBER);
			printf("--Ma denormalized\n");
		}
		if (((b.raw.mantiss > 0) && (b.raw.exp == 0))) {
			M_b = b.raw.mantiss;
			printBinaryTetr(M_b, THE_WHOLE_NUMBER);
			printf("--Mb denormalized\n");
		}

		//if var negative convert to dop code
		if (a.raw.sign != b.raw.sign) {
			if (a.raw.sign > 0) {
				M_a = convert2dop(-M_a);
				printBinaryTetr(M_a, THE_WHOLE_NUMBER);
				printf("--Ma dopcode\n");
			}
			if (b.raw.sign > 0) {
				M_b = convert2dop(-M_b);
				printBinaryTetr(M_b, THE_WHOLE_NUMBER);
				printf("--Mb dopcode\n");
			}
		}
		else result.raw.sign = a.raw.sign;

		printf("-------------------------------------------------------------\n");

		if (expA > expB) {
			diffExp = expA - expB;//different exponent
			expR = expA;//set result exponent to max exponent 
			M_b = M_b >> diffExp;//normalize less var
		}
		if (expA < expB) {
			diffExp = expB - expA;//different exponent
			expR = expB;//set result exponent to max exponent 
			M_a = M_a >> diffExp;//normalize less var
		}
		if (expA == expB) {
			diffExp = 0;
			expR = expA;//set result exponent normalize not need 
		}

		printf("different %d\n", diffExp);
		printf("exponent %d\n", expR);
		printf("-------------------------------------------------------------\n");
		printBinaryTetr(M_a, THE_WHOLE_NUMBER);
		printf("--a\n");
		printBinaryTetr(M_b, THE_WHOLE_NUMBER);
		printf("--b\n");
		printf("-------------------------------------------------------------\n");


		M_R = M_a + M_b;
		printBinaryTetr(M_R, THE_WHOLE_NUMBER);
		printf("--MR\n");


		//check result add operation
		norm_d tmp_res;
		tmp_res.ui = M_R;
		//if sign 01 or 10 then overflow - need correction
		//                     0
		if (tmp_res.raw.sign > 1) {
			M_R = M_R >> 1;
			printBinaryTetr(M_R, THE_WHOLE_NUMBER);
			printf("--MR\n");

			unsigned int tmp_bit = M_R & (1 << MANTISSA);
			printBinaryTetr(tmp_bit, THE_WHOLE_NUMBER);
			printf("--sign bit\n");

			tmp_bit = (tmp_bit << 1) + tmp_bit;
			printBinaryTetr(tmp_bit, THE_WHOLE_NUMBER);
			printf("--sign bit\n");

			M_R |= tmp_bit;
			printBinaryTetr(M_R, THE_WHOLE_NUMBER);
			printf("--x res\n");

			expR += 1;
		}

		result.raw.sign = (M_R & 0x80000000) >> THE_WHOLE_NUMBER - 1;
		result.raw.exp = expR;
		result.raw.mantiss = M_R;

		printIEEE(result);
		std::cout << "result in float:   " << result.f << '\n';
		printf("-------------------------------------------------------------\n");
		std::cout << "Print any key to exit... " << '\n';

		char ch = getchar();
		if (ch == 'q' || ch == 'Q') break;
	}
}