#include<iostream>
#include<Windows.h>
using namespace std;
// Тема: Константные методы, explicit конструктора

class Car
{
	char* model;
	int year;
	mutable double price;
public:
	Car(const char* mod, int y)
	{
		cout << "Constructor by 2 params\n";
		model = new char[strlen(mod) + 1];
		strcpy_s(model, strlen(mod) + 1, mod);
		year = y;
	}


	Car(const Car& temp) // copy constructor
	{
		model = new char[strlen(temp.model) + 1];
		strcpy_s(model, strlen(temp.model) + 1, temp.model);
		year = temp.year;
		cout << "Copy constructor\n";
	}
	~Car()
	{
		cout << "Destructor\n";
		delete[]model;
		Sleep(2000);
	}

	void operator()() const
	{
		cout << model << endl << year << endl;
	}

	Car& operator=(const Car& obj)
	{
		if (this == &obj)
			return *this;
		if (model != nullptr)
			delete[] model;
		model = new char[strlen(obj.model) + 1];
		strcpy_s(model, strlen(obj.model) + 1, obj.model);
		year = obj.year;
		price = obj.price;
	}

	operator int() const
	{
		return year;
	}

	operator char* () const
	{
		char* temp = new char[strlen(model) + 1];
		strcpy_s(temp, strlen(model) + 1, model);
		return temp;
	}

	int GetYear() const // const Car * const this;
	{
		//price = 0;
		//year = 0;
		return year;
	}
	void SetYear(int y)
	{
		year = y;
	}
};

int main()
{
	Car obj1("Audi", 2021);
	//cout << obj1.GetYear()<< endl;// 2021
	obj1();
	cout << endl << endl;


	const Car obj2("BMW", 2004);
	obj2();
	cout << endl;
	cout << "Year : " << int(obj2);
	cout << endl << endl;

	Car obj3("Mercedes", 2000);
	obj3();
	char* a = obj3;
	a[0] = 'Y';
	cout << a << endl;
	obj3();
	cout << endl << endl;

}

