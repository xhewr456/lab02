//#define _CRT_SECURE_NO_WARNINGS
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
		LinkedListNode *pointToNextNodePtr; // To move through the list

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
			pointToNextNodePtr = nextNodePointer;

			// Find the last node in the list.
			while (pointToNextNodePtr->nextNodePointer != nullptr)
				pointToNextNodePtr = pointToNextNodePtr->nextNodePointer;

			// Insert newNode as the last node.
			pointToNextNodePtr->nextNodePointer = newNode;
		}
	}
	void insertNode(double number)
	{
		LinkedListNode *newNode; // To point to a new node
		LinkedListNode *nextLinkInTheList; // pointer used to move through the list
		LinkedListNode *previousNodePtr;  // point to  the previous node

		newNode = new LinkedListNode;  // create a new node
		newNode->value = number;
		newNode->nextNodePointer = nullptr;

		// if there are no nodes in the list, make nextNodePointer point to the address of newNode
		if (nextNodePointer == nullptr)
			nextNodePointer = newNode;

		// Otherwise, insert newNode
		else
		{
			// position nodePtr at the head of list.
			// initialize previousNode to nullptr
			nextLinkInTheList = nextNodePointer;
			previousNodePtr = nullptr;

			// skip all nodes whose value is less than number
			while (nextLinkInTheList != nullptr && nextLinkInTheList->value < number)
			{
				cout << "checking value: " << nextLinkInTheList->value << endl;
				previousNodePtr = nextLinkInTheList;
				nextLinkInTheList = nextLinkInTheList->nextNodePointer;
			}
			cout << "stopping at value: " << nextLinkInTheList->value << endl;

			// if the new node is to be the first on the list, insert it before all other nodes
			if (previousNodePtr == nullptr)
			{
				nextNodePointer = nextLinkInTheList;
				newNode->nextNodePointer = nextLinkInTheList;
			}

			// otherwise, insert after the previous node
			else
			{
				previousNodePtr->nextNodePointer = newNode;
				newNode->nextNodePointer = nextLinkInTheList;
			}

		}
	}


	void deleteNode(double number)
	{
		//LinkedListNode *newNode; // To point to a new node
		LinkedListNode *traversingNode; // pointer used to move through the list
		LinkedListNode *previousNode;  // point to the previous node

		// if the list is empty, do nothing
		if (nextNodePointer == nullptr)
		{
			return;
		}

		// if the first node is the value, set traversingNode address to nextNodePointer
		// then set nextNodePointer to point traversingNode's nextNodePointer
		// then delete the traversing node
		if (nextNodePointer->value == number)
		{
			traversingNode = nextNodePointer;
			nextNodePointer = traversingNode->nextNodePointer;
			delete traversingNode;
		}

		// else, look through the list for the value
		else
		{
			// shift the traversingNode pointer to point to the first node in the list
			// and previousNode points to the current address of traversingNode
			traversingNode = nextNodePointer;
			previousNode = traversingNode;

			// skip all nodes that are not equal to number
			while (traversingNode->nextNodePointer != nullptr && nextNodePointer->value != number)
			{
				previousNode = traversingNode;
				traversingNode = traversingNode->nextNodePointer;
			}

			// if traversingNode is not at the end, set previousNode's nextNodePointer to traversingNode's nextNodePointer
			// then delete traversing node
			if (traversingNode->nextNodePointer != nullptr) //&& traversingNode->value == number)
			{
				previousNode->nextNodePointer = traversingNode->nextNodePointer;
				delete traversingNode;
			}

			// else, set previousNode's nextNodePointer to null and delete the traversing node
			else
			{
				previousNode->nextNodePointer = nullptr;
				delete traversingNode;
			}
		}
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
	linkedList.insertNode(5.4);

	linkedList.displayList();

	cout << "deleting 2.5 ..." << endl;
	linkedList.deleteNode(2.5);
	linkedList.displayList();

	cout << "deleting 12.6 ..." << endl;
	linkedList.deleteNode(12.6);
	linkedList.displayList();

	cout << "deleting 7.9 ..." << endl;
	linkedList.deleteNode(7.9);
	linkedList.displayList();


	cout << "press enter to exit the program ...";
	cin.get();
	return 0;
}
