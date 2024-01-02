//Kenneth Tidwell
//COP2551
//Project 5

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;



//CLASS
class words
{
private:

	char str1[10000];					//cstring
	string inputFileName;				//string to store user's file name
	string outputFileName;				//string to store user's output file name
	ifstream inputFile;					//input file storage location
	ofstream outputFile;				//output file storage location




public:
	void getInput();		//gets input from the user and puts it in the c-string
	void storeData();		//puts the input into a c-string
	void caseChanger();		//changes the case of the c-string
	void storeOutput();		//puts the new data into a user specified file
	void displayOutput();	//displays the new data




};

/***********************Method Definitions *************************/

void words::getInput()
{
	cout << "Please enter the file name with the file type(ex: test.txt):" << endl;
	cin >> inputFileName;
	inputFile.open(inputFileName);
	if (!inputFile)
	{
		cerr << "Input file did not open properly" << endl;
		exit(1);
	}

}

void words::storeData()
{
	inputFile.getline(str1, 10000);

}

void words::caseChanger()
{
	int counter = 0;
	int firstFlag = 0;

	while (str1[counter] != '\0')
	{
		while (firstFlag == 0)
		{
			if (str1[counter] != '.' && str1[counter] != ' ')
			{
				str1[counter] = toupper(str1[counter]);
				counter++;
				firstFlag = 1;
			}

			if (str1[counter] == ' ')
			{
				counter++;
			}
		}

		while (str1[counter] == ' ')
		{
			counter++;
		}

		if (str1[counter] == '.')
		{
			counter++;

			while (str1[counter] == ' ')
			{
				counter++;
			}

			if (str1[counter] != '.' && str1[counter] != ' ')
			{
				str1[counter] = toupper(str1[counter]);
				counter++;
			}

		}

		if (str1[counter] != '.' && str1[counter] != ' ')
		{
			str1[counter] = tolower(str1[counter]);
			counter++;
		}

	}
}

void words::storeOutput()
{
	int counts = 0;

	cout << endl << "Please enter a name for the output file (include .txt file type newoutput.txt): " << endl;
	cin >> outputFileName;
	outputFile.open(outputFileName);

	while (str1[counts] != '\0')
	{
		outputFile.put(str1[counts]);
		counts++;
	}
	


}

void words::displayOutput()
{
	int count = 0;

	cout << endl << endl;
	while (str1[count] != '\0')
	{
		cout << str1[count];
		count++;
	}

	cout << endl << endl;
}




int main()
{
	words obj1;

	obj1.getInput();
	obj1.storeData();
	obj1.caseChanger();
	obj1.displayOutput();
	obj1.storeOutput();
	




	return 0;
}