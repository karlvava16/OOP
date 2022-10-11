#pragma once
#include <iostream>
#include "Exceptions.h"

class MyString
{
private:
	char* str; // pointer to string
	int length; // string length
	static int count; // number of objects

public:
	MyString(); // default constructor
	MyString(int length); // get a param of string length
	MyString(const char* str); // get string to write
	MyString(const MyString& obj); // copy constructor
	MyString(MyString&& obj); // move constructor										// last added
	MyString(std::initializer_list<char> arr); // list constructor						// last added
	~MyString(); // destructor
	
	MyString& operator=(MyString&& obj); // move assignment								// last added
	MyString& operator=(const MyString& obj); // assignment	
	MyString& operator=(const char* str); // assignment		
	void operator()() const; // output string by using cout	
	char operator[](int index) const; // return char by index
	operator int() const; // return str length				
	operator const char* () const; // return string

	void Enter(); // input string by using keyboard

	void MyStrcpy(MyString& obj); // copy string
	bool MyStrStr(const char* str); // substring in string
	int  MyChr(char c) const; // search for character in string(character index OR -1)
	int MyStrLen() const; // get string length
	void MyStrCat(const MyString& b); // string concatenation
	void MyStrCat(const char* b); // string concatenation
	void MyDelChr(char c); // delete character from string 
	int MyStrCmp(const MyString& b) const; // compare strings
	const char* MyC_Str() const; // get const pointer to char array
	static int GetCount(); // get number of objects

	friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
};