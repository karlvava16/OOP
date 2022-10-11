#pragma once
#include <iostream>
#include "IsExist.h"
using namespace std;

class Grass
{
	IsExist exist;

public:

	Grass() {}

	void operator()(bool set)
	{
		exist(set);
	}

	void operator()() { Info(); }

	void Info()
	{
		cout << "...Grass...\n\n";
	}

	bool IsExist() const
	{
		return exist();
	}

};