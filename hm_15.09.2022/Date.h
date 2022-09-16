#pragma once
class Date
{
private:
	int day; // day
	int month; // month
	int year; // year
	static bool format; // variable for switching format

	int MaxDayInMonth(); // max day in current month
	void Check(); // check correctness of date

public:
	Date(); // default
	Date(int d); // day
	Date(int d, int m); // day.month
	Date(int d, int m, int y); // day.month.year

	static void SwitchFormat(); // switch between dd.mm.yyyy and mm/dd/yyyy

	void Print() const; // output date in setted format

	// Getters
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;

	//Setters
	void SetDay(int d);
	void SetMonth(int m);
	void SetYear(int y);
};

/*GLOBAL OPERATOR OVERLOAD*/

Date& operator++(Date& obj); // ++obj
Date& operator--(Date& obj); // --obj
Date operator++(Date& obj, int); // obj++
Date operator--(Date& obj, int); // obj++

bool operator==(const Date& obj1, const Date& obj2); // Date1 == Date2
bool operator!=(const Date& obj1, const Date& obj2); // Date1 != Date2
bool operator<(const Date& obj1, const Date& obj2); // Date1 < Date2
bool operator>(const Date& obj1, const Date& obj2); // Date1 > Date2
bool operator<=(const Date& obj1, const Date& obj2); // Date1 <= Date2
bool operator>=(const Date& obj1, const Date& obj2); // Date1 >= Date2

Date operator+(const Date& obj, int days); // Date + int
Date operator-(const Date& obj, int days); // Date - int
int operator-(const Date& obj1, const Date& obj2); // Date1 - Date2
Date operator+(int days, const Date& obj); // int + Date
Date operator-(int days, const Date& obj); // int Date

Date& operator+=(Date& obj, int days); // Date += int
Date& operator-=(Date& obj, int days); // Date -= int