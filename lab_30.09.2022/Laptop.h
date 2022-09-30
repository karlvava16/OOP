#pragma once
#include "CPU.h"
#include "GPU.h"
#include "Keyboard.h"
#include "RAM.h"
#include "StorageDevices.h"
#include "Printer.h"


class Laptop
{
	std::string model;
	unsigned year;
	CPU cpu;
	GPU gpu;
	RAM ram;
	StorageDevices sd;
	Keyboard kb;
	Printer* prntr;

public:
	Laptop();
	Laptop(Printer* prntr);
	Laptop(std::string model, unsigned year, const GPU& gpu, const CPU& cpu, const RAM& ram, const StorageDevices& sd, const Keyboard& kb, Printer* prntr);

	void Show();
};

