#include <iostream>
#include <Windows.h>
#include "Queue.h"
using namespace std;

int main()
{
	Queue<string> qu;

	const int SIZE = 256;
	char buffer[SIZE];

	while (true)
	{
		cout << "Enter visitor name : ";
		cin.getline(buffer, SIZE);
		system("cls");
		if (strcmp(buffer, "") == 0)
			break;
		else
			qu.Add(buffer);
	}


	cout << "\t|QUEUE|\n";
	qu.Show();
	cin.get();
	cin.clear();
	system("cls");

	while (!qu.IsEmpty())
	{
		cout << "\t|PROCESSING THE QUEUE|\n";
		qu.Show();
		qu.Extract();
		Sleep(1000);
		system("cls");
	}

	cout << "\t|QUEUE DONE|\n";

	return 0;
}