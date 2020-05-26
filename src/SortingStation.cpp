#include "SortingStation.h"

#include "IdNumbers.h"

SortingStation::SortingStation()
{
	id = IdNumbers::getNewId(*this);
	couriers = {};
	packages = {};
	addresses = {};
}

Courier SortingStation::getCourier(int id)
{
	for (unsigned int i = 0; i < couriers.size(); i++)
	{
		if (couriers[i].getId() == id)
		{
			return couriers[i];
		}
	}
	throw "No such courier with this ID";
}

vector<Courier> SortingStation::getCouriersList()
{
	return couriers;
}

Package SortingStation::getPackage(int id)
{
	for (unsigned int i = 0; i < packages.size(); i++)
	{
		if (packages[i].getId() == id)
		{
			return packages[i];
		}
	}
	throw "No such package with this ID";
}

vector<Package> SortingStation::getPackagesList()
{
	return packages;
}

bool SortingStation::checkAddress(string address)
{
	bool check = false;
	for (unsigned int i = 0; i < addresses.size(); i++)
	{
		if (addresses[i] == address)
		{
			check = true;
		}
	}
	return check;
}

void SortingStation::addAddress(string address)
{
	addresses.push_back(address);
}

void SortingStation::removeAddress(string address)
{
	for (unsigned int i = 0; i < addresses.size(); i++)
	{
		if (address == addresses[i])
		{
			addresses.erase(addresses.begin() + i);
			break;
		}
	}
}

vector<string> SortingStation::getAddressesList()
{
	return addresses;
}