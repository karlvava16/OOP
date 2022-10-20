#pragma once
#include<iostream>
#include"MyInterface.h"
using namespace std;

class Animal: public IAnimal // реализация интерфеса
{
protected:
	string name;
	double kg;
	string continent;
public:
	Animal() : name(""), kg(0.f), continent("") {}
	Animal(string n, double k, string cont)
	{
		name = n;
		kg = k;
		continent = cont;
	}
	virtual void Print()
	{
		cout << "\t|Animal|" << endl;
		cout << "Name: " << name << endl;
		cout << "KG: " << kg << endl;
		cout << "Continent: " << continent << endl;
	}

	void SetName(const char* name)
	{
		this->name = name;
	}

	void SetKg(double kg)
	{
		this->kg = kg;
	}

	void SetContinent(const char* continent) { this->continent = continent; }

	const char* GetName() const { return name.c_str(); }

	double GetKg() const { return kg; }

	const char* GetContinent() const { return continent.c_str(); }

	//virtual void Eat() = 0;
	//virtual void Move() = 0;	
};


