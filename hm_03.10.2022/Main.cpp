#include <iostream>
#include "Cicle.h"
#include "Square.h"
#include "SquareCicle.h"
using namespace std;

int main()
{
	Square sq = 12;
	Cicle c = 6;
	SquareCicle sqc(sq, c);
	sq.Print();
	c.Print();
	cout << endl;
	sqc.Print();
	return 0;
}


/*RESULT*/

/*
		|Square|
L = 48
D = 16.9706
S = 144
		|Cicle|
R = 37.6991
D = 12
S = 59.2176

		|CICLE INSCRIBED IN SQUARE|
		|Cicle|
R = 37.6991
D = 12
S = 59.2176
		|Square|
L = 48
D = 16.9706
S = 144
*/