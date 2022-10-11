#pragma once
#include "Fox.h"
#include "Rabbit.h"
#include "List.h"
#include "Grass.h"

class Field
{
	unsigned MAXFOXS;
	unsigned MAXRABBITS;
	unsigned MAXGRASS;

	List<Fox> foxs;
	List<Rabbit> rabbits;
	List<Grass> grass;

	void IncreaseAge()
	{
		for (int i = 0; i < foxs.GetCount(); i++)
		{
			foxs.GetElem(i + 1)->data.operator++();
			if (!foxs.GetElem(i + 1)->data.IsAlife())
			{
				foxs.Del(i + 1);
				i--;
			}
		}
		for (int i = 0; i < rabbits.GetCount(); i++)
		{
			rabbits.GetElem(i + 1)->data.operator++();
			if (!rabbits.GetElem(i + 1)->data.IsAlife())
			{
				rabbits.Del(i + 1);
				i--;
			}
		}
		for (int i = 0; i < grass.GetCount(); i++)
		{
			grass.GetElem(i + 1)->data(rand() % 5);
			if (!grass.GetElem(i + 1)->data.IsExist())
			{
				grass.Del(i + 1);
				i--;
			}
		}
	}

	void RandEntity()
	{
		int f, r, g;
		f = (rand() % (MAXFOXS - 1) + MAXFOXS / 2);
		r = (rand() % (MAXRABBITS - 1) + MAXRABBITS / 2);
		g = (rand() % (MAXFOXS - 1) + MAXFOXS / 2);

		if (foxs.GetCount() <= MAXFOXS)
		{
			for (int i = 0; i < f; i++)
			{
				foxs.AddTail(Fox((rand() % (Fox::GetMaxAge() - 1) + 1)));
			}
		}
		if (rabbits.GetCount() <= MAXRABBITS)
		{
			for (int i = 0; i < r; i++)
			{
				rabbits.AddTail(Rabbit((rand() % (Rabbit::GetMaxAge() - 1) + 1)));
			}
		}
		if (grass.GetCount() <= MAXGRASS)
		{
			for (int i = 0; i < g; i++)
			{
				grass.AddTail(Grass());
			}
		}
	}

public:

	Field() : MAXFOXS(10), MAXRABBITS(10), MAXGRASS(10) {}
	Field(unsigned f, unsigned r, unsigned g) : MAXFOXS(f), MAXRABBITS(r), MAXGRASS(g) {}

	void NextYear()
	{
		cout << "\n|Next Year|\n";
		IncreaseAge();
		RandEntity();
		if (grass.GetCount() < rabbits.GetCount())
		{
			cout << "Grass eated by rabbits\n";
			grass.DelAll();
		}
		else if (rabbits.GetCount() < foxs.GetCount())
		{
			cout << "Rabbits eated by foxs\n";
			rabbits.DelAll();
		}
	}

	void Info()
	{
		cout << "Foxs: " << foxs.GetCount() << endl;
		cout << "Rabbits: " << rabbits.GetCount() << endl;
		cout << "Grass: " << grass.GetCount() << endl;
		cout << endl;
	}
};