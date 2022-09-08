#include <iostream>
using namespace std;

class Student
{

private:
	char* name; // имя
	char* surname; // фамилия
	char* date; // дата
	char* phoneNumber; // номер телефона
	int groupNumber; // номер группы
	int year; // год

public:

	// дефолтный конструктор
	Student()
	{
		name = nullptr;
		surname = nullptr;
		date = nullptr;
		phoneNumber = nullptr;
		groupNumber = 0;
		year = 0;
	}

	// конструктор с параметрами
	Student(const char* n, const char* s, const char* d, const char* phn, int gn, int y)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		surname = new char[strlen(s) + 1];
		strcpy_s(surname, strlen(s) + 1, s);
		date = new char[strlen(d) + 1];
		strcpy_s(date, strlen(d) + 1, d);
		phoneNumber = new char[strlen(phn) + 1];
		strcpy_s(phoneNumber, strlen(phn) + 1, phn);
		groupNumber = gn;
		year = y;
	}

	// деструктор
	~Student()
	{
		delete[] name;
		delete[] surname;
		delete[] date;
		delete[] phoneNumber;
	}

	// полный ввод данных
	void Input()
	{
		char buffer[20];

		cout << "Enter name : ";
		cin >> buffer;
		if (name != nullptr)
			delete[] name;
		name = new char[strlen(buffer) + 1];
		strcpy_s(name, strlen(buffer) + 1, buffer);

		cout << "Enter surname : ";
		cin >> buffer;
		if (surname != nullptr)
			delete[] surname;
		surname = new char[strlen(buffer) + 1];
		strcpy_s(surname, strlen(buffer) + 1, buffer);

		cout << "Enter date : ";
		cin >> buffer;
		if (date != nullptr)
			delete[] date;
		date = new char[strlen(buffer) + 1];
		strcpy_s(date, strlen(buffer) + 1, buffer);

		cout << "Enter phone number : ";
		cin >> buffer;
		if (phoneNumber != nullptr)
			delete[] phoneNumber;
		phoneNumber = new char[strlen(buffer) + 1];
		strcpy_s(phoneNumber, strlen(buffer) + 1, buffer);

		cout << "Enter group number : ";
		cin >> groupNumber;

		cout << "Enter year : ";
		cin >> year;
	}
	// вывод данных
	void Print()
	{
		cout << "Name : " << name << endl;
		cout << "Surname : " << surname << endl;
		cout << "Date : " << date << endl;
		cout << "Phone number : " << phoneNumber << endl;
		cout << "Group number : " << groupNumber << endl;
		cout << "Year : " << year << endl;
	}

	// геттеры
	const char* GetName()
	{
		return name;
	}
	const char* GetSurname()
	{
		return surname;
	}
	const char* GetDate()
	{
		return date;
	}
	const char* GetPhoneNumber()
	{
		return phoneNumber;
	}
	int GetGroupNumber()
	{
		return groupNumber;
	}
	int GetYear()
	{
		return year;
	}

	// сеттеры
	void SetName(const char* n)
	{
		if (name != nullptr)
			delete[] name;
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	void SetDate(const char* d)
	{
		if (date != nullptr)
			delete[] date;
		date = new char[strlen(d) + 1];
		strcpy_s(date, strlen(d) + 1, d);
	}
	void SetPhoneNumber(const char* phn)
	{
		if (phoneNumber != nullptr)
			delete[] phoneNumber;
		phoneNumber = new char[strlen(phn) + 1];
		strcpy_s(phoneNumber, strlen(phn) + 1, phn);
	}
	void SetGroupNumber(int gn)
	{
		groupNumber = gn;
	}
	void SetYear(int y)
	{
		year = y;
	}
};


int main()
{
	// установка значений через конструктор с параметрами
	Student me("Vladislav", "Karlinskyi", "23.04.2004", "+380", 213, 2004); 

	// вывод данных
	me.Print();
	
	// пример геттера
	cout << me.GetName();

	// пример сеттера
	me.SetName("Igor");
	
	// повторный вывод геттера
	cout << me.GetName();

	return 0;
