#pragma once
#include "Animal.h"

class Dog : public Animal
{
public:
	Dog() = default;
	Dog(string n, double k, string cont) : Animal(n, k, cont) {}
	virtual void Eat() final
	{
		cout << "Dog Eat\n";
	}
	virtual void Move() final
	{
		cout << "Dog Move\n";
	}
};