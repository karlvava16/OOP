#include <iostream>
#include <string>
using namespace std;

class Point // ����� �����
{
	/*��������� ����*/
private:
	double x = 0; // ��� �������
	double y = 0; // ��� �������
	double z = 0; // ��� ��������

	/*������*/
public:

	

	
	

	

	double GetY()
	{
		return y;
	}

	double GetZ()
	{
		return z;
	}

	// �������
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

	// ������ ����� � ����
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

	// ������ ������ �� �����
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
	Point p; // �������� ������� ���� Point

	// ��������� ��� ������ ��������
	p.SetX(52);
	p.SetY(-13);
	p.SetZ(123);
	
	p.WriteToFile("test.txt"); // ���������� ����� � ����
	
	p.Print(); // ����� ������
	cout << "\n\n";

	p.SetPoint(111, 222.1, 3213.151); // ��������� ��������
	p.Print(); // ����� ������
	cout << "\n\n";

	p.ReadFromFile("test.txt"); // ������ �� �����
	p.Print();  // ����� ������

	return 0;
}
