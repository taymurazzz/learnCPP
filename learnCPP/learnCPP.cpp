#include "iostream"
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

double str_to_do(const std::string& s)
{
	std::istringstream i(s);
	double x;
	if (!(i >> x))
		return 0;
	return x;
}

int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "Руководство пользователя:" << endl
		<< "1) Везде ставим * если подразумеваем умножение. 2x не прокатит, правильный вариант 2*x" << endl
		<< "2) Программа вычисляет корни квадратных уравнений стандартного вида по типу a*x^2+b*x+c=0 или -c+b*x^2+x*2=0 порядок слагаемых и знаки не важны" << endl
		<< "3) Под знаком ^ программа подразумевает операцию возведения в степень: x^2 " << endl
		<< "4) Программа не умеет упрощать выражения и приводить их к стандартному виду квадратного уравнения " << endl
		<< "5) Нельзя писать несколько минусов вряд по типу ---------5" << endl
		<< ") Любое отступление от вышеизложенных правил приведет либо к неправильному решению либо к ошибке компиляции" << endl
	    << endl << "Введите пример: ";
	vector <string> s1;
	int lvec = 0;
	string s;
	getline(cin, s);
	string ss = "";
	double a=0, b=0, c=0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') { continue; }
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i]=='=') { ss += s[i]; s1.push_back(ss); ss = ""; lvec++; }
		else if (s[i] > 47 && s[i] < 58) {
			while (s[i] > 47 && s[i] < 58 || s[i]=='.') {
				ss += s[i];
				i++;
			}
			i--;
			s1.push_back(ss);
			ss = "";
			lvec++;
		}
		else if (s[i] == 'x' && s[i + 1] == '^') {
			s1.push_back("^");
			lvec++;
			i += 2;
		}
		else if (s[i] == 'x') { s1.push_back("x"); lvec++; }
	}

	for (int i = 0; i < lvec; i++) {
		if (s1[i] == "-") {
			s1[i + 1] = "-" + s1[i + 1];
			s1.erase(s1.begin() + i);
			lvec--;
			i--;
		}
	}

	for (int i = 0; i < lvec; i++) {
		//std::cout << s1[i] << " ";
		if (i > 1 && i < lvec-1) {
			if (s1[i] == "^") {
				if (s1[i - 1] == "*") {
					a = str_to_do(s1[i - 2]);
				}
				else if (s1[i + 1] == "*") {
					a = str_to_do(s1[i + 2]);
				}
				else {
					a = 1;
				}
			}
			if (s1[i] == "x") {
				if (s1[i - 1] == "*") {
					b = str_to_do(s1[i - 2]);
				}
				else if (s1[i + 1] == "*") {
					b = str_to_do(s1[i + 2]);
				}
				else {
					b = 1;
				}
			}
			if (s1[i] == "-^") {
				if (s1[i - 1] == "*") {
					a = str_to_do(s1[i - 2]);
				}
				else if (s1[i + 1] == "*") {
					a = str_to_do(s1[i + 2]);
				}
				else {
					a = -1;
				}
			}
			if (s1[i] == "-x") {
				if (s1[i - 1] == "*") {
					b = str_to_do(s1[i - 2]);
				}
				else if (s1[i + 1] == "*") {
					b = str_to_do(s1[i + 2]);
				}
				else {
					b = -1;
				}
			}
			if (i != lvec - 1 && s1[i + 1] != "*" && s1[i - 1] != "*" && s1[i][1] > 47 && s1[i][1] < 58) {
				c = str_to_do(s1[i]);
			}
			if (i != lvec - 1 && s1[i + 1] != "*" && s1[i - 1] != "*" && s1[i][0] > 47 && s1[i][0] < 58) {
				c = str_to_do(s1[i]);
			}
		
		}
		else if (i <= 1) {
			if (s1[i] == "^") {
				if (s1[i + 1] == "*") {
					a = str_to_do(s1[i + 2]);
				}
				else {
					a = 1;
				}
			}
			if (s1[i] == "x") {
				if (s1[i + 1] == "*") {
					b = str_to_do(s1[i + 2]);
				}
				else {
					b = 1;
				}
			}
			if (s1[i] == "-^") {
				if (s1[i + 1] == "*") {
					a = str_to_do(s1[i + 2]);
				}
				else {
					a = -1;
				}
			}
			if (s1[i] == "-x") {
				if (s1[i + 1] == "*") {
					b = str_to_do(s1[i + 2]);
				}
				else {
					b = -1;
				}
			}
			if (i != lvec - 1 && s1[i + 1] != "*" && s1[i][1] > 47 && s1[i][1] < 58) {
				c = str_to_do(s1[i]);
			}
			if (i != lvec - 1 && s1[i + 1] != "*" && s1[i][0] > 47 && s1[i][0] < 58) {
				c = str_to_do(s1[i]);
			}
		}
		else if (i >=lvec-1) {
			if (s1[i] == "^") {
				if (s1[i - 1] == "*") {
					a = str_to_do(s1[i - 2]);
				}
				else {
					a = 1;
				}
			}
			if (s1[i] == "x") {
				if (s1[i - 1] == "*") {
					b = str_to_do(s1[i - 2]);
				}
				else {
					b = 1;
				}
			}
			if (s1[i] == "-^") {
				if (s1[i - 1] == "*") {
					a = str_to_do(s1[i - 2]);
				}
				else {
					a = -1;
				}
			}
			if (s1[i] == "-x") {
				if (s1[i - 1] == "*") {
					b = str_to_do(s1[i - 2]);
				}
				else {
					b = -1;
				}
			}
			if (i!=lvec-1 && s1[i - 1] != "*" && s1[i][1] > 47 && s1[i][1] < 58) {
				c = str_to_do(s1[i]);
			}
			if (i != lvec - 1 && s1[i - 1] != "*" && s1[i][0] > 47 && s1[i][0] < 58) {
				c = str_to_do(s1[i]);
			}
		}
	}
	double x1 = 0, x2 = 0, d = 0;
	d = (b * b) - 4 * a * c;
	std::cout << a << " " << b << " " << c << " --- коэф a b c" << endl;
	if (d < 0) { cout << "Рациональных решений нет."; return 0; }
	if (d == 0) { cout << "x=" << -b / (2 * a); return 0; }
	x1 = (-b + sqrt(d)) / (2 * a);
	x2 = (-b - sqrt(d)) / (2 * a);
	cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
	
}
// x^2 * 214 + 124421*x -24 =0