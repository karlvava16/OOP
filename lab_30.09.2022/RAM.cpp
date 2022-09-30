#include "RAM.h"

RAM::RAM() : model("Kingston"), ram_mb(8192) {}

RAM::RAM(std::string model, unsigned ram_mb) : model(model), ram_mb(ram_mb) {}

void RAM::Print()
{
	std::cout << "\t|RAM|\n";
	std::cout << "Model: " << model << std::endl;
	std::cout << "RAM: " << ram_mb << "MB" << std::endl;
}