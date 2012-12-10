#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
int inputNum;
int decimalPlace;
double squareRoot = 0;
double increaseNum = 1;

cout << "    Square Root Program    " << endl;
cout << "---------------------------" << endl;
cout << "Please enter an integer: ";
cin >> inputNum;
cout << setprecision(10) << endl;

while (squareRoot*squareRoot != inputNum && increaseNum > .00000001)
{
  if ((squareRoot+increaseNum)*(squareRoot+increaseNum) <= inputNum)
	{
		squareRoot += increaseNum;
	} 
	else
	{
		increaseNum *= .1;
	}
}

cout << "The Square Root of: " << inputNum << " is " << squareRoot << endl;
cout << "---------------------------" << endl;

return 0;
}