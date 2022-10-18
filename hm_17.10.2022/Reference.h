#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>

namespace ref
{
	using namespace std;

	class Reference
	{
		string companyName;
		string owner;
		string phoneNumber;
		string address;
		string metier;

	public:
		Reference()
		{
			companyName = "";
			owner = "";
			phoneNumber = "";
			address = "";
			metier = "";
		}
		Reference(const char* companyName) : Reference()
		{
			this->companyName = companyName;
		}
		Reference(const char* companyName, const char* owner) : Reference(companyName)
		{
			this->owner = owner;
		}
		Reference(const char* companyName, const char* owner,
			const char* phoneNumber) : Reference(companyName, owner)
		{
			this->phoneNumber = phoneNumber;
		}
		Reference(const char* companyName, const char* owner,
			const char* phoneNumber, const char* address ) : Reference(companyName, owner, phoneNumber)
		{
			this->address = address;
		}
		Reference(const char* companyName, const char* owner,
			const char* phoneNumber, const char* address, const char* metier)
			: Reference(companyName, owner, phoneNumber, address)
		{
			this->metier = metier;
		}
	
		const char* GetCompanyName() const
		{
			return companyName.c_str();
		}

		const char* GetOwner() const
		{
			return owner.c_str();
		}

		const char* GetPhoneNumber() const
		{
			return phoneNumber.c_str();
		}

		const char* GetAddress() const
		{
			return address.c_str();
		}

		const char* GetMetier() const
		{
			return metier.c_str();
		}

		void SetCompanyName(const char* str) { companyName = str; }
		void SetOwner(const char* str) { owner = str; }
		void SetPhoneNumber(const char* str) { phoneNumber = str; }
		void SetAddress(const char* str) { address = str; }
		void SetMetier(const char* str) { metier = str; }

		void Info()
		{
			cout << "Company Name: " << companyName << endl;
			cout << "Owner: " << owner << endl;
			cout << "Phone Number: " << phoneNumber << endl;
			cout << "Address: " << address << endl;
			cout << "Metier: " << metier << endl;
		}
	};


	void SaveReference(const char* filename, const Reference& obj)
	{
		ofstream out;
		out.open(filename, ios::app);
		out << obj.GetCompanyName() << endl;
		out << obj.GetOwner() << endl;
		out << obj.GetPhoneNumber() << endl;
		out << obj.GetAddress() << endl;
		out << obj.GetMetier() << endl;
		out.close();
	}

	


	void ShowReference(const char* filename)
	{
		ifstream is(filename, ios::in);
		if (is.is_open())
		{
			Reference temp;
			string str;
			is >> str;
			do
			{
				temp.SetCompanyName(str.c_str());
				is >> str;
				temp.SetOwner(str.c_str());
				is >> str;
				temp.SetPhoneNumber(str.c_str());
				is >> str;
				temp.SetAddress(str.c_str());
				is >> str;
				temp.SetMetier(str.c_str());
				temp.Info();
				is >> str;
				cout << endl;
			} while (!is.eof());
		}
		is.close();
	}

	
	
	void SearchCompanyName(const char* filename, const char* company_name)
	{
		ifstream is(filename, ios::in);
		if (is.is_open())
		{
			Reference temp;
			string str;
			is >> str;
			do
			{
				temp.SetCompanyName(str.c_str());
				if (!(str == string(company_name)))
				{
					for (int i = 0; i < 5; i++)
						is >> str;
					continue;
				}
				is >> str;
				temp.SetOwner(str.c_str());
				is >> str;
				temp.SetPhoneNumber(str.c_str());
				is >> str;
				temp.SetAddress(str.c_str());
				is >> str;
				temp.SetMetier(str.c_str());
				temp.Info();
				is >> str;
				cout << endl;
			} while (!is.eof());
		}
		is.close();
	}

	void SearchOwner(const char* filename, const char* owner)
	{
		ifstream is(filename, ios::in);
		if (is.is_open())
		{
			Reference temp;
			string str;
			is >> str;
			do
			{
				temp.SetCompanyName(str.c_str());
				is >> str;
				if (!(str == string(owner)))
				{
					for (int i = 0; i < 4; i++)
						is >> str;
					continue;
				}
				temp.SetOwner(str.c_str());
				is >> str;
				temp.SetPhoneNumber(str.c_str());
				is >> str;
				temp.SetAddress(str.c_str());
				is >> str;
				temp.SetMetier(str.c_str());
				temp.Info();
				is >> str;
				cout << endl;
			} while (!is.eof());
		}
		is.close();
	}

	void SearchPhoneNumber(const char* filename, const char* phnub)
	{
		ifstream is(filename, ios::in);
		if (is.is_open())
		{
			Reference temp;
			string str;
			is >> str;
			do
			{
				temp.SetCompanyName(str.c_str());
				is >> str;
				temp.SetOwner(str.c_str());
				is >> str;
				if (!(str == string(phnub)))
				{
					for (int i = 0; i < 3; i++)
						is >> str;
					continue;
				}
				temp.SetPhoneNumber(str.c_str());
				is >> str;
				temp.SetAddress(str.c_str());
				is >> str;
				temp.SetMetier(str.c_str());
				temp.Info();
				is >> str;
				cout << endl;
			} while (!is.eof());
		}
		is.close();
	}

	void SearchAddress(const char* filename, const char* address)
	{
		ifstream is(filename, ios::in);
		if (is.is_open())
		{
			Reference temp;
			string str;
			is >> str;
			do
			{
				temp.SetCompanyName(str.c_str());
				is >> str;
				temp.SetOwner(str.c_str());
				is >> str;
				temp.SetPhoneNumber(str.c_str());
				is >> str;
				if (!(str == string(address)))
				{
					for (int i = 0; i < 2; i++)
						is >> str;
					continue;
				}
				temp.SetAddress(str.c_str());
				is >> str;
				temp.SetMetier(str.c_str());
				temp.Info();
				is >> str;
				cout << endl;
			} while (!is.eof());
		}
		is.close();
	}

	void SearchMetier(const char* filename, const char* metier)
	{
		ifstream is(filename, ios::in);
		if (is.is_open())
		{
			Reference temp;
			string str;
			is >> str;
			do
			{
				temp.SetCompanyName(str.c_str());
				is >> str;
				temp.SetOwner(str.c_str());
				is >> str;
				temp.SetPhoneNumber(str.c_str());
				is >> str;
				temp.SetAddress(str.c_str());
				is >> str;
				if (!(str == string(metier)))
				{
					is >> str;
					continue;
				}
				temp.SetMetier(str.c_str());
				temp.Info();
				is >> str;
				cout << endl;
			} while (!is.eof());
		}
		is.close();
	}

}

