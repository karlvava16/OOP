#include "Date.h"
#include <iostream>
#include <iomanip>

// init static var
bool Date::format = true;

// max day in current month
int Date::MaxDayInMonth()
{
    int max_day;
    bool year_leap;

    year_leap = (year % 400 == 0) ? true : (year % 100 != 0 && year % 4 == 0) ? true : false;

    switch (month)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        max_day = 30;
        break;
    case 2:
        max_day = year_leap ? 29 : 28;
        break;
    default:
        max_day = 31;
    }
    return max_day;
}

// check correctness of date
void Date::Check()
{
    int max_day; // variable for containing max day in month
    do
    {
        max_day = MaxDayInMonth(); // set max_day
        if (day > max_day) // if day is bigger then max_day : go to next month and set result(day - max_day) as a day 
        {
            day = day - max_day;
            month++;
        }
        if (month > 12) // if month is bigger then 12 : increase year and set result(month - 1) as a month
        {
            month = month - 12;
            year++;
        }
        if (day < 1) // if day is lower then 1 : decrease month and set day + MaxDayInMonth() as a day
        {
            month--;
            day = day + MaxDayInMonth();
        }
        if (month < 1) // if month is lower then 1 : decrease year and set month + 12 as a month
        {
            month = month + 12;
            year--;
        }
        if (year < 1) // if year is < then 1
        {
            day = 1;
            month = 1;
            year = 1;
        }
    } while (day > max_day || day < 1 || month > 12 || month < 1);
}

// default
Date::Date() : day(1), month(1), year(1970) {}

// day
Date::Date(int d) : Date()
{
    day = d;
    Check();
}

// day.month
Date::Date(int d, int m) : Date(d)
{
    month = m;
    Check();
}

// day.month.year
Date::Date(int d, int m, int y) : Date(d, m)
{
    year = y;
    Check();
}

// switch between dd.mm.yyyy and mm/dd/yyyy
void Date::SwitchFormat()
{
    format = !format;
}

// output date in setted format
void Date::Print() const
{
    if (format)
        std::cout << std::setfill('0') << std::setw(2) << day << '.' << std::setw(2) << month << '.' << std::setw(2) << year << std::endl;
    else
        std::cout << month << '/' << day << '/' << year << std::endl;
}

// ++obj
Date& Date::operator++()
{
    day += 1;
    Check();
    return *this;
}

// --obj
Date& Date::operator--()
{
    day -= 1;
    Check();
    return *this;
}

// obj++
Date Date::operator++(int)
{
    Date temp(*this);
    day += 1;
    Check();
    return temp;
}

// obj++
Date Date::operator--(int)
{
    Date temp(*this);
    day -= 1;
    Check();
    return temp;
}

// Date1 == Date2
bool Date::operator==(const Date& obj) const
{
    return (year == obj.year && month == obj.month && day == obj.day);
}

// Date1 != Date2
bool Date::operator!=(const Date& obj) const
{
    return (year != obj.year || month != obj.month || day != obj.day);
}

// Date1 < Date2
bool Date::operator<(const Date& obj) const
{
    if (year < obj.year)
        return true;
    else if (year > obj.year)
        return false;
    else
    {
        if (month < obj.month)
            return true;
        else if (month > obj.month)
            return false;
        else
        {
            if (day < obj.day)
                return true;
            else
                return false;
        }
    }
}

// Date1 > Date2
bool Date::operator>(const Date& obj) const
{
    return (*this != obj && !(*this < obj));
}

// Date1 <= Date2
bool Date::operator<=(const Date& obj) const
{
    return(*this < obj || *this == obj);
}

// Date1 >= Date2
bool Date::operator>=(const Date& obj) const
{
    return(*this > obj || *this == obj);
}

// Date + int
Date Date::operator+(int days) const
{
    Date result(*this);
    result.day += days;
    result.Check();
    return result;
}

// Date - int
Date Date::operator-(int days) const
{
    Date result(*this);
    result.day -= days;
    result.Check();
    return result;
}

// Date1 - Date2
int Date::operator-(const Date& obj) const
{

    if (*this == obj)
        return 0;
    int days = 0;
    const Date& obj1 = *this > obj ? *this : obj;
    Date obj2 = *this < obj ? *this : obj;
    while (obj1 != obj2)
    {
        obj2.day++;
        obj2.Check();
        days++;
    }
    return days;
}

// Date += int
Date& Date::operator+=(int days)
{
    day += days;
    Check();
    return *this;
}

// Date -= int
Date& Date::operator-=(int days)
{
    day -= days;
    Check();
    return *this;
}


// Getters
int Date::GetDay() const
{
    return day;
}

int Date::GetMonth() const
{
    return month;
}

int Date::GetYear() const
{
    return year;
}

//Setters
void Date::SetDay(int d)
{
    day = d;
    Check();
}

void Date::SetMonth(int m)
{
    month = m;
    Check();
}

void Date::SetYear(int y)
{
    year = y;
    Check();
}
