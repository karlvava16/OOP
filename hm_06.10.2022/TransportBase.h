#pragma once
#include <iostream>
using namespace std;

class TransportBase
{
protected:
	string model; // модель
	double fuel; // топливо
	double consumption; // расход

public:
	TransportBase() : model(""), fuel(0), consumption(0) {}

	TransportBase(const string& model) : TransportBase()
	{
		this->model = model;
	}

	TransportBase(const string& model, double fuel) : TransportBase(model)
	{
		if (fuel > 0) 
			this->fuel = fuel; 
	}

	TransportBase(const string& model, double fuel, double consumption) : TransportBase(model, fuel) 
	{
		if (consumption <= this->fuel)
			this->consumption = consumption;
	}

	void SetModel(const string& model)
	{
		this->model = model;
	}

	void SetConsumption(double consumption)
	{
		if (consumption <= this->fuel)
			this->consumption = consumption;
	}

	void SetFuel(double fuel)
	{
		if (fuel > 0)
			this->fuel = fuel;
	}

	virtual void Input()
	{
		cout << "\t|BASE INPUT|\n";
		cout << "Model: ";
		cin >> model;
		cout << "Fuel: ";
		cin >> fuel;
		cout << "Consumption: ";
		cin >> consumption;
		cout << endl;
	}

	virtual void Info() { cout << "\t|Base class TransportBase|\n"; }

	virtual void Move(double value = 1.f) { cout << "\t|Can't move. Base class TransportBase.|\n"; }

	virtual ~TransportBase() = 0
	{
		cout << "[TransportBase destructor]\n";
	}
};
