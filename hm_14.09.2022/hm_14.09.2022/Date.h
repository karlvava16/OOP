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

	Date& operator++(); // ++obj
	Date& operator--(); // --obj
	Date operator++(int); // obj++
	Date operator--(int); // obj++

	bool operator==(const Date& obj) const; // Date1 == Date2
	bool operator!=(const Date& obj) const; // Date1 != Date2
	bool operator<(const Date& obj) const; // Date1 < Date2
	bool operator>(const Date& obj) const; // Date1 > Date2
	bool operator<=(const Date& obj) const; // Date1 <= Date2
	bool operator>=(const Date& obj) const; // Date1 >= Date2

	Date operator+(int days) const; // Date + int
	Date operator-(int days) const; // Date - int
	int operator-(const Date& obj) const; // Date1 - Date2

	Date& operator+=(int days); // Date += int
	Date& operator-=(int days); // Date -= int


	// Getters
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;

	//Setters
	void SetDay(int d);
	void SetMonth(int m);
	void SetYear(int y);
};

