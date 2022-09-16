#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
	Date A(23, 01, 2004);
	Date B(31, 12, 2003);
	cout << "Date A : ";
	A.Print();
	cout << "Date B : ";
	B.Print();
	cout << endl;

	cout << "|Switch format|" << endl << endl;
	Date::SwitchFormat();

	cout << "CONST Date C : ";
    const Date C(15,9,2022);
	C.Print();
	cout << "Date D (B + 2) : ";
	Date D = B + 2;
	D.Print();
	cout << endl;

	cout << "A - B : " << A - B << endl;
	cout << "A - C : " << A - C << endl;
	cout << "A == B : " << (A == B) << endl;
	cout << "A < B : " << (A < B) << endl;
	cout << endl;

	cout << "|Switch format|" << endl << endl;
	Date::SwitchFormat();

	cout << "Set A day with 32 : ";
	A.SetDay(32);
	A.Print();

	cout << "Date E (2 + B) : ";
	Date E = 2 + B;
	E.Print();
	cout << endl;


	return 0;
}


// RESULT

/*
Date A : 23.01.2004
Date B : 31.12.2003

|Switch format|

CONST Date C : 3/1/2004
CONST Date D : 01/02/2004

A - B : 23
A - C : 38
A == B : 0
A < B : 0

Set A day with 32 : 2/1/2004
*/