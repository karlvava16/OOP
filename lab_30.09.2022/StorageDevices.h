#pragma once
#include <iostream>

class StorageDevices
{
	std::string model;
	unsigned ram_mb;

public:
	StorageDevices();
	StorageDevices(std::string model, unsigned ram_mb);

	void Print();
};

