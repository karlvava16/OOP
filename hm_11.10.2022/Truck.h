#pragma once
#include "TransportBase.h"

namespace truck
{
	using namespace transport;

	class Truck : public TransportBase
	{
		char* driver;
	public:
		Truck() : driver(nullptr), TransportBase() {}
		Truck(const string& model) : driver(nullptr), TransportBase(model) {}
		Truck(const char* model, double fuel) : driver(nullptr), TransportBase(model, fuel) {}
		Truck(const string& model, double fuel, double consumption) : driver(nullptr), TransportBase(model, fuel, consumption) {}
		Truck(const string& model, double fuel, double consumption, const char* driver) : TransportBase(model, fuel, consumption)
		{
			this->driver = new char[strlen(driver) + 1];
			strcpy_s(this->driver, strlen(driver) + 1, driver);
		}
		void Input()
		{
			cout << "\t|TRUCK INPUT|\n";
			cout << "Model: ";
			cin >> model;
			cout << "Fuel: ";
			cin >> fuel;
			cout << "Consumption: ";
			cin >> consumption;
			cout << "Driver: ";
			string temp;
			cin >> temp;
			if (driver != nullptr)
				delete[] driver;
			driver = new char[strlen(temp.c_str()) + 1];
			strcpy_s(driver, strlen(temp.c_str()) + 1, temp.c_str());
			cout << endl;
		}

		void Info()
		{
			cout << "\t|TRUCK INFO|\n";
			cout << "Model: " << model << endl;
			cout << "Fuel: " << fuel << endl;
			cout << "Consumption: " << consumption << endl;
			cout << "Driver: " << driver << endl;
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

		~Truck()
		{
			cout << "[Truck destructor]\n";
			delete[] driver;
		}
	};
}


