#pragma once
#include "TransportBase.h"

class Truck : public TransportBase
{
public:
	Truck() : TransportBase() {}
	Truck(const string& model) : TransportBase(model) {}
	Truck(const string& model, double fuel) : TransportBase(model, fuel) {}
	Truck(const string& model, double fuel, double consumption) : TransportBase(model, fuel, consumption) {}

	void Input()
	{
		cout << "\t|TRUCK INPUT|\n";
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
		cout << "\t|TRUCK INFO|\n";
		cout << "Model: " << model << endl;
		cout << "Fuel: " << fuel << endl;
		cout << "Consumption: " << consumption << endl;
		cout << endl;
	}

	void Move(double value = 1.f)
	{
		if (value * consumption < fuel)
		{
			cout << "\t|DRIVE TRUCK|\n";
			fuel -= value * consumption;
			cout << "Fuel left: " << fuel << endl;
		}
		else
		{
			cout << "\t|CAN'T DRIVE TRUCK (FUEL IS LOW)|\n";
		}
		cout << endl;
	}
};
