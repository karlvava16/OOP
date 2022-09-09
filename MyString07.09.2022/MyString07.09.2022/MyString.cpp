#include "MyString.h"

<<<<<<< HEAD
int MyString::count = 0;

// default constructor
MyString::MyString()
{
	count++;
=======
// default constructor
MyString::MyString()
{
>>>>>>> 2b3e558cecdec2472a1c854aac710f37175a2567
	str = new char[80];
	str[0] = '\0';
	length = 0;
}

// get a param of string length
MyString::MyString(int length)
{
<<<<<<< HEAD
	count++;
=======
>>>>>>> 2b3e558cecdec2472a1c854aac710f37175a2567
	this->length = length;
	str = new char[length + 1];
	str[0] = '\0';
}

// get string to write
MyString::MyString(const char* str)
{
<<<<<<< HEAD
	count++;
=======
>>>>>>> 2b3e558cecdec2472a1c854aac710f37175a2567
	length = strlen(str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++)
		this->str[i] = str[i];
	this->str[length] = '\0';
}

// destructor
MyString::~MyString()
{
<<<<<<< HEAD
	count--;
=======
>>>>>>> 2b3e558cecdec2472a1c854aac710f37175a2567
	delete[] str;
}

// input string by using keyboard
void MyString::Enter()
{
	const char BUFSIZE = 256;
	char buffer[256];
	delete[] str;
	std::cin.getline(buffer, 256);
	length = strlen(buffer);
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
		str[i] = buffer[i];
	str[length] = '\0';
}

// output string by using cout
void MyString::Print()
{
	std::cout << str;
}

// copy string
void MyString::MyStrcpy(MyString& obj)
{
	delete[] str;
	length = obj.length;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
		str[i] = obj.str[i];
	str[length] = '\0';
}

// substring in string
bool MyString::MyStrStr(const char* str)
{
	bool result = false;
	if(strlen(str) > length)
		return result;
	for (int i = 0; i < length; i++)
	{
		result = true;
		for(int j = 0; j < strlen(str); j++)
		{
			if (this->str[j + i] != str[j])
			{
				result = false;
				break;
			}
		}
		if (result)
			break;
	}
	return result;
}

// search for character in string(character index OR -1)
int MyString::MyChr(char c)
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
			return i;
	}
	return -1;
}

// get string length
int MyString::MyStrLen()
{
	return length;
}

// string concatenation
void MyString::MyStrCat(MyString& b)
{
	char* temp = new char[length + b.length + 1];
	for (int i = 0; i < length; i++)
	{
		temp[i] = str[i];
	}
	for (int i = 0; i < b.length; i++)
	{
		temp[i + length] = b.str[i];
	}
	length += b.length;
	temp[length] = '\0';
	delete[] str;
	str = temp;
}

// delete character from string 
void MyString::MyDelChr(char c)
{
	bool check = false;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			check = true;
			for (int j = i; j < length - 1; j++)
				str[j] = str[j + 1];
			str[length] = '\0';
			i--;
			length--;
		}
	}
	if (check)
	{
		char* temp = new char[length + 1];
		for (int i = 0; i < length; i++)
			temp[i] = str[i];
		temp[length] = '\0';
		delete[] str;
		str = temp;
	}
}

// compare strings
int MyString::MyStrCmp(MyString& b)
{
	char* str1 = str;
	char* str2 = b.str;

	if (strlen(str1) < strlen(str2))
	{
		return -1;
	}
	while (*str2 == '\0')
	{
		if (*str1 != *str2)
		{
			return -1;
		}
		str1++;
		str2++;
	}
	if (strlen(str1) > strlen(str2))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// get const pointer to char array
const char* MyString::MyC_Str()
{
	return str;
}
<<<<<<< HEAD

int MyString::GetCount()
{
	return count;
}
=======
>>>>>>> 2b3e558cecdec2472a1c854aac710f37175a2567
	// отлично!
