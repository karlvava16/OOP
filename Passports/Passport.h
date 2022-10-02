#pragma once
#include <iostream>
#include "Date/Date.h"
using namespace std;

class Passport
{
protected:
	string name;		// имя
	string surname;		// фамилия
	string sex;			// пол
	string placeOfBirth;// место рождения
	string nationality;	// национальность
	string recordNo;	// номер записи
	string documentNo;	// номер документа
	string authority;	// номер органа выдавшего документ
	Date dateOfBirth;	// дата рождения
	Date dateOfExiry;	// дата истечения срока дейсвтия паспорта
	Date dateOfIssue;	// дата получения

public:
	void Enter();
	void Print() const;

	string GetName() const;
	string GetSurname() const;
	string GetSex() const;
	string GetPlaceOfBirth() const;
	string GetNationality() const;
	string GetRecordNo() const;
	string GetDocumentNo() const;
	string GetAuthority() const;
	Date GetDateOfBirth() const;
	Date GetDateOfExiry() const;
	Date GetDateOfIssue() const;

	void SetName(const string& name);
	void SetSurname(const string& surname);
	void SetSex(const string& sex);
	void SetPlaceOfBirth(const string& placeOfBirth);
	void SetNationality(const string& nationality);
	void SetRecordNo(const string& recordNo);
	void SetDocumentNo(const string& documentNo);
	void SetAuthority(const string& authority);
	void SetvoidOfBirth(const Date& dateOfBirth);
	void SetvoidOfExiry(const Date& dateOfExiry);
	void SetvoidOfIssue(const Date& dateOfIssue);

	friend istream& operator>>(istream& is, Passport& date);
	friend ostream& operator<<(ostream& os, const Passport& date);
};

istream& operator>>(istream& is, Passport& passport);
ostream& operator<<(ostream& os, const Passport& passport);