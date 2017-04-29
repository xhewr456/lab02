#include<iostream>
#include<string>
#include"Currency.h"
#include"Dollars.h"

using namespace std;

class NumberList
{
private:
	// List head pointer
	double value;
	NumberList *nodePointer;

public:
	// Constructor
	NumberList()
	{
		nodePointer = nullptr;
	}

	// Destructor
	~NumberList() 
	{
	}

	// Linked list operations
	void appendNode(double num)
	{
		NumberList *newNode; // To point to a new node
		NumberList *nodePtr; // To move through the list

		// Allocate a new node and store num there.
		newNode = new NumberList;
		newNode->value = num;
		newNode->nodePointer = nullptr;

		// If there are no nodes in the list
		// make newNode the first node.

		if (nodePointer == nullptr)
			nodePointer = newNode;
		else // Otherwise, insert newNode at end.
		{
			// Initialize nodePtr to head of list.
			nodePtr = nodePointer;

			// Find the last node in the list.
			while (nodePtr->nodePointer != nullptr)
				nodePtr = nodePtr->nodePointer;

			// Insert newNode as the last node.
			nodePtr->nodePointer = newNode;
		}
	}
	void insertNode(double)
	{

	}
	void deleteNode(double)
	{

	}
	void displayList() const
	{
		NumberList *nodePtr; // To move through the list

		// Position nodePtr at the head of the list.
		nodePtr = nodePointer;

		// While nodePtr points to a node, traverse
		// the list.
		while (nodePtr != nullptr)
		{
			// Display the value in this node.
			cout << nodePtr->value << endl;

			// Move to the next node.
			nodePtr = nodePtr->nodePointer;
		}
	}
};


int main()
{
	NumberList list;
	list.appendNode(2.5);
	list.appendNode(7.9);
	list.appendNode(12.6);

	list.displayList();
	cout << "press enter to exit the program ...";
	cin.get();
	return 0;
}
