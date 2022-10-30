#include "Menu.h"


void Menu::SetColor(int text, int bg)
{
	win::HANDLE hStdOut = win::GetStdHandle(((win::DWORD)-11));
	win::SetConsoleTextAttribute(hStdOut, (win::WORD)((bg << 4) | text));
}

void Menu::SetPos(int a, int b)
{
	win::HANDLE hConsole = win::GetStdHandle(((win::DWORD)-11));
	win::COORD pos = { a, b };
	SetConsoleCursorPosition(hConsole, pos);
}

void Menu::ContextMenu()
{
	SetPos(0, 0);
	cout << "Cut [Ctrl+X]    ";
	cout << "Copy [Ctrl+C]    ";
	cout << "Past [Ctrl+V]    ";
	cout << "Rename [Ctrl+F2]    ";
	cout << "Create [Ctrl+Shft+N]    ";
	cout << "Delete [Del]    ";
	cout << "Search [Ctrl+F]    ";
	cout << "Find [Ctrl+Shft+F]    ";
	cout << "Go To Path [Ctrl+P]";
}


void Menu::Directories(const fs::path& path)
{
	if (!path.empty())
	{
		SetPos(0, 6);
		for (auto& i : fs::directory_iterator(path))
		{
			cout << setw(SECOND_PART) << i.path().filename();
			if (fs::is_directory(i))
				cout << setw(6) << "| " << "\"DIR\"" << endl;
			else
				cout << setw(6) << "| " << i.path().extension() << endl;
		}
	}
	SetPos(0, 6);
}

void Menu::Directories(const fs::path& path, size_t length, size_t current)
{
	fs::directory_iterator p;
	if (length > 2)
	{
		p = fs::directory_iterator(path);
		if (current > 0)
		{
			SetPos(0, current + 5);
			advance(p, current - 1);
			cout << setw(SECOND_PART) << (*p).path().filename();
			if (fs::is_directory((*p).path()))
				cout << setw(6) << "| " << "\"DIR\"" << endl;
			else
				cout << setw(6) << "| " << (*p).path().extension() << endl;
		}
		else
		{
			SetPos(0, length + 5);
			advance(p, length - 1);
			cout << setw(SECOND_PART) << (*p).path().filename();
			if (fs::is_directory((*p).path()))
				cout << setw(6) << "| " << "\"DIR\"" << endl;
			else
				cout << setw(6) << "| " << (*p).path().extension() << endl;
		}
	}
	if (length > 1 )
	{
		p = fs::directory_iterator(path);
		if ( current < (length - 1))
		{
			SetPos(0, current + 7);
			advance(p, current + 1);
			cout << setw(SECOND_PART) << (*p).path().filename();
			if (fs::is_directory((*p).path()))
				cout << setw(6) << "| " << "\"DIR\"" << endl;
			else
				cout << setw(6) << "| " << (*p).path().extension() << endl;
		}
		else
		{
			SetPos(0, 6);
			advance(p, 0);
			cout << setw(SECOND_PART) << (*p).path().filename();
			if (fs::is_directory((*p).path()))
				cout << setw(6) << "| " << "\"DIR\"" << endl;
			else
				cout << setw(6) << "| " << (*p).path().extension() << endl;
		}
	}
	if (length > 0)
	{
		p = fs::directory_iterator(path);
		SetPos(0, current + 6);
		advance(p, current);
		SetColor(5, 3);	//set color to highlight
		cout << setw(SECOND_PART) << (*p).path().filename();
		if (fs::is_directory((*p).path()))
			cout << setw(6) << "| " << "\"DIR\"" << endl;
		else
			cout << setw(6) << "| " << (*p).path().extension();
		SetColor(2, 0); //set default color
		cout << endl;
	}
	SetPos(0, current + 6);
}

