#pragma once
#include "AnimalBasic.h"
#include "Rabbit.h"

class Fox : public AnimalBasic
{
	static unsigned MAXAGE;

public:
	Fox() : AnimalBasic() { age = 5; maxAge = MAXAGE; }

	Fox(unsigned age) : Fox() { this->age = age; Check(); }

	void Eat(Rabbit& rabbit)
	{
		rabbit.Dead();
	}

	void Info() const
	{
		if (life())
			cout << "Hello! I am a fox.\n I'm " << age << " years old))\n\n";
		else
			cout << "Fox passed away in age of " << age << ".\n\n";
	}

	static unsigned GetMaxAge();
};

unsigned Fox::MAXAGE = 10;

unsigned Fox::GetMaxAge()
{
	return MAXAGE;
}
