#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

class Student
{
public:
	void Input() {
		double _a, _b, _c;
		string _answer;
		ifstream Data, Answers;
		Data.open("Data.txt");
		Answers.open("Answers.txt");
		if (Data) {
			while (!Data.eof()) {
				Data >> _a >> _b >> _c;
				a.push_back(_a);
				b.push_back(_b);
				c.push_back(_c);
			}
		}
		if (Answers) {
			while (!Answers.eof()) {
				getline(Answers, _answer);
				answer.push_back(_answer);
			}
		}
		Data.close();
		Answers.close();
	}
	void Output() {
		int num = 0;
		for (int i = 0; i < a.size(); i++) {
			if (result[i] == answer[i])
				num++;;
		}
		cout << name << "\nNumber of correct answers: " << num << endl;
		cout << endl;
	}
	string Solution() {
		return("0.000000");
	}
	string Solution(double _a, double _b, double _c) {
		double D = pow(_b, 2) - (4.0 * _a * _c);
		if (D == 0) {
			double x = -(_b) / (2.0 * _a);
			if (_b == 0)
				return("0.000000");
			return(to_string(x));

		}
		if (D > 0) {
			double x1 = (-(_b)-sqrt(D)) / (2.0 * _a);
			double x2 = (-(_b)+sqrt(D)) / (2.0 * _a);
			string str = to_string(x1) + " " + to_string(x2);
			return(str);
		}
		if (D < 0) {
			return("No roots");
		}
	}

protected:
	vector <double> a, b, c;
	vector <string> result, answer;
	string name;

};

class Bad : public Student {
public:
	Bad(string _name);

};

Bad::Bad(string _name) {
	name = _name;
	Input();
	for (int i = 0; i < a.size(); i++) {
		result.push_back(Solution());
	}
	Output();
}
class Averange :public Student {
public:
	Averange(string _name);
};

Averange::Averange(string _name) {
	name = _name;
	Input();
	for (int i = 0; i < a.size(); i++) {
		int random = rand() % 100;
		if (random < 55) {
			result.push_back(Solution());
		}
		else
		{
			result.push_back(Solution(a[i], b[i], c[i]));
		}
	}
	Output();
}

class Excellent : public Student {
public:
	Excellent(string _name);

};

Excellent::Excellent(string _name) {
	name = _name;
	Input();
	for (int i = 0; i < a.size(); i++) {
		result.push_back(Solution(a[i], b[i], c[i]));
	}
	Output();
}


int main()
{
	srand(time(0));
	Excellent First_st("Stas");
	Averange Second_st("Artur");
	Averange Third_st("Roma");
	Bad Forth_st("Artem");
}

