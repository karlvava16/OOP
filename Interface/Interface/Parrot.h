#pragma once
#include "Animal.h"

class Parrot : public Animal, public IFly // ������������ 
{
public:
	Parrot() = default;
	Parrot(string n, double k, string cont) :Animal(n, k, cont) {}

	// ----- ���������� ���������� IANIMAL !!!

	virtual void Eat()
	{
		cout << "Parrot Eat\n";
	}
	virtual void Move()
	{
		cout << "Parrot Move\n";
	}
	// ----- ���������� ���������� IFLY !!!
	virtual void Fly()
	{
		cout << "Parrot Fly\n";
	}

};