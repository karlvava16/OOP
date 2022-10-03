#pragma once
#include <iostream>
using namespace std;

const double M_PI = 3.141592653589793238463;

class Cicle
{
protected:
	double radius; // радиус
	double diagonal; // диагональ круга
	double square; // площадь

public:
	Cicle() : radius(0), diagonal(0), square(0) {}
	Cicle(double radius) : radius(radius), diagonal(radius * 2), square(radius * pow(M_PI, 2)) {}

	Cicle& operator=(double radius)
	{
		this->radius = radius;
		this->diagonal = radius * 2;
		this->square = radius * pow(M_PI, 2);
		return *this;
	}

	void Print()
	{
		cout << "\t|Cicle|\n";
		cout << "R = " << 2 * radius * M_PI << endl;
		cout << "D = " << diagonal << endl;
		cout << "S = " << square << endl;
	}
};

