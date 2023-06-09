#ifndef COURIER_H
#define COURIER_H

#include <iostream>
#include <vector>

#include "Vehicle.h"
#include "Package.h"

using namespace std;

class Courier
{
private:
	int id;
	string name, surname;
	vector<Package*> packages;
	Vehicle vehicle;

public:
	Courier();
	Courier(string name, string surname, Vehicle vehicle);
	Courier(int id, string name, string surname, Vehicle vehicle);

	int getId();
	string getName();
	string getSurname();
	string getFullName();

	void addPackage(Package* p); // istnieje limit paczek w zaleznosci od wielkosci pojazdu
	void removePackage(Package* p);
	vector<Package*> getPackages();

	Vehicle getVehicle();
};

#endif // !COURIER_H