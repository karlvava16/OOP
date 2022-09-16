#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	//Test class Mysrting

	MyString str1("Karl");
	MyString str2;
	MyString str3;
	str3 = str2 = str1;

	cout << "Str1 : ";
	str1();
	cout << "Str2 : ";
	str2();
	cout << "Str3 : ";
	str3();
	cout << endl;
	
	cout << "str1[2] : " << str1[2] << endl;
	cout << "int(str2) : " << int(str2) << endl;
	cout << "(const char*)str3 : " << (const char*)str3 << endl;
	return 0;
}

			//RESULT

/*
Str1 : Karl
Str2 : Karl
Str3 : Karl

str1[2] : r
int(str2) : 4
(const char*)str3 : Karl

*/