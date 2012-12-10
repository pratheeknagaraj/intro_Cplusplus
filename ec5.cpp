/*
Pratheek Nagaraj
Introduction to C++
November 18, 2009
*/

//Important Declarations
#include <iostream>
using namespace std;

//Function Identifiers
double getNumber();
void convertToInteger( double );
void reduceFraction( );

//Variables
int numer;
int denom;

//Main Function
int main()
{
  cout << "   Convert Decimal to Improper Fraction" << endl << endl;
	double myDecimal = 0;
	myDecimal = getNumber( );  //Input
	convertToInteger( myDecimal );  //Create a Fraction
	reduceFraction( );  //Reduce and Print Fraction
}

double getNumber()
{
	double num = 0;
	cout << "Please enter a decimal value: ";
	cin >> num;  //Input a Decimal
	return num;
}

void convertToInteger( double dec )
{
	int denominator = 1;  //Initialize Denominator
	double numerator;     //Create Numerator Variable
	numerator = dec;      //Initialize Numerator
	bool pass = false;    //Loop Control

	while( !pass )
	{
		/*================================
		If you would like more precision
		change the ".00001" values
		================================*/
		if ( (int)(numerator) - numerator < 0.00000001 && (int)(numerator) - numerator > -0.00000001 )  //Check Precision
		{
			pass = true;
		}
		else 
		{
			//Raise Fraction
			denominator *= 10;
			numerator *= 10;
		}
	}
	
	//Finalize Unreduced Fraction
	numer = (int)numerator;
	denom = denominator;
}

void reduceFraction( )
{
	//Loop Control
	bool pass = false;

	for ( int i = denom; i > 0 && pass == false; i-- )  //Loop through GCF
	{
		if ( numer%i == 0 && denom%i == 0)    //Divide out with no remainder
		{
			pass = true;
			numer = (int)((numer*1.0)/i);     //Reduce Numerator
			denom = (int)((denom*1.0)/i);     //Reduce Denominator
			cout << endl << numer << " / " << denom << endl;   //Print Results
			cout << endl << "Numerator: " << numer << endl;    //Print Results
			cout << "Denominator: " << denom << endl << endl;  //Print Results
		}
	}
}