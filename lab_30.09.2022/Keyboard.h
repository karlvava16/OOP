#pragma once
#include <iostream>

class Keyboard
{
	std::string model;
	unsigned key_amount;

public:
	Keyboard();
	Keyboard(std::string model, unsigned key_amount);

	void Print();

};

