#include "Passport.h"

void Passport::Enter()
{
	cout << "\t|Enter|\n";
	cout << "Name : ";
	cin >> name;		// имя
	cout << "Surname : ";
	cin >> surname;		// фамилия
	cout << "Sex : ";
	cin >> sex;			// пол
	cout << "Place of birth : ";
	cin >> placeOfBirth;// место рождения							
	cout << "Nationality : ";
	cin >> nationality;	// национальность
	cout << "RecordNo. : ";
	cin >> recordNo;	// номер записи
	cout << "DocumentNo. : ";
	cin >> documentNo;	// номер документа
	cout << "Authority : ";
	cin >> authority;	// номер органа выдавшего документ
	cout << "Date of birth : ";
	cin >> dateOfBirth;	// дата рождения
	cout << "Date of exiry : ";
	cin >> dateOfExiry;	// дата истечения срока дейсвтия паспорта
	cout << "Date of issue : ";
	cin >> dateOfIssue;	// дата получения
}

void Passport::Print() const
{
	cout << "Name : ";
	cout << name << endl;		// имя
	cout << "Surname : ";
	cout << surname << endl;		// фамилия
	cout << "Sex : ";
	cout << sex << endl;			// пол
	cout << "Place of birth : ";
	cout << placeOfBirth << endl;// место рождения							
	cout << "Nationality : ";
	cout << nationality << endl;	// национальность
	cout << "RecordNo. : ";
	cout << recordNo << endl;	// номер записи
	cout << "DocumentNo. : ";
	cout << documentNo << endl;	// номер документа
	cout << "Authority : ";
	cout << authority << endl;	// номер органа выдавшего документ
	cout << "Date of birth : ";
	cout << dateOfBirth << endl;	// дата рождения
	cout << "Date of exiry : ";
	cout << dateOfExiry << endl;	// дата истечения срока дейсвтия паспорта
	cout << "Date of issue : ";
	cout << dateOfIssue << endl;	// дата получения
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
	is >> passport.name;		// имя
	is >> passport.surname;		// фамилия
	is >> passport.sex;			// пол
	is >> passport.placeOfBirth;// место рождения
	is >> passport.nationality;	// национальность
	is >> passport.recordNo;	// номер записи
	is >> passport.documentNo;	// номер документа
	is >> passport.authority;	// номер органа выдавшего документ
	is >> passport.dateOfBirth;	// дата рождения
	is >> passport.dateOfExiry;	// дата истечения срока дейсвтия паспорта
	is >> passport.dateOfIssue;	// дата получения
	return is;
}

ostream& operator<<(ostream& os, const Passport& passport)
{
	os << passport.name;		// имя
	os << endl;
	os << passport.surname;		// фамилия
	os << endl;
	os << passport.sex;			// пол
	os << endl;
	os << passport.placeOfBirth;// место рождения
	os << endl;
	os << passport.nationality;	// национальность
	os << endl;
	os << passport.recordNo;	// номер записи
	os << endl;
	os << passport.documentNo;	// номер документа
	os << endl;
	os << passport.authority;	// номер органа выдавшего документ
	os << endl;
	os << passport.dateOfBirth;	// дата рождения
	os << endl;
	os << passport.dateOfExiry;	// дата истечения срока дейсвтия паспорта
	os << endl;
	os << passport.dateOfIssue;	// дата получения
	os << endl;	
	return os;
}
