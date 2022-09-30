#pragma once
#include <iostream>

class Printer
{
	std::string model;
	unsigned resource;
public:
	Printer();
	Printer(std::string model, unsigned resource);

	void Print();
};

