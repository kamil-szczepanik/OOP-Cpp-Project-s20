#pragma once
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
	vector<Package> vector_of_packages;
	Vehicle vehicle;
public:

	Courier();
	Courier(int id, string name, string surname, Vehicle vehicle);
	~Courier();
	int get_id();
	string get_name();
	string get_surname();
	string get_full_name(); 
	Package operator[](unsigned int which);
	void add_package(Package p); // istnieje limit paczek w zaleznosci od wielkosci pojazdu
	void remove_package(Package p);
	void show_packages();
	Vehicle get_vehicle();
	int get_vehicle_id();
	string get_vehicle_size();
	int get_vehicle_capacity();
};

