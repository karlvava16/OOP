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
		static void Directories(const fs::path& path);
		static void Directories(const fs::path& path, size_t length, size_t current);
		static void Properties(const fs::path& path, size_t length, size_t current);
		static void CurrentPath(const fs::path& path);
		static void DiskSpace(const fs::path& path);
		static void Message(wstring msg);
		static void Message(const fs::filesystem_error msg);
		static void Search();
		static wstring Enter();
		static void UpdateMenu(const fs::path& path, size_t length, size_t current);


		virtual ~Menu() final = 0;
};

