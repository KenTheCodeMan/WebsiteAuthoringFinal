//Kenneth Tidwell
//COP2535.DM1
//project 1, sort numbers in random text with two methods, count stuff

#include<iostream>
#include<fstream>
using namespace std;

//prototypes go here
int bubbleSort(int bubbleA[], const int SIZE);
int selectionSort(int selectionA[], const int SIZE);
void linearSearch(int bubbleA[]);
void binarySearch(int bubbleA[], const int SIZE);

int main()
{
	const int SIZE = 200;
	int bubbleA[SIZE] = { 0 };
	int selectionA[SIZE] = { 0 };
	int bubbleCounter = 0;
	int selectionCounter = 0;

	// inport file in
	ifstream inFile("random.txt");
	if (!inFile) {
		cout << endl << "Failed to open file";
		return 1;
	}
	
	//File to array
	for (int i = 0; i < SIZE; i++)
	{
		inFile >> bubbleA[i];
		selectionA[i] = bubbleA[i];
	}

	bubbleCounter = bubbleSort(bubbleA, SIZE);
	selectionCounter = selectionSort(selectionA, SIZE);

	cout << ("Bubble sort took ") << bubbleCounter << " exchanges to fully sort the Array." << endl << endl;
	cout << ("Selection sort took ") << selectionCounter << " exchanges to fully sort the Array.";

	linearSearch(bubbleA);
	binarySearch(bubbleA, SIZE);

	return 0;
}

/*****************function definitions************************/

//bubblesort that returns Int # of exchanges
int bubbleSort(int bubbleA[], const int SIZE)
{
	int counter = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE - 1; j++)
		{
			if (bubbleA[j] > bubbleA[j + 1])
			{
				int temp = bubbleA[j];
				bubbleA[j] = bubbleA[j + 1];
				bubbleA[j + 1] = temp;
				counter++;
			}
		}
	}
	return counter;
}

//selection sort that returns int # of exchanges 
int selectionSort(int selectionA[], const int SIZE)
{
	int counter = 0;
	for (int z = 0; z < SIZE; z++)
	{
		for (int x = z + 1; x < SIZE; x++)
		{
			if (selectionA[z] > selectionA[x])
			{
				int temp = selectionA[z];
				selectionA[z] = selectionA[x];
				selectionA[x] = temp;
				counter++;
			}
		}
	}
	return counter; 
}

// linear search
void linearSearch(int bubbleA[])
{
	bool found = false;
	while (found == false)
	{
		for (int i = 0; i < 200; i++)
			if (bubbleA[i] == 869)
			{
				found = true;
				cout << endl << endl << "869 is at element : " << i << ".  and it took " << i + 1 << " linear search comparisons.";
			}
	}
}

//binary search
void binarySearch(int bubbleA[], const int SIZE)
{
	int first = 0;
	int last = SIZE - 1;
	int middle = (first + last) / 2;
	int binaryCounter = 0;

	while (first <= last)
	{
		if (bubbleA[middle] < 869) {
			first = middle + 1;
			binaryCounter++;
		}

		else if (bubbleA[middle] == 869) {
			cout << endl << endl << "869 is at element : " << middle << ".  and it took " << binaryCounter << " binary search comparisons." << endl << endl;
			return;
		}

		else {
			last = middle - 1;
		}
		middle = (first + last) / 2;
		binaryCounter++;
	}
}