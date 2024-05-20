#pragma once
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
	void Input();
	void Output();
	string Solution();
	string Solution(double _a, double _b, double _c);
protected:
	vector <double> a, b, c;
	vector <string> result, answer;
	string name;

};

class Bad : public Student {
public:
	Bad(string _name);
};

class Averange :public Student {
public:
	Averange(string _name);
};

class Excellent : public Student {
public:
	Excellent(string _name);
};