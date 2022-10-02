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