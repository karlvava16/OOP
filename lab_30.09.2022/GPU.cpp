#include "GPU.h"

GPU::GPU() : model("MSI gtx960 gaming"), ram_mb(4096) {}

GPU::GPU(std::string model, unsigned ram_mb) : model(model), ram_mb(ram_mb) {}

void GPU::Print()
{
	std::cout << "\t|GPU|\n";
	std::cout << "Model: " << model << std::endl;
	std::cout << "RAM: " << ram_mb << "MB" << std::endl;
}