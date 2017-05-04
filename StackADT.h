#ifndef STACKADT_H
#define STACKADT_H
#include <iostream> // For cout
#include"LinkedList.h"
using namespace std;

//LinkedList;

template <class T>
class StackList :protected LinkedList<T>
{
private:
	DataNode<T> *head;
	DataNode<T> *topItem;  // pointer to the top of the stack, aka last item entered in

public:
	StackList()
	{
		//  constructor
		head = nullptr;
	}

	~StackList()
	{
		// destructor needed
	}

	void push(T value)
	{
		// put the new item on the top of the stack, aka add new node and make the new node the first item
		// some where in here the new node that was added should be the new topItem
		this->push_front(value);
	}
	void pop()
	{
		// remove and possible return the top item from the stack, aka the last item entered in
		// two choices are to remove the last item entered (aka first item, the way we are implmenting the stack) and then return nothing
		// or, send a referenced variable and store the last item in that variable (which is the example in the book), and then delete the last item entered
		// that was the user has the value that was deleted, and can use the data as they wish.  The proffessor said the choice is up to us.
	}
	void displayStack()
	{
		this->displayList();
	}
	bool isEmpty()
	{
		// returns true if the stack has no items
		if (this->getListSize == 0)
			return true;
		else
			return false;
	}
};


#endif