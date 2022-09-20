#pragma once
#include <iostream>


class Point
{
	int x;
	int y;

public:
	Point();
	Point(int x);
	Point(int x, int y);

	Point& operator=(int k);

	Point operator+(int k) const;
	Point operator-(int k) const;
	Point operator*(int k) const;
	Point operator/(int k) const;
	Point operator-() const;

	bool operator>(const Point& obj) const;

	int GetX() const { return x; }
	int GetY() const { return y; }


	friend std::ostream& operator<<(std::ostream& os, const Point& obj);
};

/*FUNC*/

Point operator+(int k, const Point& obj);
Point operator-(int k, const Point& obj);
Point operator*(int k, const Point& obj);
Point operator/(int k, const Point& obj);
