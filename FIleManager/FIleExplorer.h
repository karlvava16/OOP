#pragma once
#include <iostream>
#include <filesystem> // C++17 standard header file name
#include <algorithm>
#include "Menu.h"



using namespace std;

namespace fs = std::filesystem;

class FIleExplorer
{
	fs::path DefPath;
	size_t current;
	size_t length;

public:
	FIleExplorer() : DefPath(fs::current_path().root_path()), current(0), length(0)
	{
		for (auto& i : fs::directory_iterator(DefPath)) length++;
	}
	FIleExplorer(const fs::path& dp) : FIleExplorer() 
	{
		if (fs::is_directory(dp))
		{
			DefPath = dp;
			length = 0;
			for (auto& i : fs::directory_iterator(DefPath)) length++;
		}
	}

	void Start(); // start file explorer


	void Up();
	void Down();
	void Left();
	void Enter();

	void Create();
	void Delete();
	void Cut();

	void Copy();
	void Past();

	void Search();
	void Find();

	void Rename();

	void GoToPath();
};

