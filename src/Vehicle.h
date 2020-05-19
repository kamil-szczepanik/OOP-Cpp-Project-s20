#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle
{
private:
	int id;
	double sizeX, sizeY, sizeZ;

public:
	Vehicle();
	Vehicle(double sizeX, double sizeY, double sizeZ);
	Vehicle(int id, double sizeX, double sizeY, double sizeZ);	

	int getId();
	int getCapacity();
	Vehicle& operator=(const Vehicle& v);
};

#endif //!VEHICLE_H
