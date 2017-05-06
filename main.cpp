// 
// Lab 02
// Names:

/*
this program has been created to demostrate linked list and stack functionality on a variety of data types.
option one excerises all of the linked list functionality on an ADT
option two excerises all the stack functionality on a int
option three excerises all the stack functionality on a currency adt
option four excerises all the stack functionality on a string
option five shows the error message when attempting to work with an empty stack
There are several other standard LinkedList functions not demostrated in main but have been added for use in future projects.
Most importantly the 'tail' pointer also known as 'last' actively tracks the last node in both the linked list and the Stack.
*/


#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Currency.h"
#include"Dollars.h"
#include"StackADT.h"

using namespace std;

int getMenuInput(int);
void runLinkedList();
void runIntStack();
void runCurrencyStack();
void runStringStack();
void runEmptyStack();



int main()
{
	ios init(NULL);  
	init.copyfmt(cout); 
	int choice = 0;
	while (choice != 6){
		if (choice != 0){
			cout << "\n\nPress enter to continue.\n";
			cin.get();
		}
		cout << "\nMenu: \n 1. LinkedList Demo - Currency \n 2. Stack Demo - Integer \n 3. Stack Demo - Currency \n 4. Stack Demo - String \n 5. Stack Demo - Empty Stack \n 6. Exit \n\nEnter option #: ";
		choice = getMenuInput(6); //ensure user input is clean
		cout << endl << endl;
		//each option will demonstrate the core stack or linklist functions for the user.
		switch (choice){
		case(1) :
			runLinkedList();
			break;
		case(2) :
			runIntStack();
			break;
		case(3) :
			runCurrencyStack();
			break;
		case(4) :
			runStringStack();
			break;
		case(5) :
			runEmptyStack();
			break;
		case(6) :
			break;
		default:
			cout << "Error\n";
		}
	}
	cout << "exiting... press ENTER to complete.";
	cin.get();
	return 0;
}

int getMenuInput(int size)
{
	int userInput = 0;
	string tempString;
	getline(cin, tempString);
	while ((tempString[0] < 49 || tempString[0] > (48 + size)) || tempString[1] != '\0')
	{
		cout << "1 - " << size << " are the only valid choices, try again: ";
		getline(cin, tempString);
	}
	userInput = stoi(tempString);
	return userInput;
}

void runLinkedList(){
	// Define a LinkedList object.
	LinkedList<Currency> list;
	// Define some Currency objects.
	Currency currency1("Dollar", "Cent", 10, 15);
	Currency currency2("Euro", "Pence", 12, 4);
	Currency currency3("Peso", "Cento", 11, 41);
	// Store the Currency objects in the list.
	list.push_end(currency1);
	list.push_end(currency2);
	list.push_end(currency3);
	// Display the values in the list.
	cout << "Here are the initial values:\n";
	list.displayList();
	cout << endl;
	// Insert another Currency object.
	cout << "Now inserting a Rubel, value $4.02\n";
	Currency currency4("Ruble", "Kopecks", 4, 2);
	list.insertNodeByValue(currency4);
	// Display the values in the list.
	cout << "Here are the nodes now.\n";
	list.displayList();
	cout << endl;
	// Delete the last node.
	cout << "Now deleting the Euro currency.\n";
	list.deleteNode(currency2);
	// Display the values in the list.
	cout << "Here are the nodes left.\n";
	list.displayList();
	// Remove the last node in the list.
	cout << "\nNow deleting the last node\n";
	list.pop_end();
	cout << "Here are the nodes left.\n";
	list.displayList();
}

void runStringStack(){
	// Define some string objects.
	string string1("\"22c is good so far.\"");
	string string2("\"Stacks are cool.\"");
	string string3("\"Hello World\"");
	StackList<string> stringStack;
	cout << "<string> stack ...\n";
	cout << "pushing " << string1 << " onto the stack\n";
	stringStack.push(string1);
	cout << "pushing " << string2 << " onto the stack\n";
	stringStack.push(string2);
	cout << "stack contains:\n";
	stringStack.displayStack();
	cout << "\npushing " << string3 << " onto the stack\n";
	stringStack.push(string3);
	cout << "stack contains:\n";
	stringStack.displayStack();
	cout << "\npoping last item returns: ";
	stringStack.pop();
	cout << endl;
	cout << "stack size is: " << stringStack.getStackSize() << endl;
	cout << "stack contains:\n";
	stringStack.displayStack();
	cout << "emptying the stack ...\n";
	stringStack.emptyTheStack();
	cout << "stack size is: " << stringStack.getStackSize();
}


void runIntStack(){
	int dd1 = 1;
	int dd2 = 3;
	int dd3 = 5;
	int dd4 = 7;
	int dd5 = 11;
	// stack adt 
	StackList<int> stackTest;
	cout << "<int> stack ...\n";
	cout << "pushing " << dd1 << " onto the stack\n";
	stackTest.push(dd1);
	cout << "pushing " << dd4 << " onto the stack\n";
	stackTest.push(dd4);
	cout << "pushing " << dd3 << " onto the stack\n";
	stackTest.push(dd3);
	cout << "pushing " << dd2 << " onto the stack\n";
	stackTest.push(dd2);
	cout << "stack contains:\n";
	stackTest.displayStack();
	cout << "pushing " << dd3 << " onto the stack\n";
	stackTest.push(dd3);
	cout << "stack size is: " << stackTest.getStackSize() << endl;
	cout << "stack contains:\n";
	stackTest.displayStack();
	cout << "\npoping last item returns: ";
	stackTest.pop();
	cout << endl;
	cout << "stack contains:\n";
	stackTest.displayStack();
	cout << "emptying the stack ...\n";
	stackTest.emptyTheStack();
	cout << "stack size is: " << stackTest.getStackSize();
}

void runCurrencyStack(){
	// Define some Currency objects.
	Currency currency1("Dollar", "Cent", 10, 15);
	Currency currency2("Euro", "Pence", 12, 4);
	Currency currency3("Peso", "Cento", 11, 41);
	//Currency currency5("Yuan", "Fen", 1001, 20);
	Currency *currencyPtr = new Dollars;  
	currencyPtr->setWholeValue(13);
	currencyPtr->setFractionalValue(15);  
	Currency *currencyPtr2 = new Dollars(21, 56);

	StackList<Currency> currencyStack;
	cout << "<currency> stack ...\n";
	cout << "pushing " << currency1 << " onto the stack\n";
	currencyStack.push(currency1);
	cout << "pushing " << currency2 << " onto the stack\n";
	currencyStack.push(currency2);
	cout << "stack contains:\n";
	currencyStack.displayStack();
	cout << "pushing " << currency3 << " onto the stack\n";
	currencyStack.push(currency3);
	cout << "pushing " << *currencyPtr << " onto the stack\n";
	currencyStack.push(*currencyPtr);
	cout << "pushing " << *currencyPtr2 << " onto the stack\n";
	currencyStack.push(*currencyPtr2);
	cout << "stack contains:\n";
	currencyStack.displayStack();
	cout << "poping last item returns: ";
	currencyStack.pop();
	cout << endl << endl;
	cout << "stack size is: " << currencyStack.getStackSize() << endl;
	cout << "stack contains:\n";
	currencyStack.displayStack();
	cout << "emptying the stack ...\n";
	currencyStack.emptyTheStack();
	cout << "stack size is: " << currencyStack.getStackSize();
}

void runEmptyStack(){
	StackList<double> emptyStack;
	cout << "attempting to pop an empty stack...\n";
	emptyStack.pop();
}
