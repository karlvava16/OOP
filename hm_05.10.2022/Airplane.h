#pragma once
#include "TransportBase.h"

class Airplane : public TransportBase
{
public:
	Airplane() : TransportBase() {}
	Airplane(const string& model) : TransportBase(model) {}
	Airplane(const string& model, double fuel) : TransportBase(model, fuel) {}
	Airplane(const string& model, double fuel, double consumption) : TransportBase(model, fuel, consumption) {}

	void Input()
	{
		cout << "\t|AIRPLANE INPUT|\n";
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
		cout << "\t|AIRPLANE INFO|\n";
		cout << "Model: " << model << endl;
		cout << "Fuel: " << fuel << endl;
		cout << "Consumption: " << consumption << endl;
		cout << endl;
	}

	void Move(double value = 1.f)
	{
		if (value * consumption < fuel)
		{
			cout << "\t|FLY AIRPLANE|\n";
			fuel -= value * consumption;
			cout << "Fuel left: " << fuel << endl;
		}
		else
		{
			cout << "\t|CAN'T FLY AIRPLANE (FUEL IS LOW)|\n";
		}
		cout << endl;
	}
};
