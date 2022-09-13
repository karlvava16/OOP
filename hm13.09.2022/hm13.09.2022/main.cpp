#include <iostream>
#include "Payment.h"
using namespace std;

int main()
{
	Payment p1("Vladyslav Karlinskyi", "13.09.2022", 22, 13, 10000, 18, 1, 10);
	p1.Print();

	const Payment p2(p1);
	p2.Print();

	cout << endl << "My name : " << p2.GetnNameSurname() << endl << endl;

	Payment p3;
	p3.Enter();
	p3.Print();

	return 0;
}

// |RESULT|

/*
Name : Vladyslav Karlinskyi
Hiring date : 13.09.2022
Month Salary : 10000
Work days : 22
Worked days : 13
Income tax : 18%
Pension fund : 1%
Allowance : 10%
Accrued : 5909.09
Withheld : 531.818
Final payment : 5377.27

Name : Vladyslav Karlinskyi
Hiring date : 13.09.2022
Month Salary : 10000
Work days : 22
Worked days : 13
Income tax : 18%
Pension fund : 1%
Allowance : 10%
Accrued : 5909.09
Withheld : 531.818
Final payment : 5377.27


My name : Vladyslav Karlinskyi

		|Enter|

Enter name, surname : karl
Enter hire date : 12.12.2004
Enter work days amount : 26
Enter worked days : 31
Enter month salary : 50000
Enter income tax (%) : 18
Enter pension fund (%) : 2
Enter allowance (%) : 15

Name : karl
Hiring date : 12.12.2004
Month Salary : 50000
Work days : 25
Worked days : 25
Income tax : 18%
Pension fund : 2%
Allowance : 15%
Accrued : 50000
Withheld : 2500
Final payment : 47500
*/