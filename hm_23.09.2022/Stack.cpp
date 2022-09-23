#include <iostream>
#include <time.h>
using namespace std;

class Stack
{
	// Нижняя и верхняя границы стека
	enum { EMPTY = -1, FULL = 50 };
	// Массив для хранения данных
	char st[FULL + 1];
	// Указатель на вершину стека
	int top;

public:
	// Конструктор
	Stack();

	// Добавление элемента
	void Push(char c);

	// Извлечение элемента
	char Pop();

	char Top();

	// Очистка стека
	void Clear();

	// Проверка существования элементов в стеке
	bool IsEmpty();

	// Проверка на переполнение стека
	bool IsFull();

	// Количество элементов в стеке
	int GetCount();

	void Output()
	{
		for (int i = 0;i < top + 1;i++)
		{
			cout << st[i] << " ";
		}
		cout << endl;
	}
};


Stack::Stack()
{
	// Изначально стек пуст
	top = EMPTY;
}

void Stack::Clear()
{
	// Эффективная "очистка" стека 
	// (данные в массиве все еще существуют, 
	// но функции класса, ориентированные на работу с вершиной стека,
	// будут их игнорировать)
	top = EMPTY;
}

bool Stack::IsEmpty()
{
	// Пуст?
	return top == EMPTY;
}

bool Stack::IsFull()
{
	// Полон?
	return top == FULL;
}

int Stack::GetCount()
{
	// Количество присутствующих в стеке элементов
	return top + 1;
}

void Stack::Push(char c)
{
	// Если в стеке есть место, то увеличиваем указатель
	// на вершину стека и вставляем новый элемент
	if (!IsFull())
		st[++top] = c;
}

char Stack::Top()
{
	return st[top];
}

char Stack::Pop()
{
	// Если в стеке есть элементы, то возвращаем верхний и
	// уменьшаем указатель на вершину стека
	if (!IsEmpty())
		return st[top--];
	else // Если в стеке элементов нет
		return 0;
}

void CorrectExpression(const char* str) // is expression correct?
{
	int check = true;
	Stack s; // create stack
	for (int i = 0; i < strlen(str); i++) // from 0 till strlen(str)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') // add character if it is '(' / '{' / '['
		{
			s.Push(str[i]);
		}
		else if (str[i] == ')') // search for ')'
		{
			if (s.Top() == '(') // pop out if it is '('
				s.Pop();
			else				// push character, switch check of correctness, break the cycle
			{
				s.Push(str[i]);
				check = false;
				break;
			}
		}
		else if (str[i] == ']') // search for ']'
		{
			if (s.Top() == '[') // pop out if it is '['
				s.Pop();
			else				// push character, switch check of correctness, break the cycle
			{
				s.Push(str[i]);
				check = false;
				break;
			}
		}
		else if (str[i] == '}') // search for '}'
		{
			if (s.Top() == '{') // pop out if it is '{'
				s.Pop();
			else				// push character, switch check of correctness, break the cycle
			{
				s.Push(str[i]);
				check = false;
				break;
			}
		}
	}

	if (check)
		cout << "Expression is correct\n";
	else
	{
		cout << "Expression is incorrect : ";
		s.Output();
		cout << endl;
	}
}

void main()
{
	srand(time(0));
	
	string str1 = "({x-y-z}*[x+2y]-(z+4x))"; // first expr
	string str2 = "([x-y-z}*[x+2y)-{z+4x)]"; // second expr
	CorrectExpression(str1.c_str());
	CorrectExpression(str2.c_str());

	system("pause");
}

		//RESULT

/*
Expression is correct
Expression is incorrect : ( [ }
*/
