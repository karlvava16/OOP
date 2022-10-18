#include <iostream>
#include "Reference.h"
using namespace std;
using namespace ref;

int main()
{
	Reference test("UNIS", "Vlad", "88005535", "Sadovaya", "SoftwareDev");
	Reference test2("Step", "Akimov", "123123214", "Sadovaya", "Admin");
	//test.Info();
	//SaveReference("save.txt", test);
	//SaveReference("save.txt", test2);
	ShowReference("save.txt");
	cout << endl;
	SearchCompanyName("save.txt", "Step");
	cout << endl;
	SearchOwner("save.txt", "Vlad");
	cout << endl;
	SearchPhoneNumber("save.txt", "12312");
	cout << endl;
	SearchAddress("save.txt", "Sadovaya");
	cout << endl;
	SearchMetier("save.txt", "Admin");
	cout << endl;

	return 0;
}