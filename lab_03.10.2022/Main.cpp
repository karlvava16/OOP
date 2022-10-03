#include <iostream>
#include "Person.h"
#include "Teacher.h"
#include "Student.h"
using namespace std;

int main()
{
	Person obj1("Vlad", 18);
	Teacher obj2;
	Student obj3("Vlad", 18, "ItStep");
	return 0;
}