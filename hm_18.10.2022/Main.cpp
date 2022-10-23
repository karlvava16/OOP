#include <iostream>
#include <fstream>
using namespace std;


bool HTMLValidator(fstream& file)
{
	bool check = true;
	char symbol;
	
	file >> symbol;
	do
	{
		if (symbol == '<')
		{
			if (check)
			{
				check = false;
			}
			else
			{
				break;
			}
		}
		else if (symbol == '>')
		{
			if (!check)
			{
				check = true;
			}
			else
			{
				check = false;
				break;
			}
		}
		file >> symbol;
	} while (!file.eof());

	return check;
}

void OpenFile(fstream& file, const string& name)
{		
	file.open(name);

	if (!file.is_open())
		throw("Cannot open file\n");
}

void FileClose(fstream& file)
{
	file.close();
}


int main()
{
	fstream file;
	string name;

	cout << "Enter File Name: ";
	cin >> name;

	try
	{
		OpenFile(file, name);

		if (HTMLValidator(file))
		{
			cout << "[Correct]\n";
		}
		else
		{
			cout << "[Incorrect]\n";
		}

		FileClose(file);
	}
	catch (const char* str)
	{
		cout << str;
	}
	return 0;
}