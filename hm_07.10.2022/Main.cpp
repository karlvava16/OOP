#include <iostream>
#include "AnimalBasic.h"
#include "Rabbit.h"
#include "Fox.h"
#include "Field.h";
using namespace std;

int main()
{
	srand(time(0));
	Field a;
	while (true)
	{
		a.Info();
		cin.get();
		a.NextYear();
	}
	return 0;
}


/*RESULT*/

/*
|Next Year|
Grass eated by rabbits
Foxs: 22
Rabbits: 17
Grass: 0



|Next Year|
Rabbits eated by foxs
Foxs: 22
Rabbits: 0
Grass: 13
*/