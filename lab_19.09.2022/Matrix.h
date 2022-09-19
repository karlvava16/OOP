#pragma once
#include <iostream>
using namespace std;

template <class T>
class Matrix
{
	T** arr; // двумерный массив(матрица)
	int row; // строки
	int column; // столбцы

public:
	Matrix();
	Matrix(int row, int column);
	Matrix(const Matrix<T>& obj);
	~Matrix();

	Matrix<T> operator+(T k);
	Matrix<T> operator-(T k);
	Matrix<T> operator*(T k);
	Matrix<T> operator/(T k);
	Matrix<T>& operator=(const Matrix<T>& obj);



	void Print();
	void Random();
};

template<class T>
Matrix<T>::Matrix()
{
	arr = nullptr;
	row = column = 0;
}

template<class T>
Matrix<T>::Matrix(int row, int column)
{
	this->row = row;
	this->column = column;
	arr = new T * [this->row];
	for (int i = 0; i < this->row; i++)
	{
		arr[i] = new T[this->column];
	}
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& obj) : Matrix()
{
	row = obj.row;
	column = obj.column;
	arr = new T * [row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new T[column];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			arr[i][j] = obj.arr[i][j];
		}
	}
}

template<class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < row; i++)
		delete[] arr[i];
	delete[]arr;
}

template<class T>
Matrix<T> Matrix<T>::operator+(T k)
{
	Matrix<T> temp(*this);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			temp.arr[i][j] += k;
		}
	}
	return temp;
}

template<class T>
Matrix<T> Matrix<T>::operator-(T k)
{
	Matrix<T> temp(*this);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			temp.arr[i][j] -= k;
		}
	}
	return temp;
}

template<class T>
Matrix<T> Matrix<T>::operator*(T k)
{
	Matrix<T> temp(*this);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			temp.arr[i][j] *= k;
		}
	}
	return temp;
}

template<class T>
Matrix<T> Matrix<T>::operator/(T k)
{
	Matrix<T> temp(*this);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			temp.arr[i][j] /= k;
		}
	}
	return temp;
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& obj)
{
	if (this == &obj)
		return *this;

	if (arr != nullptr)
	{
		for (int i = 0; i < row; i++)
		{
			delete[] arr[i];
		}
		delete[]arr;
	}

	row = obj.row;
	column = obj.column;

	arr = new T * [row];
	for (size_t i = 0; i < row; i++)
	{
		arr[i] = new T[column];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			arr[i][j] = obj.arr[i][j];
		}
	}
	return *this;
}

template<class T>
void Matrix<T>::Print()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << endl << endl;
	}
}

template<class T>
void Matrix<T>::Random()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			arr[i][j] = rand() % 100 * 1.6;
		}
	}
}
