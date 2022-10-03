#pragma once
#include "Person.h"
class Teacher : public Person
{
	char* school;

public:

	Teacher();
	Teacher(const char* n, int a, const char* s);
	Teacher(const Teacher& t);
	~Teacher();
	Teacher& operator=(const Teacher& t);

	void Print();
};

