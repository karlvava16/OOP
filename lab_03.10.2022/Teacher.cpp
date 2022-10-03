#include "Teacher.h"
#include <iostream>
using namespace std;

Teacher::Teacher() : Person()
{
	school = nullptr;
}

Teacher::Teacher(const char* n, int a, const char* s) : Person(n, a)
{
	if (s == nullptr)
		return;
	school = new char[strlen(s) + 1];
	strcpy_s(school, strlen(s) + 1, s);
}

Teacher::Teacher(const Teacher& t) : Teacher(t.name, t.age, t.school) {}

Teacher::~Teacher()
{
	delete[] school;
}

Teacher& Teacher::operator=(const Teacher& t)
{
	if (this == &t)
		return *this;
	if (name != nullptr)
		delete[] name;
	if (school != nullptr)
		delete[] school;
	if (t.name == nullptr)
		name = nullptr;
	else
	{
		name = new char[strlen(t.name) + 1];
		strcpy_s(name, strlen(t.name) + 1, t.name);
	}
	if (t.school == nullptr)
		school = nullptr;
	else
	{
		school = new char[strlen(t.school) + 1];
		strcpy_s(school, strlen(t.school) + 1, t.school);
	}
	age = t.age;
	return *this;
}

void Teacher::Print()
{
	Person::Print();
	cout << "school: " << school << endl;
}
