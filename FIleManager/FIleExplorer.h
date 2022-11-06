#pragma once
#include "Menu.h"



using namespace std;

namespace fs = std::filesystem;

class FileExplorer
{
	fs::path DefPath;
	fs::path temp;
	size_t current;
	size_t length;

	bool Check()
	{
		size_t len = 0;
		for (auto& i : fs::directory_iterator(DefPath)) len++;
		if (len != length)
		{
			current = 0;
			length = len;
			Menu::UpdateMenu(DefPath, length, current);
			return false;
		}
		return true;
	}

public:
	FileExplorer() : DefPath(fs::current_path().root_path()), current(0), length(0)
	{
		for (auto& i : fs::directory_iterator(DefPath)) length++;
	}
	FileExplorer(const fs::path& dp) : FileExplorer() 
	{
		if (fs::is_directory(dp))
		{
			DefPath = dp;
			length = 0;
			for (auto& i : fs::directory_iterator(DefPath)) length++;
		}
	}

	void MainCycle(); // start file explorer


	void Up();
	void Down();
	void Left();
	void Right();

	void Create();
	void Delete();
	void Cut();
	void Copy();
	void Past();
	void Rename();

	void Search();
	void Find();

	void Update();

	void GoToPath();
};

