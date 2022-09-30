#include "CPU.h"

CPU::CPU() : model("Intel i5 6600K"), cores(4), clockRate_gHz(3.5) {}

CPU::CPU(std::string model, unsigned cores, unsigned rate) : model(model), cores(cores), clockRate_gHz(rate) {}

void CPU::Print()
{
	std::cout << "\t|CPU|\n";
	std::cout << "Model: " << model << std::endl;
	std::cout << "Cores: " << cores << std::endl;
	std::cout << "Rate: " << clockRate_gHz << "gHz" << std::endl;
}
