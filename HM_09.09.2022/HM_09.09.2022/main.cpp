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
	static int count;
public:
	Student():step(0), book(nullptr, 0) 
	{
		count++;
		name = new char[1];
		name[0] = '\0';
	}
	Student(const char* n, double st, const char* bookName, int bookPages);// использовать инициализаторы!!!
	~Student();
	void Print();
	static int GetCount();

};

int Student::count = 0;

int Student::GetCount()
{
	return count;
}

Student::Student(const char* n, double st, const char* bookName, int bookPages) : step(st), book(bookName, bookPages)
{
	count++;
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}

Student::~Student()
{
	count--;
	delete[]name;
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
	cout << "Count : " << Student::GetCount() << endl << endl;

	Student st;
	st.Print();
	cout << endl;

	cout << "Count : " << Student::GetCount() << endl << endl;


	Student st2("Vladyslav Karlinskyi", 2123.23, "OOP by using c++", 256);
	st2.Print();
	cout << endl;

	cout << "Count : " << Student::GetCount() << endl << endl;


}

/*Result*/

//Count: 0
//
//Student name :
//Step: 0
//| BOOK | Name :
//Pages : 0
//
//Count : 1
//
//Student name : Vladyslav Karlinskyi
//Step : 2123.23
//| BOOK | Name : OOP by using c++
//Pages : 256
//
//Count : 2

