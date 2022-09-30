#include "Keyboard.h"

Keyboard::Keyboard() : model("asus keyboard"), key_amount(104) {}

Keyboard::Keyboard(std::string model, unsigned key_amount) : model(model), key_amount(key_amount) {}

void Keyboard::Print()
{
	std::cout << "\t|Keyboard|\n";
	std::cout << "Model: " << model << std::endl;
	std::cout << "Key amount: " << key_amount << std::endl;
}