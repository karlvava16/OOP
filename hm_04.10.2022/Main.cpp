#include <iostream>
#include <conio.h>
#include "Transports.h"

using namespace std;

int main()
{
	char choise = '0';

	TransportBase* ptr = nullptr;

	cout << "\t|Choose transport|\n";
	cout << "1. Airplane\n";
	cout << "2. Bicycle\n";
	cout << "3. Jeep\n";
	cout << "4. Ship\n";
	cout << "5. Truck\n";
	while (choise < '1' || choise > '5')
	{
		choise = _getch();
	}
	switch (choise)
	{
	case'1':
		ptr = new Airplane("Boing", 1000, 90);
		break;
	case'2':
		ptr = new Bicycle("Redline");
		break;
	case'3':
		ptr = new Jeep("JEEP", 5, 0.5);
		break;
	case'4':
		ptr = new Ship("Yamaha", 2.5, 0.4);
		break;
	case'5':
		ptr = new Truck("Boing", 30, 0.7);
		break;
	}

	ptr->Info();
	ptr->Move();

	delete[] ptr;

	return 0;
}


/*ONE OF RESULT VARIANT*/

/*
		|Choose transport|
1. Airplane
2. Bicycle
3. Jeep
4. Ship
5. Truck
		|AIRPLANE INFO|
Model: Boing
Fuel: 1000
Consumption: 90

		|FLY AIRPLANE|
Fuel left: 910
*/