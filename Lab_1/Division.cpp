#include "Header.h"

std::string Division::division(long int c1, long int c2) {
	std::string s1 = std::to_string(c1);
	std::string s2 = std::to_string(c2);
	std::string t = "";
	t += s1[0];
	std::string o = "";
	bool g = true;
	int k = 1;
	for (int i = 0; i < 6; i++)
	{
		while (atoi(t.c_str()) < atoi(s2.c_str()))
		{
			if (s1.length() - 1 < k)
			{
				if (o == "")
				{
					o += "0,";
					t += '0';
					g = false;
				}
				else
					if (g) {
						o += ",";
						t += '0';
						g = false;
						i--;
					}
					else
					{
						o += '0';
						t += '0';
					}
				i++;
				if (i >= 6)
					break;
			}
			else
			{
				t += s1[k];
				k++;
			}
		};
		if (i != 6)
		{
			t = Sum_and_residual::residual_with_string(t, s2);
			o += '1';
			while (i != 6 && k <= s1.length() - 1 && s1[k] == '0')
			{
				o += '0';
				k++;
				i++;
			}
		}
	}
	return o;
};