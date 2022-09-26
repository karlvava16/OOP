#pragma once
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

template <class T>
class QueuePriority
{
	// �������
	T* Wait;
	// ���������
	int* Pri;
	// ������������ ������ �������
	int MaxQueueLength;
	// ������� ������ �������
	int QueueLength;

public:
	// �����������
	QueuePriority(int m);

	//����������
	~QueuePriority();

	// ���������� ��������
	void Add(T c, int p);


	// ���������� ��������
	T Extract();

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
void QueuePriority<T>::Show() {
	cout << "\n-------------------------------------\n";
	//������������ �������
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " - " << Pri[i] << "\n\n";
	}
	cout << "\n-------------------------------------\n";
}

template <class T>
QueuePriority<T>::~QueuePriority()
{
	//�������� �������
	delete[]Wait;
	delete[]Pri;
}

template <class T>
QueuePriority<T>::QueuePriority(int m)
{
	//�������� ������
	MaxQueueLength = m;
	//������� �������
	Wait = new T[MaxQueueLength];
	Pri = new int[MaxQueueLength];
	// ���������� ������� �����
	QueueLength = 0;
}

template <class T>
void QueuePriority<T>::Clear()
{
	// ����������� "�������" ������� 
	QueueLength = 0;
}

template <class T>
bool QueuePriority<T>::IsEmpty()
{
	// ����?
	return QueueLength == 0;
}

template <class T>
bool QueuePriority<T>::IsFull()
{
	// �����?
	return QueueLength == MaxQueueLength;
}

template <class T>
int QueuePriority<T>::GetCount()
{
	// ���������� �������������� � ����� ���������
	return QueueLength;
}

template <class T>
void QueuePriority<T>::Add(T c, int p)
{
	// ���� � ������� ���� ��������� �����, �� ����������� ����������
	// �������� � ��������� ����� �������
	if (!IsFull()) {
		Wait[QueueLength] = c;
		Pri[QueueLength] = p;
		QueueLength++;
	}
}

template <class T>
T QueuePriority<T>::Extract()
{
	// ���� � ������� ���� ��������, �� ���������� ���, 
	// � �������� ��������� ��������� � �������� �������	
	if (!IsEmpty()) {

		//����� ������������ ������� - �������
		int max_pri = Pri[0];
		//� ������������ ������ = 0
		int pos_max_pri = 0;

		//���� ���������
		for (int i = 1; i < QueueLength; i++)
			//���� �������� ����� ������������ �������
			if (max_pri < Pri[i]) {
				max_pri = Pri[i];
				pos_max_pri = i;
			}

		//����������� ������������ �������
		T temp1 = Wait[pos_max_pri];
		int temp2 = Pri[pos_max_pri];

		//�������� ��� ��������
		for (int i = pos_max_pri; i < QueueLength - 1; i++) {
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		//��������� ����������
		QueueLength--;
		// ������� ������������ ��������	
		return temp1;
	}
	else T();
}