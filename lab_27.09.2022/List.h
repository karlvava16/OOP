#include <iostream>
using namespace std;

template<class T>
struct Elem
{
    T data; // ������
    Elem* next, * prev;
};

template <class T>
class List
{
    // ������, �����
    Elem<T>* Head, * Tail;
    // ���������� ���������
    int Count;

public:

    // �����������
    List();
    // ����������� �����������
    List(const List&);
    // ����������
    ~List();

    // �������� ����������
    int GetCount();
    // �������� ������� ������
    Elem<T>* GetElem(int);

    // ������� ���� ������
    void DelAll();
    // �������� ��������, ���� �������� �� �����������,
    // �� ������� ��� �����������
    void Del(int pos = 0);
    // ������� ��������, ���� �������� �� �����������,
    // �� ������� ��� �����������
    void Insert(int pos = 0);

    // ���������� � ����� ������
    void AddTail(const T& n);

    // ���������� � ������ ������
    void AddHead(const T& n);

    // ������ ������
    void Print();
    // ������ ������������� ��������
    void Print(int pos);

    List& operator = (const List&);
    // �������� ���� ������� (�����������)
    List operator + (const List&);

    // ��������� �� ���������
    bool operator == (const List&);
    bool operator != (const List&);
    bool operator <= (const List&);
    bool operator >= (const List&);
    bool operator < (const List&);
    bool operator > (const List&);

    // ��������������� ������
    List operator - ();
};

template <class T>
List<T>::List()
{
    // ���������� ������ ����
    Head = Tail = NULL;
    Count = 0;
}

template <class T>
List<T>::List(const List<T>& L)
{
    Head = Tail = NULL;
    Count = 0;

    // ������ ������, �� �������� ��������
    Elem<T>* temp = L.Head;
    // ���� �� ����� ������
    while (temp != 0)
    {
        // ���������� ������
        AddTail(temp->data);
        temp = temp->next;
    }
}

template <class T>
List<T>::~List()
{
    // ������� ��� ��������
    DelAll();
}

template <class T>
void List<T>::AddHead(const T& n)
{
    // ����� �������
    Elem<T>* temp = new Elem<T>;

    // ����������� ���
    temp->prev = 0;
    // ��������� ������
    temp->data = n;
    // ��������� - ������ ������
    temp->next = Head;

    // ���� �������� ����?
    if (Head != 0)
        Head->prev = temp;

    // ���� ������� ������, �� �� ������������ � ������ � �����
    if (Count == 0)
        Head = Tail = temp;
    else
        // ����� ����� ������� - ��������
        Head = temp;

    Count++;
}

template <class T>
void List<T>::AddTail(const T& n)
{
    // ������� ����� �������
    Elem<T>* temp = new Elem<T>;
    // ���������� ���
    temp->next = 0;
    // ��������� ������
    temp->data = n;
    // ���������� - ������ �����
    temp->prev = Tail;

    // ���� �������� ����?
    if (Tail != 0)
        Tail->next = temp;

    // ���� ������� ������, �� �� ������������ � ������ � �����
    if (Count == 0)
        Head = Tail = temp;
    else
        // ����� ����� ������� - ���������
        Tail = temp;

    Count++;
}

template <class T>
void List<T>::Insert(int pos)
{
    // ���� �������� ����������� ��� ����� 0, �� ����������� ���
    if (pos == 0)
    {
        cout << "Input position: ";
        cin >> pos;
    }

    // ������� �� 1 �� Count?
    if (pos < 1 || pos > Count + 1)
    {
        // �������� �������
        cout << "Incorrect position !!!\n";
        return;
    }

    // ���� ������� � ����� ������
    if (pos == Count + 1)
    {
        // ����������� ������
        int data;
        cout << "Input new number: ";
        cin >> data;
        // ���������� � ����� ������
        AddTail(data);
        return;
    }
    else if (pos == 1)
    {
        // ����������� ������
        int data;
        cout << "Input new number: ";
        cin >> data;
        // ���������� � ������ ������
        AddHead(data);
        return;
    }

    // �������
    int i = 1;

    // ����������� �� ������ n - 1 ���������
    Elem<T>* Ins = Head;

    while (i < pos)
    {
        // ������� �� ��������, 
        // ����� ������� �����������
        Ins = Ins->next;
        i++;
    }

    // ������� �� ��������, 
    // ������� ������������
    Elem<T>* PrevIns = Ins->prev;

    // ������� ����� �������
    Elem<T>* temp = new Elem<T>;

    // ������ ������
    cout << "Input new number: ";
    cin >> temp->data;

    // ��������� ������
    if (PrevIns != 0 && Count != 1)
        PrevIns->next = temp;

    temp->next = Ins;
    temp->prev = PrevIns;
    Ins->prev = temp;

    Count++;
}

template <class T>
void List<T>::Del(int pos)
{
    // ���� �������� ����������� ��� ����� 0, �� ����������� ���
    if (pos == 0)
    {
        cout << "Input position: ";
        cin >> pos;
    }
    // ������� �� 1 �� Count?
    if (pos < 1 || pos > Count)
    {
        // �������� �������
        cout << "Incorrect position !!!\n";
        return;
    }
    ///------------------------------------------------
    // �������
   Elem<T>* Del = nullptr;
   int i = 1;

    // ���������� � ����� ������� 
    // ������� ���������
    if (pos <= Count / 2)
    {
        // ������ � ������
        Del = Head;       

        while (i < pos)
        {
            // ��������� �� ������� ��������
            Del = Del->next;
            i++;
        }
    }
    else
    {
        // ������ � ������
        Del = Tail;
       while (i <= Count - pos)
        {
            // ��������� �� ������� ��������
            Del = Del->prev;
            i++;
        }
    }
    /////---------------------------------------------

    // ������� �� ��������, 
    // ������� ������������ ����������
    Elem<T>* PrevDel = Del->prev;
    // ������� �� ��������, ������� ������� �� ���������
    Elem<T>* AfterDel = Del->next;

    // ���� ������� �� ������
    if (PrevDel != 0 && Count != 1)
        PrevDel->next = AfterDel;
    // ���� ������� �� �����
    if (AfterDel != 0 && Count != 1)
        AfterDel->prev = PrevDel;

    // ��������� �������?
    if (pos == 1)
        Head = AfterDel;
    if (pos == Count)
        Tail = PrevDel;

    // �������� ��������
    delete Del;

    Count--;
}

