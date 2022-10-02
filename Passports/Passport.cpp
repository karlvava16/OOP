#include "Passport.h"

void Passport::Enter()
{
	cout << "\t|Enter|\n";
	cout << "Name : ";
	cin >> name;		// ���
	cout << "Surname : ";
	cin >> surname;		// �������
	cout << "Sex : ";
	cin >> sex;			// ���
	cout << "Place of birth : ";
	cin >> placeOfBirth;// ����� ��������							
	cout << "Nationality : ";
	cin >> nationality;	// ��������������
	cout << "RecordNo. : ";
	cin >> recordNo;	// ����� ������
	cout << "DocumentNo. : ";
	cin >> documentNo;	// ����� ���������
	cout << "Authority : ";
	cin >> authority;	// ����� ������ ��������� ��������
	cout << "Date of birth : ";
	cin >> dateOfBirth;	// ���� ��������
	cout << "Date of exiry : ";
	cin >> dateOfExiry;	// ���� ��������� ����� �������� ��������
	cout << "Date of issue : ";
	cin >> dateOfIssue;	// ���� ���������
}

void Passport::Print() const
{
	cout << "Name : ";
	cout << name << endl;		// ���
	cout << "Surname : ";
	cout << surname << endl;		// �������
	cout << "Sex : ";
	cout << sex << endl;			// ���
	cout << "Place of birth : ";
	cout << placeOfBirth << endl;// ����� ��������							
	cout << "Nationality : ";
	cout << nationality << endl;	// ��������������
	cout << "RecordNo. : ";
	cout << recordNo << endl;	// ����� ������
	cout << "DocumentNo. : ";
	cout << documentNo << endl;	// ����� ���������
	cout << "Authority : ";
	cout << authority << endl;	// ����� ������ ��������� ��������
	cout << "Date of birth : ";
	cout << dateOfBirth << endl;	// ���� ��������
	cout << "Date of exiry : ";
	cout << dateOfExiry << endl;	// ���� ��������� ����� �������� ��������
	cout << "Date of issue : ";
	cout << dateOfIssue << endl;	// ���� ���������
}

string Passport::GetName() const
{
	return name;
}

string Passport::GetSurname() const
{
	return surname;
}

string Passport::GetSex() const
{
	return sex;
}

string Passport::GetPlaceOfBirth() const
{
	return placeOfBirth;
}

string Passport::GetNationality() const
{
	return nationality;
}

string Passport::GetRecordNo() const
{
	return recordNo;
}

string Passport::GetDocumentNo() const
{
	return documentNo;
}

string Passport::GetAuthority() const
{
	return authority;
}

Date Passport::GetDateOfBirth() const
{
	return dateOfBirth;
}

Date Passport::GetDateOfExiry() const
{
	return dateOfExiry;
}

Date Passport::GetDateOfIssue() const
{
	return dateOfIssue;
}

void Passport::SetName(const string& name)
{
	this->name = name;
}

void Passport::SetSurname(const string& surname)
{
	this->surname = surname;
}

void Passport::SetSex(const string& sex)
{
	this->sex = sex;
}

void Passport::SetPlaceOfBirth(const string& placeOfBirth)
{
	this->placeOfBirth = placeOfBirth;
}

void Passport::SetNationality(const string& nationality)
{
	this->nationality = nationality;
}

void Passport::SetRecordNo(const string& recordNo)
{
	this->recordNo = recordNo;
}

void Passport::SetDocumentNo(const string& documentNo)
{
	this->documentNo = documentNo;
}

void Passport::SetAuthority(const string& authority)
{
	this->authority = authority;
}

void Passport::SetvoidOfBirth(const Date& dateOfBirth)
{
	this->dateOfBirth = dateOfBirth;
}

void Passport::SetvoidOfExiry(const Date& dateOfExiry)
{
	this->dateOfExiry = dateOfExiry;
}

void Passport::SetvoidOfIssue(const Date& dateOfIssue)
{
	this->dateOfIssue = dateOfIssue;
}

istream& operator>>(istream& is, Passport& passport)
{
	is >> passport.name;		// ���
	is >> passport.surname;		// �������
	is >> passport.sex;			// ���
	is >> passport.placeOfBirth;// ����� ��������
	is >> passport.nationality;	// ��������������
	is >> passport.recordNo;	// ����� ������
	is >> passport.documentNo;	// ����� ���������
	is >> passport.authority;	// ����� ������ ��������� ��������
	is >> passport.dateOfBirth;	// ���� ��������
	is >> passport.dateOfExiry;	// ���� ��������� ����� �������� ��������
	is >> passport.dateOfIssue;	// ���� ���������
	return is;
}

ostream& operator<<(ostream& os, const Passport& passport)
{
	os << passport.name;		// ���
	os << endl;
	os << passport.surname;		// �������
	os << endl;
	os << passport.sex;			// ���
	os << endl;
	os << passport.placeOfBirth;// ����� ��������
	os << endl;
	os << passport.nationality;	// ��������������
	os << endl;
	os << passport.recordNo;	// ����� ������
	os << endl;
	os << passport.documentNo;	// ����� ���������
	os << endl;
	os << passport.authority;	// ����� ������ ��������� ��������
	os << endl;
	os << passport.dateOfBirth;	// ���� ��������
	os << endl;
	os << passport.dateOfExiry;	// ���� ��������� ����� �������� ��������
	os << endl;
	os << passport.dateOfIssue;	// ���� ���������
	os << endl;	
	return os;
}
