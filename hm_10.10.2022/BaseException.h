#pragma once
#include <iostream>
using namespace std;

class BaseException
{
protected:
	char str[100];
public:
	BaseException() : str("") {};
	BaseException(const char* s)
	{
		strcpy_s(str, strlen(s) + 1, s);
	}
	virtual void Print()
	{
		cout <<'[' << str << "] ";
	}
};