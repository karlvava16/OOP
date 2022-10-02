#include <iostream>
#include "Passport.h"
#include "ForeignPassport.h";
using namespace std;

int main()
{

	Passport passport;

	// Input Example (copy and paste in cmd)
	//Vladyslav Karlinskyi M Odessa/UKR UKR 20040123-12345 012345678 0123 23 01 2004 23 01 2032 23 01 2022
	cin >> passport;
	cout << endl;
	passport.Print();
	ForeignPassport fp('T', "UKR", passport);
	cout << endl << endl;

	fp.SetAuthority("3201");
	fp.SetDocumentNo("876543210");
	fp.Print();

	return 0;
}

/*RESULT*/

/*
Vladyslav Karlinskyi M Odessa/UKR UKR 20040123-12345 012345678 0123 23 01 2004 23 01 2032 23 01 2022

Name : Vladyslav
Surname : Karlinskyi
Sex : M
Place of birth : Odessa/UKR
Nationality : UKR
RecordNo. : 20040123-12345
DocumentNo. : 012345678
Authority : 0123
Date of birth : 23.01.2004
Date of exiry : 23.01.2032
Date of issue : 23.01.2022


Type : T
Country code : UKR
Name : Vladyslav
Surname : Karlinskyi
Sex : M
Place of birth : Odessa/UKR
Nationality : UKR
RecordNo. : 20040123-12345
DocumentNo. : 876543210
Authority : 3201
Date of birth : 23.01.2004
Date of exiry : 23.01.2032
Date of issue : 23.01.2022

*/