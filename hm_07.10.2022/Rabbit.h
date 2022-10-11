#pragma once
#include "AnimalBasic.h"

class Rabbit : public AnimalBasic
{
	static unsigned MAXAGE;
public:
	Rabbit() : AnimalBasic() { age = 4; maxAge = MAXAGE; }

	Rabbit(unsigned age) : Rabbit() { this->age = age; Check(); }

	void Info() const
	{
		if (life())
			cout << "Hey! Rabbit is here!\n I'm " << age << " years old HFHFH [RABBIT SOUNDS]\n\n";
		else
			cout << "Rabbit's journey ended at the age of " << age << ".\n\n";
	}

	static unsigned GetMaxAge();
};

unsigned Rabbit::MAXAGE = 8;

unsigned Rabbit::GetMaxAge()
{
	return MAXAGE;
}
