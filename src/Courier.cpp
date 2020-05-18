#include "Courier.h"

Courier::Courier()
{
	this->id = 0;
	this->name = "John";
	this->surname = "Smith";
	Vehicle vehicle(1, "S");
	this->vehicle = vehicle;
}
Courier::Courier(int id, string name, string surname, Vehicle vehicle)
{
	this->id = id;
	this->name = name;
	this->surname = surname;
	this->vehicle = vehicle;
}
Courier::~Courier()
{
	
}
int Courier::get_id()
{
	return id;
}
string Courier::get_name()
{
	return name;
}
string Courier::get_surname()
{
	return surname;
}
string Courier::get_full_name()
{
	return (name + " " + surname);
}

Package Courier::operator[](unsigned int which)
{
	return vector_of_packages[which];
}
void Courier::add_package(Package p)
{
	if (vector_of_packages.size() < vehicle.get_capacity())
	{
		vector_of_packages.push_back(p);
	}
	else
	{
		cout << "Unable to add package - limit of " << vehicle.get_capacity() << " packages has been reached !" << endl;
	}
}
void Courier::remove_package(Package p)
{
	for (unsigned int i = 0; i < vector_of_packages.size(); i++)
	{
		if (vector_of_packages[i].id == p.id)
		{
			vector_of_packages.erase(vector_of_packages.begin() + i);
		}
	}
}
void Courier::show_packages()
{
	for (unsigned int i = 0; i < vector_of_packages.size(); i++)
	{
		if (i < vector_of_packages.size() - 1)
		{
			cout << vector_of_packages[i].id << ", ";
		}
		else cout << vector_of_packages[i].id;
	}
	cout << endl;
}
Vehicle Courier::get_vehicle()
{
	return vehicle;
}
int Courier::get_vehicle_id()
{
	return vehicle.get_id();
}
string Courier::get_vehicle_size()
{
	return vehicle.get_size();
}
int Courier::get_vehicle_capacity()
{
	return vehicle.get_capacity();
}