/*
Pratheek Nagaraj
Introduction to C++
November 28, 2009
*/

//Directives, Header Files, and Namespaces
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

//Function Identifiers
void runMenu( );
void displayMenu( );
int getOption( );
void exitFunc( );
void encrypFunc( );
void decrypFunc( );
void inputFileFunc();
void outputFileFunc();
void runEncryption( char[] );
void runDecryption( char[] );

//Global Objects and Variables
ifstream inputFile;
ofstream outputFile;
ifstream inputFile2;
bool cont = true;

//Main Method
int main()
{ 
  runMenu(); //Run the Menu Function
}

//Menu Function
void runMenu( )
{
	//Variable
	int option;

	//Loop for Program continue
	while ( cont )
	{
		//Display Choise
		displayMenu( );
		//Get User Choise
		option = getOption( );
		if ( option == 1 )  //Encryption
		{
			encrypFunc( ); //Run Function
		}
		else if ( option == 2 )  //Decryption
		{
			decrypFunc( ); //Run Function
		}
		else if ( option == 3 )  //Exit
		{
			cont = false;
			exitFunc( ); //Run Function
		}
	}
}

//Display Menu Function
void displayMenu( )
{
	//Create Menu
	cout << "      Menu       " << endl << "------------------" << endl;
	cout << "[1] Encryption" << endl << "[2] Decryption" << endl << "[3] Exit" << endl << endl;
}

//User Input Option
int getOption( )
{
	//Variables
	int option = 0;
	char entered[51];
	bool pass = false;
	
	//Output
	cout << "Your Selection: ";

	//Input
	cin >> entered;
	option = atoi(entered);

	//Check if valid option
	if ( option <= 3 && option >= 1 )  //Valid
	{
		pass = true;
	}
	else  //Invalid
	{
		cout << "Invalid Selection" << endl;
		option = 0;
	}
	
	//Return the option
	return option;
}

//Quite Program Function
void exitFunc() 
{
	cout << endl << "Thank You" << endl << "Goodbye" << endl;
}

//Encryption Function
void encrypFunc()
{
	//Password Variable, Get Password
	char password[31];
	cout << endl << "Please enter a password: ";
	cin >> password;
	
	//Input File Variable and Pass Variable
	char fileName[51];
	bool inputPass = false;

	//Get File Name
	cout << "Please enter an input file name: ";
	cin >> fileName;
	inputFile.open(fileName); //Locate Path, change if needed

	//Check if valid
	if (inputFile.fail())
	{  
		//Invalid
		cout << "Error opening file." << endl;
		cont = false;
	}
	else
	{
		//Valid
		inputPass = true;
	}
	
	char fileName2[51];
	
	//Get Output File if valid
	if ( inputPass )
	{
		cout << "Please enter an output file name: ";
		cin >> fileName2;
		outputFile.open(fileName2,ios::ate);  //Directory Path, change if needed

		//Run Encryption Process
		runEncryption( password );
	}
}

//Encryption Process
void runEncryption( char pass[31] )
{
	//Starting Variables
	int a = 0;
	const int SIZE = 250; //Please keep words under 250 characters in length
	char character[SIZE]; 
	int j = 0;
	int f = strlen(pass);

	//Get Words from File
	while ((character[a++]=inputFile.get()) != EOF)
	{
		--a;
		character[a];
		//Cycle through password
		if ( j >= f )
		{
			j = 0;
		}
		j++;

		//Output encrypted character to file
		outputFile << (char)(character[a]+pass[j]);
	}
	
	//Close input and output
	inputFile.close();
	outputFile.close();

	cout << " ...Finished " << endl << endl;
}

//Decryption Function
void decrypFunc()
{
	//Get a Password
	char password[31];
	cout << endl << "Please enter a password: ";
	cin >> password;
	
	//Variable fileName and pass variable
	char fileName[51];
	bool inputPass = false;

	cout << "Please enter an input file name (for decryption): ";
	cin >> fileName;
	inputFile2.open(fileName);  //Directory Path, change if needed
	
	//Check if valid
	if (inputFile2.fail())
	{
		//Invalid
		cout << "Error opening file." << endl;
		cont = false;
	}
	else
	{
		//Valid
		inputPass = true;
	}

	//Run if valid
	if ( inputPass )
	{
		//Run decryption process
		cout << "Running Decryption Process..." << endl << endl;
		runDecryption( password );
	}
}

//Decryption Process Function
void runDecryption( char pass[31] )
{
	//Starting Variables
	int a = 0;
	const int SIZE = 250; //Please keep words under 250 characters in length
	char character[SIZE];
	int j = 0;
	int f = strlen(pass);

	//Run through words in file
	while ((character[a++]=inputFile2.get()) != EOF)
	{
		--a;
		character[a];
		//Cycle through password
		if ( j >= f )
		{
			j = 0;
		}
		j++;
		//Decrypt and print to screen
		cout << (char)(character[a]-pass[j]);
	}
	//Close input file
	inputFile2.close();

	cout << endl << " ...Finished " << endl << endl;
}

