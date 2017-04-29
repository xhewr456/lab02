#include<iostream>
#include<string>
#include"Currency.h"
#include"Dollars.h"

using namespace std;

class LinkedListNode
{
private:
	// List head pointer
	double value;
	LinkedListNode *nextNodePointer;

public:
	// Constructor
	LinkedListNode()
	{
		nextNodePointer = nullptr;
	}

	// Destructor
	~LinkedListNode() 
	{
	}

	// Linked list operations
	void appendNode(double num)
	{
		LinkedListNode *newNode; // To point to a new node
		LinkedListNode *nodePtr; // To move through the list

		// Allocate a new node and store num there.
		newNode = new LinkedListNode;
		newNode->value = num;
		newNode->nextNodePointer = nullptr;

		// If there are no nodes in the list make newNode the first node
		if (nextNodePointer == nullptr)
			nextNodePointer = newNode;

		// Otherwise, insert newNode at end
		else
		{
			// Initialize nodePtr to head of list.
			nodePtr = nextNodePointer;

			// Find the last node in the list.
			while (nodePtr->nextNodePointer != nullptr)
				nodePtr = nodePtr->nextNodePointer;

			// Insert newNode as the last node.
			nodePtr->nextNodePointer = newNode;
		}
	}
	void insertNode(double number)
	{
		LinkedListNode *newNode; // To point to a new node
		LinkedListNode *nodePtr; // To move through the list
		LinkedListNode *previousNode;  // the previous node

		newNode = new LinkedListNode;
		newNode->value = number;
		newNode->nextNodePointer = nullptr;

		// If there are no nodes in the list make newNode the first node
		if (nextNodePointer == nullptr)
			nextNodePointer = newNode;

		// Otherwise, insert newNode
		else
		{
			// position nodePtr at the head of list.
			nodePtr = nextNodePointer;

			// initialize previousNode to nullptr
			previousNode = nullptr;

			// skip all nodes whose value is less than number
			while (nodePtr != nullptr && nodePtr->value < number)
			{
				previousNode = nodePtr;
				nodePtr = nodePtr->nextNodePointer;
			}

			// if the new node is to be the first on the list, insert it before all other nodes
			if (previousNode == nullptr)
			{
				nextNodePointer = nodePtr;
				newNode->nextNodePointer = nodePtr;
			}

			// otherwise, insert after the previous node
			else
			{
				previousNode->nextNodePointer = newNode;
				newNode->nextNodePointer = nodePtr;
			}

		}
	}
	void deleteNode(double)
	{

	}
	void displayList() const
	{
		LinkedListNode *nodePtr; // To move through the list

		// Position nodePtr at the head of the list.
		nodePtr = nextNodePointer;

		// While nodePtr points to a node, traverse the list.
		while (nodePtr != nullptr)
		{
			// Display the value in this node.
			cout << nodePtr->value << endl;

			// Move to the next node.
			nodePtr = nodePtr->nextNodePointer;
		}
	}
};


int main()
{
	LinkedListNode linkedList;
	linkedList.appendNode(2.5);
	linkedList.appendNode(7.9);
	linkedList.appendNode(12.6);

	// put a new node between the 7.9 and 12.6 node
	linkedList.insertNode(10.5);

	linkedList.displayList();
	cout << "press enter to exit the program ...";
	cin.get();
	return 0;
}
