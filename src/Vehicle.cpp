#include "Vehicle.h"
#include <iostream>

using namespace std;

Vehicle::Vehicle()
{
	this->id = 0;
	this->capacity = 30;
	this->size = "S";
}

Vehicle::Vehicle(int id, string size)
{
	this->id = id;
	
	while (size != "S" && size != "L")
	{
		cout << "There is no such size of vehicle!" << endl;
		cout << "Type in correct size name ('S' or 'L'): ";
		cin >> size;
		if (size == "S" || size == "L")
		{
			break;
		}
	}
	if (size == "S")
	{
		this->capacity = 30;
	}
	else if (size == "L")
	{
		this->capacity = 60;
	}
	this->size = size;
}
Vehicle::~Vehicle()
{

}
int Vehicle::get_id()
{
	return id;
}
int Vehicle::get_capacity()
{
	return capacity;
}
string Vehicle::get_size()
{
	return size;
}
Vehicle Vehicle::operator=(Vehicle F)
{
	id = F.get_id();
	size = F.get_size();
	capacity = F.get_capacity();
	return *this;
}
	