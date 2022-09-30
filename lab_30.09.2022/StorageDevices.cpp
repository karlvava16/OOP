#include "StorageDevices.h"

StorageDevices::StorageDevices() : model("asus keyboard"), ram_mb(1024000) {}

StorageDevices::StorageDevices(std::string model, unsigned ram_mb) : model(model), ram_mb(ram_mb) {}

void StorageDevices::Print()
{
	std::cout << "\t|Keyboard|\n";
	std::cout << "Model: " << model << std::endl;
	std::cout << "RAM: " << ram_mb << "MB" << std::endl;
}