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
	is >> fPassport.name;		// ���
	is >> fPassport.surname;		// �������
	is >> fPassport.sex;			// ���
	is >> fPassport.placeOfBirth;// ����� ��������
	is >> fPassport.nationality;	// ��������������
	is >> fPassport.recordNo;	// ����� ������
	is >> fPassport.documentNo;	// ����� ���������
	is >> fPassport.authority;	// ����� ������ ��������� ��������
	is >> fPassport.dateOfBirth;	// ���� ��������
	is >> fPassport.dateOfExiry;	// ���� ��������� ����� �������� ��������
	is >> fPassport.dateOfIssue;	// ���� ���������
	return is;
}

ostream& operator<<(ostream& os, const ForeignPassport& fPassport)
{
	os << fPassport.type;
	os << endl;
	os << fPassport.countryCode;
	os << endl;
	os << fPassport.name;		// ���
	os << endl;
	os << fPassport.surname;		// �������
	os << endl;
	os << fPassport.sex;			// ���
	os << endl;
	os << fPassport.placeOfBirth;// ����� ��������
	os << endl;
	os << fPassport.nationality;	// ��������������
	os << endl;
	os << fPassport.recordNo;	// ����� ������
	os << endl;
	os << fPassport.documentNo;	// ����� ���������
	os << endl;
	os << fPassport.authority;	// ����� ������ ��������� ��������
	os << endl;
	os << fPassport.dateOfBirth;	// ���� ��������
	os << endl;
	os << fPassport.dateOfExiry;	// ���� ��������� ����� �������� ��������
	os << endl;
	os << fPassport.dateOfIssue;	// ���� ���������
	os << endl;
	return os;
}
