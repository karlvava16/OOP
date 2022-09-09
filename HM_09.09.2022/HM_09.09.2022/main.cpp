#include<iostream>
using namespace std;

class Book
{
	char* name;
	int pages;
public:
	Book(const char* n);
	Book(const char* n, int p); // реализовать делегирование!!!
	void Print();
	~Book();
};

Book::Book(const char* n) : pages(0)
{
	if (n != nullptr)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	else
	{
		name = new char[1];
		name[0] = '\0';
	}
}

Book::Book(const char* n, int p) : Book(n) 
{
	pages = p;
}

Book::~Book()
{
	delete[] name;
}

void Book::Print()
{
	cout << "Name : " << name << endl;
	cout << "Pages : " << pages << endl;
}


class Student
{
	char* name;
	const double step;// !!
	Book book; //!!!
public:
	Student():step(0), book(nullptr, 0) 
	{
		name = new char[1];
		name[0] = '\0';
	}
	Student(const char* n, double st, const char* bookName, int bookPages);// использовать инициализаторы!!!
	~Student();
	void Print();

};

Student::Student(const char* n, double st, const char* bookName, int bookPages) : step(st), book(bookName, bookPages)
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}

Student::~Student()
{
	if (name != nullptr)
	{
		delete[]name;
	}
}

void Student::Print()
{
	cout << "Student name : " << name << endl;
	cout << "Step : " << step << endl;
	cout << "|BOOK|";
	book.Print();
}


// показать использование объектом в функции main
int main()
{
	Student st;
	st.Print();
	cout << endl;

	Student st2("Vladyslav Karlinskyi", 2123.23, "OOP by using c++", 256);
	st2.Print();
}

