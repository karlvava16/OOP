#pragma once
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class PrintRequest
{
	string filename;
	string user;
	unsigned priority;

public:
	PrintRequest() : filename(""), user(""), priority(0) {}
	PrintRequest(const string& filename) : filename(filename), user("unknown"), priority(1) {}
	PrintRequest(const string& filename, const string& user) : filename(filename), user(user), priority(10) {}
	PrintRequest(const string& filename, const string& user, unsigned priority) : filename(filename), user(user), priority(priority) {}
	PrintRequest(const PrintRequest& obj)
	{
		filename = obj.filename;
		user = obj.user;
		priority = obj.priority;
	}

	PrintRequest& operator= (const PrintRequest& obj)
	{
		this->filename = obj.filename;
		this->user = obj.user;
		this->priority = obj.priority;
		return *this;
	}

	string GetFilename() { return filename; }
	string GetUser() { return user; }
	unsigned GetProroity() { return priority; }

	void SetFilename(const string& filename) { this->filename = filename; };
	void SetUser(const string& user) { this->user = user; };
	void SetPriority(unsigned priority) { this->priority = priority; };


	friend ostream& operator<<(ostream& os, const PrintRequest& obj);
};

ostream& operator<<(ostream& os, const PrintRequest& obj)
{
	os << "Filename : " << obj.filename.c_str() << '\n';
	os << "User : " << obj.user.c_str() << '\n';
	os << "priority : " << obj.priority << '\n';
	return os;
}