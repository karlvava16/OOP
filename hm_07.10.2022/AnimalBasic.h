#pragma once
#include <iostream>
#include "IsExist.h"

using namespace std;

class AnimalBasic
{
protected:
	unsigned age;
	unsigned maxAge;
	IsExist life;
	
	void Check()
	{
		if (age > maxAge)
		{
			age = maxAge;
			Dead();
		}
		else if (age < 1)
			age = 1;
	}


public:
	AnimalBasic() : age(1), maxAge(2), life(true) {}
	
	IsExist operator++(int)
	{
		IsExist temp(this);
		if (life())
		{
			age++;
			Check();
		}
		return temp;
	}

	bool operator++()
	{
		if (life())
		{
			age++;
			Check();
		}
		return age;
	}

	void Dead()
	{
		life = false;
	}

	bool IsAlife() const
	{
		return life();
	}

	unsigned GetAge() const
	{
		return age;
	}

	void operator()() { Info(); }

	virtual void Info() const = 0;
	virtual ~AnimalBasic() = 0 {}
};