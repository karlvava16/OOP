#include <iostream>
#include "shared_ptr.h"
using namespace std;

class Foo
{
private:

	int m_number;

public:
	Foo(int number) : m_number(number)
	{
	}

	int GetNumber()
	{
		return m_number;
	}
};

my::shared_ptr<Foo> Test(my::shared_ptr<Foo> obj)
{
	cout << "Test: " << obj.use_count() << endl;

	return obj;
}

int main()
{
	my::shared_ptr<Foo> p1(new Foo(5));
	my::shared_ptr<Foo> p2;

	p2 = p1;
	cout << p1.use_count() << endl;
	cout << p2.get() << ' ' << p2.get()->GetNumber() << endl;
	//cout << p1.get() << ' ' << p1.get()->GetNumber() << endl;
	my::shared_ptr<Foo>rez = Test(p1);
	cout << "Main: " << rez.use_count() << endl;
	cout << "GetNumber() " << rez.get()->GetNumber() << endl;

	return 0;
}


/*RESULT*/

/*
2
00000199707A6100 5
Test: 3
Main: 3
GetNumber() 5
*/