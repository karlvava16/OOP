#pragma once
#include "Animal.h"

class Cat : public Animal
{
public:
	Cat() : Animal() {}
	Cat(string n, double k, string cont) : Animal(n, k, cont) {}
	virtual void Eat() final
	{
		cout << "Cat Eat\n";
	}
	virtual void Move() final
	{
		cout << "Cat Move\n";
	}
	virtual void Print()
	{
		cout << "\t|Cat|" << endl;
		cout << "Name: " << name << endl;
		cout << "KG: " << kg << endl;
		cout << "Continent: " << continent << endl;
	}
};