#include "Header.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;

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
string checkAreNeighboursSDNF(string s1, string s2) {
	vector<string> a = fragmentationAND(s1);
	vector<string> b = fragmentationAND(s2);
	string ret = "";
	int k = 0;

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i] == b[j])
			{
				if (ret == "")
				{
					ret += a[i];
				}
				else
				{
					ret += "*" + a[i];
				}
				break;
			}
			if ((j == (b.size() - 1)) && (a[i] != b[j]))
			{
				k++;
			}
		}
		if (k > 1)
		{
			return "";
		}
	}

	return ret;
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

int cntDigit(string s) {
	int ret = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1' || s[i] == '0')ret++;
	}
	return ret;
}
string conv2TDNF(vector<string> fragment) {
	string resOUT = "";
	string znak = "";

	for (int i = 0; i < fragment.size(); i++)
	{
		string el = "(";
		for (int j = 1; j < fragment[i].size(); j++) {
			ostringstream index;
			index << j;
			if (j < fragment[i].size() - 1)znak = "*";
			else znak = "";
			if (cntDigit(fragment[i]) <= 1)znak = "";
			switch (fragment[i][j])
			{
			case '0': el += "!x" + index.str() + znak;
				break;
			case '1': el += "x" + index.str() + znak;
				break;
			default:
				break;
			}

		}
		if (i < fragment.size() - 1)znak = "+";
		else znak = "";
		el += ")" + znak;
		resOUT += el;
	}
	return resOUT;
}
string conv2TKNF(vector<string> fragment) {
	string resOUT = "";
	string znak = "";

	for (int i = 0; i < fragment.size(); i++)
	{
		string el = "(";
		for (int j = 1; j < fragment[i].size(); j++) {
			ostringstream index;
			index << j;
			if (j < fragment[i].size() && j>1)znak = "+";
			else znak = "";
			if (cntDigit(fragment[i]) <= 1)znak = "";
			if (el == "(" && znak == "+")znak = "";
			switch (fragment[i][j])
			{
			case '0': el += znak + "!x" + index.str();
				break;
			case '1': el += znak + "x" + index.str();
				break;
			default:
				break;
			}

		}
		if (i < fragment.size() - 1)znak = "*";
		else znak = "";
		el += ")" + znak;
		resOUT += el;
	}
	return resOUT;
}
vector<string> conv2DigitOR(string sourceString) {
	vector<string> resOUT;
	vector<string> fragOR = fragmentationOR(sourceString);
	for (int i = 0; i < fragOR.size(); i++)
	{
		vector<string> fragAND = fragmentationAND(fragOR[i]);
		string t_j = "?";
		for (int j = 0; j < fragAND.size(); j++) {
			if (fragAND[j][0] == '!') t_j += "0";
			else t_j += "1";
		}
		resOUT.push_back(t_j);
	}
	return resOUT;
}
vector<string> conv2DigitAND(string sourceString) {
	vector<string> resOUT;
	vector<string> fragAND = fragmentationAND2(sourceString);
	for (int i = 0; i < fragAND.size(); i++)
	{
		vector<string> fragOR = fragmentationOR(fragAND[i]);
		string t_j = "?";
		for (int j = 0; j < fragOR.size(); j++) {
			if (fragOR[j][0] == '!') t_j += "0";
			else t_j += "1";
		}
		resOUT.push_back(t_j);
	}
	return resOUT;
}
vector<string> gluingFUNK(vector<string> fragments) {
	vector<string> resOUT;
	int size_frg = fragments.size();
	for (int i = 0; i < size_frg; i++)
	{
		//if not final elements then compare , else get next element
		string cs = fragments[i];
		int l = fragments[i].size();
		int flag = 1;
		int count_glue = 0;

		if (fragments[i][0] == '?')
		{
			for (int j = 0; j < size_frg; j++)
			{
				int hit = 0;
				flag = 1;
				cs = fragments[i];
				int group = abs(countOne(fragments[i]) - countOne(fragments[j]));
				//if element is one group 
				if ((group) <= 1 && (i != j)) {
					for (int k = 1; k < l; k++) {
						if ((fragments[i][k] != fragments[j][k])) {
							cs[k] = '-';
							hit++;
						}
						if (hit > 1) {
							flag = 0;
						}
					}
					if (hit > 1)count_glue++;
					//before push - find duplicate (if element not present then add to resOUT)
					if (find(resOUT.begin(), resOUT.end(), cs) == resOUT.end() && flag == 1) {
						resOUT.push_back(cs);
					}
				}
				else {
					count_glue++;
				}
			}
		}
		else if (fragments[i][0] == '#')resOUT.push_back(cs);
		if (count_glue >= size_frg) {
			cs = fragments[i];
			cs[0] = '#';
			resOUT.push_back(cs);
		}
	}
	return resOUT;
}
int countOne(string s) {
	int ret = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1')ret++;
	}
	return ret;
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

