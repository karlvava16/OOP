#pragma once
#include <iostream>
using namespace std;

class Payment
{
private:
	char* nameSurname; // name, surname, father name
	char* hireDate; // hiring date
	int workDaysAmount; // work days amount
	int workedDays; // worked days
	double monthSalary; // month salary
	double incomeTaxP; // income tax percent
	double pensionFundP; // pension fund percent
	double allowanceP; // allowance percent
	double accrued; // accrued
	double withheld; // withheld
	double finalPayment; // final payment

	void CalcualateResult(); // calculate accrued and withheld

public:
	Payment(); // default constructor
	Payment(const char* nameSurname, const char* hireDate,
		int workDaysAmount, int workedDays, double monthSalary,
		double incomeTaxP, double pensionFundP, double allowanceP); // constructor with full params
	explicit Payment(const Payment& obj); // copy constructor
	~Payment(); // destructor

	void Enter(); // enter 

	void Print() const; // output info

	// Getters
	const char* GetnNameSurname() const;
	const char* GetnhireDate() const;
	int GetWorkDaysAmount() const;
	int GetWorkedDays() const;
	double GetMonthSalary() const;
	double GetIncomeTaxP() const;
	double GetPensionFundP() const;
	double GetAllowanceP() const;
	double GetAccrued() const;
	double GetWithheld() const;
	double GetFinalPayment() const;

	// Setters
	void SetnNameSurname(const char* nameSurname);
	void SetnhireDate(const char* hireDate);
	void SetMonthSalary(double monthSalary);
	void SetWorkDaysAmount(int workDaysAmount);
	void SetWorkedDays(int workedDays);
	void SetIncomeTaxP(double incomeTaxP);
	void SetPensionFundP(double pensionFundP);
	void SetAllowanceP(double allowanceP);
};
