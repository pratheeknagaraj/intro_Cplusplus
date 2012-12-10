/*
Pratheek Nagaraj
Introduction to C++
October 20, 2009
*/

#include<iostream>
#include<iomanip>
using namespace std;
bool check( int, int, int );

int main()
{
  //Local Variables
	int x,y,z;
	bool answer = false;
	int maxNum = 512;

	//User Interaction
	cout << "Display answers less than what (int)? ";
	cin >> maxNum;
	cout << endl;

	//Assignment Checker Loops
	for ( x=0 ; x<100 ; x++ )
	{
		for ( y=0 ; y<100 ; y++ )
		{
			for ( z=0 ; z<100 ; z++ )
			{
				answer = check(x,y,z);
				if ( answer == true && x*y*z < maxNum )
				{
					cout << "One answer is: x = " << x << ", y = " << y << ", z = " << z << endl;
					cout << "   " << x << "*" << y << "*" << z << " = (" << x << "+" << y << "+" << z << ")*20 + 32" << endl;
					cout << "   " << x*y*z << " = " << (x+y+z)*20 + 32 << endl << endl;
				}
			}
		}
	}

	//Disclaimers
	cout << "   Note: the lowest match is x = 8, y = 8, z = 8" << endl;
	cout << "         however there are multiple answers" << endl << endl;
}
bool check( int a, int b, int c)
{
	//Checking Function
	if ( a*b*c == (a+b+c)*20 + 32 )
	{
		return true;
	}
	else
	{
		return false;
	}
}