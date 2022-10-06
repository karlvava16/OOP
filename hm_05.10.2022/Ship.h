#pragma once
#include "TransportBase.h"

class Ship : public TransportBase
{
public:
	Ship() : TransportBase() {}
	Ship(const string& model) : TransportBase(model) {}
	Ship(const string& model, double fuel) : TransportBase(model, fuel) {}
	Ship(const string& model, double fuel, double consumption) : TransportBase(model, fuel, consumption) {}

	void Input()
	{
		cout << "\t|SHIP INPUT|\n";
		cout << "Model: ";
		cin >> model;
		cout << "Fuel: ";
		cin >> fuel;
		cout << "Consumption: ";
		cin >> consumption;
		cout << endl;
	}

	void Info()
	{
		cout << "\t|SHIP INFO|\n";
		cout << "Model: " << model << endl;
		cout << "Fuel: " << fuel << endl;
		cout << "Consumption: " << consumption << endl;
		cout << endl;
	}

	void Move(double value = 1.f)
	{
		if (value * consumption < fuel)
		{
			cout << "\t|SAIL SHIP|\n";
			fuel -= value * consumption;
			cout << "Fuel left: " << fuel << endl;
		}
		else
		{
			cout << "\t|CAN'T SALE SHIP (FUEL IS LOW)|\n";
		}
		cout << endl;
	}
};
