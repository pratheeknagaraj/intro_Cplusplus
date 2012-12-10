/*
Pratheek Nagaraj
Introduction to C++
October 29, 2009
*/

//Important Declarations
#include <iostream>
#include <fstream>
using namespace std;

//Functions
void checkCharacter(char);
void outputInfo();

//Global count variables
int aCount = 0;
int eCount = 0;
int iCount = 0;
int oCount = 0;
int uCount = 0;

int main()
{
  //Create an inputFile
	ifstream inFile;
	inFile.open("C:\\input.txt"); // <-- Insert your file name here

	//Input File Wording Intake
	const int SIZE = 100; //Please keep words under 100 characters in length
	char character[SIZE]; //Otherwise change this constant (And the marked location below)

	//If there is an error reading input file
	if (inFile.fail())
	{
		cout << "Error opening file\n";
	}
	else
	{    
		int a=0;

		//Find the next word
		while ((character[a++]=inFile.get()) != EOF)
		{
			--a;
			checkCharacter(character[a]);
		}
		//Close Input file
		inFile.close();
		//Display information
		outputInfo();
	}
	return 0;
}

void checkCharacter(char letter)
{
	if (letter == 65 || letter == 97)  //Lower or Uppercase A
	{
		aCount ++;
	} 
	if (letter == 69 || letter == 101) //Lower or Uppercase E
	{
		eCount ++;
	}
	if (letter == 73 || letter == 105) //Lower or Uppercase I
	{
		iCount ++;
	}
	if (letter == 79 || letter == 111) //Lower or Uppercase O
	{
		oCount ++;
	}
	if (letter == 85 || letter == 117) //Lower or Uppercase U
	{
		uCount ++;
	}
}

void outputInfo()
{
	//Output File is not Neccessary
	ofstream outFile;
	outFile.open("C:\\Users\\Pratheek\\Desktop\\output.txt",ios::ate);
	outFile << "Document Vowel Statistics" << endl << endl;
	
	//Declare a few arrays to sort
	int amountArray [5] = {aCount,eCount,iCount,oCount,uCount};
	int amountArrayText [5] = {1,2,3,4,5};
	int orderArray [5];
	int orderArrayText [5];

	//Run through arrays in order to sort
	for(int i=0; i < 5; i++) //For amountArray
	{
		int position = 4;

		for(int j=4; j >= 0; j--) //For amountArray comparison
		{
			//Reordering in position
			if (amountArray[i] < amountArray[j])
			{
				position --;
			}
			
			if (amountArray[i] == amountArray[j] && j < i)
			{
				position --;
			}
		}
		//Add to orderArray
		orderArray[position] = amountArray[i];
		orderArrayText[position] = amountArrayText[i];
	}
	
	//Print out the orderArray
	for (int i=0; i < 5; i++)
	{
		//Switch Statement for formatted feedback
		switch (orderArrayText[i])
		{
			//If it's an A
			case 1: cout << "\"A\" Count: " << orderArray[i] << endl;
					outFile << "\"A\" Count: " << orderArray[i] << endl;
					break;
			//If it's an E
			case 2: cout << "\"E\" Count: " << orderArray[i] << endl;
					outFile << "\"E\" Count: " << orderArray[i] << endl;
					break;
			//If it's an I
			case 3: cout << "\"I\" Count: " << orderArray[i] << endl;
					outFile << "\"I\" Count: " << orderArray[i] << endl;
					break;
			//If it's an O
			case 4: cout << "\"O\" Count: " << orderArray[i] << endl;
					outFile << "\"O\" Count: " << orderArray[i] << endl;
					break;
			//If it's an U
			case 5: cout << "\"U\" Count: " << orderArray[i] << endl;
					outFile << "\"U\" Count: " << orderArray[i] << endl;
					break;
		}
	}
	//Close (optional) output file
	outFile.close();

}