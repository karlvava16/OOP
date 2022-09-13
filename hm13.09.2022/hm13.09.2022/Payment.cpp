#include "Payment.h"


// calculate accrued and withheld
void Payment::CalcualateResult()
{
	accrued = monthSalary / workDaysAmount * workedDays; // salary for worked days
	finalPayment = accrued; // copy accrued in finalPayment
	finalPayment -= accrued * (incomeTaxP * 0.01); // minus percent of income tax
	finalPayment -= accrued * (pensionFundP * 0.01); /// minus percent of pension fund
	finalPayment += accrued * (allowanceP * 0.01); // plus percent of allowance
	withheld = accrued - finalPayment; // salary for worked days minus final payment
}

// default constructor
Payment::Payment()
{
	nameSurname = new char[1];
	nameSurname[0] = '\0';
	hireDate = new char[1];
	hireDate[0] = '\0';
	monthSalary = 0;
	workDaysAmount = 0;
	workedDays = 0;
	incomeTaxP = 0;
	pensionFundP = 0;
	allowanceP = 0;
	accrued = 0;
	withheld = 0;
	finalPayment = 0;
}

// constructor with full params
Payment::Payment(const char* nameSurname, const char* hireDate,
	int workDaysAmount, int workedDays, double monthSalary,
	double incomeTaxP, double pensionFundP, double allowanceP)
{
	this->nameSurname = new char[strlen(nameSurname) + 1];
	strcpy_s(this->nameSurname, strlen(nameSurname) + 1, nameSurname);

	this->hireDate = new char[strlen(hireDate) + 1];
	strcpy_s(this->hireDate, strlen(hireDate) + 1, hireDate);

	if (workDaysAmount > 25)
		this->workDaysAmount = 25;
	else
		this->workDaysAmount = workDaysAmount;

	if (workedDays > workDaysAmount)
		this->workedDays = workDaysAmount;
	else
		this->workedDays = workedDays;

	this->monthSalary = monthSalary;
	this->incomeTaxP = incomeTaxP;
	this->pensionFundP = pensionFundP;
	this->allowanceP = allowanceP;
	this->accrued = 0;
	this->withheld = 0;
	this->finalPayment = 0;

	CalcualateResult();
}

// copy constructor
Payment::Payment(const Payment& obj)
{
	nameSurname = new char[strlen(obj.nameSurname) + 1];
	strcpy_s(nameSurname, strlen(obj.nameSurname) + 1, obj.nameSurname);

	hireDate = new char[strlen(obj.hireDate) + 1];
	strcpy_s(hireDate, strlen(obj.hireDate) + 1, obj.hireDate);

	workDaysAmount = obj.workDaysAmount;
	workedDays = obj.workedDays;
	monthSalary = obj.monthSalary;
	incomeTaxP = obj.incomeTaxP;
	pensionFundP = obj.pensionFundP;
	allowanceP = obj.allowanceP;
	accrued = obj.accrued;
	withheld = obj.withheld;
	finalPayment = obj.finalPayment;
}

// destructor
Payment::~Payment()
{
	delete[]nameSurname;
	delete[]hireDate;
}

// enter
void Payment::Enter()
{
	const int BUFFSIZE = 256;
	char buffer[BUFFSIZE];

	cout << "\t|Enter|\n\n";

	cout << "Enter name, surname : ";
	cin.getline(buffer, BUFFSIZE);
	if (nameSurname != nullptr)
		delete[]nameSurname;
	nameSurname = new char[strlen(buffer) + 1];
	strcpy_s(nameSurname, strlen(buffer) + 1, buffer);

	cout << "Enter hire date : ";
	cin.getline(buffer, BUFFSIZE);
	if (hireDate != nullptr)
		delete[]hireDate;
	hireDate = new char[strlen(buffer) + 1];
	strcpy_s(hireDate, strlen(buffer) + 1, buffer);

	cout << "Enter work days amount : ";
	cin >> workDaysAmount;
	if (workDaysAmount > 25)
		workDaysAmount = 25;
	cout << "Enter worked days : ";
	cin >> workedDays;
	if (workedDays > workDaysAmount)
		workedDays = workDaysAmount;
	cout << "Enter month salary : ";
	cin >> monthSalary;
	cout << "Enter income tax (%) : ";
	cin >> incomeTaxP;
	cout << "Enter pension fund (%) : ";
	cin >> pensionFundP;
	cout << "Enter allowance (%) : ";
	cin >> allowanceP;
	cout << endl;

	CalcualateResult();
}

// output info
void Payment::Print() const
{
	cout << "Name : " << nameSurname << endl;
	cout << "Hiring date : " << hireDate << endl;
	cout << "Month Salary : " << monthSalary << endl;
	cout << "Work days : " << workDaysAmount << endl;
	cout << "Worked days : " << workedDays << endl;
	cout << "Income tax : " << incomeTaxP << '%' << endl;
	cout << "Pension fund : " << pensionFundP << '%' << endl;
	cout << "Allowance : " << allowanceP << '%' << endl;
	cout << "Accrued : " << accrued << endl;
	cout << "Withheld : " << withheld << endl;
	cout << "Final payment : " << finalPayment << endl << endl;
}

// Getters
const char* Payment::GetnNameSurname() const
{
	return nameSurname;
}

const char* Payment::GetnhireDate() const
{
	return hireDate;
}

double Payment::GetMonthSalary() const
{
	return monthSalary;
}

int Payment::GetWorkDaysAmount() const
{
	return workDaysAmount;
}

int Payment::GetWorkedDays() const
{
	return workedDays;
}

double Payment::GetIncomeTaxP() const
{
	return incomeTaxP;
}

double Payment::GetPensionFundP() const
{
	return pensionFundP;
}

double Payment::GetAllowanceP() const
{
	return allowanceP;
}

double Payment::GetAccrued() const
{
	return accrued;
}

double Payment::GetWithheld() const
{
	return withheld;
}

double Payment::GetFinalPayment() const
{
	return finalPayment;
}


// Setters
void Payment::SetnNameSurname(const char* nameSurname)
{
	if (this->nameSurname != nullptr)
		delete[]this->nameSurname;
	this->nameSurname = new char[strlen(nameSurname) + 1];
	strcpy_s(this->nameSurname, strlen(nameSurname) + 1, nameSurname);
}

void Payment::SetnhireDate(const char* hireDate)
{
	if (this->hireDate != nullptr)
		delete[]this->hireDate;
	this->hireDate = new char[strlen(hireDate) + 1];
	strcpy_s(this->hireDate, strlen(hireDate) + 1, hireDate);
}

void Payment::SetMonthSalary(double monthSalary)
{
	this->monthSalary = monthSalary;
	CalcualateResult();
}

void Payment::SetWorkDaysAmount(int workDaysAmount)
{
	if (workDaysAmount > 25)
		this->workDaysAmount = 25;
	else
		this->workDaysAmount = workDaysAmount;
	CalcualateResult();
}

void Payment::SetWorkedDays(int workedDays)
{
	if (workedDays > workDaysAmount)
		this->workedDays = workDaysAmount;
	else
		this->workedDays = workedDays;
	CalcualateResult();
}

void Payment::SetIncomeTaxP(double incomeTaxP)
{
	this->incomeTaxP = incomeTaxP;
	CalcualateResult();
}

void Payment::SetPensionFundP(double pensionFundP)
{
	this->pensionFundP = pensionFundP;
	CalcualateResult();
}

void Payment::SetAllowanceP(double allowanceP)
{
	this->allowanceP = allowanceP;
	CalcualateResult();
}
