#pragma once
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

template <class T>
class Queue
{
	// Очередь
	T* Wait;
	// Максимальный размер очереди
	int MaxQueueLength;
	// Текущий размер очереди
	int QueueLength;

public:
	// Конструктор
	Queue(int m);

	//Деструктор
	~Queue();

	// Добавление элемента
	void Add(const T& c);

	// Извлечение элемента
	T Extract();
	//void Extract();

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
void Queue<T>::Show() {
	cout << "\n-------------------------------------\n";
	//демонстрация очереди
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " ";
	}
	cout << "\n-------------------------------------\n";
}

template <class T>
Queue<T>::~Queue()
{
	//удаление очереди
	delete[]Wait;
}

template <class T>
Queue<T>::Queue(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new T[MaxQueueLength];
	// Изначально очередь пуста
	QueueLength = 0;
}

template <class T>
void Queue<T>::Clear()
{
	// Эффективная "очистка" очереди 
	QueueLength = 0;
}

template <class T>
bool Queue<T>::IsEmpty()
{
	// Пуст?
	return QueueLength == 0;
}

template <class T>
bool Queue<T>::IsFull()
{
	// Полон?
	return QueueLength == MaxQueueLength;
}

template <class T>
int Queue<T>::GetCount()
{
	// Количество присутствующих в стеке элементов
	return QueueLength;
}

template <class T>
void Queue<T>::Add(const T& c)
{
	// Если в очереди есть свободное место, то увеличиваем количество
	// значений и вставляем новый элемент
	if (!IsFull())
		Wait[QueueLength++] = c;
}

template <class T>
T Queue<T>::Extract()
{
	// Если в очереди есть элементы, то возвращаем тот, 
	// который вошел первым и сдвигаем очередь	
	if (!IsEmpty()) {
		//запомнить первый
		T temp = Wait[0];

		//сдвинуть все элементы
		for (int i = 1; i < QueueLength; i++)
			Wait[i - 1] = Wait[i];

		//уменьшить количество
		QueueLength--;

		//вернуть первый(нулевой)
		return temp;
	}

	else // Если в стеке элементов нет
		return T();
}