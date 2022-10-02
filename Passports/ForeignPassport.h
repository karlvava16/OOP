#pragma once
#include "Passport.h"

class ForeignPassport : public Passport
{
protected:
	char type;
	string countryCode;

public:
	ForeignPassport() = default;
	ForeignPassport( char type, const string& countryCode, const Passport& passport) : Passport(passport), type(type), countryCode(countryCode) {}

	void Enter()
	{
		cout << "Type : ";
		cin >> type;
		cout << "Country code :";
		cin >> countryCode;
		Passport::Enter();
	}

	void Print()
	{
		cout << "Type : " << type << endl;
		cout << "Country code : " << countryCode << endl;
		Passport::Print();
	}

	char GetType() const
	{
		return type;
	}

	string GetCountryCode() const
	{
		return countryCode;
	}

	void SetType(char type)
	{
		this->type = type;
	}

	void SetCountryCode(const string& countryCode)
	{
		this->countryCode = countryCode;
	}

	friend istream& operator>>(istream& is, ForeignPassport& fPassport);
	friend ostream& operator<<(ostream& os, const ForeignPassport& fPassport);
};

istream& operator>>(istream& is, ForeignPassport& fPassport)
{
	is >> fPassport.type;
	is >> fPassport.countryCode;
	is >> fPassport.name;		// имя
	is >> fPassport.surname;		// фамилия
	is >> fPassport.sex;			// пол
	is >> fPassport.placeOfBirth;// место рождения
	is >> fPassport.nationality;	// национальность
	is >> fPassport.recordNo;	// номер записи
	is >> fPassport.documentNo;	// номер документа
	is >> fPassport.authority;	// номер органа выдавшего документ
	is >> fPassport.dateOfBirth;	// дата рождения
	is >> fPassport.dateOfExiry;	// дата истечения срока дейсвтия паспорта
	is >> fPassport.dateOfIssue;	// дата получения
	return is;
}

ostream& operator<<(ostream& os, const ForeignPassport& fPassport)
{
	os << fPassport.type;
	os << endl;
	os << fPassport.countryCode;
	os << endl;
	os << fPassport.name;		// имя
	os << endl;
	os << fPassport.surname;		// фамилия
	os << endl;
	os << fPassport.sex;			// пол
	os << endl;
	os << fPassport.placeOfBirth;// место рождения
	os << endl;
	os << fPassport.nationality;	// национальность
	os << endl;
	os << fPassport.recordNo;	// номер записи
	os << endl;
	os << fPassport.documentNo;	// номер документа
	os << endl;
	os << fPassport.authority;	// номер органа выдавшего документ
	os << endl;
	os << fPassport.dateOfBirth;	// дата рождения
	os << endl;
	os << fPassport.dateOfExiry;	// дата истечения срока дейсвтия паспорта
	os << endl;
	os << fPassport.dateOfIssue;	// дата получения
	os << endl;
	return os;
}