template <class T>
void List<T>::Print(int pos)
{
    // ������� �� 1 �� Count?
    if (pos < 1 || pos > Count)
    {
        // �������� �������
        cout << "Incorrect position !!!\n";
        return;
    }

    Elem<T>* temp;

    // ���������� � ����� ������� 
    // ������� ���������
    if (pos <= Count / 2)
    {
        // ������ � ������
        temp = Head;
        int i = 1;

        while (i < pos)
        {
            // ��������� �� ������� ��������
            temp = temp->next;
            i++;
        }
    }
    else
    {
        // ������ � ������
        temp = Tail;
        int i = 1;

        while (i <= Count - pos)
        {
            // ��������� �� ������� ��������
            temp = temp->prev;
            i++;
        }
    }
    // ����� ��������
    cout << pos << " Elem<T>ent: ";
    cout << temp->data << endl;
}

template <class T>
void List<T>::Print()
{
    // ���� � ������ ������������ ��������, �� ��������� �� ����
    // � �������� ��������, ������� � ���������
    if (Count != 0)
    {
        Elem<T>* temp = Head;
        cout << "\n";
        while (temp->next != 0)
        {
            cout << temp->data << "\n";
            temp = temp->next;
        }

        cout << temp->data << "\n";
    }
}

template <class T>
void List<T>::DelAll()
{
    // ���� �������� ��������, ������� �� ������ � ������
    while (Count != 0)
        Del(1);
}

template <class T>
int List<T>::GetCount()
{
    return Count;
}
/// <summary>

template <class T>
Elem<T>* List<T>::GetElem(int pos)
{
    Elem<T>* temp = nullptr;
    // �������
   int i = 1;

    // ���������� � ����� ������� 
    // ������� ���������
    if (pos <= Count / 2)
    {
        // ������ � ������
        temp = Head;

        while (i < pos)
        {
            // ��������� �� ������� ��������
            temp = temp->next;
            i++;
        }
    }
    else
    {
        // ������ � ������
        temp = Tail;
        while (i <= Count - pos)
        {
            // ��������� �� ������� ��������
            temp = temp->prev;
            i++;
        }
    }
    /////---------------------------------------------

    // ������� �� 1 �� Count?
    if (pos < 1 || pos > Count)
    {
        // �������� �������
        cout << "Incorrect position !!!\n";
        return 0;
    }

     return temp;
}

template <class T>
List<T>& List<T>::operator = (const List<T>& L)
{
    // �������� ������������ �������� "������ ����"
    if (this == &L)
        return *this;

    // �������� ������� ������
    this->~List(); // DelAll();

    Elem<T>* temp = L.Head;

    // �������� ��������
    while (temp != 0)
    {
        AddTail(temp->data);
        temp = temp->next;
    }

    return *this;
}
// �������� ���� �������
template <class T>
List<T> List<T>::operator + (const List<T>& L)
{
    // ������� �� ��������� ������ �������� ������� ������
    List Result(*this);
    // List Result = *this;

    Elem<T>* temp = L.Head;

    // ��������� �� ��������� ������ �������� ������� ������
    while (temp != 0)
    {
        Result.AddTail(temp->data);
        temp = temp->next;
    }

    return Result;
}

template <class T>
bool List<T>::operator == (const List<T>& L)
{
    // ��������� �� ����������
    if (Count != L.Count)
        return false;

    Elem<T>* t1, * t2;

    t1 = Head;
    t2 = L.Head;

    // ��������� �� ����������
    while (t1 != 0)
    {
        // ������� ������, �������
        // ��������� �� ���������� ��������
        if (t1->data != t2->data)
            return false;

        t1 = t1->next;
        t2 = t2->next;
    }

    return true;
}

template <class T>
bool List<T>::operator != (const List<T>& L)
{
    // ���������� ���������� ������� ���������
    return !(*this == L);
}

template <class T>
bool List<T>::operator >= (const List<T>& L)
{
    // ��������� �� ����������
    if (Count > L.Count)
        return true;
    // ��������� �� ����������
    if (*this == L)
        return true;

    return false;
}

template <class T>
bool List<T>::operator <= (const List<T>& L)
{
    // ��������� �� ����������
    if (Count < L.Count)
        return true;
    // ��������� �� ����������
    if (*this == L)
        return true;

    return false;
}

template <class T>
bool List<T>::operator > (const List<T>& L)
{
    if (Count > L.Count)
        return true;

    return false;
}

template <class T>
bool List<T>::operator < (const List<T>& L)
{
    if (Count < L.Count)
        return true;

    return false;
}

// ���������
template <class T>
List<T> List<T>::operator - () // 1 2 3 4 5
{
    List Result;

    Elem<T>* temp = Head;
    // �������� �������� ������, ������� � ���������,
    // � ���� ����� ���������� ��������� � ������,
    // ����� ������� ��������� ������ Result ����� ���������
    // �������� � �������� �������
    while (temp != 0)
    {
        Result.AddHead(temp->data);// 5 4 3 2 1
        temp = temp->next;
    }

    return Result;
}
