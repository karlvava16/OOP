#pragma once
#include "Animal.h"

class Dolphin : public Animal, public ISwim
{
public:
	Dolphin() : Animal() {}
	Dolphin(string n, double k, string cont) : Animal(n, k, cont) {}
	virtual void Eat() final
	{
		cout << "Dolphin Eat\n";
	}
	virtual void Move() final
	{
		cout << "Dolphin Move\n";
	}
	virtual void Swim() final
	{
		cout << "Dolphin Swim\n";
	}
	virtual void Print()
	{
		cout << "\t|Dolphin|" << endl;
		cout << "Name: " << name << endl;
		cout << "KG: " << kg << endl;
		cout << "Continent: " << continent << endl;
	}
};