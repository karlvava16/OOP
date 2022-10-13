#pragma once
#include "Animal.h"

class Pinguin : public Animal, public ISwim
{
public:
	Pinguin() = default;
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
};