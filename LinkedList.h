// A class template for holding a linked list.
// The node type is also a class template.
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream> // For cout
using namespace std;

//*********************************************
// The ListNode class creates a type used to *
// store a node of the linked list. *
//*********************************************

template <class T>
class ListNode
{
public:
	T value; // Node value
	ListNode<T> *next; // Pointer to the next node

					   // Constructor
	ListNode(T nodeValue)
	{
		value = nodeValue;
		next = nullptr;
	}
};

//*********************************************
// LinkedList class *
//*********************************************

template <class T>
class LinkedList
{
private:
	ListNode<T> *head; // List head pointer

public:
	// Constructor
	LinkedList()
	{
		head = nullptr;
	}

	// Destructor
	~LinkedList();

	// Linked list operations
	void appendNode(T);
	void insertNode(T);
	void deleteNode(T);
	void displayList() const;
	void insertNodeAnywhere()
	{
		// insert node at any location by sending the location as an argument, along with sending the value to insert as an argument also
	}
	void searchNodes()
	{
		// search the nodes for the value sent
		// if the value is found, return the position and maybe cout the value
		// if the value was not found, return -1, simalar to a binary search
	}

};


//**************************************************
// appendNode appends a node containing the value *
// passed into newValue, to the end of the list. *
//**************************************************

template <class T>
void LinkedList<T>::appendNode(T newValue)
{

	ListNode<T> *newNode; // To point to a new node
	ListNode<T> *nodePtr; // To move through the list

						  // Allocate a new node and store newValue there.
	newNode = new ListNode<T>(newValue);

	// If there are no nodes in the list
	// make newNode the first node.
	if (!head)
		head = newNode;
	else // Otherwise, insert newNode at end.
	{
		// Initialize nodePtr to head of list.
		nodePtr = head;

		// Find the last node in the list.
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}
}

//***************************************************
// displayList shows the value stored in each node *
// of the linked list pointed to by head. *
//***************************************************

template <class T>
void LinkedList<T>::displayList() const
{
	ListNode<T> *nodePtr; // To move through the list

						  // Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr points to a node, traverse
	// the list.
	while (nodePtr)
	{
		// Display the value in this node.
		cout << nodePtr->value << endl;

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}

//**************************************************
// The insertNode function inserts a node with *
// newValue copied to its value member. *
//**************************************************

template <class T>
void LinkedList<T>::insertNode(T newValue)
{
	ListNode<T> *newNode; // A new node
	ListNode<T> *nodePtr; // To traverse the list
	ListNode<T> *previousNode = nullptr; // The previous node
										 // Allocate a new node and store newValue there.
	newNode = new ListNode<T>(newValue);

	// If there are no nodes in the list
	// make newNode the first node.
	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else // Otherwise, insert newNode.
	{
		// Position nodePtr at the head of list.
		nodePtr = head;

		// Initialize previousNode to nullptr.
		previousNode = nullptr;

		// Skip all nodes whose value is less than newValue.
		while (nodePtr != nullptr && nodePtr->value < newValue)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If the new node is to be the 1st in the list,
		// insert it before all other nodes.
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else // Otherwise insert after the previous node.
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

//******************************************************
// The deleteNode function searches for a node *
// with searchValue as its value. The node, if found, *
// is deleted from the list and from memory. *
//******************************************************

template <class T>
void LinkedList<T>::deleteNode(T searchValue)
{
	cout << "in deleteNode().\n";
	ListNode<T> *nodePtr; // To traverse the list
	ListNode<T> *previousNode; // To point to the previous node
							   // If the list is empty, do nothing.
	cout << "finished making two pointers.\n";
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->value == searchValue)
	{
		nodePtr = head->next;
		cout << "deleteing node (node at the beginning)...\n";
		delete head;
		cout << "all done.\n";
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;
		previousNode = nullptr;
		// Skip all nodes whose value member is not equal to searchValue.
		while (nodePtr != nullptr && nodePtr->value != searchValue)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list,
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr->next != nullptr)
		{
			previousNode->next = nodePtr->next;
			cout << "deleteing node (node not at the end)...\n";
			delete nodePtr;
			cout << "all done.\n";
		}
		// if the last item in the list is the desired value, set previousNode-> to null and delete nodePtr
		else if (nodePtr->value == searchValue && nodePtr->next == nullptr)
		{
			previousNode->next = nullptr;
			cout << "deleteing node (node at the end)...\n";
			delete nodePtr;
			cout << "all done.\n";
		}
	}
	cout << "closing deletNode() ...\n";
}

//**************************************************
// Destructor *
// This function deletes every node in the list. *
//**************************************************

template <class T>
LinkedList<T>::~LinkedList()
{
	ListNode<T> *nodePtr; // To traverse the list
	ListNode<T> *nextNode; // To point to the next node

						   // Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}
#endif
