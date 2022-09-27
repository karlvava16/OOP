#pragma once
#include <iostream>
#include "List.h"
using namespace std;

template <class T>
class Queue
{
	// �������
	List<T> Wait;

public:
	// ���������� ��������
	void Add(const T& c);

	// ���������� ��������
	T Extract();
	//void Extract();

	// ������� �������
	void Clear();

	// �������� ������������� ��������� � �������
	bool IsEmpty();

	// ���������� ��������� � �������
	int GetCount();

	//������������ �������
	void Show();
};

template <class T>
void Queue<T>::Show() {
	cout << "\n-------------------------------------\n";
	Wait.Print();
	cout << "\n-------------------------------------\n";
}

template <class T>
void Queue<T>::Clear()
{
	// ����������� "�������" ������� 
	Wait.DelAll();
}

template <class T>
bool Queue<T>::IsEmpty()
{
	// ����?
	return Wait.GetCount() == 0;
}

template <class T>
int Queue<T>::GetCount()
{
	// ���������� �������������� � ����� ���������
	return Wait.GetCount();
}

template <class T>
void Queue<T>::Add(const T& c)
{
	// ���� � ������� ���� ��������� �����, �� ����������� ����������
	// �������� � ��������� ����� �������
	Wait.AddTail(c);
}

template <class T>
T Queue<T>::Extract()
{
	// ���� � ������� ���� ��������, �� ���������� ���, 
	// ������� ����� ������ � �������� �������	
	Elem<T> temp = *Wait.GetElem(1);
	Wait.Del(1);
	return temp.data;
}