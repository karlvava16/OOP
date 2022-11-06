#include "FileExplorer.h"

void FileExplorer::MainCycle()
{
	win::SetConsoleCP(1251);
	win::SetConsoleOutputCP(1251);


	win::HANDLE out = win::GetStdHandle((win::DWORD) - 1);

	win::CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);

	Menu::UpdateMenu(DefPath, length, current);
	
	while (true)
	{
		try
		{
			if (_getch() == VK_RETURN)
			{
			Right();
			}
			if (win::GetKeyState(VK_ESCAPE) < 0)																	
			{																												
				system("cls");																								
				break;																										
			}																												
			else if (win::GetKeyState(VK_CONTROL) < 0 && win::GetKeyState(0x52) < 0)
			{																												
				Update();
			}																												
			else if (win::GetKeyState(VK_UP) < 0)
			{
				Up();																										
			}																												
			else if (win::GetKeyState(VK_DOWN) < 0)
			{																												
				Down();																										
			}																												
			else if (win::GetKeyState(VK_LEFT) < 0)
			{																												
				Left();																										
			}
			else if (win::GetKeyState(VK_CONTROL) < 0 && win::GetKeyState(0x50) < 0)
			{
				GoToPath();
			}
			else if (win::GetKeyState(VK_CONTROL) < 0 && win::GetKeyState(VK_SHIFT) < 0 && win::GetKeyState(0x4E) < 0)
			{
				Create();
			}
			else if (win::GetKeyState(VK_DELETE) < 0)
			{
				Delete();
			}
			else if (win::GetKeyState(VK_CONTROL) < 0 && win::GetKeyState(VK_SHIFT) < 0 && win::GetKeyState(0x46) < 0)
			{
				Find();
			}
			else if (win::GetKeyState(VK_CONTROL) < 0 && win::GetKeyState(0x58) < 0)
			{
				Cut();
			}
			else if (win::GetKeyState(VK_CONTROL) < 0 && win::GetKeyState(0x43) < 0)
			{
				Copy();
			}
			else if (win::GetKeyState(VK_CONTROL) < 0 && win::GetKeyState(0x56) < 0)
			{
				Past();
			}
			else if (win::GetKeyState(VK_CONTROL) < 0 && win::GetKeyState(VK_F2) < 0)
			{
				Rename();
			}
		}
		catch (fs::filesystem_error msg)
		{
			Menu::Message(msg);
		}
	}
}


void FileExplorer::Up()
{
	if (Check())
	{
		if (current == 0)
			current = length;
		current--;
		Menu::Message(L"");
		Menu::Directories(DefPath, length, current);
		Menu::Properties(DefPath, length, current);
		Menu::DiskSpace(DefPath);
		win::Sleep(100);

	}
}

void FileExplorer::Down()
{
	if (Check())
	{
		current++;
		if (current >= length)
			current = 0;
		Menu::Message(L"");
		Menu::Directories(DefPath, length, current);
		Menu::Properties(DefPath, length, current);
		Menu::DiskSpace(DefPath);
		win::Sleep(100);
	}
}

void FileExplorer::Left()
{
	fs::path temp = DefPath.parent_path();
	if (DefPath != temp)
	{
		DefPath = temp;
		Check();
	}
}

void FileExplorer::Right()
{
	if (Check())
	{
		auto p = fs::directory_iterator(DefPath);
		advance(p, current);
		if ((*p).is_directory())
		{
			DefPath = (*p).path().string();
			Check();
		}
	}
}


void FileExplorer::Create()
{
	fs::path temp = DefPath;
	try
	{
		temp /= Menu::Enter();
		fs::create_directories(temp);
		Menu::UpdateMenu(DefPath, length, current);
		Menu::Message(L"CREATED DIRECTORY");
	}
	catch (fs::filesystem_error msg)
	{
		throw(msg);
	}
}

void FileExplorer::Delete()
{
	try
	{
		if (length > 0 && Check())
		{
			auto p = fs::directory_iterator(DefPath);
			advance(p, current);
			remove((*p).path());
			length--;
			current = 0;

			Menu::UpdateMenu(DefPath, length, current);
			Menu::Message(L"DELETED");
		}
		else
		{
			Menu::Message(L"DIR IS EMPTY");
		}
	}
	catch (fs::filesystem_error msg)
	{
		throw(msg);
	}
}

void FileExplorer::Cut()
{
}

void FileExplorer::Copy()
{
}

void FileExplorer::Past()
{
}

void FileExplorer::Rename()
{
	try
	{
		if (Check())
		{
			wstring name = Menu::Enter();
			auto p = fs::directory_iterator(DefPath);
			advance(p, current);
			if ((*p).path().filename() == name)
			{
				Menu::Message(L"SAME NAME");
				return;
			}
			else
			{
				fs::rename(DefPath / (*p).path().filename(), DefPath / name);
				Menu::Message(L"HAS BEEN RENAMED");
				Menu::Directories(DefPath, length, current);
				Menu::Properties(DefPath, length, current);
			}
		}
	}
	catch (fs::filesystem_error msg)
	{
		throw(msg);
	}
}


void FileExplorer::Search()
{
}

void FileExplorer::Find()
{
}


void FileExplorer::GoToPath()
{
	try
	{
		Check();
		fs::path p = Menu::Enter();
		if (DefPath == p)
		{
			Menu::Message(L"SAME PATH");
		}
		else if (fs::is_directory(p))
		{
			DefPath = p.string();
			length = 0;
			current = 0;
			for (auto& i : fs::directory_iterator(DefPath)) length++;
			Menu::UpdateMenu(DefPath, length, current);
		}
		else
		{
			Menu::Message(L"INACCESSIBLE PATH");
		}
	}
	catch (fs::filesystem_error msg)
	{
		throw(msg);
	}
}

void FileExplorer::Update()
{
	if (Check())
	{
		Menu::UpdateMenu(DefPath, length, current);
		win::Sleep(100);
	}// ResetMenu [Ctrl+R]
}