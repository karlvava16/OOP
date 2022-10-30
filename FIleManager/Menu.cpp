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
	SetPos(0, 0);
}


void Menu::Directories(const fs::path& path, size_t current)
{
	SetPos(0, 6);
	size_t index = 0;
	for (auto & i : fs::directory_iterator(path))
	{
		if (index != current)
		{
			cout << setw(SECOND_PART) << i.path().filename();
			if (fs::is_directory(i))
				cout << setw(6) << "| " << "\"DIR\"" << endl;
			else
				cout << setw(6) << "| " << i.path().extension() << endl;
		}
		else
		{
			SetColor(5, 3);	//set color to highlight
			cout << setw(SECOND_PART) << i.path().filename();
			if(fs::is_directory(i))
				cout << setw(6) << "| " << "\"DIR\"" << endl;
			else
				cout << setw(6) << "| " << i.path().extension() << endl;
			SetColor(2, 0); //set default color
		}
		index++;
	}
}

void Menu::Directories(const fs::path& path, size_t current, size_t length)
{
	SetPos(0, 6);
	size_t index = 0;
	auto p = fs::directory_iterator(path);
	if (current == 0)
	{
		advance(p, current);

	}
	for (auto& i : fs::directory_iterator(path))
	{
		if (index != current)
		{
			cout << setw(SECOND_PART) << i.path().filename();
			if (fs::is_directory(i))
				cout << setw(6) << "| " << "\"DIR\"" << endl;
			else
				cout << setw(6) << "| " << i.path().extension() << endl;
		}
		else
		{
			SetColor(5, 3);	//set color to highlight
			cout << setw(SECOND_PART) << i.path().filename();
			if (fs::is_directory(i))
				cout << setw(6) << "| " << "\"DIR\"" << endl;
			else
				cout << setw(6) << "| " << i.path().extension() << endl;
			SetColor(2, 0); //set default color
		}
		index++;
	}
}

void Menu::Properties(const fs::path& path, size_t current)
{
	SetPos(SECOND_PART + 20, 6);
	auto p = fs::directory_iterator(path);
	advance(p, current);
	for (int i = 0; i < THIRD_PART; i++) cout << '-';
	SetPos(SECOND_PART + 20, 7);
	cout << "[Selected]";
	SetPos(SECOND_PART + 20, 8);
	cout << "Name: " << (*p).path().filename() << setw(THIRD_PART - strlen((*p).path().filename().string().c_str())) << "";
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
	SetPos(0, 0);
}

void Menu::CurrentPath(const fs::path& path)
{
	SetPos(0, 1);
	for (int i = 0; i < FIRST_PART; i++) cout << '-';
	SetPos(0, 2);
	cout << setw(FIRST_PART) << path << endl;
	for (int i = 0; i < FIRST_PART; i++) cout << '-';
	SetPos(0, 0);
}


void Menu::DiskSpace(const fs::path& path)
{
	SetPos(SECOND_PART + 20, 13);
	fs::space_info si(fs::space(path.root_path().string()));
	for (int i = 0; i < THIRD_PART; i++) cout << '-';
	SetPos(SECOND_PART + 20, 14);
	cout << "[" << path.root_path() << "]";
	SetPos(SECOND_PART + 20, 15);
	cout << "Capacity: " << si.capacity << setw(THIRD_PART - 10) << "";
	SetPos(SECOND_PART + 20, 16);
	cout << "Available: " << si.available << setw(THIRD_PART - 11) << "";
	SetPos(SECOND_PART + 20, 17);
	cout << "Free: " << si.free << setw(THIRD_PART - 6) << "";
	SetPos(SECOND_PART + 20, 18);
	for (int i = 0; i < THIRD_PART; i++) cout << '-';
	SetPos(0, 0);
}

void Menu::Message()
{
	SetPos(0, 4);
	cout << setw(FIRST_PART) << "";
	SetPos(0, 5);
	for (int i = 0; i < FIRST_PART; i++) cout << '-';
	SetPos(0, 0);
}

void Menu::Message(const fs::filesystem_error msg)
{
	SetPos(0, 4);
	cout << msg.what() << setw(FIRST_PART - strlen(msg.what())) << "";
	SetPos(0, 5);
	for (int i = 0; i < FIRST_PART; i++) cout << '-';
	SetPos(0, 0);
}

void Menu::Search()
{

}

void Menu::UpdateMenu(const fs::path& path, size_t current)
{
	system("cls");
	cout << setiosflags(ios::left);
	SetColor(2, 0);
	ContextMenu();
	Message();
	CurrentPath(path);
	Directories(path, current);
	Properties(path, current);
	DiskSpace(path);
}

fs::path Menu::EnterPath()
{
	SetPos(0, 0);
	system("cls");
	char buffer[1] = {' '};
	string temp = "";
	cout << "Enter Path: ";
	cin.getline(buffer, 1);
	do
	{
		temp += buffer[0];
		cin.getline(buffer, 1);
	} while (buffer[0] != '\t');

	if (is_directory(fs::path(temp)))
		return  fs::path(temp);
	else
		return fs::path();
}
