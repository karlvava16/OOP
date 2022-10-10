#pragma once
#include "BaseException.h"

// создание строки с длиной в ноль элементов
class StringLengthZero : public BaseException
{
public:
	StringLengthZero() : BaseException() {}
	StringLengthZero(const char* s) :BaseException(s)
	{}
	void Print()
	{
		cout << "StringLengthZero. String length is zero.\n";
	}
};

// ошибка при получении большей подстроки чем оснавная строка
class StrStrException : public BaseException
{
public:
	StrStrException() : BaseException() { }
	StrStrException(const char* s) : BaseException(s)
	{}
	void Print()
	{
		
		cout << "StrStrException. Substring is bigger than main string.\n";
	}
};

// ноль терминатор при инициализации списком
class NULLTerminatorInitListException : public BaseException
{
public:
	NULLTerminatorInitListException() : BaseException() { }
	NULLTerminatorInitListException(const char* s) : BaseException(s)
	{}
	void Print()
	{

		cout << "NULLTerminatorInitListException. Can't use null terminator for initializer list.\n";
	}
};

// индекс за пределами выделенной памяти
class IndexOutOfRange : public BaseException
{
public:
	IndexOutOfRange() : BaseException() { }
	IndexOutOfRange(const char* s) : BaseException(s)
	{}
	void Print()
	{
		cout << "IndexOutOfRange. Index out of range.\n";
	}
};

