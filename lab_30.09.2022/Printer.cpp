#include "Printer.h"

Printer::Printer() : model("HP Printer Nonstop 1000a"), resource(2500) {}

Printer::Printer(std::string model, unsigned resource) : model(model), resource(resource) {}

void Printer::Print()
{
	std::cout << "\t|Printer|\n";
	std::cout << "Model: " << model << std::endl;
	std::cout << "Resource: " << resource << std::endl;
}