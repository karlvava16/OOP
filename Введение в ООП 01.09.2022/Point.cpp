#include <iostream>
#include <string>
using namespace std;


class Point // Класс точки
{
	/*Приватные поля*/
private:
	double x = 0; // ось абсцисс
	double y = 0; // ось ординат
	double z = 0; // ось аппликат

	/*Методы*/
public:

	// Установка значений
	void SetPoint(double xs, double ys, double zs)
	{
		x = xs;
		y = ys;
		z = zs;
	}

	// Ввод данных
	void Enter()
	{
		cout << "x : ";
		cin >> x;
		cout << "y : ";
		cin >> y;
		cout << "z : ";
		cin >> z;
		cout << endl;
	}

	//  Вывод данных
	void Print()
	{
		cout << '(' << x << ", " << y << ", " << z << ")\n";
	}

	// Акссесоры

	// Геттеры
	double GetX()
	{
		return x;
	}

	double GetY()
	{
		return y;
	}

	double GetZ()
	{
		return z;
	}

	// Сеттеры
	void SetX(double xs)
	{
		x = xs;
	}

	void SetY(double ys)
	{
		y = ys;
	}

	void SetZ(double zs)
	{
		z = zs;
	}

	// Запись точки в файл
	void WriteToFile(const char fileName[])
	{
		FILE* f;
		fopen_s(&f, fileName, "w");
		if (f == nullptr)
		{
			cout << "Cannot write file\n";
			return;
		}
		else
		{
			fputs(to_string(x).c_str(), f);
			fputc(' ', f);
			fputs(to_string(y).c_str(), f);
			fputc(' ', f);
			fputs(to_string(z).c_str(), f);
			fputc(' ', f);
			fputc('\n', f);

			fclose(f);
		}
	}

	// Чтение данных из файла
	void ReadFromFile(const char fileName[])
	{	
		FILE* f; 
		fopen_s(&f, fileName, "r");
		if (f == nullptr)
		{
			cout << "Cannot read file\n";
			return;
		}
		else
		{
			string str;
			char symbol[2]{ getc(f), '\0'};
			
			while (symbol[0] != '\n')
			{
				str.append(symbol);
				symbol[0] = getc(f);
			}

			double** arrXYZ = new double* [3];

			arrXYZ[0] = &x;
			arrXYZ[1] = &y;
			arrXYZ[2] = &z;

			unsigned int start = 0;
			unsigned int n = 0;
			for (unsigned int i = 0; i < 3; i++)
			{
				while (start < str.length())
				{
					if (str[start] != ' ')
					{
						for (n = 0; str[start + n] != ' '; n++);
						*arrXYZ[i] = stod(str.substr(start, n));
						start += n;
						break;
					}
					start++;
				}

			}
			delete[] arrXYZ;
		}
	}
};


int main()
{
	Point p; // создание объекта типа Point

	// Установка при помощи сеттеров
	p.SetX(52);
	p.SetY(-13);
	p.SetZ(123);
	
	p.WriteToFile("test.txt"); // сохранение точки в файл
	
	p.Print(); // вывод данных
	cout << "\n\n";

	p.SetPoint(111, 222.1, 3213.151); // установка значений
	p.Print(); // вывод данных
	cout << "\n\n";

	p.ReadFromFile("test.txt"); // чтение из файла
	p.Print();  // вывод данных

	return 0;
}
