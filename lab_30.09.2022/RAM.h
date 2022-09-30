#pragma once
#include <iostream>

class RAM
{
	std::string model;
	unsigned ram_mb;

public:
	RAM();
	RAM(std::string model, unsigned ram_mb);

	void Print();
};

