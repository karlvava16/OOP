#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	//Test class Mysrting

	cout << "\t|Constructors|\n";
	MyString con1;
	cout << "Con1 : " << con1.MyC_Str() << endl;
	cout << "Len : " << con1.MyStrLen() << endl;
	MyString con2(15);
	cout << "Con2 : " << con2.MyC_Str() << endl;
	cout << "Len : " << con2.MyStrLen() << endl;
	MyString con3("test");
	cout << "Con3 : " << con3.MyC_Str() << endl;
	cout << "Len : " << con3.MyStrLen() << endl;
	cout << endl;
	
	cout << "|Strings for methods testing|\n";
<<<<<<< HEAD
	cout << endl;

	cout << "\t|GetCount (static)|\n";
	cout << MyString::GetCount() << endl;
	cout << endl;

=======
>>>>>>> 2b3e558cecdec2472a1c854aac710f37175a2567
	MyString str1("karl");
	MyString str2(" vava 16");
	MyString str3("");
	cout << "String number 1 : " << str1.MyC_Str() << endl;
	cout << "String number 2 : " << str2.MyC_Str() << endl;
	cout << "String number 3 : " << str3.MyC_Str() << endl;
	cout << endl;

<<<<<<< HEAD
	cout << "\t|GetCount (static)|\n";
	cout << MyString::GetCount() << endl;
	cout << endl;

=======
>>>>>>> 2b3e558cecdec2472a1c854aac710f37175a2567
	cout << "\t|Print|\n";
	str1.Print();
	cout << endl << endl;

	cout << "\t|MyStrCat|\n";
	str1.MyStrCat(str2);
	str1.Print();
	cout << endl;
	
	cout << "\t|MyDelChr|\n";
	str1.MyDelChr('a');
	str1.Print();
	cout << endl;

	cout << "\t|MyChr|\n";
	str1.Print();
	cout << endl << "First char : " << str1.MyChr('v') << endl;
	cout << endl;

	cout << "|Strings for methods testing|\n";
	MyString str4("nice one");
	MyString str5("one");
	cout << "String number 4 : " << str4.MyC_Str() << endl;
	cout << "String number 5 : " << str5.MyC_Str() << endl;
	cout << endl;

	cout << "\t|MyStrCmp|\n";
	cout << str4.MyStrCmp(str5) << endl;
	cout << endl;

<<<<<<< HEAD
	cout << "\t|GetCount (static)|\n";
	cout << MyString::GetCount() << endl;
	cout << endl;

=======
>>>>>>> 2b3e558cecdec2472a1c854aac710f37175a2567
	cout << "\t|Enter|\n";
	str3.Enter();
	str3.Print();
	cout << endl << endl;

	return 0;
}