#pragma once
#include "TransportBase.h"

class Bicycle : public TransportBase
{
public:
	Bicycle() : TransportBase() {}
	Bicycle(const string& model) : TransportBase(model) {}
	
	void Input()
	{
		cout << "\t|BICYCLE INPUT|\n";
		cout << "Model: ";
		cin >> model;
		cout << endl;
	}

	void Info()
	{
		cout << "\t|BICYCLE INFO|\n";
		cout << "Model: " << model << endl;
		cout << endl;
	}

	void Move(double value = 1.f)
	{
		cout << "\t|RIDE BICYCLE|\n";
	}

	void SetConsumption(double consumption) {}

	void SetFuel(double fuel) {}
};
