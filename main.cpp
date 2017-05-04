// This program demonstrates the linked list template.
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Currency.h"
#include"Dollars.h"
#include"StackADT.h"

using namespace std;

int main()
{
	ios init(NULL);  // clifford:  just trying some stuff out
	init.copyfmt(cout);  // this saves the default cout format style so cout formatting can be reset easily

						 // Define a LinkedList object.
						 //cout << "creating currency object linked list head node ...\n";
	LinkedList<Currency> list;



	// stack adt 
	cout << "stack ...\n";
	StackList<int> stackTest;
	cout << "pushing 3 onto the stack\n";
	stackTest.push(3);
	cout << "pushing 4 onto the stack\n";
	stackTest.push(4);
	cout << "stack contains:\n";
	stackTest.displayStack();
	cout << "pushing 8 onto the stack\n";
	stackTest.push(8);
	cout << "pushing 15 onto the stack\n";
	stackTest.push(15);
	cout << "stack contains:\n";
	stackTest.displayStack();
	cout << endl << endl;




	// Define some Currency objects.
	//cout << "creating currency objects one through five ... \n";
	Currency currency1("Dollar", "Cent", 10, 15);
	Currency currency2("Euro", "Pence", 12, 4);
	Currency currency3("Peso", "Cento", 11, 41);
	//Currency currency5("Yuan", "Fen", 1001, 20);

	Currency *currencyPtr = new Dollars;  // clifford:  just trying some stuff out
	currencyPtr->setWholeValue(13);		  //               |
	currencyPtr->setFractionalValue(15);  //               \/
	Currency *currencyPtr2 = new Dollars(21, 56);

	//cout << "creating doubles linked list head node ...\n";
	LinkedList<double> numbersList;

	double dd1 = 1;
	double dd2 = 2;
	double dd3 = 3;

	//cout << "creating string linked list head node ...\n";
	LinkedList<string> stringList;

	string str1 = "one";
	string str2 = "two";
	string str3 = "three";

	// Store the Currency objects in the list.
	//cout << "appending nodes to currency linked list ...\n";
	list.appendNode(currency1);
	list.appendNode(currency2);
	list.appendNode(currency3);
	list.appendNode(*currencyPtr);  // clifford:  just trying some stuff out
	list.appendNode(*currencyPtr2);

	//cout << "appeneding nodes to doubles linked list ...\n";
	numbersList.appendNode(dd1);
	numbersList.appendNode(dd2);
	numbersList.appendNode(dd3);

	//cout << "appending nodes to string linked list ...\n";
	stringList.appendNode("one");
	stringList.appendNode(str2);
	stringList.appendNode("three");


	// Display the values in the list.
	cout << "Here are the initial values:\n";
	list.displayList();
	cout << endl;

	// Insert another Currency object.
	cout << "Now inserting the Ruble 4.02.\n";
	Currency currency4("Ruble", "Kopecks", 4, 2);
	list.insertNode(currency4);

	// Display the values in the list.
	cout << "Here are the nodes now.\n";
	list.displayList();
	cout << endl;

	// Delete the last node.
	cout << "\nNow deleting the Ruble.\n";
	list.deleteNode(currency4);
	cout << "Now deleting the Dollar (21.56).\n";
	list.deleteNode(*currencyPtr2);

	// Display the values in the list.
	cout << "Here are the nodes left.\n";
	list.displayList();
	cout << "currency list has: " << list.getListSize() << " items" << endl;

	// clifford:  just trying some stuff out
	cout.copyfmt(init);
	cout << "\n\n---------------------------------------\n";  // clifford:  just trying some stuff out
	numbersList.insertNodeAtIndex(4.5, 1);
	numbersList.push_front(7);
	numbersList.displayList();
	cout << "numberList2 ...\n";
	LinkedList<int> numberList2;
	numberList2.appendNode(1);
	numberList2.insertNodeAtIndex(2, 1);
	//numberList2.push_front(3);
	numberList2.displayList();

	cout << "searching <double> list for 6 returns: " << numbersList.searchNodes(6) << endl;
	cout << "searching <double> list for 3 returns: " << numbersList.searchNodes(3) << endl;
	cout << "searching <double> list for 4.5 returns: " << numbersList.searchNodes(4.5) << endl;
	//cout << "\n--------------------------\n";
	//stringList.displayList();


	cin.get();
	return 0;
}