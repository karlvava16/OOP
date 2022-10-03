#pragma once
#include "Person.h"
class Student : public Person
{
	char* academy;

public:

	Student();
	Student(const char* n, int a, const char* acad);
	Student(const Student& st);
	~Student();
	Student& operator=(const Student& st);

	void Print();
};

