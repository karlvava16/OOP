#pragma once
#include "TransportBase.h"

class Ship : public TransportBase
{
	char* captain;
public:
	Ship() : captain(nullptr), TransportBase() {}
	Ship(const string& model) : captain(nullptr), TransportBase(model) {}
	Ship(const char* model, double fuel) : captain(nullptr), TransportBase(model, fuel) {}
	Ship(const string& model, double fuel, double consumption) : captain(nullptr), TransportBase(model, fuel, consumption) {}
	Ship(const string& model, double fuel, double consumption, const char* captain) : TransportBase(model, fuel, consumption)
	{
		this->captain = new char[strlen(captain) + 1];
		strcpy_s(this->captain, strlen(captain) + 1, captain);
	}
	void Input()
	{
		cout << "\t|SHIP INPUT|\n";
		cout << "Model: ";
		cin >> model;
		cout << "Fuel: ";
		cin >> fuel;
		cout << "Consumption: ";
		cin >> consumption;
		cout << "Captain: ";
		string temp;
		cin >> temp;
		if (captain != nullptr)
			delete[] captain;
		captain = new char[strlen(temp.c_str()) + 1];
		strcpy_s(captain, strlen(temp.c_str()) + 1, temp.c_str());
		cout << endl;
	}

	void Info()
	{
		cout << "\t|SHIP INFO|\n";
		cout << "Model: " << model << endl;
		cout << "Fuel: " << fuel << endl;
		cout << "Consumption: " << consumption << endl;
		cout << "Captain: " << captain << endl;
		cout << endl;
	}

	void Move(double value = 1.f)
	{
		if (value * consumption < fuel)
		{
			cout << "\t|DRIVE SHIP|\n";
			fuel -= value * consumption;
			cout << "Fuel left: " << fuel << endl;
		}
		else
		{
			cout << "\t|CAN'T DRIVE SHIP (FUEL IS LOW)|\n";
		}
		cout << endl;
	}

	~Ship()
	{
		cout << "[Ship destructor]\n";
		delete[] captain;
	}
};
