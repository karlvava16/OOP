#pragma once
#include <iostream>

class GPU
{
	std::string model;
	unsigned ram_mb;

public:
	GPU();
	GPU(std::string model, unsigned ram_mb);

	void Print();
};

