#pragma once
#include <iostream>
#include <string>

class MyString
{
private:
	char* str; // pointer to string
	int length; // string length
<<<<<<< HEAD
	static int count; // number of objects
=======
>>>>>>> 2b3e558cecdec2472a1c854aac710f37175a2567

public:
	MyString(); // default constructor
	MyString(int length); // get a param of string length
	MyString(const char* str); // get string to write
	~MyString(); // destructor

	void Enter(); // input string by using keyboard
	void Print(); // output string by using cout

	void MyStrcpy(MyString& obj); // copy string
	bool MyStrStr(const char* str); // substring in string
	int  MyChr(char c); // search for character in string(character index OR -1)
	int MyStrLen(); // get string length
	void MyStrCat(MyString& b); // string concatenation
	void MyDelChr(char c); // delete character from string 
	int MyStrCmp(MyString& b); // compare strings
	const char* MyC_Str(); // get const pointer to char array
<<<<<<< HEAD
	static int GetCount(); // get number of objects
=======
>>>>>>> 2b3e558cecdec2472a1c854aac710f37175a2567
};
