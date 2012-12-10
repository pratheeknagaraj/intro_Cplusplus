#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std; 

int main() {
  
	//Declare Variables
	double principal = 0.0;
	double interest = 0.0;
	int months = 0;
	double monthlyPay = 0.0;
	double balance = 0.0;

	//Output and Inputs
	cout << setw(33) << right << "Amortization Schedule" << endl << endl;
	cout << "Enter Principal: ";
	cin >> principal;
	cout << "Enter Interest (Decimal Notation): ";
	cin >> interest;
	cout << "Enter number of months for repayment: ";
	cin >> months;

	balance = principal;
	
	//Find Monthly Pay
	monthlyPay = principal/((1-pow(1+(interest/12),-months))/(interest/12));

	//Create Table Headers
	cout << setprecision(2) << fixed;

	cout << endl << "\tMonthly Payment is: " << monthlyPay << endl << endl;
	
	cout << setw(10) << left << "Pay #" 
		<< setw(15) << "Monthly Int" 
		<< setw(18) << "Month Principal" 
		<< setw(10) << "Balance" << endl << endl;
	
	//Variables for Looping
	double monthlyInt;
	double monthlyPrincipal;
	double totalInterest = 0.0;
	
	//Loop of output Table
	for (int i = 1; i <= months; i++)
	{	
		//Data for table
		cout << setw(10) << left << i;
		monthlyInt = balance * (interest/12);
		totalInterest += monthlyInt;
		cout << setw(15) << monthlyInt;
		monthlyPrincipal = monthlyPay - monthlyInt;
		cout << setw(18) << monthlyPrincipal;
		balance -= monthlyPrincipal;
		cout << setw(10) << right << balance << endl;
	}
	
	//Final Interest
	cout << endl << "Total Interest is: " << totalInterest << endl;
	//Notes
	cout << endl << "Note: This program will not carry significant rounding errors" << endl;
	cout << "      since actual values are stored, rounding is for readability" << endl;
	//Copyright
	cout << endl << "Pratheek Nagaraj © 2009 All Rights Reserved" << endl << endl;

	return 0;
}