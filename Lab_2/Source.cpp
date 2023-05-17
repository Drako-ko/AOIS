#include "Header.h"

logic_formula::logic_formula(string fl)
{
	formula = fl;

	//table initialization
	set table[8] = {
		{0, 0, 0},
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1},
		{1, 1, 0},
		{0, 1, 1},
		{1, 0, 1},
		{1, 1, 1}
	};


	string reverse_polish_formula = translate(formula);
	for (int i = 0; i < 8; i++)
	{
		table[i].f = result(reverse_polish_formula, table[i].a, table[i].b, table[i].c);
	}

	//SDNF initialization
	for (auto& t : table)
	{
		if (t.f == 1)
		{
			sdnf += (t.a == 0) ? "!a*" : "a*";
			sdnf += (t.b == 0) ? "!b*" : "b*";
			sdnf += (t.c == 0) ? "!c" : "c";
			sdnf += "+";
		}
	}
	sdnf.pop_back();

	//SKNF initialization
	for (auto& t : table)
	{
		if (t.f == 0)
		{
			sknf += "(";
			sknf += (t.a == 1) ? "!a+" : "a+";
			sknf += (t.b == 1) ? "!b+" : "b+";
			sknf += (t.c == 1) ? "!c" : "c";
			sknf += ")*";
		}
	}
	sknf.pop_back();

	//numeric binary SDNF initialization
	for (auto& t : table)
	{
		if (t.f == 1)
		{
			numeric_binary_sdnf += to_string(t.a) + to_string(t.b) + to_string(t.c) + "+";
		}
	}
	numeric_binary_sdnf.pop_back();

	//numeric binary SKNF initialization
	for (auto& t : table)
	{
		if (t.f == 0)
		{
			numeric_binary_sknf += to_string(t.a) + to_string(t.b) + to_string(t.c) + "*";
		}
	}
	numeric_binary_sknf.pop_back();

	//numeric decimal SDNF initialization
	int a = 0;
	for (int i = 0; i < 8; i++)
	{
		if (table[i].f == 1)
		{
			a += pow(2, i);
			numeric_decimal_sdnf += to_string(i) + "+";
		}
	}
	numeric_decimal_sdnf.pop_back();

	//numeric decimal SKNF initialization
	for (int i = 0; i < 8; i++)
	{
		if (table[i].f == 0)
		{
			numeric_decimal_sknf += to_string(i) + "*";
		}
	}
	numeric_decimal_sknf.pop_back();

	//index initialization
	index = to_string(a);
}

void logic_formula::print_table()
{
	std::cout << "#" << '\t';
	for (int i = 0; i < 8; i++)
	{
		std::cout << i << '\t';
	}
	std::cout << std::endl << "";
	std::cout << std::endl << "a" << '\t';
	for (int i = 0; i < 8; i++)
	{
		std::cout << table[i].a << "\t";
	}
	std::cout << std::endl << "b" << '\t';
	for (int i = 0; i < 8; i++)
	{
		std::cout << table[i].b << "\t";
	}
	std::cout << std::endl << "c" << '\t';
	for (int i = 0; i < 8; i++)
	{
		std::cout << table[i].c << "\t";
	}
	std::cout << std::endl << "";
	std::cout << std::endl << "f" << '\t';
	for (int i = 0; i < 8; i++)
	{
		std::cout << table[i].f << "\t";
	}
}

void logic_formula::print_SDNF()
{
	std::cout << sdnf;
}
void logic_formula::print_SKNF()
{
	std::cout << sknf;
}
void logic_formula::print_numeric_binary_sdnf()
{
	std::cout << numeric_binary_sdnf;
}
void logic_formula::print_numeric_binary_sknf()
{
	std::cout << numeric_binary_sknf;
}
void logic_formula::print_numeric_decimal_sdnf()
{
	std::cout << numeric_decimal_sdnf;
}
void logic_formula::print_numeric_decimal_sknf()
{
	std::cout << numeric_decimal_sknf;
}
void logic_formula::print_index()
{
	std::cout << index;
}

