/*
Pratheek Nagaraj
Introduction to C++
November 3, 2009
*/

//Important Declarations
#include <iostream>
#include <fstream>
using namespace std;

//Initialize Functions
void runProgram();
int checkNumber( int, int, int );

int main()
{
  //Run Program
	runProgram();
}

void runProgram()
{
	int returnNum;
	cout << "The number is..." << endl;

	for ( int i = 0; i < 6; i++ ) //Hundreds Loop
	{
		for ( int j = 0; j < 10; j++ )  //Tens Loop
		{
			for ( int k = 0; k < 10; k++ )  //Ones Loop
			{
				returnNum = checkNumber( i, j, k );  //Pass Numbers to checker
				if ( returnNum != 0 )
				{
					cout << returnNum << endl; //Print correct answer
				}
			}
		}
	}
}

int checkNumber( int a, int b, int c )
{
	int myNum = a*100+b*10+c;  //Make 3 digit number
	int myNum1 = a*100+c*10+b;  //Make first condition number
	int myNum2 = b*100+a*10+c;  //Make second condition number

	if ( myNum1 + 27 == myNum && myNum2 + 180 == myNum )  //Check conditions
	{
		return myNum;  //Correct Number!
	}
	else
	{
		return 0;   //Inccorect Number
	}
}