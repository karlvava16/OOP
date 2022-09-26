#include <iostream>
#include <string.h>
#include <time.h>
#include "Queue.h";
#include "QueuePriority.h"
#include "PrintRequest.h"
using namespace std;


void main()
{
	srand(time(0));

	QueuePriority<PrintRequest> QUP(25);
	Queue<PrintRequest> QU(25);
	
	PrintRequest pr;
	const int SIZE = 256;
	char buffer[SIZE];
	bool check = true;
	while (check)
	{
		cout << "Enter filename : ";
		cin.getline(buffer, SIZE);
		pr.SetFilename(buffer);
		cout << "Enter user : ";
		cin.getline(buffer, SIZE);
		pr.SetUser(buffer);
		cout << "Enter priority : ";
		cin.getline(buffer, SIZE);
		pr.SetPriority(atoi(buffer));
		cout << "Continue? (1 = true, 0 = false) : ";
		cin >> check;
		QUP.Add(pr, pr.GetProroity());
		system("cls");
	}
	

	////создание очереди
	//
	//PrintRequest first("123.docs", "Vlad");
	//PrintRequest second("hm.pdf", "Kris", 100);
	//PrintRequest third("done_hm.cpp", "Alex", 50);
	//PrintRequest forth("random.txt");
	//PrintRequest fifth();
	//QUP.Add(first, first.GetProroity());
	//QUP.Add(second, second.GetProroity());
	//QUP.Add(third, third.GetProroity());
	//QUP.Add(forth, forth.GetProroity());

	cout << "\n|QUEUE + PRIORITY|\n\n";
	//показ очереди
	QUP.Show();

	cout << "\n|PRINTING|\n\n\n";
	while (!QUP.IsEmpty())
	{
		QU.Add(QUP.Extract());
	}

	cout << "|PRINTED FILES TABLE|\n";
	QU.Show();
	
}

