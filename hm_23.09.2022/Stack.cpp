#include <iostream>
#include <time.h>
using namespace std;

class Stack
{
	// ������ � ������� ������� �����
	enum { EMPTY = -1, FULL = 50 };
	// ������ ��� �������� ������
	char st[FULL + 1];
	// ��������� �� ������� �����
	int top;

public:
	// �����������
	Stack();

	// ���������� ��������
	void Push(char c);

	// ���������� ��������
	char Pop();

	char Top();

	// ������� �����
	void Clear();

	// �������� ������������� ��������� � �����
	bool IsEmpty();

	// �������� �� ������������ �����
	bool IsFull();

	// ���������� ��������� � �����
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
	// ���������� ���� ����
	top = EMPTY;
}

void Stack::Clear()
{
	// ����������� "�������" ����� 
	// (������ � ������� ��� ��� ����������, 
	// �� ������� ������, ��������������� �� ������ � �������� �����,
	// ����� �� ������������)
	top = EMPTY;
}

bool Stack::IsEmpty()
{
	// ����?
	return top == EMPTY;
}

bool Stack::IsFull()
{
	// �����?
	return top == FULL;
}

int Stack::GetCount()
{
	// ���������� �������������� � ����� ���������
	return top + 1;
}

void Stack::Push(char c)
{
	// ���� � ����� ���� �����, �� ����������� ���������
	// �� ������� ����� � ��������� ����� �������
	if (!IsFull())
		st[++top] = c;
}

char Stack::Top()
{
	return st[top];
}

char Stack::Pop()
{
	// ���� � ����� ���� ��������, �� ���������� ������� �
	// ��������� ��������� �� ������� �����
	if (!IsEmpty())
		return st[top--];
	else // ���� � ����� ��������� ���
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