void Menu::Properties(const fs::path& path,size_t length, size_t current)
{
	if (length > 0)
	{
		SetPos(SECOND_PART + 20, 6);
		auto p = fs::directory_iterator(path);
		advance(p, current);
		for (int i = 0; i < THIRD_PART; i++) cout << '-';
		SetPos(SECOND_PART + 20, 7);
		cout << "[Selected]";
		SetPos(SECOND_PART + 20, 8);
		cout << "Name: " << (*p).path().filename() << setw(THIRD_PART - strlen((*p).path().filename().string().c_str()) - 1) << "";
		SetPos(SECOND_PART + 20, 9);
		cout << "Type: ";
		if (fs::is_directory((*p).path()))
		{
			cout << "\"DIR\"" << setw(THIRD_PART - 6) << "";
			SetPos(SECOND_PART + 20, 10);
			cout << setw(THIRD_PART - 6) << "";

		}
		else
		{
			fs::space_info si(fs::space((*p).path().string()));
			cout << (*p).path().extension() << setw(THIRD_PART - strlen((*p).path().extension().string().c_str())) << "";
			SetPos(SECOND_PART + 20, 10);
			cout << "Size: " << file_size((*p).path()) << setw(THIRD_PART - 6) << "";
		}

		SetPos(SECOND_PART + 20, 11);
		for (int i = 0; i < THIRD_PART; i++) cout << '-';
	}
}

void Menu::CurrentPath(const fs::path& path)
{
	SetPos(0, 1);
	for (int i = 0; i < FIRST_PART; i++) cout << '-';
	SetPos(0, 2);
	cout << setw(FIRST_PART) << path << endl;
	for (int i = 0; i < FIRST_PART; i++) cout << '-';
	
}


void Menu::DiskSpace(const fs::path& path)
{
	SetPos(SECOND_PART + 20, 13);
	fs::space_info si(fs::space(path.root_path().string()));
	for (int i = 0; i < THIRD_PART; i++) cout << '-';
	SetPos(SECOND_PART + 20, 14);
	cout << "[" << path.root_path() << "]";
	SetPos(SECOND_PART + 20, 15);
	cout << "Capacity: ";
	cout << setw(THIRD_PART - 12) << si.capacity;
	SetPos(SECOND_PART + 20, 16);
	cout << "Available: ";
	cout << setw(THIRD_PART - 13) << si.available;
	SetPos(SECOND_PART + 20, 17);
	cout << "Free: ";
	cout << setw(THIRD_PART - 8) << si.free;
	SetPos(SECOND_PART + 20, 18);
	for (int i = 0; i < THIRD_PART; i++) cout << '-';
}

void Menu::Message(wstring msg)
{
	SetPos(0, 4);
	for (int i = 0; i < FIRST_PART; i++) cout << ' ';
	SetPos(0, 4);
	wcout << msg << setw(FIRST_PART - wcslen(msg.c_str())) << L"";
	SetPos(0, 5);
	for (int i = 0; i < FIRST_PART; i++) cout << '-';	
}

void Menu::Message(const fs::filesystem_error msg)
{
	SetPos(0, 4);
	for (int i = 0; i < FIRST_PART; i++) cout << ' ';
	SetPos(0, 4);
	cout << msg.what() << setw(FIRST_PART - strlen(msg.what())) << "";
	SetPos(0, 5);
	for (int i = 0; i < FIRST_PART; i++) cout << '-';	
}

void Menu::Search()
{

}

wstring Menu::Enter()
{
	_getch();
	SetPos(0, 4);
	for (int i = 0; i < FIRST_PART; i++) cout << ' ';
	SetPos(0, 4);

	wstring temp;
	cout << "Enter: ";
	getline(wcin, temp);

	SetPos(0, 4);
	return temp;
}

void Menu::UpdateMenu(const fs::path& path, size_t length, size_t current)
{
	system("cls");
	cout << setiosflags(ios::left);
	SetColor(2, 0);
	ContextMenu();
	Message(L"");
	CurrentPath(path);
	Directories(path);
	Directories(path, length, current);
	Properties(path, length, current);
	DiskSpace(path);
}
