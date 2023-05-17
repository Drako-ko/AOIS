#include "Header.h"

long long int Multiplication::multiplication(long int c1, long int c2)
{
	int i = 0;
	std::vector  <long long int> s;
	long int c3 = c2;
	while (c2 != 0)
	{
		if (c2 % 10 == 1)
		{
			s.push_back(c1 * pow(10, i));
		}
		c2 /= 10;
		i++;
	};
	for (int j = 1; j < s.size(); j++) {
		s[0] = s[0] + s[j];
		long long int t = s[0];
		int k = 1;
		while (t != 0) {
			if (t % 10 >= 2)
			{
				s[0] -= 2 * pow(10, k - 1);
				s[0] += pow(10, k);
			};
			t = s[0] / pow(10, k);
			k++;
		}
	};
	if (s.size() == 0)
		return 0;
	else
		return s[0];
}