#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

using namespace std;

class Vehicle
{
private:
	int id;
	double sizeX, sizeY, sizeZ;

public:
	Vehicle();
	Vehicle(int id, double sizeX, double sizeY, double sizeZ);	

	int getId();
	int getCapacity();
};

#endif //!VEHICLE_H