string toTDF(string sourceString) {
	vector<string> r = fragmentationOR(sourceString);
	string pre_s, ret_s = "";
	for (int i = 0; i < r.size(); i++)
	{
		if (!checkExcess(r, i))
		{
			if (ret_s == "")pre_s = "";
			else pre_s = "+";
			ret_s += pre_s + r[i];
		}
	}
	return ret_s;
}
string checkAreNeighboursSKNF(string s1, string s2) {
	vector<string> a = fragmentationOR(s1);
	vector<string> b = fragmentationOR(s2);
	string ret = "(";
	int k = 0;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i] == b[j])
			{
				if (ret == "(")
				{
					ret += a[i];
				}
				else
				{
					ret += "+" + a[i];
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
	ret += ")";
	return ret;
}
/*
string gluingSKNF(string sourceString) {
	string gluingResult = "";
	vector<string> fragments = fragmentationAND2(sourceString);
	for (int i = 0; i < fragments.size(); i++)
	{
		for (int j = i + 1; j < fragments.size(); j++)
		{
			if (checkAreNeighboursSKNF(fragments[i], fragments[j]) != "")
				if (gluingResult == "")
				{
					gluingResult += checkAreNeighboursSKNF(fragments[i], fragments[j]);
				}
				else
				{
					gluingResult += "*" + checkAreNeighboursSKNF(fragments[i], fragments[j]);
				}
		}
	}
	return gluingResult;
}
*/

string toTKF(string sourceString) {
	vector<string> r = fragmentationAND2(sourceString);
	string pre_s, post_s;
	int erase_const = 0;
	post_s = ")";
	for (int i = 0; i < r.size(); i++) {
		if (checkExcess2(r, i))
		{
			if (i == 0) {
				pre_s = "(";
				erase_const = 2;
			}
			else {
				pre_s = "*(";
				erase_const = 3;
			}

			sourceString.erase(sourceString.find(pre_s + r[i] + post_s), r[i].length() + erase_const);
		}
	}
	return sourceString;
}

/*
bool isInclude3(string s, string str) {
vector<string> Str = fragmentationOR(str);
for (int i = 0; i < Str.size(); i++) {
if (isInclude(s, Str[i]))
{
return true;
}
};
return false;
}
*/
bool checkExcess(vector<string> s, int q) {
	vector<vector<string>> r;
	vector<string> d;

	for (int i = 0; i < s.size(); i++) {
		vector<string> t = fragmentationAND(s[i]);
		r.push_back(t);
	}
	vector<string> k = r[q];

	for (int i = 0; i < k.size(); i++)
	{
		for (int j = 0; j < r.size(); j++)
		{
			if (j != q)
			{
				if (find(r[j], reverse(k[i])))
				{
					r.erase(r.begin() + j);
				}
			}
		}
	}

	for (int i = 0; i < r.size(); i++)
	{
		if (i != q)
		{
			for (int j = 0; j < r[i].size(); j++)
			{
				if (!find(k, r[i][j]))
				{
					d.push_back(r[i][j]);
				}
			}
		}
	}

	for (int i = 0; i < d.size(); i++)
	{
		if (find(d, reverse(d[i])))
		{
			return true;
		}
	}

	return false;
}
bool checkExcess2(vector<string> s, int q) {
	vector<vector<string>> r;
	vector<string> d;

	for (int i = 0; i < s.size(); i++) {
		vector<string> t = fragmentationOR(s[i]);
		r.push_back(t);
	}
	vector<string> k = r[q];

	for (int i = 0; i < k.size(); i++)
	{
		for (int j = 0; j < r.size(); j++)
		{
			if (j != q)
			{
				if (find(r[j], reverse(k[i])))
				{
					r.erase(r.begin() + j);
				}
			}
		}
	}

	for (int i = 0; i < r.size(); i++)
	{
		if (i != q)
		{
			for (int j = 0; j < r[i].size(); j++)
			{
				if (!find(k, r[i][j]))
				{
					d.push_back(r[i][j]);
				}
			}
		}
	}

	for (int i = 0; i < d.size(); i++)
	{
		if (find(d, reverse(d[i])))
		{
			return true;
		}
	}

	return false;
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
bool isInclude2(string s1, string s2) {
	vector<string> v = fragmentationOR(s1);
	for (int i = 0; i < v.size(); i++) {
		if (v[i].length() == 2)
		{
			if (s2.find("+" + v[i]) == -1 && s2.find(v[i]) != 0)
				return false;
		}
		else
			if (s2.find(v[i]) == -1)
				return false;
	}
	return true;
}
vector<vector<int>> makeDiagram(int countOfArguments) {
	int horizontalO;
	vector<vector<int>> diagram;
	if (countOfArguments % 2 == 0)
	{
		diagram.resize(pow(2, countOfArguments / 2));
		horizontalO = pow(2, countOfArguments / 2);
	}
	else
	{
		diagram.resize(pow(2, (countOfArguments - 1) / 2));
		horizontalO = pow(2, (countOfArguments + 1) / 2);
	}
	for (int i = 0; i < diagram.size(); i++)
	{
		vector<int> t(horizontalO);
		diagram[i] = t;
	}
	return diagram;
}
int GrayCode(unsigned int code) {
	return code ^ (code >> 1);
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
bool isInclude3(string s, string str) {
	vector<string> str0 = conv2DigitOR(str);
	vector<string> s0 = conv2DigitOR(s);
	for (int i = 0; i < str0.size(); i++) {
		if (s0[0] == str0[i])
		{
			return true;
		}
	};
	return false;
}
string FindTDF(string s1, string s2) {
	string d = "";
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == '0' && s2[i] == '0')
			d += "*!x" + to_string(i + 1);
		if (s1[i] == '1' && s2[i] == '1')
			d += "*x" + to_string(i + 1);
	}
	d.erase(0, 1);
	return d;
}
vector<string> normal(vector<string> s) {
	vector<string> t;
	for (int i = 0; i < s.size(); i++) {
		if (!find(t, s[i]))
			t.push_back(s[i]);
	};
	for (int i = 0; i < t.size(); i++) {
		vector<string> fr = fragmentationAND(t[i]);
		bool g = false;
		for (int k = 0; k < t.size() - 1; k++)
		{
			if (k != i)
				if ((isInclude(fr[0], t[k]) && isInclude(fr[1], t[k + 1])) ||
					(isInclude(fr[1], t[k]) && isInclude(fr[0], t[k + 1])))
				{
					t.erase(t.begin() + i);
					g = true;
					break;
				}
		}
		if (g)
		{
			break;
		}
	};
	return t;
}
bool isInclude4(string s, string str) {
	vector<string> Str = fragmentationAND2(str);
	for (int i = 0; i < Str.size(); i++)
	{
		if (isInclude2(s, Str[i]))
		{
			return true;
		}
	};
	return false;
}
string FindTKF(string s1, string s2) {
	string d = "(";
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == '0' && s2[i] == '0')
			d += "+x" + to_string(i + 1);
		if (s1[i] == '1' && s2[i] == '1')
			d += "+!x" + to_string(i + 1);
	}
	d.erase(1, 1);
	d += ")";
	return d;
}
vector<string> normal2(vector<string> s) {
	vector<string> t;
	for (int i = 0; i < s.size(); i++)
	{
		if (!find(t, s[i].substr(1, s[i].length() - 2)))
		{
			t.push_back(s[i].substr(1, s[i].length() - 2));
		}
	};
	for (int i = 0; i < t.size(); i++)
	{
		vector<string> fr = fragmentationOR(t[i]);
		bool g = false;
		int u = 0;
		for (int k = 0; k < t.size(); k++)
		{
			if (k != i)
			{
				if (isInclude2(fr[u], t[k]))
				{
					u++;
				}
			}
			if (u == 2)
			{
				t.erase(t.begin() + i);
				g = true;
				break;
			}
		}
		if (g)
		{
			break;
		}
	};
	return t;
}

