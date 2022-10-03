#include "Person.h"
#include <iostream>
using namespace std;

Person::Person()
{
	name = nullptr;
	age = 0;
}

Person::Person(const char* n, int a) : Person()
{
	if (n == nullptr)
		return;
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
	age = a;
}

Person::Person(const Person& p) : Person(p.name, p.age) {}

Person::~Person()
{
	delete[]name;
}

Person& Person::operator=(const Person& p)
{
	if (this == &p)
		return *this;
	if (name != nullptr)
		delete[] name;
	if (p.name == nullptr)
		name = nullptr;
	else
	{
		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);
	}
	age = p.age;
	return *this;
}

void Person::Print()
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
}
