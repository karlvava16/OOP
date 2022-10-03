#pragma once
class Person
{
protected:
	char* name;
	int age;

public:
	Person();
	Person(const char* n, int a);

	Person(const Person& p);
	~Person();
	Person& operator=(const Person& p);

	void Print();
};

