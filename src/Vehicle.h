#pragma once
#include <iostream>

using namespace std;

class Vehicle
{
private:
	int id;
	string size;
	int capacity;
public:
	Vehicle(int id, string size);
	Vehicle();
	~Vehicle();
	int get_id();
	string get_size();
	int get_capacity();
	Vehicle operator=(Vehicle F);
};

