#include <iostream>
#include "Laptop.h"
using namespace std;

int main()
{
	Printer pr;
	Laptop lt(&pr);
	lt.Show();
	return 0;
}