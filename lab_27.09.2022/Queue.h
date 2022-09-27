#pragma once
#include <iostream>
#include "List.h"
using namespace std;

template <class T>
class Queue
{
	// Очередь
	List<T> Wait;

public:
	// Добавление элемента
	void Add(const T& c);

	// Извлечение элемента
	T Extract();
	//void Extract();

	// Очистка очереди
	void Clear();

	// Проверка существования элементов в очереди
	bool IsEmpty();

	// Количество элементов в очереди
	int GetCount();

	//демонстрация очереди
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
	// Эффективная "очистка" очереди 
	Wait.DelAll();
}

template <class T>
bool Queue<T>::IsEmpty()
{
	// Пуст?
	return Wait.GetCount() == 0;
}

template <class T>
int Queue<T>::GetCount()
{
	// Количество присутствующих в стеке элементов
	return Wait.GetCount();
}

template <class T>
void Queue<T>::Add(const T& c)
{
	// Если в очереди есть свободное место, то увеличиваем количество
	// значений и вставляем новый элемент
	Wait.AddTail(c);
}

template <class T>
T Queue<T>::Extract()
{
	// Если в очереди есть элементы, то возвращаем тот, 
	// который вошел первым и сдвигаем очередь	
	Elem<T> temp = *Wait.GetElem(1);
	Wait.Del(1);
	return temp.data;
}