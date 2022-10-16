#pragma once
#include "Base.h"
#include <ostream>

namespace vehicle
{
	using namespace base;
	class Vehicle
	{
	protected:
		double petrol_amount;
		double tank_volume;
		bool OnBase;

	public:
		Vehicle(double petrol_amount, double tank_volume)
		{
			OnBase = true;
			Base::SetVehicles(Base::GetVehicles() + 1);
			if (tank_volume > 0.f)
				this->tank_volume = tank_volume;
			else
				this->tank_volume = 5.f;

			if (petrol_amount < 0.f)
				this->petrol_amount = 0.f;
			else if (petrol_amount < this->tank_volume)
				this->petrol_amount = petrol_amount;
			else
				this->petrol_amount = this->tank_volume;
		}

		virtual double getTankVolume() final { return tank_volume; }
		virtual double getPetrolAmount() final { return petrol_amount; }

		virtual bool arrive()
		{
			if (OnBase || petrol_amount < (tank_volume / 4.f))
			{
				return false;
			}
			else
			{
				Base::SetVehicles(Base::GetVehicles() + 1);
				Base::GetPeople(-1);
				petrol_amount = tank_volume / 4.f;
				OnBase = true;
				return true;
			}
		}
		virtual bool leave()
		{
			if (!OnBase || Base::GetPetrol() < (tank_volume - petrol_amount) || Base::GetPeople() < 1)
			{
				return false;
			}
			else
			{
				Base::SetVehicles(Base::GetVehicles() - 1);
				petrol_amount = Base::GetPetrol(tank_volume - petrol_amount);
				Base::GetPeople(1);
				OnBase = false;
				return true;
			}
		}

		virtual void Info()
		{
			cout << "On The Base: ";
			if (OnBase)
				cout << "true\n";
			else
				cout << "false\n";
			cout << "Petrol: " << petrol_amount << endl;
			cout << "Tank Volume: " << tank_volume << endl;
		};

		virtual ~Vehicle() = 0 { }
	};
}

