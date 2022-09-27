#include <iostream>
using namespace std;


struct Element
{
	// Данные
	char data;
	// Адрес следующего элемента списка
	Element* Next;
};

// Односвязный список
class List
{
	// Адрес головного элемента списка
	Element* Head;
	// Адрес головного элемента списка
	Element* Tail;
	// Количество элементов списка
	int Count;

public:
	// Конструктор
	List();
	// Деструктор
	~List();

	// Добавление элемента в список
	// (Новый элемент становится последним)
	void Add(char data);

	// Удаление элемента списка
	// (Удаляется головной элемент)
	void Del();
	// Удаление всего списка
	void DelAll();

	// Распечатка содержимого списка
	// (Распечатка начинается с головного элемента)
	void Print();

	// Получение количества элементов, находящихся в списке
	int GetCount();


																		/*LAST ADDED*/
	// Вставка элемента в нужную позицию
	void Insert(char data, int posiotion);

	// Удаление элемента по заданной позиции
	void Remove(int position);

	// Поиск значения и возврат его позиции
	int Find(char c);
};

List::List()
{
	// Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// Вызов функции удаления
	DelAll();
}

int List::GetCount()
{
	// Возвращаем количество элементов
	return Count;
}

void List::Add(char data)
{
	// создание нового элемента
	Element* temp = new Element;

	// заполнение данными
	temp->data = data;
	// следующий элемент отсутствует
	temp->Next = NULL;
	// новый элемент становится последним элементом списка
	// если он не первый добавленный
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
		Count++;
	}
	// новый элемент становится единственным
	// если он первый добавленный
	else {
		Head = Tail = temp;
		Count++;
	}
}

void List::Del()
{
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// перебрасываем голову на следующий элемент
	Head = Head->Next;
	// удаляем бывший головной элемент
	delete temp;
	Count--;
}

void List::DelAll()
{
	// Пока еще есть элементы
	while (Head != 0)
		// Удаляем элементы по одному
		Del();
	Count--;
}

void List::Print()
{
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// Пока еще есть элементы
	while (temp != 0)
	{
		// Выводим данные
		cout << temp->data << " ";
		// Переходим на следующий элемент
		temp = temp->Next;
	}

	cout << "\n\n";
}


																		/*LAST ADDED*/

// Вставка элемента в нужную позицию 
void List::Insert(char data, int position)
{
	if (position - 1 <= Count && position > 1)
	{
		position--;
		Element* ElPosition = Head;
		while (position > 1)
		{
			ElPosition = ElPosition->Next;
			position--;
		}
		Element* temp = new Element;
		temp->data = data;
		temp->Next = ElPosition->Next;
		ElPosition->Next = temp;
		Count++;
	}
	else if (position == 1)
	{
		Element* temp = new Element;
		temp->data = data;
		temp->Next = Head;
		Head = temp;
		Count++;
	}
	else
	{
		Add(data);
	}
}

// Удаление элемента по заданной позиции
void List::Remove(int position)
{
	if (position <= Count && position > 1)
	{
		position--;
		Element* ElPosition = Head;
		while (position > 1)
		{
			ElPosition = ElPosition->Next;
			position--;
		}
		Element* elDel = ElPosition->Next;
		ElPosition->Next = elDel->Next;
		delete elDel;
		Count--;
	}
	else if (position == 1)
	{
		Del();
	}
}

// Поиск значения и возврат его позиции
int List::Find(char c)
{
	int count = 0;
	Element* temp = Head;
	do
	{
		count++;
		if (temp->data == c)
			return count;
		else
			temp = temp->Next;
	} while (temp != NULL);
	return NULL;
}

// Тестовый пример
void main()
{
	// Создаем объект класса List
	List lst;

	// Тестовая строка
	char s[] = "Hello, World !!!";
	// Выводим строку
	cout << s << "\n\n";
	// Определяем длину строки
	int len = strlen(s);
	// Загоняем строку в список
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	// Распечатываем содержимое списка
	//lst.Print();
	// Удаляем три элемента списка
	/*lst.Del();
	lst.Del();
	lst.Del();*/
	//Распечатываем содержимое списка
	lst.Print();
	lst.Insert('g', 16);
	lst.Print();
	lst.Remove(2);
	lst.Print();
	cout << endl << lst.Find('W');
}

	/*RESULT*/

/*
Hello, World !!!

H e l l o ,   W o r l d   ! ! !

H e l l o ,   W o r l d   ! ! g !

H l l o ,   W o r l d   ! ! g !


7
*/