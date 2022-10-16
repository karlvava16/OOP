#pragma once
#include <iostream>
using namespace std;

namespace base
{
	class Base
	{
		static int people_on_base;
		static int vehicles_on_base;
		static double petrol_on_base;
		static double goods_on_base;

	public:

		static int GetPeople(int people) 
		{
			if (people < people_on_base)
				people_on_base -= people;
			else
			{
				people = people_on_base;
				people_on_base = 0;
			}
			return people;
		}
		static double GetPetrol(double petrol)
		{
			if (petrol < petrol_on_base)
				petrol_on_base -= petrol;
			else
			{
				petrol = petrol_on_base;
				petrol_on_base = 0.f;
			}
			return petrol;
		}
		static double GetGoods(double goods)
		{
			if (goods < goods_on_base)
				goods_on_base -= goods;
			else
			{
				goods = goods_on_base;
				goods_on_base = 0;
			}
			return goods;
		}

		static int GetPeople() { return people_on_base; }
		static int GetVehicles() { return vehicles_on_base; }
		static double GetPetrol() { return petrol_on_base; }
		static double GetGoods() { return goods_on_base; }

		static void SetPeople(int people)
		{
			if (people > 0)
				people_on_base = people;
			else
				people_on_base = 0;
		}
		static void SetVehicles(int vihicles)
		{
			if (vihicles > 0)
				vehicles_on_base = vihicles;
			else
				vehicles_on_base = 0;
		}
		static void SetPetrol(double petrol)
		{
			if (petrol > 0.f)
				petrol_on_base = petrol;
			else
				petrol_on_base = 0.f;
		}
		static void SetGoods(double goods) 
		{
			if (goods > 0.f)
				goods_on_base = goods;
			else
				goods_on_base = 0.f;
		}


		static void Print()
		{
			cout << "\t|Base|\n";
			cout << "People: " << people_on_base << endl;
			cout << "Vehicles: " << vehicles_on_base << endl;
			cout << "Petrol: " << petrol_on_base << endl;
			cout << "Goods: " << goods_on_base << endl;
		}

		virtual ~Base() = 0;
	};

	int Base::people_on_base = 15;
	int Base::vehicles_on_base = 0;
	double Base::petrol_on_base = 2000;
	double Base::goods_on_base = 100;
}