vector<string> fragmentationAND(string sourceString) {
	vector<string> result;
	if (sourceString[0] == '(')
	{
		sourceString = sourceString.substr(1, sourceString.length() - 2);
	}
	while (sourceString != "")
	{
		if (sourceString.find("*") == -1)
		{
			result.push_back(sourceString);
			sourceString = "";
		}
		else
		{
			result.push_back(sourceString.substr(0, sourceString.find("*")));
			sourceString.erase(0, sourceString.find("*") + 1);
		}
	};
	return result;
}

vector<string> fragmentationAND2(string sourceString) {
	vector<string> result;
	while (sourceString != "")
	{
		result.push_back(sourceString.substr(1, sourceString.find(")") - 1));
		sourceString.erase(0, sourceString.find(")") + 2);
	};
	return result;
}

string reverse(string sourceString) {
	if (sourceString[0] == '!')
	{
		return sourceString.substr(1, sourceString.length());
	}
	else
	{
		return "!" + sourceString;
	}
}

bool find(vector<string> sourceString, string stringToFind) {
	for (int i = 0; i < sourceString.size(); i++) {
		if (sourceString[i] == stringToFind)
		{
			return true;
		}
	}
	return false;
}

bool checkExcess(vector<string> sourceConstituents, int q) {
	vector<vector<string>> fragmentedConstituents;
	vector<string> fragmentsAnalyzingVector;
	for (int i = 0; i < sourceConstituents.size(); i++)
	{
		vector<string> fragmentsAnalyzingVector = fragmentationAND(sourceConstituents[i]);
		fragmentedConstituents.push_back(fragmentsAnalyzingVector);
	}
	vector<string> k = fragmentedConstituents[q];
	for (int i = 0; i < k.size(); i++) {
		for (int j = 0; j < fragmentedConstituents.size(); j++)
		{
			if (j != q)
			{
				if (find(fragmentedConstituents[j], reverse(k[i])))
				{
					fragmentedConstituents.erase(fragmentedConstituents.begin() + j);
				}
			}
		}
	}

	for (int i = 0; i < fragmentedConstituents.size(); i++)
	{
		if (i != q)
		{
			for (int j = 0; j < fragmentedConstituents[i].size(); j++)
			{
				if (!find(k, fragmentedConstituents[i][j]))
				{
					fragmentsAnalyzingVector.push_back(fragmentedConstituents[i][j]);
				}
			}
		}
	}

	for (int i = 0; i < fragmentsAnalyzingVector.size(); i++)
	{
		if (!find(fragmentsAnalyzingVector, reverse(fragmentsAnalyzingVector[i])))
		{
			return false;
		}
	}
	return true;
}

bool isInclude(string s1, string s2) {
	vector<string> v = fragmentationAND(s1);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].length() == 2)
		{
			if (s2.find("*" + v[i]) == -1 && s2.find("+" + v[i]) == -1 && s2.find(v[i]) != 0)
			{
				return false;
			}
		}
		else
		{
			if (s2.find(v[i]) == -1)
			{
				return false;
			}
		}
	}
	return true;
}

string twoten(int x, int n) {
	string k;
	int i = 0;
	long int c = 0;
	while (x != 0) {
		while (x - pow(2, i + 1) >= 0)
		{
			i++;
		}
		x -= pow(2, i);
		c += pow(10, i);
		i = 0;
	};
	k = to_string(c);
	while (k.length() < n)
	{
		k = '0' + k;
	}
	return k;
}

string checkAreNeighboursSDNF(string s1, string s2) {
	vector<string> a = fragmentationAND(s1);
	vector<string> b = fragmentationAND(s2);
	string minNeighboursResult = "";
	int k = 0;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) {
				if (minNeighboursResult == "")
				{
					minNeighboursResult += a[i];
				}
				else
				{
					minNeighboursResult += "*" + a[i];
				}
				break;
			}
			if (j == b.size() - 1 && a[i] != b[j])
			{
				k++;
			}
		}
		if (k > 1)
		{
			return "";
		}
	}
	return minNeighboursResult;
}

vector<string> fragmentationOR(string sourceString) {
	vector<string> fragments;
	while (sourceString != "")
	{
		if (sourceString.find("+") == -1)
		{
			fragments.push_back(sourceString);
			sourceString = "";
		}
		else
		{
			fragments.push_back(sourceString.substr(0, sourceString.find("+")));
			sourceString.erase(0, sourceString.find("+") + 1);
		}
	};
	return fragments;
}