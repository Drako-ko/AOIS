#include "Header.h"
#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int main(void)
{
	setlocale(LC_ALL, "Russian");
	//string SDNF = "(!x1*!x2*!x3)+(!x1*x2*!x3)+(x1*x2*!x3)+(x1*x2*x3)";
	//string SKNF = "(x1+x2+!x3)*(x1+!x2+!x3)*(!x1+x2+x3)*(!x1+x2+!x3)";
	//string SDNF = "(!x1*x2*!x3)+(x1*!x2*!x3)+(x1*!x2*x3)+(x1*x2*!x3)+(x1*x2*x3)";
	//string SKNF = "(x1+x2+x3)*(x1+x2+!x3)*(x1+!x2+!x3)";
	//string SDNF = "(!x1*!x2*!x3)+(!x1*!x2*x3)+(!x1*x2*x3)+(x1*!x2*x3)+(x1*x2*x3)";
	//string SKNF = "(x1+!x2+x3)*(!x1+x2+x3)*(!x1+!x2+x3)";
	string SDNF = "(!x1*!x2*!x3)+(!x1*x2*!x3)+(!x1*x2*x3)+(x1*x2*!x3)+(x1*x2*x3)";
	string SKNF = "(x1+x2+!x3)*(!x1+x2+x3)*(!x1+x2+!x3)";
	//string SDNF = "(!x1*!x2*!x3)+(x1*!x2*!x3)+(x1*x2*!x3)";
	//string SKNF = "(x1+x2+!x3)*(x1+!x2+x3)*(x1+!x2+!x3)*(!x1+x2+!x3)*(!x1+!x2+!x3)";
	string test;
	//(a+!b)*!c
	for (int i = 0; i < 80; cout << '.', i++);
	cout << "\n\t\tМетод непосредственных преобразований:\n\n";

	cout << "СДНФ: " << SDNF << endl;
	cout << "СКНФ: " << SKNF << endl;

	vector<string> dSDNF = conv2DigitOR(SDNF);//for sdnf
	vector<string> dSKNF = conv2DigitAND(SKNF);//for sknf
	vector<string> tmp_dSDNF;
	vector<string> tmp_dSKNF;
	string TDF;
	string KNF;

	bool running = true;
	int i = 0;
	while (running) {
		tmp_dSDNF = dSDNF;
		dSDNF = gluingFUNK(tmp_dSDNF);
		//compare and stop
		if (dSDNF == tmp_dSDNF) {
			TDF = conv2TDNF(dSDNF);
			running = false;
		}
	}
	cout << "\n\nТупиковая DF: ";
	cout << TDF << "\n\n";
	cout << "СКНФ: " << SKNF << endl;

	running = true;
	i = 0;
	while (running) {
		tmp_dSKNF = dSKNF;
		dSKNF = gluingFUNK(tmp_dSKNF);
		//compare and stop
		if (dSKNF == tmp_dSKNF) {
			KNF = conv2TKNF(dSKNF);
			running = false;
		}
	}


	cout << KNF << "\n\nТупиковая KF: ";
	string TKF = toTKF(KNF);
	cout << TKF << "\n\n";


	for (int i = 0; i < 80; cout << '.', i++);
	cout << "\n\t\tМетод Квайна - Мак-Класки: \n\n";

	test = MCClassSDNF(SDNF, TDF);
	cout << "\n\n" << TDF << "\n\n";
	test = MCClassSKNF(SKNF, KNF);
	cout << "\n\n" << TKF << "\n\n";

	for (int i = 0; i < 80; cout << '.', i++);
	cout << "\n\t\tМетод Вейча - Карно: \n\n";

	test = WeichCarno(SDNF, 3);
	cout << "\n\n" << TDF << "\n\n";
	test = WeichCarno2(SKNF, 3);
	cout << "\n\n" << TKF << '\n';

	system("pause > NUL");
	return 0;
}