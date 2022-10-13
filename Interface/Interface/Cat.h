#pragma once
#include "Animal.h"

class Cat : public Animal
{
public:
	Cat() = default;
	Cat(string n, double k, string cont) : Animal(n, k, cont) {}
	virtual void Eat() final
	{
		cout << "Cat Eat\n";
	}
	virtual void Move() final
	{
		cout << "Cat Move\n";
	}
};