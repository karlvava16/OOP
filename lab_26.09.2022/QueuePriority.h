#pragma once
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

template <class T>
class QueuePriority
{
	// Очередь
	T* Wait;
	// Приоритет
	int* Pri;
	// Максимальный размер очереди
	int MaxQueueLength;
	// Текущий размер очереди
	int QueueLength;

public:
	// Конструктор
	QueuePriority(int m);

	//Деструктор
	~QueuePriority();

	// Добавление элемента
	void Add(T c, int p);


	// Извлечение элемента
	T Extract();

	// Очистка очереди
	void Clear();

	// Проверка существования элементов в очереди
	bool IsEmpty();

	// Проверка на переполнение очереди
	bool IsFull();

	// Количество элементов в очереди
	int GetCount();

	//демонстрация очереди
	void Show();
};

template <class T>
void QueuePriority<T>::Show() {
	cout << "\n-------------------------------------\n";
	//демонстрация очереди
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " - " << Pri[i] << "\n\n";
	}
	cout << "\n-------------------------------------\n";
}

template <class T>
QueuePriority<T>::~QueuePriority()
{
	//удаление очереди
	delete[]Wait;
	delete[]Pri;
}

template <class T>
QueuePriority<T>::QueuePriority(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new T[MaxQueueLength];
	Pri = new int[MaxQueueLength];
	// Изначально очередь пуста
	QueueLength = 0;
}

template <class T>
void QueuePriority<T>::Clear()
{
	// Эффективная "очистка" очереди 
	QueueLength = 0;
}

template <class T>
bool QueuePriority<T>::IsEmpty()
{
	// Пуст?
	return QueueLength == 0;
}

template <class T>
bool QueuePriority<T>::IsFull()
{
	// Полон?
	return QueueLength == MaxQueueLength;
}

template <class T>
int QueuePriority<T>::GetCount()
{
	// Количество присутствующих в стеке элементов
	return QueueLength;
}

template <class T>
void QueuePriority<T>::Add(T c, int p)
{
	// Если в очереди есть свободное место, то увеличиваем количество
	// значений и вставляем новый элемент
	if (!IsFull()) {
		Wait[QueueLength] = c;
		Pri[QueueLength] = p;
		QueueLength++;
	}
}

template <class T>
T QueuePriority<T>::Extract()
{
	// Если в очереди есть элементы, то возвращаем тот, 
	// у которого наивысший приоритет и сдвигаем очередь	
	if (!IsEmpty()) {

		//пусть приоритетный элемент - нулевой
		int max_pri = Pri[0];
		//а приоритетный индекс = 0
		int pos_max_pri = 0;

		//ищем приоритет
		for (int i = 1; i < QueueLength; i++)
			//если встречен более приоритетный элемент
			if (max_pri < Pri[i]) {
				max_pri = Pri[i];
				pos_max_pri = i;
			}

		//вытаскиваем приоритетный элемент
		T temp1 = Wait[pos_max_pri];
		int temp2 = Pri[pos_max_pri];

		//сдвинуть все элементы
		for (int i = pos_max_pri; i < QueueLength - 1; i++) {
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		//уменьшаем количество
		QueueLength--;
		// возврат извлеченного элемента	
		return temp1;
	}
	else T();
}