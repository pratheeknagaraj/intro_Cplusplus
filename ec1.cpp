#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std; 

int main() { 
  //Local Variables
	//Equation: x^2 + 2x - 15 = 0
	int a = 1;
	int b = 2;
	int c = -15;
	int x1;
	int x2;

	//Solving
	x1 = (-b+sqrt(pow((double)b, 2.0) - 4*a*c))/2*a;
	x2 = (-b-sqrt(pow((double)b, 2.0) - 4*a*c))/2*a;

	//Outputs
	cout << "Solving Quadratics Program" << endl;
	cout << "Equation: x^2 + 2x - 15 = 0" << endl;
	cout << "--------------------------" << endl;
	cout << "Roots: " << x1 << ", " << x2 << endl;
	cout << "Y-Intercept: " << c << endl;
	cout << "Sum of roots: " << (double)b/-a << endl;
	cout << "Product of roots: " << (double)c/a << endl;

	return 0;
}