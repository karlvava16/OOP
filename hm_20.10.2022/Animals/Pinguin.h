#pragma once
#include "Animal.h"

class Pinguin : public Animal, public ISwim
{
public:
	Pinguin() : Animal() {}
	Pinguin(string n, double k, string cont) : Animal(n, k, cont) {}
	virtual void Eat() final
	{
		cout << "Pinguin Eat\n";
	}
	virtual void Move() final
	{
		cout << "Pinguin Move\n";
	}
	virtual void Swim() final
	{
		cout << "Pinguin Swim\n";
	}

	virtual void Print()
	{
		cout << "\t|Pinguin|" << endl;
		cout << "Name: " << name << endl;
		cout << "KG: " << kg << endl;
		cout << "Continent: " << continent << endl;
	}
};