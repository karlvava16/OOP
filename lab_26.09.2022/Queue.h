#pragma once
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

template <class T>
class Queue
{
	// �������
	T* Wait;
	// ������������ ������ �������
	int MaxQueueLength;
	// ������� ������ �������
	int QueueLength;

public:
	// �����������
	Queue(int m);

	//����������
	~Queue();

	// ���������� ��������
	void Add(const T& c);

	// ���������� ��������
	T Extract();
	//void Extract();

	// ������� �������
	void Clear();

	// �������� ������������� ��������� � �������
	bool IsEmpty();

	// �������� �� ������������ �������
	bool IsFull();

	// ���������� ��������� � �������
	int GetCount();

	//������������ �������
	void Show();
};

template <class T>
void Queue<T>::Show() {
	cout << "\n-------------------------------------\n";
	//������������ �������
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " ";
	}
	cout << "\n-------------------------------------\n";
}

template <class T>
Queue<T>::~Queue()
{
	//�������� �������
	delete[]Wait;
}

template <class T>
Queue<T>::Queue(int m)
{
	//�������� ������
	MaxQueueLength = m;
	//������� �������
	Wait = new T[MaxQueueLength];
	// ���������� ������� �����
	QueueLength = 0;
}

template <class T>
void Queue<T>::Clear()
{
	// ����������� "�������" ������� 
	QueueLength = 0;
}

template <class T>
bool Queue<T>::IsEmpty()
{
	// ����?
	return QueueLength == 0;
}

template <class T>
bool Queue<T>::IsFull()
{
	// �����?
	return QueueLength == MaxQueueLength;
}

template <class T>
int Queue<T>::GetCount()
{
	// ���������� �������������� � ����� ���������
	return QueueLength;
}

template <class T>
void Queue<T>::Add(const T& c)
{
	// ���� � ������� ���� ��������� �����, �� ����������� ����������
	// �������� � ��������� ����� �������
	if (!IsFull())
		Wait[QueueLength++] = c;
}

template <class T>
T Queue<T>::Extract()
{
	// ���� � ������� ���� ��������, �� ���������� ���, 
	// ������� ����� ������ � �������� �������	
	if (!IsEmpty()) {
		//��������� ������
		T temp = Wait[0];

		//�������� ��� ��������
		for (int i = 1; i < QueueLength; i++)
			Wait[i - 1] = Wait[i];

		//��������� ����������
		QueueLength--;

		//������� ������(�������)
		return temp;
	}

	else // ���� � ����� ��������� ���
		return T();
}