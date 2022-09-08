#include <iostream>
using namespace std;


class Student // ����� ��������
{
	/*��������� ����*/
private:
	string name = ""; // ��� ��������
	string surname = ""; // ������� ��������
	string fatherName = ""; // �������� ��������
	string birthday = ""; // ���� ��� ��������
	string phoneNumber = ""; // ����� ��������
	string educationalInstitution = ""; // ������� ���������
	string countryAndCity = ""; // ������, �����
	string group = ""; // ����� ������

	/*������*/ 
public:
	// ����� ������ ��������
	void Print()
	{
		cout << "Name : " << name << endl;
		cout << "surname : " << surname << endl;
		cout << "Father's Name : " << fatherName << endl;
		cout << "birthday : " << birthday << endl;
		cout << "Phone Number : " << phoneNumber << endl;
		cout << "Educational Institution : " << educationalInstitution << endl;
		cout << "County and City : " << countryAndCity << endl;
		cout << "group : " << group << endl;
	}

	// ���� ������ ��������
	void Enter()
	{
		cout << "Enter :" << endl;
		cout << "Name : ";
		cin >> name;
		cout << "surname : ";
		cin >> surname;
		cout << "Father's Name : ";
		cin >> fatherName;
		cout << "birthday : ";
		cin >> birthday;
		cout << "phoneNumber : ";
		cin >> phoneNumber;
		cout << "Educational Institution : ";
		cin >> educationalInstitution;
		cout << "County and City : ";
		cin >> countryAndCity;
		cout << "group : ";
		cin >> group;
		cout << endl;
	}

	// ���������

	// �������
	string GetName()
	{
		return name;
	}

	string GetSurname()
	{
		return surname;
	}

	string GetFatherName()
	{
		return fatherName;
	}

	string GetBirthday()
	{
		return birthday;
	}

	string GetPhoneNumber()
	{
		return phoneNumber;
	}

	string GetEducationalInstitution()
	{
		return educationalInstitution;
	}

	string GetCountryAndCity()
	{
		return countryAndCity;
	}

	string GetGroup()
	{
		return group;
	}

	// �������
	void SetName(string n)
	{
		name = n;
	}

	void SetSurname(string sn)
	{
		surname = sn;
	}

	void SetFatherName(string fn)
	{
		fatherName = fn;
	}

	void SetBirthday(string bd)
	{
		birthday = bd;
	}

	void SetPhoneNumber(string phn)
	{
		phoneNumber = phn;
	}

	void SetEducationalInstitution(string EI)
	{
		educationalInstitution = EI;
	}
	
	void SetCountryAndCity(string CC)
	{
		countryAndCity = CC;
	}
	
	void SetGroup(string gn)
	{
		group = gn;
	}
};




int main()
{
	Student me; // ������� ������� ������ Student 

	me.Enter(); // ���� ���������� � ��������
	cout << endl;

	me.Print(); // ����� ���������� � ��������

	me.SetFatherName("Yra"); // ������ �������
	cout << me.GetFatherName() << endl; // ������ ������� � ����� ����������

	return 0;
}
