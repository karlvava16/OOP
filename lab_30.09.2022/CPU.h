#pragma once
#include <iostream>

class CPU
{
	std::string model;
	unsigned cores;
	unsigned clockRate_gHz;

public:
	CPU();
	CPU(std::string model, unsigned cores, unsigned rate);

	void Print();
};

