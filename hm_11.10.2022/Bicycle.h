#pragma once
#include "TransportBase.h"

namespace bicycle
{
	using namespace transport;


	class Bicycle : public TransportBase
	{
		char* name;

	public:
		Bicycle() : name(nullptr), TransportBase() {}
		Bicycle(const string& model) : name(nullptr), TransportBase(model) {}
		Bicycle(const string& model, const char* name) : TransportBase(model)
		{
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
		}


		void Input()
		{
			cout << "\t|BICYCLE INPUT|\n";
			cout << "Model: ";
			cin >> model;
			cout << "Name: ";
			string temp;
			cin >> temp;
			if (name != nullptr)
				delete[] name;
			name = new char[strlen(temp.c_str()) + 1];
			strcpy_s(name, strlen(temp.c_str()) + 1, temp.c_str());
			cout << endl;
		}

		void Info()
		{
			cout << "\t|BICYCLE INFO|\n";
			cout << "Model: " << model << endl;
			cout << "Name: " << name << endl;
			cout << endl;
		}

		void Move(double value = 1.f)
		{
			cout << "\t|RIDE BICYCLE|\n";
		}

		void SetConsumption(double consumption) {}

		void SetFuel(double fuel) {}

		~Bicycle()
		{
			cout << "[Bicycle destructor]\n";
			delete[] name;
		}

	};
}
