#pragma once
#include "Vehicle.h"


namespace bus
{
	using namespace vehicle;

	class Bus : public Vehicle
	{
		int people_amount;
		int max_people;

	public:
		Bus(int people, int max_people, double petrol, double max_petrol) : Vehicle(petrol, max_petrol)
		{
			if (max_people >= 4)
				this->max_people = max_people;
			else
				this->max_people = 4;
			if (people < 0)
				this->people_amount = 0;
			else if (people <= this->max_people)
				this->people_amount = people;
			else
				this->people_amount = this->max_people;
		}

		int getPeopleCount() const { return people_amount; }

		int getMaxPeople() const { return max_people; }


		bool arrive() final
		{
			if (Vehicle::arrive())
			{
				people_amount += Base::GetPeople(-people_amount);
				return true;
				
			}
			return false;
		}

		bool leave() final
		{
			if (Vehicle::leave())
			{
				people_amount = Base::GetPeople((max_people - people_amount));
				return true;
			}
			return false;
		}

		void Info() final
		{
			cout << "|Bus|\n";
			Vehicle::Info();
			cout << "People: " << people_amount << endl;
			cout << "Max People: " << max_people << endl;
		}
	};
}