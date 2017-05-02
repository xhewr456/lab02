#ifndef STACKADT_H
#define STACKADT_H
#include <iostream> // For cout
#include"LinkedList.h"
using namespace std;

//class LinkedList;

template <class T>
class StackList :protected ListNode
{
private:

	int stackSize; // The stack size
	top;  // indicates the top of the stack,


public:
	StackList()
	{
		//  constructor
	}
	void push()
	{
		// put the new item on the top (last item) of the stack
	}
	void pop()
	{
		// retrive AND remove the top item from the stack, aka the last item entered in, or the last element of the list
	}
	//void top()
	//{
	//	// "An integer that is used to mark the top of the stack."  so says the book
	//}
	bool isEmpty()
	{
		// returns true if the stack has no items
	}
};


#endif