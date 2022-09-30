#include "Laptop.h"

Laptop::Laptop() : model("asus zenbook 15 pro"), year(2021), prntr(nullptr)
{
}

Laptop::Laptop(Printer* prntr) : Laptop()
{
	this->prntr = prntr;
}

Laptop::Laptop(std::string model, unsigned year, const GPU& gpu, const CPU& cpu, const RAM& ram, const StorageDevices& sd, const Keyboard& kb, Printer* prntr)
{
	this->model = model;
	this->year = year;
	this->gpu = gpu;
	this->cpu = cpu;
	this->ram = ram;
	this->sd = sd;
	this->kb = kb;
	this->prntr = prntr;
}

void Laptop::Show()
{
	std::cout << "----------------------\n";
	std::cout << "         Laptop\n";
	std::cout << "----------------------\n";
	std::cout << "Model:" << model << std::endl;
	std::cout << "Year:" << year << std::endl;
	gpu.Print();
	cpu.Print();
	ram.Print();
	sd.Print();
	kb.Print();
	if (prntr != nullptr)
		prntr->Print();

}
