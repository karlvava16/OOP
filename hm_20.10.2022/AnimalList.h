#pragma once
#include "Animals/Animals.h"
#include <list>
#include <conio.h>

class AnimalList
{
	list<Animal*> animals;

	// добавить
	bool Add()
	{
		char choise = ' ';
		system("cls");
		cout << "Select animal to add:\n";
		cout << "1) Cat\n";
		cout << "2) Dog\n";
		cout << "3) Dolphin\n";
		cout << "4) Parrot\n";
		cout << "5) Pinguin\n\n";
		do
		{
			choise = _getch();
			switch (choise)
			{
			case'1':
				animals.push_back(new Cat);
				break;
			case'2':
				animals.push_back(new Dog);
				break;
			case'3':
				animals.push_back(new Dolphin);
				break;
			case'4':
				animals.push_back(new Parrot);
				break;
			case'5':
				animals.push_back(new Pinguin);
				break;
			case 27:
				return false;
				break;
			default:
				break;
			}

		} while (!(choise >= '1' && choise <= '5'));

		string temp;
		double temp2;
		cout << "Enter Name: ";
		cin >> temp;
		animals.back()->SetName(temp.c_str());
		cout << "Enter Kg: ";
		cin >> temp2;
		animals.back()->SetKg(temp2);
		cout << "Enter Continent: ";
		cin >> temp;
		animals.back()->SetContinent(temp.c_str());

		cout << "\n[Added New Animal]";
		_getch();
		return true;
	}

	// удалиить 
	void Delete()
	{

		if (animals.size() == 0)
		{
			system("cls");
			cout << "[Animal List Is Empty]";
		}
		else
		{
			size_t choise;
			do
			{
				system("cls");
				cout << "Enter Animal Number: ";
				cin >> choise;

			} while (!(choise <= animals.size() && choise > 0));
			choise--;

			auto temp = animals.begin();

			advance(temp, choise);


			delete temp._Ptr->_Myval;

			animals.erase(temp);

			cout << "\n[An Animal Deleted]";
		}
		_getch();
	}

	// поиск по имени
	void SearchByName()
	{
		string str;
		cout << "Enter Animal Name: ";
		cin >> str;
		cout << endl;

		cout << "Found:\n";

		int j = 1;
		for (auto i = animals.begin(); i != animals.end(); i++)
		{
			if (strcmp((*i)->GetName(), str.c_str()) == 0)
			{
				cout << "(" << j << ")";
				(*i)->Print();
				cout << endl;
			}
			j++;
		}
	}

	// поиск по весу
	void SearchByWeight()
	{
		double weight;
		cout << "Enter Animal Weight: ";
		cin >> weight;
		cout << endl;

		cout << "Found:\n";

		int j = 1;
		for (auto i = animals.begin(); i != animals.end(); i++)
		{
			if ((*i)->GetKg() == weight)
			{
				cout << "(" << j << ")";
				(*i)->Print();
				cout << endl;
			}
			j++;
		}
	}

	// поиск по континенту
	void SearchByContinent()
	{
		string str;
		cout << "Enter Continent: ";
		cin >> str;
		cout << endl;

		cout << "Found:\n";

		int j = 1;
		for (auto i = animals.begin(); i != animals.end(); i++)
		{
			if (strcmp((*i)->GetContinent(), str.c_str()) == 0)
			{
				cout << "(" << j << ")";
				(*i)->Print();
				cout << endl;
			}
			j++;
		}
	}

	// поиск
	void Search()
	{
		char choise = ' ';
		system("cls");
		cout << "Search By:\n";
		cout << "1) Name\n";
		cout << "2) Weight\n";
		cout << "3) Continent\n\n";
		do
		{
			choise = _getch();
			switch (choise)
			{
			case'1':
				SearchByName();
				break;
			case'2':
				SearchByWeight();
				break;
			case'3':
				SearchByContinent();
				break;
			case 27:
				return;
				break;
			default:
				break;
			}
		} while (!(choise >= '1' && choise <= '3'));
		_getch();
	}

	// вставка
	void Insert()
	{
		size_t choise;
		do
		{
			system("cls");
			cout << "Enter Insert Number: ";
			cin >> choise;

		} while (!(choise <= animals.size() && choise > 0));
		choise--;

		if (Add())
		{
			system("cls");
			auto temp = animals.begin();

			advance(temp, choise);

			auto element = animals.back();
			animals.pop_back();

			animals.insert(temp, element);
			cout << "[New Animal Inserted]";
			_getch();
		}
	}

	// вывести список
	void Show()
	{
		system("cls");
		int j = 1;
		for (auto i = animals.begin(); i != animals.end(); i++)
		{
			cout << "(" << j << ")";
			(*i)->Print();
			cout << endl;
			j++;
		}
		_getch();
	}

	// редактирование
	void Edit()
	{
		size_t choise;
		do
		{
			system("cls");
			cout << "Enter Edit Number: ";
			cin >> choise;

		} while (!(choise <= animals.size() && choise > 0));
		choise--;

		auto temp = animals.begin();

		advance(temp, choise);

		cout << "(" << choise + 1 << ")";
		(*temp)->Print();
		cout << endl;

		string str;
		double dbl;

		cout << "Enter New Name: ";
		cin >> str;
		(*temp)->SetName(str.c_str());
		cout << "Enter New Kg: ";
		cin >> dbl;
		(*temp)->SetKg(dbl);
		cout << "Enter New Continent: ";
		cin >> str;
		(*temp)->SetContinent(str.c_str());
		cout << "\n[Animal Edited]";
		_getch();
	}

	// меню
	void Menu()
	{
		system("cls");
		cout << "|Animal List|\n";
		cout << "1) Add\n";
		cout << "2) Delete\n";
		cout << "3) Search\n";
		cout << "4) Insert\n";
		cout << "5) Show\n";
		cout << "6) Edit\n";
		cout << "7) Exit\n";
	}

public:

	// основная функция
	void Start()
	{
		char choise;
		do
		{
			Menu();
			choise = _getch();
			switch (choise)
			{
			case'1':
				Add();
				break;
			case'2':
				Delete();
				break;
			case'3':
				Search();
				break;
			case'4':
				Insert();
				break;
			case'5':
				Show();
				break;
			case'6':
				Edit();
				break;
			case'7':
			case 27:
				return;
				break;
			default:
				break;
			}
		} while (true);
	}
};

