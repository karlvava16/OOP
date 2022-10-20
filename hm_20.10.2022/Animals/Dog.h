#pragma once
#include "Animal.h"

class Dog : public Animal
{
public:
	Dog() : Animal() {}
	Dog(string n, double k, string cont) : Animal(n, k, cont) {}
	virtual void Eat() final
	{
		cout << "Dog Eat\n";
	}
	virtual void Move() final
	{
		cout << "Dog Move\n";
	}
	virtual void Print()
	{
		cout << "\t|Dog|" << endl;
		cout << "Name: " << name << endl;
		cout << "KG: " << kg << endl;
		cout << "Continent: " << continent << endl;
	}
};