#include <iostream>
#include "Bus.h"
#include "Truck.h"

using namespace std;

int main()
{
	bus::Bus bus(0, 20, 0, 5);
	bus.Info();
	cout << endl;

	base::Base::Print();
	cout << endl;

	bus.leave();

	base::Base::Print();
	cout << endl;

	bus.Info();
	cout << endl;

	bus.arrive();

	base::Base::Print();
	cout << endl;

	bus.Info();
	cout << endl;
	return 0;
}

/*RESULT*/

/*
|Bus|
On The Base: true
Petrol: 0
Tank Volume: 5
People: 0
Max People: 20

		|Base|
People: 15
Vehicles: 1
Petrol: 2000
Goods: 100

		|Base|
People: 0
Vehicles: 0
Petrol: 1995
Goods: 100

|Bus|
On The Base: false
Petrol: 5
Tank Volume: 5
People: 14
Max People: 20

		|Base|
People: 15
Vehicles: 1
Petrol: 1995
Goods: 100

|Bus|
On The Base: true
Petrol: 1.25
Tank Volume: 5
People: 0
Max People: 20
*/