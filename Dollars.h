// Derived from the Currency class
// its role is to send the name of the currency to the Currency class using constructor initialization list
// and have destructor that demostrates polymorhpism


#ifndef DOLLARS_H
#define DOLLARS_H
#include<string>
#include<iostream>
#include"Currency.h"

class Dollars : public Currency
{
public:
	// constructor that uses constructor initialization list
	Dollars() :Currency("Dollars", "Cents")
	{
	}
	Dollars(int wholeValue, int partialValue) :Currency("Dollars", "Cents")
	{
		//string w = "Dollars"; 
		//string p = "Cents";
		//Currency::Currency(w, p);
		Currency::setWholeValue(wholeValue);
		Currency::setFractionalValue(partialValue);
	}

	// virtual destructor uses polymorphism to get called by the currency class pointers
	virtual ~Dollars()
	{
		cout << "dollars class Deconstructor\n";
	}
};

#endif