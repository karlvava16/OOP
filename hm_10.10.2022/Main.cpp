#include "MyString.h"
#include <conio.h>

int main()
{
	char choose = '0';
	cout << "1. StringLengthZero\n";
	cout << "2. StrStrException\n";
	cout << "3. NULLTerminatorInitListException\n";
	cout << "4. IndexOutOfRange\n\n";

	while (!(choose >= '1' && choose <= '4'))
	{
		choose = _getch();
	}
	try
	{
		if (choose == '1')
		{
			MyString b(0);
		}
		else if (choose == '2')
		{
			MyString a("Vlad");
			a.MyStrStr("Vladislav");
		}
		else if (choose == '3')
		{
			MyString c = { 'H', 'E', 'L', 'L', 'O', '\0' };
		}
		else
		{
			MyString d("World");
			cout << d[12];
		}
	}
	catch(BaseException* ex)
	{
		ex->Print();
		delete ex;
	}
	return 0;
}


/*RESULT*/

/*
1. StringLengthZero
2. StrStrException
3. NULLTerminatorInitListException
4. IndexOutOfRange

StringLengthZero. String length is zero.
*/