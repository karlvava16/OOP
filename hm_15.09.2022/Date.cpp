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
            year = 1;
        }
    } while (day > max_day || day < 1 || month > 12 || month < 1);
}

// default
Date::Date() : day(1), month(1), year(1) {}

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



/*GLOBAL OPERATOR OVERLOAD*/

Date& operator++(Date& obj)
{
    obj.SetDay(obj.GetDay() + 1);
    return obj;
}

Date& operator--(Date& obj)
{
    obj.SetDay(obj.GetDay() - 1);
    return obj;
}

Date operator++(Date& obj, int)
{
    Date temp(obj);
    obj.SetDay(obj.GetDay() + 1);
    return temp;
}

Date operator--(Date& obj, int)
{
    Date temp(obj);
    obj.SetDay(obj.GetDay() - 1);
    return temp;
}

bool operator==(const Date& obj1, const Date& obj2)
{
    return (obj1.GetYear() == obj2.GetYear() && obj1.GetMonth() == obj2.GetMonth() && obj1.GetDay() == obj2.GetDay());
}

bool operator!=(const Date& obj1, const Date& obj2)
{
    return (obj1.GetYear() != obj2.GetYear() || obj1.GetMonth() != obj2.GetMonth() || obj1.GetDay() != obj2.GetDay());
}

bool operator<(const Date& obj1, const Date& obj2)
{
    if (obj1.GetYear() < obj2.GetYear())
        return true;
    else if (obj1.GetYear() > obj2.GetYear())
        return false;
    else
    {
        if (obj1.GetMonth() < obj2.GetMonth())
            return true;
        else if (obj1.GetMonth() > obj2.GetMonth())
            return false;
        else
        {
            if (obj1.GetDay() < obj2.GetDay())
                return true;
            else
                return false;
        }
    }
}

bool operator>(const Date& obj1, const Date& obj2)
{
    return (obj1 != obj2 && !(obj1 < obj2));
}

bool operator<=(const Date& obj1, const Date& obj2)
{
    return(obj1 < obj2 || obj1 == obj2);
}

bool operator>=(const Date& obj1, const Date& obj2)
{
    return(obj1 > obj2 || obj1 == obj2);
}


Date operator+(const Date& obj, int days)
{
    Date temp(obj);
    temp.SetDay(temp.GetDay() + days);
    return temp;
}

Date operator-(const Date& obj, int days)
{

    return (obj + (-days));
}

int operator-(const Date& obj1, const Date& obj2)
{
    if (obj1 == obj2)
        return 0;
    int days = 0;
    const Date& obj_1 = obj1 > obj2 ? obj1 : obj2;
    Date obj_2 = obj1 < obj2 ? obj1 : obj2;
    while (obj_1 != obj_2)
    {
        obj_2++;
        days++;
    }
    return days;
}

Date operator+(int days, const Date& obj)
{   
    return Date(obj + days);
}

Date operator-(int days, const Date& obj)
{
    return Date(obj - days);
}


Date& operator+=(Date& obj, int days)
{
    obj.SetDay(obj.GetDay() + days);
    return obj;
}

Date& operator-=(Date& obj, int days)
{
    obj.SetDay(obj.GetDay() - days);
    return obj;
}