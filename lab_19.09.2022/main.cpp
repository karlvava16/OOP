#include "Matrix.h"

int main()
{
	cout << "|Obj1 (3,5)|" << endl;
	Matrix<int> obj1(3, 5);
	obj1.Random();
	obj1.Print();
	cout << endl;

	cout << "|Obj2 (obj2 = obj1)|" << endl;
	Matrix<int> obj2;
	obj2 = obj1;
	obj2.Print();
	cout << endl;

	cout << "|Obj3 (obj3 = obj1 + 4)|" << endl;
	Matrix<int> obj3 = obj1 + 4;
	obj3.Print();
	cout << endl;
}