#include "FileExplorer.h"

void FileExplorer::Start()
{
	setlocale(0, "");
	win::SetConsoleCP(1251);
	win::SetConsoleOutputCP(1251);

	Menu::UpdateMenu(DefPath, length, current);

	while (true)
	{
		try
		{
			if (win::GetAsyncKeyState(VK_ESCAPE))																			//
			{																												//
				system("cls");																								//
				break;																										//
			}																												//
			else if ((win::GetAsyncKeyState(VK_CONTROL) && win::GetAsyncKeyState(0x52)) ||									//
				((win::GetAsyncKeyState(VK_LWIN) || win::GetAsyncKeyState(VK_RWIN)) && win::GetAsyncKeyState(VK_UP)))		//
			{																												//
				Menu::UpdateMenu(DefPath, length, current);																	// ResetMenu [Ctrl+R]
				win::Sleep(100);																							//
			}																												//
			else if ((win::GetAsyncKeyState(VK_CONTROL) && win::GetAsyncKeyState(0x50)))									//
				GoToPath();																									//
			else if (win::GetAsyncKeyState(VK_UP))																			// Go To Path [Ctrl+P]
			{																												//
				Up();																										//
			}																												//
			else if (win::GetAsyncKeyState(VK_DOWN))																		//
			{																												//
				Down();																										//
			}																												//
			else if (win::GetAsyncKeyState(VK_LEFT))																		//
			{																												//
				Left();																										//
			}																												//
			else if (win::GetAsyncKeyState(VK_RETURN) || win::GetAsyncKeyState(VK_RIGHT))									//
				Enter();																									// Press Enter To Continue
			else if (win::GetAsyncKeyState(VK_DELETE))																		//
				Delete();																									// Delete [Del]
			else if (win::GetAsyncKeyState(VK_CONTROL) && win::GetAsyncKeyState(VK_SHIFT) && win::GetAsyncKeyState(0x46))	// 
				Find();																										// Find [Ctrl+Shft+F]
			else if (win::GetAsyncKeyState(VK_CONTROL) && win::GetAsyncKeyState(0x46))										//
				Search();																									// Search [Ctrl+F]
			else if (win::GetAsyncKeyState(VK_CONTROL) && win::GetAsyncKeyState(0x46))										//
				Search();																									// Search [Ctrl+F]
			else if (win::GetAsyncKeyState(VK_CONTROL) && win::GetAsyncKeyState(0x58))										//
				Cut();																										// Cut [Ctrl+X]
			else if (win::GetAsyncKeyState(VK_CONTROL) && win::GetAsyncKeyState(0x43))										//
				Copy();																										// Copy [Ctrl+C] 
			else if (win::GetAsyncKeyState(VK_CONTROL) && win::GetAsyncKeyState(0x56))										//
				Past();																										// Past [Ctrl+V]
			else if (win::GetAsyncKeyState(VK_CONTROL) && win::GetAsyncKeyState(VK_F2))										//
				Rename();																									// Rename [Ctrl+F2]

		}
		catch (fs::filesystem_error msg)
		{
			Menu::Message(msg);
		}
	}
}

void FileExplorer::Up()
{
	if (current == 0)
		current = length;
	current--;
	Menu::ContextMenu();
	Menu::Message(L"");
	Menu::Directories(DefPath, length, current);
	Menu::Properties(DefPath, length, current);
	win::Sleep(100);
	while (win::GetAsyncKeyState(VK_DOWN))
	{
		current++;
		if (current >= length)
			current = 0;
		Menu::ContextMenu();
		Menu::Message(L"");
		Menu::Directories(DefPath, length, current);
		Menu::Properties(DefPath, length, current);
	}
}

void FileExplorer::Down()
{
	current++;
	if (current >= length)
		current = 0;
	win::Sleep(100);
	Menu::ContextMenu();
	Menu::Message(L"");
	Menu::Directories(DefPath, length, current);
	Menu::Properties(DefPath, length, current);
	while (win::GetAsyncKeyState(VK_DOWN))
	{
		current++;
		if (current >= length)
			current = 0;
		Menu::ContextMenu();
		Menu::Message(L"");
		Menu::Directories(DefPath, length, current);
		Menu::Properties(DefPath, length, current);
	}
	
}

void FileExplorer::Left()
{
	fs::path temp = DefPath.parent_path();
	if (DefPath != temp)
	{
		DefPath = temp;
		length = 0;
		current = 0;
		for (auto& i : fs::directory_iterator(DefPath)) length++;
		Menu::UpdateMenu(DefPath, length, current);
	}
}

void FileExplorer::Enter()
{
	auto p = fs::directory_iterator(DefPath);
	advance(p, current);
	if ((*p).is_directory())
	{
		DefPath = (*p).path().string();
		length = 0;
		current = 0;
		for (auto& i : fs::directory_iterator(DefPath)) length++;
		Menu::UpdateMenu(DefPath, length, current);
	}
}

void FileExplorer::Create()
{
}

void FileExplorer::Delete()
{
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

void FileExplorer::Search()
{
}

void FileExplorer::Find()
{
}



void FileExplorer::Rename()
{
	wstring name = Menu::Enter();
	auto p = fs::directory_iterator(DefPath);
	advance(p, current);
	try
	{
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
		char a = _getch();
	}
	catch (fs::filesystem_error msg)
	{
		Menu::Message(msg);
	}
}

void FileExplorer::GoToPath()
{

}