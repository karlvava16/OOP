#pragma once
#include "Vehicle.h"


namespace truck
{
	using namespace vehicle;

	class Truck : public Vehicle
	{
		double goods_amount;
		double max_goods;

	public:
		Truck(int people, int max_goods, double petrol, double max_petrol) : Vehicle(petrol, max_petrol)
		{
			if (max_goods >= 0)
				this->max_goods = max_goods;
			else
				this->max_goods = 0;
			if (people < 0)
				this->goods_amount = 0;
			else if (people <= this->max_goods)
				this->goods_amount = people;
			else
				this->goods_amount = this->max_goods;
		}

		double getCurrentLoad() const { return goods_amount; }

		double getMaxPeople() const { return max_goods; }

		bool arrive() final
		{
			if (Vehicle::arrive())
			{
				goods_amount += Base::GetGoods(-goods_amount);
				return true;
			}
			return false;
		}

		bool leave() final
		{
			if (Vehicle::leave())
			{
				goods_amount = Base::GetGoods(max_goods - goods_amount);
				return true;
			}
			return false;
		}

		void Info() final
		{
			cout << "|Truck|\n";
			Vehicle::Info();
			cout << "Goods: " << goods_amount << endl;
			cout << "Max Goods: " << max_goods << endl;
		}

	};
}