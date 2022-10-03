#pragma once
#include <iostream>
using namespace std;

class Square
{
protected:
	double side; // �������
	double diagonal; // ��������� ��������
	double square; // �������

public:
	Square() : side(0), diagonal(0), square(0) {}
	Square(double side) : side(side), diagonal(side * sqrt(2)), square(pow(side, 2)) {}
	
	Square& operator=(double side)
	{
		this->side = side;
		this->diagonal = side * sqrt(2);
		this->square = pow(side, 2);
		return *this;
	}

	void Print()
	{
		cout << "\t|Square|\n";
		cout << "L = " << side * 4 << endl;
		cout << "D = " << diagonal << endl;
		cout << "S = " << square << endl;
	}
};