//--------------------------------------------------------
string MCClassSDNF(string SDNF, string DNF) {
	vector<string> fragmentedSDNF = fragmentationOR(SDNF);
	vector<string> fragmentedDNF = fragmentationOR(DNF);
	vector<vector<char>> table;
	vector<string> preResult;
	table.resize(fragmentedDNF.size());
	for (int i = 0; i < table.size(); i++) {
		table[i].resize(fragmentedSDNF.size());
	};
	for (int i = 0; i < fragmentedDNF.size(); i++)
		for (int j = 0; j < fragmentedSDNF.size(); j++)
		{
			if (isInclude(fragmentedDNF[i], fragmentedSDNF[j]))
				table[i][j] = 'X';
		};

	for (int i = 0; i < fragmentedSDNF.size(); i++)
	{
		cout << "\t  " << fragmentedSDNF[i];
	}

	for (int i = 0; i < fragmentedDNF.size(); i++)
	{
		cout << endl;
		cout << fragmentedDNF[i] << "     ";
		for (int j = 0; j < fragmentedSDNF.size(); j++)
			cout << table[i][j] << "\t\t     ";
	}

	return  "ok";
}
//--------------------------------------------------------
string MCClassSKNF(string SKNF, string KNF) {
	vector<string> h = fragmentationAND2(SKNF);
	vector<string> l = fragmentationAND2(KNF);
	vector<vector<char>> table;
	vector<string> r;
	table.resize(l.size());

	for (int i = 0; i < table.size(); i++) {
		table[i].resize(h.size());
	};

	for (int i = 0; i < l.size(); i++)
	{
		for (int j = 0; j < h.size(); j++)
		{
			if (isInclude2(l[i], h[j]))
				table[i][j] = 'X';
		};
	}

	for (int i = 0; i < h.size(); i++)
	{
		cout << "\t  " << h[i];
	}

	for (int i = 0; i < l.size(); i++)
	{
		cout << '\n' << l[i] << "     ";
		for (int j = 0; j < h.size(); j++)
			cout << table[i][j] << "\t\t     ";
	}

	return  "ok";
}
//--------------------------------------------------------
string WeichCarno(string SDNF, int countOfArguments) {
	vector<vector<int>> diagram = makeDiagram(countOfArguments);
	vector<string> v;
	vector<string> g;
	vector<string> answer;
	string TF;
	int horizontalO = 0;
	int verticalO = 0;
	if (countOfArguments % 2 == 0) {
		horizontalO = pow(2, countOfArguments / 2);
		verticalO = pow(2, countOfArguments / 2);
	}
	else {
		horizontalO = pow(2, (countOfArguments + 1) / 2);
		verticalO = pow(2, (countOfArguments - 1) / 2);
	}
	for (int i = 0; i < verticalO; i++)
		v.push_back(twoten(GrayCode(i), log2(verticalO)));
	for (int i = 0; i < horizontalO; i++)
		g.push_back(twoten(GrayCode(i), log2(horizontalO)));
	for (int i = 0; i < diagram.size(); i++)
		for (int j = 0; j < diagram[i].size(); j++)
		{
			string s = v[i] + g[j];
			string b = "";
			for (int k = 0; k < s.length(); k++)
			{

				if (s[k] == '0')
					if (b == "")
						b += "!x" + to_string(k + 1);
					else
						b += "*!x" + to_string(k + 1);
				else
					if (b == "")
						b += "x" + to_string(k + 1);
					else
						b += "*x" + to_string(k + 1);
			}
			if (!isInclude3(b, SDNF))
				diagram[i][j] = 0;
			else
				diagram[i][j] = 1;
		}

	for (int i = 0; i < g.size(); i++)
	{
		cout << "\t" << g[i];
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << '\n' << v[i] << "      ";
		for (int j = 0; j < g.size(); j++)
		{
			cout << diagram[i][j] << "\t ";
		}
	}

	return "ok";
}

