#pragma once
#include "TransportBase.h"

class Jeep : public TransportBase
{
public:
	Jeep() : TransportBase() {}
	Jeep(const string& model) : TransportBase(model) {}
	Jeep(const string& model, double fuel) : TransportBase(model, fuel) {}
	Jeep(const string& model, double fuel, double consumption) : TransportBase(model, fuel, consumption) {}

	void Input()
	{
		cout << "\t|JEEP INPUT|\n";
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
		cout << "\t|JEEP INFO|\n";
		cout << "Model: " << model << endl;
		cout << "Fuel: " << fuel << endl;
		cout << "Consumption: " << consumption << endl;
		cout << endl;
	}

	void Move(double value = 1.f)
	{
		if (value * consumption < fuel)
		{
			cout << "\t|DRIVE JEEP|\n";
			fuel -= value * consumption;
			cout << "Fuel left: " << fuel << endl;
		}
		else
		{
			cout << "\t|CAN'T DRIVE JEEP (FUEL IS LOW)|\n";
		}
		cout << endl;
	}
};
