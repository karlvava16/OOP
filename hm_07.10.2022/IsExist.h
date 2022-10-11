#pragma once
#include <iostream>
using namespace std;

/// <summary>
/// класс существования объекта
/// </summary>
class IsExist
{
	bool isExist; // существует или нет
	
public:
	IsExist(bool value = true) : isExist(value) {} // конструктор

	bool operator()() const// получение результата
	{
		return isExist;
	}
	bool operator()(bool value) // назначить значение
	{
		isExist = value;
		return value;
	}
};