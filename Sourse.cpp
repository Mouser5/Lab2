#include "Header.h"

void Student::Get() {
	cout << "Academic perfomance:";
}

void Student::Input() {
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

int Student::Output() {
	int num = 0;
	for (int i = 0; i < a.size(); i++) {
		if (result[i] == answer[i])
			num++;;
	}
	return num;
}

string Student::Solution() {
	return("0.000000");
}

string Student::Solution(double _a, double _b, double _c) {
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

void Bad::Get() {

	std::cout << "| " << name << " | " << Output() << " | " << "Academic perfomance: " << "2 |" << std::endl;
}

Bad::Bad(string _name) {
	name = _name;
	Input();
	for (int i = 0; i < a.size(); i++) {
		result.push_back(Solution());
	}
	Get();
}

void Averange::Get() {
	std::cout << "| " << name << " | " << Output() << " | " <<"Academic perfomance: "<< "4 |" << std::endl;
}

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
	Get();
}

void Excellent::Get() {
	std::cout << "| " << name << " | " << Output() << " | " << "Academic perfomance: " << "5 |" << std::endl;
}

Excellent::Excellent(string _name) {
	name = _name;
	Input();
	for (int i = 0; i < a.size(); i++) {
		result.push_back(Solution(a[i], b[i], c[i]));
	}
	Get();
}