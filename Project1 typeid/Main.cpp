#include <iostream>
#include "Circle.h"
#include "Figure.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;
/*
Используя идентификацию типа времени исполнения
  (run - time type identification — RTTI) можно определить тип объекта во время исполнения программы.Для этого используется функция typeid. Для использования этой функции необходимо включить заголовочный файл typeinfo.Общая форма записи функции typeid имеет следующий вид :

typeid (объект)

Здесь объект является объектом, чей тип требуется определить.
Функция typeid возвращает ссылку на объект типа typeinfo, который описывает тип объекта. (В проекте стандарта С++ этот тип называется type_info.)
*/

Figure* GeneratorOfFigures()
{
    Figure* figure = nullptr;

    int choice = rand() % 3;// 0 1 2

    switch (choice)
    {
        case 0:
            figure = new Triangle(10.5, 6.5);
            break;
        case 1:
            figure = new Rectangle(10.5, 6.5);
            break;
        case 2:
            figure = new Circle(10);
            break;
    }

    return figure;
}

void Print(Figure** ptr, const int SIZE)
{
    int cicrle = 0;
    int rectangle = 0;
    int triangle = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (dynamic_cast<Circle*>(ptr[i])) // Нарушение принцыпа Барбары Лисков(SOLID) !!!! 
        {
            cicrle++;
        }
        else if (dynamic_cast<Triangle*>(ptr[i]))
        {
            triangle++;
        }
        else if (dynamic_cast<Rectangle*>(ptr[i]))
        {
            rectangle++;
        }
    }

    cout << "cicrle: " << cicrle << endl;
    cout << "rectangle: " << rectangle << endl;
    cout << "triangle: " << triangle << endl;
    cout << endl;
	

}

int main()
{
    srand(time(0));

    const int SIZE = 10;
    Figure** ptr = new Figure*[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        ptr[i] = GeneratorOfFigures();
    }

	Print(ptr, SIZE);
	delete[] ptr;
    system("pause");
    return 0;
}

/*RESULT*/

/*
cicrle: 2
rectangle: 2
triangle: 6
*/