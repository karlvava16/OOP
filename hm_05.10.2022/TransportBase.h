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

	virtual void SetModel(const string& model)
	{
		this->model = model;
	}

	virtual void SetConsumption(double consumption)
	{
		if (consumption <= this->fuel)
			this->consumption = consumption;
	}

	virtual void SetFuel(double fuel)
	{
		if (fuel > 0)
			this->fuel = fuel;
	}

	virtual void Input() = 0;

	virtual void Info() = 0;

	virtual void Move(double value = 1.f) = 0;
};
