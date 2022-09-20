#include"Matrix.h"
#include "Point.h"

int main()
{
	Matrix<int> obj1(3, 5);
	obj1.Random();
	obj1.Print();
	cout << "\n---------------------------------------\n";
	Matrix<int> b;
	b = obj1;
	b.Print();

	Matrix<Point> a(5,5);

	a.Random();
	a.Print();
	cout << endl;

	cout << a << endl;

	Matrix<Point> sum = a + 3;
	Matrix<Point> sum2 = 3 + a;

	if (sum > sum2)
	{
		cout << "sum > sum2\n";
	}
}