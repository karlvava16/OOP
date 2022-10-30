#pragma once

#define FIRST_PART 211
#define SECOND_PART 110
#define THIRD_PART 70


#include <iostream>
#include <filesystem> // C++17 standard header file name
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include <string>

namespace win
{
#include <windows.h>
}

using namespace std;

namespace fs = std::filesystem;

class Menu
{
	static void SetColor(int text, int bg);
	static void SetPos(int a, int b);

	public:
		static void ContextMenu();
		static void Directories(const fs::path& path, size_t current);
		static void Directories(const fs::path& path, size_t current, size_t length);
		static void Properties(const fs::path& path, size_t current);
		static void CurrentPath(const fs::path& path);
		static void DiskSpace(const fs::path& path);
		static void Message();
		static void Message(const fs::filesystem_error msg);
		static void Search();
		static void UpdateMenu(const fs::path& path, size_t current);
		static fs::path EnterPath();


		virtual ~Menu() final = 0;
};

