#include<iostream>
#include<string>
#include"Currency.h"
#include"Dollars.h"

using namespace std;

class ADTNode
{
private:
	int intValue;
	ADTNode *headNode;
	ADTNode *adtNodePointer = nullptr;
public:
	int getIntData()
	{
		return intValue;
	}
	void setIntData(int number)
	{ 
		intValue = number;
	}
	ADTNode* getNextPointer()
	{
		return adtNodePointer;
	}
	void displayList() const
	{
		// run through the list, displaying each node that is not the head node
	}
	void insertNode(double number)
	{
		// insert a node
	}
	void deleteNode(double number)	
	{
		// delete a node
	}
};

int main()
{

	cout << "press enter to exit the program ...";
	cin.get();
	return 0;
}
