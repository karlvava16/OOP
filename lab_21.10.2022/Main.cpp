#include <iostream>
#include <map>
#include <fstream>
#include <map>
using namespace std;


int main()
{
	string str;

	cout << "Enter File Name: ";
	cin >> str;
	ifstream is(str.c_str(), ios::in);

	ofstream os;


	if (!is)
	{
		cout << "Cannot open file\n";
		return -1;
	}

	map<string, int> dict;

	do
	{
		is >> str;
		if (dict.find(str) == dict.end()) {
			dict.insert({ str, 1 });
		}
		else {
			dict.find(str)->second++;
		}
	} while (!is.eof());

	os.open("dictDone.txt");


	for (auto i = dict.begin(); i != dict.end(); i++)
	{
		if (i->second >= 2)
		{
			cout << '(' << i->second << ')' << i->first << endl;
			os << '(' << i->second << ')' << i->first << endl;
		}
	}

	os.close();
	
	return 0;
}