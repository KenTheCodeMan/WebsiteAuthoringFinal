//Kenneth Tidwell
//COP2535.DM1
//project 3, input data from file into linked list, and create second linked list with the data reversed from the first list

#include <iostream>
#include <fstream>
using namespace std;

class list
{
public:
	void print();
	char inputChar;
	


	struct ListNode {
		char value;
		ListNode *next;
		ListNode* head = nullptr;
		bool first = false;

		ListNode() {

		}
		//constructor
		ListNode(char value1, ListNode* next1 = nullptr)
		{
		if (!first) {
			head = new ListNode;
			head-> value = value1;
			head-> next = nullptr;
			first = true;
			}
		value = value1;
		next = next1;
		cout << value1;
		}

	};
	ListNode* head;



	struct ListNodeReverse {
		char valueTwo;
		ListNodeReverse* next;
		//constructor
		ListNodeReverse(char value2, ListNodeReverse* next2 = nullptr)
		{
			valueTwo = value2;
			next = next2;
		}
	};

};

void importandDisplay() {
	char inputChar;
	list::ListNode* charList = nullptr;
	list::ListNodeReverse* charList2 = nullptr;
	ifstream inputFile("linkedText.txt");

	if (!inputFile)
	{
		cout << "error in opening the file";
		exit(1);
	}

	cout << "The contents of the file are: " << endl;
	while (inputFile >> inputChar) {
		//cout << inputChar << " ";
		charList = new list::ListNode(inputChar, charList);
		charList2 = new list::ListNodeReverse(inputChar, charList2);
	}

	cout << endl << "The contents of the list are: " << endl;
	list::ListNode* ptr = charList;
	while (ptr != nullptr)
	{
		cout << ptr->value << " ";
		ptr = ptr->next;
	}


	cout << endl << "The contents of the reverse list are: " << endl;
	list::ListNodeReverse* ptr2 = charList2;
	while (ptr2 != nullptr)
	{
		cout << ptr2->valueTwo << " ";
		ptr2 = ptr2->next;
	}
}

void list::print()
{
	ListNode* current;
	current = head;
	while (current != nullptr)
	{
		cout << current->value << ' ';
		current = current->next;
	}
}

int main()
{
	importandDisplay();


	return 0;
}