#pragma once
#include<iostream>
using namespace std;

typedef struct Address
{
	string homeNum;
	string streetName;
	string ward;
	string district;
	string city;

	void addressInput();
	void addressOutput();
	bool compareAddress(Address address2);
}

Address;
