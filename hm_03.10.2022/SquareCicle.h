#pragma once

#include <iostream>
#include "Cicle.h"
#include "Square.h"
using namespace std;

class SquareCicle : public Square, public Cicle
{
protected:
	short inscribed; // вписаны объекты или нет

	int Inscribed() // определение вписанного объекта
	{
		if (Square::diagonal <= Cicle::diagonal)
			inscribed = 1;
		else if (Square::side >= Cicle::diagonal)
			inscribed = -1;
		else
			inscribed = 0;
		return inscribed;
	}

public:
	SquareCicle() : Square(), Cicle() { inscribed = 0; }
	SquareCicle(double side, double radius) : Square(side), Cicle(radius) { Inscribed(); }
	SquareCicle (const Square& sq, const Cicle& c) : Square(sq), Cicle(c) { Inscribed(); }

	SquareCicle& operator=(const Square& sq)
	{
		Square::operator=(sq);
		Inscribed();
		return *this;
	}

	SquareCicle& operator=(const Cicle& c)
	{
		Cicle::operator=(c);
		Inscribed();
		return *this;
	}

	SquareCicle& operator()(const Square& sq, const Cicle& c)
	{
		Square::operator=(sq);
		Cicle::operator=(c);
		Inscribed();
		return *this;
	}

	void Print()
	{
		if (inscribed > 0)
			cout << "\t|SQUARE INSCRIBED IN CICLE|\n";
		else if (inscribed < 0)
			cout << "\t|CICLE INSCRIBED IN SQUARE|\n";
		else
			cout << "\t|NO ONE INSCRIBED|\n";
		Cicle::Print();
		Square::Print();
	}
};