string WeichCarno2(string SKNF, int n) {
	vector<vector<int>> diagram = makeDiagram(n);
	vector<string> v;
	vector<string> g;
	vector<string> answer;
	string TF;
	int horizontalO;
	int verticalO;
	if (n % 2 == 0) {
		horizontalO = pow(2, n / 2);
		verticalO = pow(2, n / 2);
	}
	else {
		horizontalO = pow(2, (n + 1) / 2);
		verticalO = pow(2, (n - 1) / 2);
	}
	for (int i = 0; i < verticalO; i++)
		v.push_back(twoten(GrayCode(i), log2(verticalO)));
	for (int i = 0; i < horizontalO; i++)
		g.push_back(twoten(GrayCode(i), log2(horizontalO)));
	for (int i = 0; i < diagram.size(); i++)
	{
		for (int j = 0; j < diagram[i].size(); j++)
		{
			string s = v[i] + g[j];
			string b = "";
			for (int k = 0; k < s.length(); k++)
			{

				if (s[k] == '0')
				{
					if (b == "")
					{
						b += "x" + to_string(k + 1);
					}
					else
					{
						b += "+x" + to_string(k + 1);
					}
				}
				else
				{
					if (b == "")
					{
						b += "!x" + to_string(k + 1);
					}
					else
					{
						b += "+!x" + to_string(k + 1);
					}
				}
			}
			if (isInclude4(b, SKNF))
				diagram[i][j] = 0;
			else
				diagram[i][j] = 1;
		}
	}
	for (int i = 0; i < g.size(); i++)
		cout << "\t" << g[i];
	for (int i = 0; i < v.size(); i++)
	{
		cout << '\n' << v[i] << "      ";
		for (int j = 0; j < g.size(); j++)
			cout << diagram[i][j] << "\t ";
	}
	return "ok";
}