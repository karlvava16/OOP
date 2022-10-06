#pragma once
#include "TransportBase.h"

class Airplane : public TransportBase
{
	char* pilot;
public:
	Airplane() : pilot(nullptr), TransportBase() {}
	Airplane(const string& model) : pilot(nullptr), TransportBase(model) {}
	Airplane(const char* model, double fuel) : pilot(nullptr), TransportBase(model, fuel) {}
	Airplane(const string& model, double fuel, double consumption) : pilot(nullptr), TransportBase(model, fuel, consumption) {}
	Airplane(const string& model, double fuel, double consumption, const char* pilot) : TransportBase(model, fuel, consumption) 
	{
		this->pilot = new char[strlen(pilot) + 1];
		strcpy_s(this->pilot, strlen(pilot) + 1, pilot);
	}


	void Input()
	{
		cout << "\t|AIRPLANE INPUT|\n";
		cout << "Model: ";
		cin >> model;
		cout << "Fuel: ";
		cin >> fuel;
		cout << "Consumption: ";
		cin >> consumption;
		cout << "Pilot: ";
		string temp;
		cin >> temp;
		if (pilot != nullptr)
			delete[] pilot;
		pilot = new char[strlen(temp.c_str()) + 1];
		strcpy_s(pilot, strlen(temp.c_str()) + 1, temp.c_str());
		cout << endl;
	}

	void Info()
	{
		cout << "\t|AIRPLANE INFO|\n";
		cout << "Model: " << model << endl;
		cout << "Fuel: " << fuel << endl;
		cout << "Consumption: " << consumption << endl;
		cout << "Pilot: " << pilot << endl;
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

	 ~Airplane()
	{
		cout << "[Airplane destructor]\n";
		delete[] pilot;
	}
};

