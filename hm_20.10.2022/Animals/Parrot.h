#pragma once
#include "Animal.h"

class Parrot : public Animal, public IFly // наследование 
{
public:
	Parrot() : Animal() {}
	Parrot(string n, double k, string cont) :Animal(n, k, cont) {}

	// ----- реализация ИНТЕРФЕЙСА IANIMAL !!!

	virtual void Eat()
	{
		cout << "Parrot Eat\n";
	}
	virtual void Move()
	{
		cout << "Parrot Move\n";
	}
	// ----- реализация ИНТЕРФЕЙСА IFLY !!!
	virtual void Fly()
	{
		cout << "Parrot Fly\n";
	}

	virtual void Print()
	{
		cout << "\t|Parrot|" << endl;
		cout << "Name: " << name << endl;
		cout << "KG: " << kg << endl;
		cout << "Continent: " << continent << endl;
	}
};