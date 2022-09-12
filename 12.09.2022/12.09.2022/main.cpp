#include<iostream>
using namespace std;

class Person
{
public:
	Person(const char* n, const char* s, int a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		surname = new char[strlen(s) + 1];
		strcpy_s(surname, strlen(s) + 1, s);
		age = a;
	}

	Person(const Person& obj)
	{
		name = new char[strlen(obj.name) + 1];
		strcpy_s(name, strlen(obj.name) + 1, obj.name);
		surname = new char[strlen(obj.surname) + 1];
		strcpy_s(surname, strlen(obj.surname) + 1, obj.surname);
		age = obj.age;
	}

	void Print()
	{
		cout << "Name : " << name << endl;
		cout << "Surname : " << surname << endl;
		cout << "Age : " << age << endl << endl;
	}

	~Person()
	{
		delete[] name;
		delete[] surname;
	}

private:
	char* name;
	char* surname;
	int age;

};


int main()
{
	Person* p1 = new Person{ "Vladyslav", "Karlinskyi", 18 };
	cout << "|P1|" << endl;
	p1->Print();
	Person p2 = *p1;
	delete p1;
	cout << "|P2|" << endl;
	p2.Print();
	

}


//		RESULT

/*
|P1|
Name : Vladyslav
Surname : Karlinskyi
Age : 18

|P2|
Name : Vladyslav
Surname : Karlinskyi
Age : 18
*/