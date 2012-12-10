#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std; 

int main() { 
  //set coordinates
	double homeX = 80;	
	double homeY = 26;
	double hurricaneX = 0;
	double hurricaneY = 0;
	double hurricaneSpeed = 0;
	double distance = 0;
	int time = 0;
	int days = 0;
	int hours = 0;

	//Inputs
	cout << "Hurricane Program" << endl << endl;
	cout << "Enter Hurricane's North Coordinate: ";
	cin >> hurricaneY;
	cout << "Enter Hurricane's West Coordinate: ";
	cin >> hurricaneX;
	cout << "Enter Hurricane's Speed(mph): ";
	cin >> hurricaneSpeed;
	if ( hurricaneY > 90 || hurricaneX > 180 ) {
		cout << "Error! Input not in Domain" << endl;
		return 0;
	}

	//Manipulation
	distance = sqrt(pow(homeX-hurricaneX,2.0)+pow(homeY-hurricaneY,2.0));
	distance *= 69.046767; //Miles in standard latitute & longitude
	time = static_cast<int>(distance/hurricaneSpeed);
	if (time >= 24) { //Hours and Days
		 days = (time - time%24)/24;
		 time = time - days*24;
	}
	hours = time;

	//Output
	cout << endl << "----------------------" << endl;
	cout << "Distance: " << distance << "miles" << endl;
	cout << "Time: " << days << "days " << hours << "hours" << endl;

	return 0;
}