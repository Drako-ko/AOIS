#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class logic_formula
{
private:
	struct set
	{
		bool a;
		bool b;
		bool c;
		bool f;
	};
	set table[8];
	string formula;
	string sdnf = "";
	string sknf = "";
	string numeric_binary_sdnf = "";
	string numeric_binary_sknf = "";
	string numeric_decimal_sdnf = "";
	string numeric_decimal_sknf = "";
	string index = "";
	
	int priority(char op) {
		if (op == '!')
			return 4;
		else if (op == '*')
			return 3;
		else if (op == '+')
			return 2;
		else if (op == '(')
			return 1;
		else
			return 0;
	}
	std::string translate(std::string in) {
		std::string out;
		std::stack<char> st;
		char buff;
		for (int i = 0; i < in.length(); i++)
		{
			switch (in[i])
			{
				case '(': st.push(in[i]); break;

				case ')':
				{
					while ((st.top()) != '(')
					{
						buff = st.top();
						st.pop();
						out += buff;
					}
					st.pop();
					break;
				}
			}
			if (in[i] >= 'a' && in[i] <= 'c')
			{
				out += in[i];
			}
			if (in[i] == '*' || in[i] == '+' || in[i] == '!')
			{
				while (!st.empty() && priority(st.top()) >= priority(in[i]))
				{
					buff = st.top();
					st.pop();
					out += buff;
				}
				st.push(in[i]);
			}
		}
		while (!st.empty())
		{
			buff = st.top();
			st.pop();
			out += buff;
		}
		return out;
	}
	double result(string in, bool a, bool b, bool c)
	{
		std::stack<char> st_val;
		bool n1, n2, res;
		for (int i = 0; i < in.length(); i++)
		{
			if (in[i] == 'a')
			{
				st_val.push(a);
			}
			else if (in[i] == 'b')
			{
				st_val.push(b);
			}
			else if (in[i] == 'c')
			{
				st_val.push(c);
			}
			else if (in[i] == '+')
			{
				n2 = st_val.top();
				st_val.pop();
				n1 = st_val.top();
				st_val.pop();
				res = n1 | n2;
				st_val.push(res);
			}
			else if (in[i] == '*')
			{
				n2 = st_val.top();
				st_val.pop();
				n1 = st_val.top();
				st_val.pop();
				res = n1 & n2;
				st_val.push(res);
			}
			else if (in[i] == '!')
			{
				n1 = st_val.top();
				st_val.pop();
				res = !n1;
				st_val.push(res);
			}
		}
		return st_val.top();
	}
public:
	logic_formula(string fl);
	void print_table();
	void print_SDNF();
	void print_SKNF();
	void print_numeric_binary_sdnf();
	void print_numeric_binary_sknf();
	void print_numeric_decimal_sdnf();
	void print_numeric_decimal_sknf();
	void print_index();
};