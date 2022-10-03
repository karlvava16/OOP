#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() : Person()
{
	academy = nullptr;
}

Student::Student(const char* n, int a, const char* acad) : Person(n, a)
{
	academy = nullptr;
	if (acad == nullptr)
		return;
	academy = new char[strlen(acad) + 1];
	strcpy_s(academy, strlen(acad) + 1, acad);
}

Student::Student(const Student& st) : Student(st.name, st.age, st.academy) {}

Student::~Student()
{
	delete[] academy;
}

Student& Student::operator=(const Student& st)
{
	if (this == &st)
		return *this;
	if (name != nullptr)
		delete[] name;
	if (academy != nullptr)
		delete[] academy;
	if (st.name == nullptr)
		name = nullptr;
	else
	{
		name = new char[strlen(st.name) + 1];
		strcpy_s(name, strlen(st.name) + 1, st.name);
	}
	if (st.academy == nullptr)
		academy = nullptr;
	else
	{
		academy = new char[strlen(st.academy) + 1];
		strcpy_s(academy, strlen(st.academy) + 1, st.academy);
	}
	age = st.age;
	return *this;
}

void Student::Print()
{
	Person::Print();
	cout << "Academy: " << academy << endl;
}
